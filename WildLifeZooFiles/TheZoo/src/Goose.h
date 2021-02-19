/*
 * Goose.h
 *
 *  Created on: Feb 10, 2021
 *      Author: 1717185_snhu
 */

#ifndef GOOSE_H
#define GOOSE_H

#include "Oviparous.h"
using namespace std;

class Goose : public Oviparous { // Derived from Oviparous
	public:
		Goose(string trackNum, string name);
};

#endif
