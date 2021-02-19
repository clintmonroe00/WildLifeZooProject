/*
 * Animal.cpp
 *
 *  Created on: Feb 10, 2021
 *      Author: Clint Monroe
 */

#include <iostream>
using namespace std;

#include "Animal.h"

// Default constructor, set protected member variable to empty string
Animal::Animal() {
	this->trackNum = "";
	this->name     = "";
}

// Constructor with parameters
Animal::Animal(int t_trackNum, string t_name) {
	this->trackNum = t_trackNum;
	this->name     = t_name;
}

void Animal::setTrackNum(string t_trackNum) {
	trackNum = t_trackNum;
}

void Animal::setName(string t_name) {
	name = t_name;
}

// Grab track number
string Animal::getTrackNum() {
	return this->trackNum;
}

// Grab name
string Animal::getName() {
	return this->name;
}

// Grab type
AnimalType Animal::getAnimalType() {
	return this->type;
}

// Grab subtype
AnimalSubType Animal::getAnimalSubType() {
	return this->subType;
}
