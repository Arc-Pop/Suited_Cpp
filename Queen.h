#ifndef QUEEN_H_
#define QUEEN_H_
#include "Card.h"

class Queen  : public Card{
public:
	Queen();
	virtual ~Queen();
	int heal[2];

	int GetHP();
	void SetHP(int _HP);

};

#endif
