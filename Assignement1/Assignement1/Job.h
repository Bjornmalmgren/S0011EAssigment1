#pragma once
#include <string>
#include <cstdlib> 
#include <ctime>   
enum JOB
{
	Waiter = 14,
	Secretary = 18,
	Police = 22,
	Teacher = 16
};

class Jobs
{
public:
	void selectJobs();
	int Payment(int work);
	std::string job1;
	int MPH1;
	std::string workPlace1;

	std::string job2;
	int MPH2;
	std::string workPlace2;
private:

};

int Jobs::Payment(int work) {
	if (work == 0) {
		return MPH1;
	}
	else
	{
		return MPH2;
	}
}
void Jobs::selectJobs() {
	srand(time(0));
	int randomJob1 = rand() % 6;
	int randomJob2 = rand() % 6;
	while (randomJob1 == randomJob2) {
		srand(time(0));
		randomJob2 = rand() % 6;
	}
	switch (randomJob1)
	{
	case 0:
		job1 = "Waiter";
		MPH1 = 14;
		workPlace1 = "Café";
		break;
	case 1:
		job1 = "Secretary";
		MPH1 = 18;
		workPlace1 = "Lawyer's office";
		break;
	case 2:
		job1 = "Police";
		MPH1 = 22;
		workPlace1 = "Police station";
		break;
	case 3:
		job1 = "Teacher";
		MPH1 = 16;
		workPlace1 = "High School";
		break;
	case 4:
		job1 = "Groundskeeper";
		MPH1 = 25;
		workPlace1 = "English Mansion";
		break;
	case 5:
		job1 = "Butcher";
		MPH1 = 20;
		workPlace1 = "Butcher shop";
		break;
	default:
		break;
	}
	switch (randomJob2)
	{
	case 0:
		job2 = "Waiter";
		MPH2 = 14;
		workPlace2 = "Café";
		break;
	case 1:
		job2 = "Secretary";
		MPH2 = 18;
		workPlace2 = "Lawyer's office";
		break;
	case 2:
		job2 = "Police";
		MPH2 = 22;
		workPlace2 = "Police station";
		break;
	case 3:
		job2 = "Teacher";
		MPH2 = 16;
		workPlace2 = "High School";
		break;
	case 4:
		job2 = "Groundskeeper";
		MPH2 = 25;
		workPlace2 = "English Mansion";
		break;
	case 5:
		job2 = "Butcher";
		MPH2 = 20;
		workPlace2 = "Butcher shop";
		break;
	default:
		break;
	}
}



