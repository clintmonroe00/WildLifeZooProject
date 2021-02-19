/*
 * Crocodile.cpp
 *
 *  Created on: Feb 10, 2021
 *      Author: 1717185_snhu
 */

#include <iostream>
using namespace std;

#include "Crocodile.h"

// Constructor
Crocodile::Crocodile(string trackNum, string name) {
	this->trackNum = trackNum;
	this->name     = name;
	this->subType  = AnimalSubType::CROCODILE;
}
