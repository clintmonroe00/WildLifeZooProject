/*
 * AnimalFactory.h
 *
 *  Created on: Feb 18, 2021
 *      Author: Clint Monroe
 * Description: Declares factory method for creation of objects.
 */

#ifndef ANIMALFACTORY_H
#define ANIMALFACTORY_H

#include "AnimalType.h"
#include "Animal.h"

using namespace std;

class AnimalFactory {
	public:
		static Animal* create(AnimalSubType type, string trackNum, string name);
};

#endif
