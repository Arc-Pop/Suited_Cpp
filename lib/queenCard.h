#ifndef QUEENCARD_H_
#define QUEENCARD_H_
#include "card.h"

class QueenCard  : public Card{
public:
	QueenCard();
	virtual ~QueenCard();
	int heal[2];

	int GetHP();
	void SetHP(int _HP);

};

#endif
