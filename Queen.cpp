#include "Queen.h"

Queen::Queen() {
	switch(gameTime){
		case 1: {HP = 40; break;}
		case 2: {HP = 45; break;}
		case 3: {HP = 50; break;}
		}

	heal[0] = -1;
}

int Queen::GetHP(){return HP;}

void Queen::SetHP(int _HP){HP = _HP;};


Queen::~Queen() {
	// TODO Auto-generated destructor stub
}

