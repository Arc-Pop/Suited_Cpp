#ifndef PLAYER_H_
#define PLAYER_H_

#include "Card.h"
#include "King.h"
#include "Queen.h"
#include "Jack.h"

#include <string>

using namespace std;

class Player : public Card{
public:
	Player();

	Player(string _firstName , string _lastName, int _highScore);

	int cardSet=0;

	int level=1;

	void SetFirstName(string _firstName);

	string GetFirstName();

	void SetLastName(string _lastName);

	string GetLastName();

	void SetHighScore(int score);

	int GetHighScore();

	void SetLevel(int lev);

	void SetTitle();

	int GetLevel();

	bool human=0;//USE TO INDICATE IF PLAYER IS A COMPUTER AND AS A RETURN OR EXIT CONTROL     0 MEANS COMPUTER    1 MEANS HUMAN

	bool IsHuman();

	void SetHuman(bool _human);

	int KingHealth();

	bool DuelWield(int left , int right);

	bool Heal(int _heal);

	bool Counter();

	int QueenHealth();

	void EmptyHand();//CHANGES VALUES IN EMPTYCARDS ARRAY TO REMOVE CARDS FLIPPED OVER AFTER THEY HAVE BEEN PLAYED

	int JackHealth();

    bool TellStory();

	int RandomChoice(int numberOfChoices);

	void ClearScreen();

	int ChoiceCheck(int numChoices);

	//FOUND ON: https://stackoverflow.com/questions/15580179/how-do-i-find-the-name-of-an-operating-system
	string getOsName();

	virtual ~Player();

	King pKing;

	Queen pQueen;

	Jack pJack;

	string firstName;
	string lastName;

	int turnTotal=0;
	bool turn=0;

protected:

	int highScore;


private:

};

#endif /* PLAYER_H_ */
