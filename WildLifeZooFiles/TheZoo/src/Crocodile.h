/*
 * Crocodile.h
 *
 *  Created on: Feb 10, 2021
 *      Author: 1717185_snhu
 */

#ifndef CROCODILE_H
#define CROCODILE_H

#include "Oviparous.h"
using namespace std;

class Crocodile : public Oviparous { // Derived from Oviparous
	public:
		Crocodile(string trackNum, string name);
};

#endif
