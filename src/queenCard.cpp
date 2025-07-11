#include "../lib/queenCard.h"

QueenCard::QueenCard() {
	switch(gameTime){
		case 1: {HP = 40; break;}
		case 2: {HP = 45; break;}
		case 3: {HP = 50; break;}
		}

	heal[0] = -1;
}

QueenCard::~QueenCard() {
	// TODO Auto-generated destructor stub
}

int QueenCard::GetHP(){return HP;}

void QueenCard::SetHP(int _HP){HP = _HP;};



