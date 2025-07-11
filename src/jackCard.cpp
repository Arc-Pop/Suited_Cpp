/*
 * Jack.cpp
 *
 *  Created on: Nov 7, 2022
 *      Author: jon
 */

#include "../lib/jackCard.h"

JackCard::JackCard() {

	switch(gameTime){
		case 1: {HP = 35; break;}
		case 2: {HP = 40; break;}
		case 3: {HP = 45; break;}
		}

	counterAttack[0] = -1;
	counterAttack[1] = -1;

}

JackCard::~JackCard() {
	// TODO Auto-generated destructor stub
}

int JackCard::GetHP(){return HP;}

void JackCard::SetHP(int _HP){HP = _HP;};

void JackCard::SetCounter(int _counterAttack){counterAttack[1]=_counterAttack; counterAttack[0]=0;}

int JackCard::GetCounter(){return counterAttack[0];}

