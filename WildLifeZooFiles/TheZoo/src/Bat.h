/*
 * Bat.h
 *
 *  Created on: Feb 10, 2021
 *      Author: 1717185_snhu
 */

#ifndef BAT_H
#define BAT_H

#include "Mammal.h"
using namespace std;

class Bat : public Mammal { // Derived from Mammal
	public:
		Bat(string trackNum, string name);
};

#endif
