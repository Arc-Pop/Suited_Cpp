#ifndef KING_H_
#define KING_H_
#include "Card.h"

class King : public Card{
public:
	King();
	virtual ~King();

	int Attack();

	int GetHP();

	int dualWield[4];



	void SetHP(int _HP);



private:

protected:

};

#endif
