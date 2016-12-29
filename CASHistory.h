
#ifndef CASHistory_H
#define CASHistory_H

const double P0=1013.25;//Set constant
const double A0=661.48;

class CASHistory
{
public:
	void welcome();// Declare the welcome function
	void Read_data();// Declare the Read_data function

	int Time_calculate();// Declare the Time_calculate
	void rerun();
	CASHistory::CASHistory();//initialization of variables

private:
	//Declare variables
	long t;
	long t_first;
	long t_last;

	double cas;
	double cas_first;//Cas of first row 
	double cas_last;//Cas of last row 
	double star;//rate between barlength and cas value

	double pt;//Total pressure
	bool first_row;//Flag of first rom
	

	int hour_1;//Start time
	int minute_1;
	int second_1;
	
	int hour_2;//Finish time
	int minute_2;
	int second_2;

	int barLength;// barlength

	long Tsample_time;//total time

	double maxPT;//maximum value of total pressure 
	double minPT;//minimum value of total pressure 

	double maxCAS;//maximum value of cas
	double minCAS;//minimum value of cas

};
#endif
