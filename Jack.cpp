/*
 * Jack.cpp
 *
 *  Created on: Nov 7, 2022
 *      Author: jon
 */

#include "Jack.h"

Jack::Jack() {

	switch(gameTime){
		case 1: {HP = 35; break;}
		case 2: {HP = 40; break;}
		case 3: {HP = 45; break;}
		}

	counterAttack[0] = -1;
	counterAttack[1] = -1;

}

int Jack::GetHP(){return HP;}

void Jack::SetHP(int _HP){HP = _HP;};

void Jack::SetCounter(int _counterAttack){counterAttack[1]=_counterAttack; counterAttack[0]=0;}

int Jack::GetCounter(){return counterAttack[0];}

Jack::~Jack() {
	// TODO Auto-generated destructor stub
}

