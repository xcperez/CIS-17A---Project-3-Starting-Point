#pragma once
#include <string>
class Adventurer
{
private:
	std::string _name;
	

public:

	Adventurer(std::string name);
	Adventurer();
	~Adventurer();

	std::string GetName() const { return _name; }
	std::string virtual Attack() { return _name + " punches the enemies!"; }
};

