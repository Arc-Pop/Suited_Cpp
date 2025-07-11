
#include "../lib/kingCard.h"


KingCard::KingCard() {

	switch(gameTime){
		case 1: {HP = 45; break;}
		case 2: {HP = 50; break;}
		case 3: {HP = 55; break;}
		}

	dualWield[0] = -1;
	dualWield[1] = -1;

}

int KingCard::GetHP(){return HP;}

void KingCard::SetHP(int _HP){HP = _HP;};

KingCard::~KingCard() {
	// TODO Auto-generated destructor stub
}

