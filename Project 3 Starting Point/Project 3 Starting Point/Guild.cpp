#include <iostream>
#include <string>
#include <iterator>
#include "Guild.h"

Guild::Guild(std::string name) : _name(name)
{
}

Guild::~Guild()
{
}

void Guild::addAdventurer(std::shared_ptr<Adventurer> _adventurer)
{

	_adventurers.push_back(_adventurer);

}

std::string Guild::GetInfo()
{
	std::string output = "Your guild has: \n";

	for (std::vector<std::shared_ptr<Adventurer>>::iterator adv = _adventurers.begin(); adv != _adventurers.begin(); adv++)
	{

		if (std::dynamic_pointer_cast<Mage>(*adv) != nullptr) {

			mages++;

		}
		else if (std::dynamic_pointer_cast<Paladin>(*adv) != nullptr) {

			paladins++;

		}
		else if (std::dynamic_pointer_cast<Warrior>(*adv) != nullptr) {

			warriors++;

		}
		else if (std::dynamic_pointer_cast<Ranger>(*adv) != nullptr) {

			rangers++;

		}
	}
	output += mages > 0 ? std::to_string(mages) + " mages\n" : "No mages!\n";
	output += rangers > 0 ? std::to_string(rangers) + " rangers\n" : "No rangers!\n";
	output += warriors	> 0 ? std::to_string(warriors) + " warriors\n" : "No warriors!\n";
	output += paladins	> 0 ? std::to_string(paladins) + " paladins\n" : "No paladins!\n";
	return output;
}

std::string Guild::AttackWithMages()
{
	std::string output = "You command your mages to attack! \n";

	for (std::vector<std::shared_ptr<Adventurer>>::iterator mage = _adventurers.begin(); mage != _adventurers.end(); mage++)
	{

		if (std::dynamic_pointer_cast<Mage>(*mage)) {

			output += (*mage)->Attack();

		}
	}
	return output;
}

std::string Guild::AttackWithPaladins()
{
	std::string output = "You command your paladins to attack! \n";
	for (std::vector<std::shared_ptr<Adventurer>>::iterator paladin = _adventurers.begin(); paladin != _adventurers.end(); paladin++)
	{

		if (std::dynamic_pointer_cast<Paladin>(*paladin)) {

			output += (*paladin)->Attack();

		}
	}
	return output;
}

std::string Guild::AttackWithRangers()
{
	std::string output = "You command your rangers to attack! \n";
	for (std::vector<std::shared_ptr<Adventurer>>::iterator ranger = _adventurers.begin(); ranger != _adventurers.end(); ranger++)
	{

		if (std::dynamic_pointer_cast<Ranger>(*ranger)) {

			output += (*ranger)->Attack();

		}
	}
	return output;
}

std::string Guild::AttackWithWarriors()
{
	std::string output = "You command your warriors to attack! \n";
	for (std::vector<std::shared_ptr<Adventurer>>::iterator warrior = _adventurers.begin(); warrior != _adventurers.end(); warrior++)
	{

		if (std::dynamic_pointer_cast<Warrior>(*warrior)) {

			output += (*warrior)->Attack();

		}
	}
	return output;
}

std::string Guild::AttackWithAllAdventurers()
{
	std::string output = "";
	output += AttackWithMages();
	output += AttackWithPaladins();
	output += AttackWithRangers();
	output += AttackWithWarriors();
	return output;
}