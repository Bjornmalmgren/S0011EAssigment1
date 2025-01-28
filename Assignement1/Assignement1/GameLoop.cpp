#include "GameLoop.h"


int main() {
	std::list<Person> people;
	long long tick = 0.0;
	int TPS = 1;
	const long long TPSDuration = 1000000000.0/TPS;
	


	bool isTrue = true;
	int amountOfTicks = 0;
	auto time = std::chrono::system_clock::now();
	auto startTime = std::chrono::system_clock::now();
	auto lastTime = std::chrono::system_clock::now();
	auto currentTime = lastTime;
	Person Per = Person(0, "Per", 2);
	people.push_back(Per);
	EntityMgr->registerEntity(&Per);

	Person Erika = Person(1, "Erika", 19);
	people.push_back(Erika);
	EntityMgr->registerEntity(&Erika);

	Person Lena = Person(2, "Lena", 7);
	people.push_back(Lena);
	EntityMgr->registerEntity(&Lena);

	Person Bob = Person(3, "Bob", 9);
	people.push_back(Bob);
	EntityMgr->registerEntity(&Bob);
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
			for (Person p : people)
			{
				Person* P = (Person*)EntityMgr->GetEntityFromId(p.getID());
				if (P != nullptr) {
					if (P->dead == true) {


					}
					else
					{

						P->Update();
						if (P->dead == true) {
							std::cout << P->name << " is dead";
							std::cout << " H: " << P->checkHunger();
							std::cout << " T: " << P->checkThirst();
							std::cout << " F: " << P->checkfatigue();
							std::cout << " S: " << P->checkSocial();
							std::cout << " M: " << P->checkMoney();
							int tID = P->ID;
							EntityMgr->removeeEntity(&p);
							

						}
						std::cout << "  |";
					}
				}
				
			}
			
			std::cout << endl;
		}
		
	}
	return 0;
}

