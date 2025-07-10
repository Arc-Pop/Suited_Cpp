#include "Player.h"
#include <iostream>
#include <string>
#include <fstream>
#include <cassert>
#include <vector>
#include <chrono>
#include <thread>

using namespace std;
using namespace std::this_thread; // sleep_for, sleep_until
using namespace std::chrono; // nanoseconds, system_clock, seconds


Player::Player() {
	firstName = "King's";
	lastName = "Advisor";
	highScore = 0;

	pKing.dualWield[0]=-1;
	pKing.dualWield[1]=-1;

}

Player::Player(string _firstName , string _lastName , int _highScore){
	firstName = _firstName;
	lastName = _lastName;
	highScore = _highScore;
	human = 1;
}

void Player::ClearScreen(){for(unsigned int i = 0 ; i<40 ; i++){cout << endl;} cout << "\r";}//FUNCTION      CLEAR SCREEN LOOP



string Player::GetFirstName(){return firstName;}

void Player::SetFirstName(string _firstName){firstName = _firstName;}

string Player::GetLastName(){return lastName;}

void Player::SetLastName(string _lastName){lastName = _lastName;}

void Player::SetHighScore(int score){highScore = score;}

int Player::GetHighScore(){return highScore;}

int Player::KingHealth(){return pKing.GetHP();}

int Player::QueenHealth(){return pQueen.GetHP();}

int Player::JackHealth(){return pJack.GetHP();}

bool Player::IsHuman(){return human;}

void Player::SetTitle(){
	switch(GetSuitNum()){
		case 1:{ pJack.title = "County Jack"; pQueen.title = "Countess" ; pKing.title = "Count" ; break;}
		case 2:{ pJack.title = "Duchy Jack"; pQueen.title = "Duchess" ; pKing.title = "Duke" ; break;}
		case 3:{ pJack.title = "March Jack"; pQueen.title = "Marchioness" ; pKing.title = "Marquess" ; break;}
		case 4:{ pJack.title = "Sultany Jack"; pQueen.title = "Countess" ; pKing.title = "Count" ; break;}
		}}

int Player::RandomChoice(int numberOfChoices){
	int curTime = time(NULL);
	srand(curTime);
	int choice = (rand() + (firstName.size() + lastName.size()))%(numberOfChoices+1);
	return choice;
}

int Player::ChoiceCheck(int numChoices){//BEGIN   FUNCTION FOR TAKING AND CHECKING USER INPUT TO CHECK IF IT IS A NUMBER IN THE RANGE OF CHOICES

	string usrChoice;
	int usrChoiceNumber=-1;
	int numberCheck=-1;

	while(numberCheck==-1){

	cout << "Enter a number choice between 0 and " << numChoices << ": ";
	cin >> usrChoice;


	for(unsigned int i=0 ; i<usrChoice.size() ; i++){if(!isdigit(usrChoice.at(i))){numberCheck++;}}
	if(numberCheck==-1){usrChoiceNumber = stoi(usrChoice);}

	if(usrChoiceNumber > -1 && usrChoiceNumber < (numChoices+1)){return usrChoiceNumber;}

	cout << "Invalid input. Please try again." << endl;
	numberCheck=-1;
	}return 0;}//END   FUNCTION FOR TAKING AND CHECKING USER INPUT TO CHECK IF IT IS A NUMBER IN THE RANGE OF CHOICES




bool Player::DuelWield(int left , int right){

	int cardCheck = 0;//BEGIN    CHECK THAT PLAYER HAS 2 CARDS THEY CAN PLAY
	int cardPass = 1;//BEGIN   CHECK THAT ALL INPUT VALIDITY TESTS HAVE PASSED.


	for(int i=0 ; i<10 ; i++){
	if(numberCards[i] > 0 && numberCards[i]<11){cardCheck++;}}//END    CHECK THAT PLAYER HAS 2 CARDS THEY CAN PLAY

	if(cardCheck>1){//BEGIN    IF PLAYER HAS AT LEAST 2 CARDS
	while(cardPass>0){//CONTINUE RUNNING CHECKS UNTIL EVERYTHING PASSES
		cardPass = 0;

	if(isdigit(left) || left<1 || left>10){cout << "Invalid entry for left hand attack.\n Enter the number of a card in your hand or 0 to return to move menu." << endl; cin >> left; cardPass++;}

	if(isdigit(right) || right<1 || right>10){cout << "Invalid entry for left hand attack.\n Enter the number of a card in your hand or 0 to return to move menu." << endl; cin >> right; cardPass++;}

	if(left==right){cout << "Enter two different numbers or 0 to return to move menu" << endl; cin >> left; if(left==0){return 0;} cin>>right;cardPass++;}

	if(numberCards[left-1]==-1){cout << "You do not have a " << left << "\n" << "Enter another number for left hand attack or 0 to return to move menu." << endl; cin >> left;cardPass++;}

	if(numberCards[right-1]==-1){cout << "You do not have a " << right << "\n" << "Enter another number for right hand attack or 0 to return to move menu." << endl; cin >> right;cardPass++;}

	if(left==0 || right==0){return 0;}
	}//END CHECKS FOR VALID INPUT

	pKing.dualWield[2] = left;

	pKing.dualWield[3] = right;

	pKing.dualWield[0] = 0;

	pKing.dualWield[1] = 0;

	numberCards[left-1] = -2;

	numberCards[right-1] = -2;

	return 1;

	}//END    IF PLAYER HAS AT LEAST 2 CARDS

	else{
		cout << "You do not have two cards to dual wield with." << endl;
				return 0;
	}
}//END   DUAL WIELD



bool Player::Heal(int _heal)
{while(isdigit(_heal)||_heal<1||_heal>10){ cout << "Enter a card number in your hand to heal by or enter 0 to return to previous menu.";
	cin >> _heal;
	if(_heal==0){return 0;}} pQueen.heal[0]=_heal; return 1;}


bool Player::Counter(){
	int cAttack=0;
	{while(isdigit(cAttack)||cAttack<1||cAttack>10){ cout << firstName << " " << lastName << ", Enter a card number in your hand to ready counter attack, or enter 0 to return to previous menu: ";
		cin >> cAttack;
		if(cAttack==0){return 0;}
		else if(isdigit(cAttack)||cAttack<1||cAttack>10){ cout << "Not a valid input. Please try again." << endl;}
		else if(isdigit(cAttack) && cAttack>1 && cAttack<10){ int haveCard=0; for(int i=0 ; i<10 ; i++){ if(cAttack==numberCards[i]){ haveCard++;}}if(haveCard==0){ cout << "You don't have that card." << endl ; cAttack=0;}}
	}

	pJack.counterAttack[1]=cAttack-1;
	pJack.counterAttack[0]=0;
	numberCards[cAttack-1] = -1;

	return 1;}

}


void Player::SetLevel(int lev){level = lev;}

int Player::GetLevel(){return level;}

void Player::SetHuman(bool _human){human = _human;}

void Player::EmptyHand(){//BEGIN   EMPTYHAND() FUNCTION: REMOVES CARDS FROM HAND WHEN THEY ARE SHOW REVERSED

	unsigned int noCard=0; //COUNT THE NUMBER OF CARDS THAT HAVE BEEN PLAYED
	for(unsigned int i=0 ; i<10 ; i++){ if(numberCards[i] == -1){noCard++;}}

	if(noCard==1){ emptyCards[0]=-1;}

	else if(noCard>1 && noCard%2==1){ for(unsigned int i=0 ; i<(noCard/2) ; i++){ emptyCards[i]=-1 ; emptyCards[9-i]=-1;}emptyCards[(noCard/2)]=-1;}

	else if(noCard>1 && noCard%2==0){ for(unsigned int i=0 ; i<(noCard/2) ; i++){ emptyCards[i]=-1 ; emptyCards[9-i]=-1;}}

}//END   EMPTYHAND() FUNCTION

bool Player::TellStory(){

	switch(this->suitNum){//BEGIN  SUIT
		case 1:{//BEGIN   CLUBS
				switch(this->level){
					case 1:{//BEGIN   CLUBS LEVEL 1

						cout << "You awake at sunset in an unfamiliar wood to the sound of a scream. What do you do?" << endl;
						sleep_until(system_clock::now() +5s);
						cout << " 0: Go back to sleep." << endl;
						cout << " 1: Try to Help." << endl;
						cout << " 2: Run away." << endl << endl;

						int cChoice1 = ChoiceCheck(2);

						switch(cChoice1){//BEGIN    CLUB FIRST CHOICE SWITCH
						case 0:{return 0;}//EXIT OPTION

						case 1:{//BEGIN   TRY TO HELP
							cout << "You run towards the scream and as you coming through a clearing you see a woman pulling the long grey beard of an old man." << endl;
							cout << "A younger man is pulling at the ladies waist, but she holds her grip as the king screams in agony. \"What's going on!?\" you ask" << endl;
							cout << "as you try to recall how you got here. Time to lay off the sauce buddy. At least you got it better together than these three." << endl <<endl;
							sleep_until(system_clock::now() +5s);
						break;}//END   TRY TO HELP

						case 2:{}
							break;}//END    CLUB FIRST CHOICE SWITCH



						break;}//END   CLUBS LEVEL 1

					case 2:{//BEGIN   CLUBS LEVEL 2
						break;}//END   CLUBS LEVEL 2

					case 3:{//BEGIN   CLUBS LEVEL 3
						break;}//END   CLUBS LEVEL 3

					case 4:{//BEGIN   CLUBS LEVEL 4
						break;}//END   CLUBS LEVEL 4
				}break;}//END   CLUBS


	case 2:{//BEGIN   DIAMONDS
				switch(level){
					case 1:{//BEGIN   DIAMONDS LEVEL 1
						break;}//END   DIAMONDS LEVEL 1

					case 2:{//BEGIN   DIAMONDS LEVEL 2
						break;}//END   DIAMONDS LEVEL 2

					case 3:{//BEGIN   DIAMONDS LEVEL 3
						break;}//END   DIAMONDS LEVEL 3

					case 4:{//BEGIN   DIAMONDS LEVEL 4
						break;}//END   DIAMONDS LEVEL 4
				}break;}//END   DIAMONDS


	case 3:{//BEGIN   HEARTS
				switch(level){
					case 1:{//BEGIN   HEARTS LEVEL 1
						break;}//END   HEARTS LEVEL 1

					case 2:{//BEGIN   HEARTS LEVEL 2
						break;}//END   HEARTS LEVEL 2

					case 3:{//BEGIN   HEARTS LEVEL 3
						break;}//END   HEARTS LEVEL 3

					case 4:{//BEGIN   HEARTS LEVEL 4
						break;}//END   HEARTS LEVEL 4
				}break;}//END   HEARTS


	case 4:{//BEGIN   SPADES
				switch(level){
					case 1:{//BEGIN   SPADES LEVEL 1
						break;}//END   SPADES LEVEL 1

					case 2:{//BEGIN   SPADES LEVEL 2
						break;}//END   SPADES LEVEL 2

					case 3:{//BEGIN   SPADES LEVEL 3
						break;}//END   SPADES LEVEL 3

					case 4:{//BEGIN   SPADES LEVEL 4
						break;}//END   SPADES LEVEL 4
				}break;}//END   SPADES
		}//END  SUIT
		return 0;
	}//END   FUNCTION TELLSTORY




Player::~Player() {
	// TODO Auto-generated destructor stub
}

