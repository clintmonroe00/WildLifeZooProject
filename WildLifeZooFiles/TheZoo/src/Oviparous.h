/*
 * Oviparous.h
 *
 *  Created on: Feb 10, 2021
 *      Author: 1717185_snhu
 */

#ifndef OVIPAROUS_H
#define OVIPAROUS_H

#include "Animal.h"
using namespace std;

class Oviparous : public Animal { // Derived from Animal
	public:
		Oviparous();
		Oviparous(int t_numberOfEggs);
		void setNumberOfEggs(int t_numberOfEggs);
		int  getNumberOfEggs();
	protected:
		int numberOfEggs;
};

#endif
