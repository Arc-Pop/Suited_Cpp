#ifndef PLAYER_H_
#define PLAYER_H_

#include "card.h"
#include "kingCard.h"
#include "queenCard.h"
#include "jackCard.h"
#include "numberCards.h"

#include <string>

class Player{
public:
	Player();

	Player(string _firstName , string _lastName, int _suit);

	void MakePlayer();

	virtual ~Player();

	string GetFirstName();

	string GetLastName();

	struct PlayerCards{
		KingCard King;
		QueenCard Queen;
		JackCard Jack;
		NumberCards Number;
	};

	PlayerCards Cards;

	int turnTotal;
	
	int cardSet;

protected:

private:
	string firstName;	
	string lastName;
};

#endif /* PLAYER_H_ */
