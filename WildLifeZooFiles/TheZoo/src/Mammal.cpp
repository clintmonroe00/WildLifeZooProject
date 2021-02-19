/*
 * Mammal.cpp
 *
 *  Created on: Feb 10, 2021
 *      Author: 1717185_snhu
 */

#include <iostream>
using namespace std;

#include "Mammal.h"
#include "AnimalType.h"

// Default constructor, set protected member variable to 0
Mammal::Mammal() {
	this->type = AnimalType::MAMMAL;
	this->nurse = 0;
}

// Constructor with parameters
Mammal::Mammal(int t_nurse) {
	this->nurse = t_nurse;
}

void Mammal::setNurse(int t_nurse) {
	nurse = t_nurse;
}

int Mammal::getNurse() {
	return this->nurse;
}
