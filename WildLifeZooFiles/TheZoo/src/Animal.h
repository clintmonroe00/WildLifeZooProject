/*
 * Animal.h
 *
 *  Created on: Feb 10, 2021
 *      Author: Clint Monroe
 */

#ifndef ANIMAL_H
#define ANIMAL_H

#include "AnimalType.h"

using namespace std;

class Animal {
	public:
		Animal();
		Animal(int t_trackNum, string t_name);
		void          setTrackNum(string t_trackNum);
		void          setName(string t_name);
		string        getTrackNum();
		string        getName();
		AnimalType    getAnimalType();
		AnimalSubType getAnimalSubType();
	protected:
		string        trackNum;
		string        name;
		AnimalType    type;
		AnimalSubType subType;
};

#endif
