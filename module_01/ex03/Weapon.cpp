#include "Weapon.hpp"

Weapon::Weapon(std::string type) {
	if (type.empty())
		_type = "fists";
	else
		_type = type;
}

void Weapon::setType(std::string type)
{
	if (!type.empty())
		_type = type;
}

const std::string Weapon::getType()
{
	const std::string &typeRef = _type;

	return typeRef;
}