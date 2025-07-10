
#include "King.h"


King::King() {

	switch(gameTime){
		case 1: {HP = 45; break;}
		case 2: {HP = 50; break;}
		case 3: {HP = 55; break;}
		}

	dualWield[0] = -1;
	dualWield[1] = -1;

}

int King::GetHP(){return HP;}

void King::SetHP(int _HP){HP = _HP;};

King::~King() {
	// TODO Auto-generated destructor stub
}

