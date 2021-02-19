/*
 * AnimalTypeMap.h
 *
 *  Created on: Feb 19, 2021
 *      Author: Clint Monroe
 * Description: Maps enum data members to strings for use in smart assignment
 *              of classes/subclasses when outputting animal object details.
 */

#ifndef ANIMALTYPEMAP_H_
#define ANIMALTYPEMAP_H_

#include <map>
#include "AnimalType.h"

using namespace std;

map<AnimalType, string> mapType {
	{MAMMAL, "Mammal"}, {OVIPAROUS, "Oviparous"}
};

map<AnimalSubType, string> mapSubType {
	{BAT, "Bat"}, {CROCODILE, "Crocodile"},
	{GOOSE, "Goose"}, {PELICAN, "Pelican"},
	{SEALION, "SeaLion"}, {WHALE, "Whale"},
};

#endif
