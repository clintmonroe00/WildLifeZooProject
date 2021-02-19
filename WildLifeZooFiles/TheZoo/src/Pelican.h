/*
 * Pelican.h
 *
 *  Created on: Feb 10, 2021
 *      Author: 1717185_snhu
 */

#ifndef PELICAN_H
#define PELICAN_H

#include "Oviparous.h"
using namespace std;

class Pelican : public Oviparous { // Derived from Oviparous
	public:
		Pelican(string trackNum, string name);
};

#endif
