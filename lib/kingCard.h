#ifndef KINGCARD_H_
#define KINGCARD_H_
#include "card.h"

class KingCard : public Card{
public:
	KingCard();
	virtual ~KingCard();

	int Attack();

	int GetHP();

	int dualWield[4];



	void SetHP(int _HP);



private:

protected:

};

#endif
