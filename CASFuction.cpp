
/****************************************************************************************************************/
#include <fstream>
#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include "conio.h"
#include <cfloat>
#include <climits>

#include"CASHistory.h"
using namespace std;
/****************************************************************************************************************/
CASHistory::CASHistory()//initialization of variables
{
	t=0;
	cas=0;
	pt=0;

	t_first=0;
	t_last=0;
	first_row=0;
	cas_first=0;

	hour_1=0;
	minute_1=0;
	second_1=0;

	hour_2=0;
	minute_2=0;
	second_2=0;

	Tsample_time=0;
	star=0;
	barLength=0;

	this->maxPT = -DBL_MAX;//initialization the maxPT
	this->minPT = +DBL_MAX;//initialization the minPT
}
void CASHistory::Read_data()
{
	cout << "Please enter file name in txt: ";
	string name;
	cin >> name;
	/*Preparing of reading the txt file*/
	ifstream cas_file;
	ifstream inf(name.c_str());

	if(!inf)
	{
		cout << "Sorry,The file does not exist!" << endl;//If system can not find the file,the programme will close.
		system("pause");
		exit(1);
	}

	else
	{
		/*Begin to read the file to access the range of the data and calculate the value of star*/


		cas_file.open(name.c_str());

		while (cas_file>>t>>pt) //compair the min and max total pressure
		{


			if (pt > maxPT)
				maxPT = pt;
			else if (pt < minPT)
				minPT = pt;



			if(first_row==0)
			{
				cas = A0 * sqrt(5 * (pow(pt / P0 + 1, 2.0 / 7) - 1)); // Cas formula
				cas_first=cas;
				t_first=t;
				first_row=1;
			}

			if(cas_file.peek() == '\n')
			{
				cas = A0 * sqrt(5 * (pow(pt / P0 + 1, 2.0 / 7) - 1)); // Cas formula
				cas_last=cas;
				t_last=t;}
		}

		this->maxCAS = A0 * sqrt(5 * (pow(this->maxPT / P0 + 1, 2.0 / 7) - 1)); // Cas formula

		cas_file.close();
		/*End to read the file to access the range of the data and calculate the value of star*/

		/****************************************************************************************************************/
		/*Begin to calculate the value of cas and output to the console*/
		cas_file.open(name.c_str());

		while (cas_file>>t>>pt) 
		{

			cas = A0 * sqrt(5 * (pow(pt / P0 + 1, 2.0 / 7) - 1)); // Cas formula


			barLength = 69 * cas / this->maxCAS;

			cout << setiosflags(ios::fixed)<< setiosflags(ios::right)<<setprecision(1)
				<<setw(barLength)<<setfill('*') << ' ' <<t<<", "<<cas<<endl;//Format the output


		}



		cas_file.close();
		/*End to  calculate the value of cas and output to the console*/
	}

}
/****************************************************************************************************************/
int CASHistory::Time_calculate()//change the total second into normal time  
{
	hour_1=t_first/3600;
	minute_1=t_first%3600/60;
	second_1=t_first%3600%60;

	hour_2=t_last/3600;
	minute_2=t_last%3600/60;
	second_2=t_last%3600%60;
	cout<<endl<<endl;
	cout<<"Recording start time= "<<hour_1<<" : "<<minute_1<<" : "<<second_1<<endl;
	cout<<"Recording finish time= "<<hour_2<<" : "<<minute_2<<" : "<<second_2<<endl;
	cout<<"Total sample period= "<<t_last-t_first+1<<" second"<<endl;
	return 0;
}
/****************************************************************************************************************/
void CASHistory::welcome()//show the basic information
{
	cout<<setw(80)<<cout.fill('*');
	cout<<"Members 1:"<<endl;
	cout<<"SID: "<<endl;

	cout<<"Members 2: "<<endl;
	cout<<"SID: "<<endl;
}




