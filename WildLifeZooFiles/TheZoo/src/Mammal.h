/*
 * Mammal.h
 *
 *  Created on: Feb 10, 2021
 *      Author: 1717185_snhu
 */

#ifndef MAMMAL_H
#define MAMMAL_H

#include "Animal.h"
using namespace std;

class Mammal : public Animal { // Derived from Animal
	public:
		Mammal();
		Mammal(int t_nurse);
		void setNurse(int t_nurse);
		int  getNurse();
	protected:
		int nurse;
};

#endif
