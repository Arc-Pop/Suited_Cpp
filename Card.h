#ifndef CARD_H_
#define CARD_H_

#include <string>
using namespace std;

class Card{
	protected:
    string suit;
	string heart = "\u2665";
	string diamond = "\u2666";
	string club = "\u2667";
	string spade = "\u2664";
	string cardName = "Just A. Number";
	string suitCode;

	int HP=0;
	int difficulty = 2;
	int suitNum=4;



	public:

	string title;

    int numberCards[10];

    int tempCards[10];

	bool canMove=1;

    int emptyCards[10];

	Card();
    Card(int p1S);
    string GetSuit();
    void SetSuit(int p1S);

    void Print();
    void PrintParty(string suitName);
    string center(const std::string& s, unsigned width);
	int GetSuitNum();
	string GetSuitCode();

	void CardSwap(int cardSet1[] , int cardSet2[]);

	void SetSuitNum(int _suitNum);
	int SuitSelection(int takenSuit);

	int gameTime = 2;

    int AttackWho(int partyNum);



    private:

};
#endif /* CARD_H_ */
