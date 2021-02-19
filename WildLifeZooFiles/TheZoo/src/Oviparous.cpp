/*
 * Oviparous.cpp
 *
 *  Created on: Feb 10, 2021
 *      Author: 1717185_snhu
 */

#include <iostream>
using namespace std;

#include "Oviparous.h"

// Default constructor, set protected member variable to empty string
Oviparous::Oviparous() {
	this->type = AnimalType::OVIPAROUS;
	this->numberOfEggs = 0;
}

// Constructor with parameters
Oviparous::Oviparous(int t_numberOfEggs) {
	this->numberOfEggs = t_numberOfEggs;
}

void Oviparous::setNumberOfEggs(int t_numberOfEggs) {
	numberOfEggs = t_numberOfEggs;
}

int Oviparous::getNumberOfEggs() {
	return this->numberOfEggs;
}
