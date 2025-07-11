#ifndef JACKCARD_H_
#define JACKCARD_H_
#include "card.h"

class JackCard : public Card {
public:
	JackCard();
	virtual ~JackCard();
	int GetHP();
	void SetHP(int _HP);
	void SetCounter(int _counterAttack);
	int GetCounter();
	int counterAttack[2];

};

#endif
