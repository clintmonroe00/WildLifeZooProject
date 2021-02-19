/*
 * AnimalType.h
 *
 *  Created on: Feb 18, 2021
 *      Author: Clint Monroe
 * Description: Declares enum data members for assignment of type and subtype.
 *
 */

#ifndef ANIMALTYPE_H
#define ANIMALTYPE_H

#include <map>

using namespace std;

enum AnimalType {
	MAMMAL = 1,
	OVIPAROUS = 2,
};

enum AnimalSubType {
	BAT = 1,
	CROCODILE = 2,
	GOOSE = 3,
	PELICAN = 4,
	SEALION = 5,
	WHALE = 6,
};

#endif
