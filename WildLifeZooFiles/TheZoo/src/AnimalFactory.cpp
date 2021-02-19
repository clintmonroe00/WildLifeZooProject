/*
 * AnimalFactory.cpp
 *
 *  Created on: Feb 18, 2021
 *      Author: Clint Monroe
 * Description: Defines factory method for creation of objects.
 *              Uses a switch case based on animal subtype.
 */

#include <iostream>
using namespace std;

#include "AnimalFactory.h"
#include "Bat.h"
#include "Crocodile.h"
#include "Goose.h"
#include "Pelican.h"
#include "SeaLion.h"
#include "Whale.h"

Animal* AnimalFactory::create(AnimalSubType type, string trackNum, string name) {
	Animal* animal = nullptr;

	switch(type) {
		case AnimalSubType::BAT:
			return new Bat(trackNum, name);
			break;
		case AnimalSubType::CROCODILE:
			return new Crocodile(trackNum, name);
			break;
		case AnimalSubType::GOOSE:
			return new Goose(trackNum, name);
			break;
		case AnimalSubType::PELICAN:
			return new Pelican(trackNum, name);
			break;
		case AnimalSubType::SEALION:
			return new SeaLion(trackNum, name);
			break;
		case AnimalSubType::WHALE:
			return new Whale(trackNum, name);
			break;
		default:
			cout << "Invalid selection, please try again." << endl;
			break;
	}

	return animal;
}
