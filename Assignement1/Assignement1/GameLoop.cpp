#include "GameLoop.h"


int main() {
	std::vector<int> people;
	long long tick = 0.0;
	int TPS = 500;
	const long long TPSDuration = 1000000000.0/TPS;
	


	bool isTrue = true;
	int amountOfTicks = 0;
	auto time = std::chrono::system_clock::now();
	auto startTime = std::chrono::system_clock::now();
	auto lastTime = std::chrono::system_clock::now();
	auto currentTime = lastTime;
	Person Per = Person(0, "Per", 2);
	people.push_back(Per.ID);
	EntityMgr->registerEntity(&Per);
	

	Person Erika = Person(1, "Erika", 19);
	people.push_back(Erika.ID);
	EntityMgr->registerEntity(&Erika);

	Person Lena = Person(2, "Lena", 7);
	people.push_back(Lena.ID);
	EntityMgr->registerEntity(&Lena);

	Person Bob = Person(3, "Bob", 9);
	people.push_back(Bob.ID);
	EntityMgr->registerEntity(&Bob);
	double deltaTime = 0.0;

	for (int i = 0; i < people.size(); i++)
	{
		Person* b = (Person*)EntityMgr->GetEntityFromId(people[i]);
		
		b->people.reserve(people.size());
		b->people = people;
	}
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
			for (int i = 0; i< EntityMgr->mapsSize();i++)
			{
				int p = people[i];
				Person* P = (Person*)EntityMgr->GetEntityFromId(p);
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
						EntityMgr->removeeEntity(EntityMgr->GetEntityFromId(P->ID));
						people.erase(people.begin() + i);
						for (int i = 0; i < people.size(); i++)
						{
							Person* b = (Person*)EntityMgr->GetEntityFromId(people[i]);
							b->people.reserve(people.size());
							b->people = people;
						}
						

					}
					std::cout << "  |";
				}
				
				
			}
			if (people.size() == 0) {
				isTrue = false;
			}
			
			std::cout << endl;
		}
		
	}
	return 0;
}

