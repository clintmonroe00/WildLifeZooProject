/*
 * SeaLion.h
 *
 *  Created on: Feb 10, 2021
 *      Author: 1717185_snhu
 */

#ifndef SEALION_H
#define SEALION_H

#include "Mammal.h"
using namespace std;

class SeaLion : public Mammal { // Derived from Mammal
	public:
		SeaLion(string trackNum, string name);
};

#endif
