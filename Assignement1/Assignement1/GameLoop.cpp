#include "GameLoop.h"


int main() {
	
	long long tick = 0.0;
	int TPS = 500;
	const long long TPSDuration = 1000000000.0/TPS;
	Person Per = Person(0, "Per");
	bool isTrue = true;
	int amountOfTicks = 0;
	auto time = std::chrono::system_clock::now();
	auto startTime = std::chrono::system_clock::now();
	auto lastTime = std::chrono::system_clock::now();
	auto currentTime = lastTime;
	
	double deltaTime = 0.0;
	while (isTrue)
	{
		currentTime = std::chrono::system_clock::now();
		tick += std::chrono::duration_cast<std::chrono::nanoseconds>(currentTime - lastTime).count();
		lastTime = currentTime;
		if (tick >= TPSDuration)
		{
			amountOfTicks++;
			deltaTime = tick / 1000000000.0;
			tick -= TPSDuration;
			//std::cout <<"Delta time: " << deltaTime << std::endl;
			time = std::chrono::system_clock::now();
			auto t = std::chrono::duration_cast<std::chrono::minutes>(time - startTime).count();
			/*if (t < 10) {
				std::cout << "[00:0" << t << "] ";
			}
			else if(t < 60)
			{
				std::cout << "[00:" << t << "] ";
			}*/
			std::cout << "[ " << amountOfTicks << " ]";
			if (Per.dead == true) {
				
				std::cout << "Hunger: " << Per.checkHunger();
				std::cout << " Thirst: " << Per.checkThirst();
				std::cout << " Fatigue: " << Per.checkfatigue();
			}
			else
			{
				std::cout << "Hunger: " << Per.checkHunger();
				std::cout << " Thirst: " << Per.checkThirst();
				std::cout << " Fatigue: " << Per.checkfatigue();

				std::cout << " Fatigue: " << Per.checkMoney();
				Per.Update();
				
			}
			
		}
		
	}
	return 0;
}

