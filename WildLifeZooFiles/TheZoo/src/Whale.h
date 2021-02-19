/*
 * Whale.h
 *
 *  Created on: Feb 10, 2021
 *      Author: 1717185_snhu
 */

#ifndef WHALE_H
#define WHALE_H

#include "Mammal.h"
using namespace std;

class Whale : public Mammal { // Derived from Mammal
	public:
		Whale(string trackNum, string name);
};

#endif
