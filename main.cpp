
/****************************************************************************************************************/
#include <fstream>
#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include  <stdlib.h> 

#include"CASHistory.h"


using namespace std;
/****************************************************************************************************************/
void main()
{
	char flat=' ';//Initialization of char variable
	CASHistory Cas_history;//Declare the Class variable
	Cas_history.welcome();
	while(1)
	{
		Cas_history.Read_data();
		Cas_history.Time_calculate();
		/*re-run function*/
		cout<<"If you want to Re-run,please press 'y', or press any other key to exit."<<endl; 
		cin>>flat;
		if(flat!='y')
		{

			break;
		}
		system("cls");//clean the screen

		Cas_history.welcome();
	}
	system("pause");
}

