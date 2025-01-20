#include <iostream>
#include <chrono>
#include <ctime>

int main() {
	
	long long tick = 0.0;
	int TPS = 60;
	const long long TPSDuration = 1000000000.0/TPS;

	bool isTrue = true;


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
			
			deltaTime = tick / 1000000000.0;
			tick -= TPSDuration;
			std::cout <<"Delta time: " << deltaTime << std::endl;

			//update
		}
		
	}
}

