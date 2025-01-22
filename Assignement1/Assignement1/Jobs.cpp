#include "Job.h"

int Jobs::Payment() {
	return MPH1;
}
void Jobs::selectJobs() {
	srand(time(0));
	int randomJob1 = rand() % 6;

	switch (randomJob1)
	{
	case 0:
		job1 = "Waiter";
		MPH1 = 22;
		workPlace1 = "Cafe";
		hungerSpeed = 1.5;
		thirstSpeed = 1.5;
		fatigueSpeed = 1.2;
		break;
	case 1:
		job1 = "Secretary";
		MPH1 = 16;
		workPlace1 = "Lawyer's office";
		hungerSpeed = 0.8;
		thirstSpeed = 1;
		fatigueSpeed = 1;
		break;
	case 2:
		job1 = "Police";
		MPH1 = 26;
		workPlace1 = "Police station";
		hungerSpeed = 2;
		thirstSpeed = 2;
		fatigueSpeed = 2.2;
		break;
	case 3:
		job1 = "Teacher";
		MPH1 = 20;
		workPlace1 = "High School";
		hungerSpeed = 1.1;
		thirstSpeed = 1.2;
		fatigueSpeed = 2;
		break;
	case 4:
		job1 = "Groundskeeper";
		MPH1 = 29;
		workPlace1 = "English Mansion";
		hungerSpeed = 2;
		thirstSpeed = 2.5;
		fatigueSpeed = 2.5;
		break;
	case 5:
		job1 = "Butcher";
		MPH1 = 24;
		workPlace1 = "Butcher shop";
		hungerSpeed = 1.8;
		thirstSpeed = 1.3;
		fatigueSpeed = 2.2;
		break;
	default:
		break;
	}

}