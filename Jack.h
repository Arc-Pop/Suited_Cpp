#ifndef JACK_H_
#define JACK_H_
#include "Card.h"

class Jack : public Card {
public:
	Jack();
	virtual ~Jack();
	int GetHP();
	void SetHP(int _HP);
	void SetCounter(int _counterAttack);
	int GetCounter();
	int counterAttack[2];

};

#endif
