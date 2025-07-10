#include "Card.h"
#include "King.h"
#include "Queen.h"
#include "Jack.h"
#include "Player.h"
#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <iomanip>
#include <cassert>
#include <fstream>
#include <sstream>

using namespace std;



/*
 FUNCTION for centering text. TAKEN from this website:
 https://stackoverflow.com/questions/17512825/align-text-to-center-in-string-c
 */
std::string center (const std::string& s, unsigned width)
{
    assert (width > 0);
    if (int padding = width - s.size (), pad = padding >> 1; pad > 0)
        return std::string (padding, ' ').insert (pad, s);
    return s;
}





void ClearScreen(){for(unsigned int i = 0 ; i<40 ; i++){cout << endl;} cout << "\r";}//FUNCTION      CLEAR SCREEN LOOP



int ChoiceCheck(int numChoices){//BEGIN   FUNCTION FOR TAKING AND CHECKING USER INPUT TO CHECK IF IT IS A NUMBER IN THE RANGE OF CHOICES

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



//FUNCTION: GETTING MENU OPTION
int MainMenu(){

	ClearScreen();

	using namespace std::this_thread; // sleep_for, sleep_until
	using namespace std::chrono; // nanoseconds, system_clock, seconds

	//PRINT MENU UNTIL IN RANGE OPTION IS ENTERED
	Card startCard;//BEGIN   PRINT THE TITLE SCREEN
	cout << endl << center("\u2665\u2667\u2666\u2664\u2665\u2667\u2666\u2664\u2665" , 170) << endl;
	cout << center("SUITED!" , 151) << endl;
	cout << center("\u2665\u2664\u2666\u2667\u2665\u2664\u2666\u2667\u2665" , 170)  << endl;
	startCard.PrintParty(startCard.GetSuit());//END   PRINT THE TITLE SCREEN

	  cout << "Choose Your Destiny!" << endl << endl;//BEGIN   PRINT THE MAIN MENU
	  cout << " 0: Quit" << endl ;
	  cout << " 1: Story" << endl;
	  cout << " 2: Battle" << endl;
	  cout << " 3: Instructions" << endl;
	  cout << " 4: Options" << endl;
	  cout << " 5: Credits" << endl << endl;

	  int option = ChoiceCheck(5);
	  return option;}

void PrintInstructions(){

cout << endl;

cout << "Suited is written to replicate a card game that I created using a standard deck of playing cards. " << endl;
cout << "The card game is modeled on the rpg video games I played as a kid in which you control a party of three characters in turn based combat." << endl;
cout <<endl;

cout << "Up to 4 people can play at once but this program version will focus first on a single player vs computer model and potentially expand to" << endl;
cout << "include a multiplayer \"Battle\" option. My intent with this program is really more as a way to teach people how to play the card game " << endl;
cout << "with each other than it is to create a video game equivalent." << endl;
cout << endl;

cin.ignore();
cout << "Press enter to continue...";
cin.get();
cout << endl;


cout << "The game is played by first selecting one of the four suits of cards, spades, clubs, hearts, or diamonds. Gather all the cards of that " << endl;
cout << "suit into your hand. Place the king, queen, and jack in front of you facing up. This is your party each of who you can choose to attack" << endl;
cout << "with or use their special ability." << endl;
cout << endl;


cout << "The king is a mighty warrior who can duel wield." << endl;
cout << "The queen a wise witch with healing magic." << endl;
cout << "The jack a loyal guard who can block and counter attack." << endl;
cout << endl;

cout << "Press enter to continue...";
cin.get();
cout <<endl;


cout << "You hold your 10 number cards (ace is 1) in your hand." << endl;
cout << "Your turn begins by choosing a character to act with and" << endl;
cout <<	"ends when you have played for each character in your party." << endl;
cout << "You do not have to play each character during every turn." << endl;
cout << endl;


cout <<	"To take action with a character you decide which character you want to use," << endl;
cout <<	"whether to attack with them or use their special" << endl;
cout << "and then use you number cards for the value of their turn." << endl;
cout << endl;

cout << "Press enter to continue...";
cin.get();
cout <<endl;


cout << "For example, you may choose to select the king first and use his duel wield special ability to attack the opponent's queen. " << endl;
cout <<	"You pick an 8 and a 7 hitting her for 15 damage. " << endl;
cout <<	"Now you lay the 8 and 7 face down on the table and can't use them again until you begin a turn with no cards in your hand." << endl;
cout << endl;

cout << "During the opponents turn the queen heals herself for 10" << endl;
cout <<	"then the player uses their jacks special ability by placing a card face down below the jack." << endl;
cout << "This card is used to deal counter attack damage during an opponents attack which is blocked dealing no damage." << endl;
cout << endl;
cout <<	"The jack's special move can be used in response to any opponents attack on any party member." << endl;
cout << "The jack blocks that party member from taking damage while also dealing the damage of the card played face down on him." << endl;
cout << endl;

cout << "Press enter to continue...";
cin.get();
cout <<endl;

cout << "If you run out of cards before taking action with each character your turn ends and on your next turn all 10 cards return to your hand." << endl;
cout << endl;
cout << "The health of the party can vary to shorten or extend games. " << endl;
cout << "The recommended health levels are Jack 40 , Queen 45 , King 50." << endl;
cout << "The game is over when only one player has party members left." << endl;
cout << endl;
cout << "Select an unseen card from the opponents hand and whoever has the highest number goes first." << endl;
cout << "Repeat if the cards are the same value until a winner is decided." << endl;
cout << endl;
cout << "Let the games, BEGIN!";
cout << endl;

cout << "Press enter to return to menu." << endl;
cin.get();
cout <<endl;
}//END OF INSTRUCTIONS FUNCTION



//FUNCTION FOR OPTIONS
void OptionsMenu(int difficulty , int gameLength){

	int opMChoice;

	int loopLeave=0;

	while(loopLeave == 0){

	cout << "You've Got Options" << endl;
	cout << endl;
	cout << "0: Back" << endl;
	cout << "1: Difficulty" << endl;
	cout << "2: Life Points" << endl;
	cout << "Enter your choice: " ; cin >> opMChoice;

	if(isdigit(opMChoice) || opMChoice < 1 || opMChoice > 3){ cout << "Not an option." << endl; loopLeave=0 ; cin.clear() ; cin.ignore();}

	switch (opMChoice){

	case 1:{//BEGIN   CASE 1 DIFFICULTY LEVEL
		difficulty = 0;
		while(isdigit(difficulty) || difficulty<1 || difficulty>3){
		cout << "Enter a difficulty level." << endl;
		cout << "1: Easy" << endl;
		cout << "2: Normal" << endl;
		cout << "3: Hard" << endl;
		cout << "Enter difficulty choice: ";
		cin >> difficulty;

		cout << endl;

		if(isdigit(difficulty) || difficulty<1 || difficulty>3){
		cout << "Not a valid difficulty level." << endl;
		cout << "Please try again." << endl;
		difficulty = 0;}} break; } //END   CASE 1 DIFFICULTY LEVEL


	case 2:{//BEGIN   CASE 2 GAME LENGTH
		gameLength = 0;
		while(isdigit(gameLength) || gameLength<1 || gameLength>3){
		cout << "Adjust Game Length By Choosing Party Life Points." << endl;
		cout << "1: King - 45HP   Queen - 40HP   Jack - 35HP" << endl;
		cout << "2: King - 50HP   Queen - 45HP   Jack - 40HP" << endl;
		cout << "3: King - 55HP   Queen - 50HP   Jack - 45HP" << endl;
		cout << "Enter Life Choice: ";
		cin >> gameLength ; cout << endl;

		if(isdigit(gameLength) || gameLength<1 || gameLength>3){cout << "Not a valid life choice." << endl << "Please try again." << endl ; cin.clear() ; cin.ignore() ; gameLength = 0;}
		} break; }//END   CASE 2 GAME LENGTH

	case 0:{loopLeave = 1;break;}

	}}}




//FUNCTION for playing Credits

void PrintCredits(){
	using namespace std::this_thread;
	using namespace std::chrono;

	for(unsigned int i=0 ; i<30 ; i++){
		cout << endl;
		sleep_until(system_clock::now() +.1s);
	}

	cout << center("Suited was created by Jonathan Arc" , 150) << endl;

	for(unsigned int i=0 ; i<15 ; i++){
			cout << endl;
			sleep_until(system_clock::now() +.3s);
		}
	sleep_until(system_clock::now() +3s);


	cout << center("All the code was written by Jonathan Arc except those listed below." , 150) << endl;
	sleep_until(system_clock::now() +.3s);
	cout << endl;
	sleep_until(system_clock::now() +.3s);
	cout << center("The center() function was found on this website:" , 150) << endl;
	sleep_until(system_clock::now() +.3s);
	cout << center("https://stackoverflow.com/questions/17512825/align-text-to-center-in-string-c" , 150) << endl;
	sleep_until(system_clock::now() +.3s);
	cout << center("Posted by: Mikal Keenan" , 150) << endl;
	sleep_until(system_clock::now() +.3s);


	for(unsigned int i=0 ; i<15 ; i++){
			cout << endl;
			sleep_until(system_clock::now() +.3s);
		}

	sleep_until(system_clock::now() +3s);


	cout << "Press enter to return to menu." << endl;
	cin.ignore();
	cin.get();
	cout <<endl;

for(unsigned int i = 0 ; i<30 ; i++){
		cout << endl;
	}
}//END OF CREDITS FUNCTION

bool CheckCard(int cToC , Player pToC){//BEGIN   CHECKCARD FUNCTION. CHECKS IF CARD INPUT IS VALID INPUT AND AVAILABLE TO PLAYER

	if(!isdigit(cToC)){return 0;}

	if(cToC<1 || cToC>10){return 0;}

	for(int t=1 ; t<11 ; t++){

		if(pToC.numberCards[t] == cToC){
			return 1;
		}
	}
	return 0;
}//END   CHECKCARD FUNCTION.





void PrintBoard(Player _p1 , Player _p2){

	//SWITCHES TO DISPLAY EMPTY SET DEPENDING ON TURN AS INDICATED BY (cardSet) VARIABLE. (cardSet=0) MEANS DISPLAY CARD BACK.
	if(_p1.cardSet == 0){ for(int i=0 ; i<10 ; i++){ _p1.numberCards[i] = _p1.emptyCards[i];}}
	if(_p2.cardSet == 0){ for(int i=0 ; i<10 ; i++){ _p2.numberCards[i] = _p2.emptyCards[i];}}

	int ftn=1;
	int ftN=1;


		//THESE VALUES ARE THE CARD OVER DISTANCE AND THE CARD UNDER DISTANCE.
		int cO=16;	//CARD OVER SPACE FROM THE BEGINNING OF ONE CARD TO THE NEXT

		int oP =0; //OFF PRINT TURNS OFF NORMAL PRINT ELSE CONDITIONAL

		int p1ScoreSum = _p1.KingHealth() + _p1.QueenHealth() + _p1.JackHealth();//PLAYER 1 SCORE TOTAL SUM OF PLAYER HEALTH
		int p2ScoreSum = _p2.KingHealth() + _p2.QueenHealth() + _p2.JackHealth();//PLAYER 2 SCORE TOTAL SUM OF PLAYER HEALTH

		//TRACKING VARIABLES FOR TEXT
		int jL1=0; //JACK LOOP PLAYER 1;
		int jL2=0; //JACK LOOP PLAYER 2;

		int qL1=0; //QUEEN LOOP PLAYER 1;
		int qL2=0; //QUEEN LOOP PLAYER 2;

		int kL1=0; //KING LEFT PLAYER 1;
		int kL2=0; //KING LEFT PLAYER 2;

		int kR1=0; //KING RIGHT PLAYER 1;
		int kR2=0; //KING RIGHT PLAYER 2;





		//CARD START VALUES IN CARDSTRING VARIABLE ("cardTable.txt")
		unsigned int p2NR[9];//PLAYER 2 NUMBER ROW FIRST COLUMN VALUES;
		p2NR[0]=0 ; p2NR[1]=161 ; p2NR[2]=322 ; p2NR[3]=483 ; p2NR[4]=644 ; p2NR[5]=805 ; p2NR[6]=966 ; p2NR[7]=1127 ; p2NR[8]=1288 ; p2NR[9]=1449 ;

		unsigned int p2RR[9];//PLAYER 2 ROYAL ROW FIRST COLUMN VALUES;
		p2RR[0]=1789 ; p2RR[1]=1926 ; p2RR[2]=2063 ; p2RR[3]=2200 ; p2RR[4]=2337 ; p2RR[5]=2474 ; p2RR[6]=2611 ; p2RR[7]=2748 ; p2RR[8]=2885 ; p2RR[9]=3022 ;

		unsigned int p1NR[9];//PLAYER 1 NUMBER ROW FIRST COLUMN VALUES;
		p1NR[0]= 5163 ; p1NR[1]= 5324 ; p1NR[2]= 5485 ; p1NR[3]= 5646 ; p1NR[4]= 5807 ; p1NR[5]= 5968 ; p1NR[6]= 6129 ; p1NR[7]= 6290 ; p1NR[8]= 6451 ; p1NR[9]= 6612 ;

		unsigned int p1RR[9];//PLAYER 1 ROYAL ROW FIRST COLUMN VALUES;
		p1RR[0]=3376 ; p1RR[1]=3513 ; p1RR[2]=3650 ; p1RR[3]=3787 ; p1RR[4]=3924 ; p1RR[5]=4061 ; p1RR[6]=4222 ; p1RR[7]=4384 ; p1RR[8]=4545 ; p1RR[9]=4706 ;


		ifstream fin("cardTable.txt");//BEGIN   READ FILE INTO (cardString) STRING VARIABLE
			string cardString , tempLine; while (getline(fin, tempLine)) {cardString = cardString + tempLine; cardString.push_back('\n');}
			fin.close();//END   READ FILE INTO (cardString) STRING VARIABLE


				for(unsigned int cP=0 ; cP<cardString.size() ; cP++){oP=0;//BEGIN  PRINT BOARD LOOP



					for(int n=0 ; n<10 ; n++){//BEGIN   NUMBER CARD LOOP FOR NUMBER CARDS 1 TO 10

						//PLAYER 2 NUMBER CARDS

						if(_p2.numberCards[n]==-1){//BEGIN   EMPTY CARD SPOT
							for(int r=0 ; r<15 ; r++){
							if( (cP < p2RR[0]) && (cP==(n*cO)+p2NR[r])){//AREA OF CARD, ROW
								for(int l=0 ; l<15 ; l++){//LENGTH OF BLANK SPACE
								cout << " "; cP++; oP++;}}}}//END   EMPTY CARD SPOT


						else if(_p2.numberCards[n]==0){//BEGIN   BACK OF CARD
								for(int l=2 ; l<9 ; l++){//ROWS TO PRINT X
								if((cP > (p2NR[l] + cO*n + 1)) && (cP < (p2NR[l] + cO*n) + 10)){//THE AREA OF THE CARD TO PRINT ON (CARD NUMBER)
									for(int k=0 ; k<11 ; k++){cout << "X" ; cP++ ; oP++ ;}//COLUMN TO PRINT, PRINT, INCREMENT COUNTER
									cP--;}}}//END   BACK OF CARD, REMOVES THE LAST INCREMENT FROM THE LOOP FOR CORRECT SPACING

							else if(_p2.numberCards[n]>0 && _p2.numberCards[n]<11){//BEGIN   PRINT NUMBER CARD
							if(_p2.numberCards[n]!=n+1){
								for(int l=2 ; l<11 ; l++){//ROWS TO PRINT
									if((cP > (p2NR[l] + cO*n)-1) && (cP < (p2NR[l] + cO*n) + 10)){//THE AREA OF THE CARD TO PRINT ON (CARD NUMBER)
										for(int k=0 ; k<13 ; k++)
											if((cardString.at(p2NR[l] + k + (_p2.numberCards[n]-1)*cO))=='o'){
												cout << _p2.GetSuitCode(); cP++; oP++;
											}
											else{
										cout << cardString.at(p2NR[l] + k + (_p2.numberCards[n]-1)*cO) ; cP++ ; oP++ ;}//COLUMN TO PRINT, PRINT, INCREMENT COUNTER
											cP--;}}}//END   BACK OF CARD, REMOVES THE LAST INCREMENT FROM THE LOOP FOR CORRECT SPACING
							}//END   PRINT NUMBER CARD


							//PLAYER 1 NUMBER CARDS

								if(_p1.numberCards[n]==-1){//BEGIN   EMPTY CARD SPOT
									for(int r=0 ; r<15 ; r++){
									if( (cP > p1RR[9]) && (cP==(n*cO)+p1NR[r])){//AREA OF CARD, ROW
										for(int l=0 ; l<15 ; l++){//LENGTH OF BLANK SPACE
										cout << " "; cP++; oP++;}}}}//END   EMPTY CARD SPOT

								if(_p1.numberCards[n]==0){//BEGIN   BACK OF CARD
									for(int l=2 ; l<9 ; l++){//ROWS TO PRINT X
									if((cP > (p1NR[l] + cO*n + 1)) && (cP < (p1NR[l] + cO*n) + 10)){//THE AREA OF THE CARD TO PRINT ON (CARD NUMBER)
										for(int k=0 ; k<11 ; k++){cout << "X" ; cP++ ; oP++ ;}//COLUMN TO PRINT, PRINT, INCREMENT COUNTER
										cP--;}}}//END   BACK OF CARD, REMOVES THE LAST INCREMENT FROM THE LOOP FOR CORRECT SPACING

								else if(_p1.numberCards[n]>0 && _p1.numberCards[n]<11){//BEGIN   PRINT NUMBER CARD
								if(_p1.numberCards[n]!=n+1){
									for(int l=2 ; l<11 ; l++){//ROWS TO PRINT X
										if((cP > (p1NR[l] + cO*n)-1) && (cP < (p1NR[l] + cO*n) + 10)){//THE AREA OF THE CARD TO PRINT ON (CARD NUMBER)
											for(int k=0 ; k<13 ; k++)
												if((cardString.at(p1NR[l] + k + _p1.numberCards[n]*cO))=='S'){
													cout << _p1.GetSuitCode(); cP++; oP++;
												}
												else{
											cout << cardString.at(p1NR[l] + k + _p1.numberCards[n]*cO) ; cP++ ; oP++ ;}//COLUMN TO PRINT, PRINT, INCREMENT COUNTER
												cP--;}}}//END   BACK OF CARD, REMOVES THE LAST INCREMENT FROM THE LOOP FOR CORRECT SPACING
								}//END   PRINT NUMBER CARD
								}//END   NUMBER CARD LOOP FOR NUMBER CARDS 1 TO 10


				if(cP==p2RR[jL2]){jL2++;//BEGIN   P2 JACK LOOP COUNTER-ATTACK

					 if(_p2.pJack.GetCounter()==0){//BEGIN   HIDDEN JACK COUNTER SHOW BACK OF CARD
						 if(jL2==1){cout<<" "; for(int p=0 ; p<13 ; p++){cout << "_"; oP++; cP++;}cP++;}//PRINT TOP LINE OF CARD

						 if(jL2==2){cout << "|"; for(int p=0 ; p<13 ; p++){cout << " ";oP++; cP++;}cout << "|"; cP++;cP++;}//PRINT SECOND LINE OF CARD

						 if(jL2>2 && jL2<10){cout << "| "; oP++; cP++; oP++; cP++; for(int k=0 ; k<11 ; k++){cout << "X" ; oP++; cP++;}cout << " |";oP++; cP++;oP++; cP++;}

						 if(jL2==10){cout << "|"; cP++;for(int d=0 ; d<13 ; d++){cout << "_";cP++;} cout<<"|";cP++;}}//END   HIDDEN JACK COUNTER SHOW BACK OF CARD

						else if(_p2.pJack.GetCounter()>0 && _p2.pJack.GetCounter()<11){//BEGIN   JACK COUNTER CARD
								for(int k=0 ; k<15 ; k++){//LENGTH OF CARD
									if(cardString.at(p2NR[jL2-1] + k + (_p2.pJack.GetCounter()-1)*cO) == 'o'){cout << _p2.GetSuitCode();oP++; cP++;}
									else{cout << cardString.at(p2NR[jL2-1] + k + (_p2.pJack.GetCounter()-1)*cO) ; oP++; cP++;}}}//END   JACK COUNTER CARD

					oP++; oP++;}//END   P2 JACK LOOP COUNTER-ATTACK


				if(cP==p1RR[jL1]){jL1++;//BEGIN  P1 JACK LOOP

						 if(_p1.pJack.GetCounter()==0){//BEGIN   JACK COUNTER REVERSE SIDE
							 if(jL1==1){cout<<" "; for(int p=0 ; p<13 ; p++){cout << "_"; oP++; cP++;}cP++;}//PRINT TOP LINE OF CARD

							 if(jL1==2){cout << "|"; for(int p=0 ; p<13 ; p++){cout << " ";oP++; cP++;}cout << "|"; cP++;cP++;}//PRINT SECOND LINE OF CARD

							 if(jL1>2 && jL1<10){cout << "| "; oP++; cP++; oP++; cP++; for(int k=0 ; k<11 ; k++){cout << "X" ; oP++; cP++;}cout << " |";oP++; cP++;oP++; cP++;}

							 if(jL1==10){cout << "|"; cP++;for(int d=0 ; d<13 ; d++){cout << "_";cP++;} cout<<"|";cP++;}}//END   HIDDEN JACK COUNTER SHOW BACK OF CARD

						else if(_p1.pJack.GetCounter()>0 && _p1.pJack.GetCounter()<11){//JACK COUNTER REVERSE SIDE
								for(int k=0 ; k<15 ; k++){//LENGTH OF CARD
									if(cardString.at(p1NR[jL1-1] + k + (_p1.pJack.GetCounter()-1)*cO) == 'S'){cout << _p1.GetSuitCode();oP++; cP++;}
									else{cout << cardString.at(p1NR[jL1-1] + k + (_p1.pJack.GetCounter()-1)*cO) ; oP++; cP++;}}}//END   JACK COUNTER CARD

					oP++; oP++;}//END   P1 JACK LOOP



				if(cP==p2RR[qL2]+cO*2+1){qL2++;//BEGIN   PLAYER 2 QUEEN LOOP
					if(_p2.pQueen.heal==0){//BEGIN   QUEEN REVERSE
						if(qL2==1){cout<<" "; for(int p=0 ; p<13 ; p++){cout << "_"; oP++; cP++;}cP++;}//PRINT TOP LINE OF CARD

						if(qL2==2){cout << "|"; for(int p=0 ; p<13 ; p++){cout << " ";oP++; cP++;}cout << "|"; cP++;cP++;}//PRINT SECOND LINE OF CARD

						if(qL2>2 && qL2<10){cout << "| "; oP++; cP++; oP++; cP++; for(int k=0 ; k<11 ; k++){cout << "X" ; oP++; cP++;}cout << " |";oP++; cP++;oP++; cP++;}

						if(qL2==10){cout << "|"; cP++;for(int d=0 ; d<13 ; d++){cout << "_";cP++;}}}//END   QUEEN REVERSE

					else if(_p2.pQueen.heal[0]>0 && _p2.pQueen.heal[0]<11){//BEGIN   QUEEN NUMBER UP
						for(int k=0 ; k<15 ; k++){//LENGTH OF CARD

							if(cardString.at(p2NR[qL2-1] + k + ((_p2.pQueen.heal[0] - 1)*cO)) == 'o'){cout << _p2.GetSuitCode() ;oP++;cP++;}
							else{cout << cardString.at(p2NR[qL2-1] + k + (_p2.pQueen.heal[0]-1)*cO); oP++; cP++;}}}//END   QUEEN NUMBER UP
			oP++; oP++;cP--;}//END   PLAYER 2 QUEEN LOOP



				if(cP==p1RR[qL1]+cO*2+1){qL1++;//BEGIN   PLAYER 1 QUEEN LOOP
					if(_p1.pQueen.heal[0]==0){//BEGIN   QUEEN REVERSE
						if(qL1==1){cout<<" "; for(int p=0 ; p<13 ; p++){cout << "_"; oP++; cP++;}cP++;}//PRINT TOP LINE OF CARD

						if(qL1==2){cout << "|"; for(int p=0 ; p<13 ; p++){cout << " ";oP++; cP++;}cout << "|"; cP++;cP++;}//PRINT SECOND LINE OF CARD

						if(qL1>2 && qL1<10){cout << "| "; oP++; cP++; oP++; cP++; for(int k=0 ; k<11 ; k++){cout << "X" ; oP++; cP++;}cout << " |";oP++; cP++;oP++; cP++;}

						if(qL1==10){cout << "|"; cP++;for(int d=0 ; d<13 ; d++){cout << "_";cP++;}}}//END   QUEEN REVERSE

					else if(_p1.pQueen.heal[0]>0 && _p1.pQueen.heal[0]<11){//BEGIN   QUEEN NUMBER UP
						for(int k=0 ; k<15 ; k++){//LENGTH OF CARD

							if(cardString.at(p1NR[qL1-1] + k + ((_p1.pQueen.heal[0]-1)*cO)) == 'S'){cout << _p1.GetSuitCode() ;oP++;cP++;}
							else{cout << cardString.at(p1NR[qL1-1] + k + (_p1.pQueen.heal[0]-1)*cO); oP++; cP++;}}}//END   QUEEN NUMBER UP
			oP++; oP++;cP--;}//END   PLAYER 1 QUEEN LOOP



				if(cP==p2RR[kL2]+cO*4+1){kL2++;//BEGIN   PLAYER 2 KING LEFT
					if(_p2.pKing.dualWield[0]==0){//BEGIN   KING LEFT REVERSE
						if(kL2==1){cout<<" "; for(int p=0 ; p<13 ; p++){cout << "_"; oP++; cP++;}cP++;}//PRINT TOP LINE OF CARD

						if(kL2==2){cout << "|"; for(int p=0 ; p<13 ; p++){cout << " ";oP++; cP++;}cout << "|"; cP++;cP++;}//PRINT SECOND LINE OF CARD

						if(kL2>2 && kL2<10){cout << "| "; oP++; cP++; oP++; cP++; for(int k=0 ; k<11 ; k++){cout << "X" ; oP++; cP++;}cout << " |";oP++; cP++;oP++; cP++;}

						if(kL2==10){cout << "|"; cP++;for(int d=0 ; d<13 ; d++){cout << "_";cP++;} cout << "|"; cP++;}cP--;}//END   KING LEFT REVERSE

					else if(_p2.pKing.dualWield[0]>0 && _p2.pKing.dualWield[0]<11){//NUMBER UP
						for(int k=0 ; k<15 ; k++){//LENGTH OF CARD
							if(cardString.at(p2NR[kL2-1] + k + ((_p2.pKing.dualWield[0]-1)*cO)) == 'o'){cout << _p2.GetSuitCode() ;oP++;cP++;}
							else{cout << cardString.at(p2NR[kL2-1] + k + (_p2.pKing.dualWield[0]-1)*cO); oP++; cP++;}}}//END   p2 KING LEFT CARD
			oP++; oP++;cP--;}//END   PLAYER 2 KING LEFT


				if(cP==p1RR[kL1]+cO*4+1){kL1++;//BEGIN   PLAYER 1 KING LEFT
					if(_p1.pKing.dualWield[0]==0){//BEGIN   KING LEFT REVERSE
						if(kL1==1){cout<<" ";cP++; for(int p=0 ; p<13 ; p++){cout << "_"; oP++; cP++;}cP++;}//PRINT TOP LINE OF CARD

						if(kL1==2){cout << "|";cP++; for(int p=0 ; p<13 ; p++){cout << " ";oP++; cP++;}cout << "|"; cP++;cP++;}//PRINT SECOND LINE OF CARD

						if(kL1>2 && kL1<10){cout << "| ";cP++; oP++; cP++; oP++; cP++; for(int k=0 ; k<11 ; k++){cout << "X" ; oP++; cP++;}cout << " |";oP++; cP++;oP++; cP++;}

						if(kL1==10){cP++;cout << "|"; cP++;for(int d=0 ; d<13 ; d++){cout << "_";cP++;} cout << "|"; cP++;}cP--;}//END   KING LEFT REVERSE

					else if(_p1.pKing.dualWield[0]>0 && _p1.pKing.dualWield[0]<11){//BEGIN   p1 KING LEFT FRONT
						for(int k=0 ; k<15 ; k++){//LENGTH OF CARD
							if(cardString.at(p1NR[kL1-1] + k + ((_p1.pKing.dualWield[0]-1)*cO)) == 'S'){cout << _p1.GetSuitCode() ;oP++;cP++;}
							else{cout << cardString.at(p1NR[kL1-1] + k + (_p1.pKing.dualWield[0]-1)*cO); oP++; cP++;}}}//END   p1 KING LEFT FRONT
			oP++; oP++;cP--;}//END   PLAYER 1 KING LEFT


				if(cP==p2RR[kR2]+cO*6+1){kR2++;//BEGIN   PLAYER 2 KING RIGHT

					if(_p2.pKing.dualWield[1]==0){//BEGIN   KING RIGHT REVERSE
						if(kR2==1){cout<<" "; for(int p=0 ; p<13 ; p++){cout << "_"; oP++; cP++;}cP++;}//PRINT TOP LINE OF CARD

						if(kR2==2){cout << "|"; for(int p=0 ; p<13 ; p++){cout << " ";oP++; cP++;}cout << "|"; cP++;cP++;}//PRINT SECOND LINE OF CARD

						if(kR2>2 && kR2<10){cout << "| "; oP++; cP++; oP++; cP++; for(int k=0 ; k<11 ; k++){cout << "X" ; oP++; cP++;}cout << " |";oP++; cP++;oP++; cP++;}

						if(kR2==10){cout << "|"; cP++;for(int d=0 ; d<13 ; d++){cout << "_";cP++;} cout << "|"; cP++;}cP--;}//END   KING LEFT REVERSE

					else if(_p2.pKing.dualWield[1]>0 && _p2.pKing.dualWield[1]<11){//NUMBER UP
						for(int k=0 ; k<15 ; k++){//LENGTH OF CARD
							if(cardString.at(p2NR[kR2-1] + k + ((_p2.pKing.dualWield[1]-1)*cO)) == 'o'){cout << _p2.GetSuitCode() ;oP++;cP++;}
							else{cout << cardString.at(p2NR[kR2-1] + k + (_p2.pKing.dualWield[1]-1)*cO); oP++; cP++;}}cP--;}//END   p2 KING LEFT CARD
			oP++; oP++;}//END   PLAYER 2 KING RIGHT


				if(cP==p1RR[kR1]+cO*6+1){kR1++;//BEGIN   PLAYER 1 KING RIGHT

					if(_p1.pKing.dualWield[1]==0){//BEGIN   KING RIGHT REVERSE
						if(kR1==1){cout<<" "; for(int p=0 ; p<13 ; p++){cout << "_"; oP++; cP++;}cP++;}//PRINT TOP LINE OF CARD

						if(kR1==2){cout << "|"; for(int p=0 ; p<13 ; p++){cout << " ";oP++; cP++;}cout << "|"; cP++;cP++;}//PRINT SECOND LINE OF CARD

						if(kR1>2 && kR1<10){cout << "| "; oP++; cP++; oP++; cP++; for(int k=0 ; k<11 ; k++){cout << "X" ; oP++; cP++;}cout << " |";oP++; cP++;oP++; cP++;}

						if(kR1==10){cout << "|"; cP++;for(int d=0 ; d<13 ; d++){cout << "_";cP++;} cout << "|"; cP++;}cP--;}//END   KING LEFT REVERSE

					else if(_p1.pKing.dualWield[1]>0 && _p1.pKing.dualWield[1]<11){//NUMBER UP
						for(int k=0 ; k<15 ; k++){//LENGTH OF CARD
							if(cardString.at(p1NR[kR1-1] + k + ((_p1.pKing.dualWield[1]-1)*cO)) == 'S'){cout << _p1.GetSuitCode() ;oP++;cP++;}
							else{cout << cardString.at(p1NR[kR1-1] + k + (_p1.pKing.dualWield[1]-1)*cO); oP++; cP++;}}cP--;}//END   p1 KING LEFT CARD
			oP++; oP++;}//END   PLAYER 1 KING RIGHT


				//BEGIN   PRINT PLAYER NAMES ON BOARD

				if(cP==2185  - ((_p2.firstName.size()/2) + (_p2.firstName.size()%2)) ){for(unsigned int k=0 ; k<_p2.firstName.size() ; k++){cout<< _p2.firstName.at(k) ; cP++;} cP--;}//PRINT PLAYER 2 FIRST NAME

				else if(cP==2459 - ((_p2.lastName.size()/2) + (_p2.lastName.size()%2))){for(unsigned int k=0 ; k<_p2.lastName.size() ; k++){cout<< _p2.lastName.at(k) ; cP++;} cP--;}//PRINT PLAYER 2 LAST NAME

				else if(cP==3772 - ((_p1.firstName.size()/2) + (_p1.firstName.size()%2)) ){for(unsigned int k=0 ; k<_p1.firstName.size() ; k++){cout<< _p1.firstName.at(k) ; cP++;} cP--;}//PRINT PLAYER 1 FIRST NAME

				else if(cP==4046 - ((_p1.lastName.size()/2) + (_p1.lastName.size()%2)) ){for(unsigned int k=0 ; k<_p1.lastName.size() ; k++){cout<< _p1.lastName.at(k) ; cP++;} cP--;}//PRINT PLAYER 2 LAST NAME
				//END OF NAME PRINT PART OF PRINTBOARD FUNCTION


				//BEGIN    PRINT NORMAL CARD FUNCTION
				else if(cardString.at(cP) == 'S'){ cout << _p1.GetSuitCode();}
				else if(cardString.at(cP) == 'o'){ cout << _p2.GetSuitCode();}
				else if(cardString.at(cP) == 'c'){ if(_p2.KingHealth()<9){cout << _p2.KingHealth() << " "; cP++;} else{cout << _p2.KingHealth();}cP++;}
				else if(cardString.at(cP) == 'C'){ if(_p1.KingHealth()<9){cout << _p1.KingHealth() << " "; cP++;} else{cout << _p1.KingHealth();}cP++;}
				else if(cardString.at(cP) == 'v'){ if(_p2.QueenHealth()<9){cout << _p2.QueenHealth() << " "; cP++;} else{cout << _p2.QueenHealth();}cP++;}
				else if(cardString.at(cP) == 'V'){ if(_p1.QueenHealth()<9){cout << _p1.QueenHealth() << " "; cP++;} else{cout << _p1.QueenHealth();}cP++;}
				else if(cardString.at(cP) == 'z'){ if(_p2.JackHealth()<9){cout << _p2.JackHealth() << " "; cP++;} else{cout << _p2.JackHealth();}cP++;}
				else if(cardString.at(cP) == 'Z'){ if(_p1.JackHealth()<9){cout << _p1.JackHealth() << " "; cP++;} else{cout << _p1.JackHealth();}cP++;}
				else if(cardString.at(cP) == 'u')
						{
						cout << p2ScoreSum << " " << "points";
							if(p2ScoreSum>100){for(int g=0 ; g<9 ; g++){ cP++;}}
							else if(p2ScoreSum<100){for(int  g=0 ; g<8 ; g++){ cP++;}}
							else if(p2ScoreSum<10){for(int  g=0 ; g<7 ; g++){ cP++;}}
						}

				else if(cardString.at(cP) == 'U')
						{
						cout << p1ScoreSum << " " << "points";
							if(p2ScoreSum>100){for(int g=0 ; g<9 ; g++){ cP++;}}
							else if(p2ScoreSum<100){for(int  g=0 ; g<8 ; g++){ cP++;}}
							else if(p2ScoreSum<10){for(int  g=0 ; g<7 ; g++){ cP++;}}
						}

				else if((_p2.turnTotal == 0)&&(cardString.at(cP) == 'n')){if(ftn>9){cout << ftn; ftn++; cP++;}else{cout << " " << ftn; ftn++; cP++;}}
				else if((_p2.turnTotal > 0)&&(cardString.at(cP) == 'n')){cout << " "; cP++; ftn++;}
				else if((_p1.turnTotal == 0)&&(cardString.at(cP)) == 'N'){if(ftN>9){cout << ftN; ftN++; cP++;}else{cout << " " << ftN; ftN++; cP++;}}
				else if((_p1.turnTotal > 0)&&(cardString.at(cP) == 'N')){cout << " "; cP++; ftN++; }
				else if(oP==0){cout << cardString[cP];}
				}

			}//END   PRINT BOARD FUNCTION







void ChangeTurn(int _goesFirst , Player& _p1 , Player& _p2){//BEGIN   CHANGES THE BOARD AROUND WHILE SWITCHING TURNS

	if(_goesFirst==2){cout << _p1.firstName << " " << _p1.lastName << ", press enter to flip cards then change places with " << _p2.firstName << " " << _p2.lastName << ".";}
	else if(_goesFirst==1){cout << _p2.firstName << " " << _p2.lastName << ", press enter to flip cards then change places with " << _p1.firstName << " " << _p1.lastName << ".";}
	cin.ignore();
	cin.get();

	_p1.cardSet=0;
	_p2.cardSet=0;

	if(_goesFirst==1){ _p1.EmptyHand(); ClearScreen(); PrintBoard(_p1 , _p2);}//PRINT BOARD WITH ALL CARDS FACE DOWN
	else if(_goesFirst==2){_p2.EmptyHand(); ClearScreen(); PrintBoard(_p2 , _p1);}//PRINT BOARD WITH ALL CARDS FACE DOWN


	if(_goesFirst==1){cout << _p1.firstName << " " << _p1.lastName << ", press enter to flip cards and begin turn.";}
	else if(_goesFirst==2){cout << _p2.firstName << " " << _p2.lastName << ", press enter to flip cards and begin turn.";}
	cin.get();

	if(_goesFirst==1){ _p1.cardSet=1 ; _p1.EmptyHand(); ClearScreen(); PrintBoard(_p1 , _p2);}//PRINT BOARD WITH CURRENT PLAYERS CARD UP
	else if(_goesFirst==2){_p2.cardSet=2 ; _p2.EmptyHand(); ClearScreen(); PrintBoard(_p2 , _p1);}//PRINT BOARD WITH CURRENT PLAYERS CARD UP

}//END   CHANGES THE BOARD AROUND WHILE SWITCHING TURNS



//FUNCTION ADD NEW PLAYER PROFILE
Player NewPlayer(){

	ClearScreen();

	Player tempP;
	string fN="";//FIRST NAME
	string lN="";//LAST NAME

	cout << "Enter your first name or 0 to return to previous menu: ";

	while(fN.size()>15 || fN.size()<1){
	cin.clear();
	cin.ignore();
	getline(cin , fN);

	if(fN=="0"){ClearScreen() ; return tempP;}

	if(fN.size()>15){
		cout << "That name is too long." << endl;
		cout << "First name must be 14 characters or less." << endl;
		cout << "Please try again.";
		cin.clear();
		cin.ignore();
	}
	if(fN.size()<1){
			cout << "That name is too short." << endl;
			cout << "First name must be 1 character or more." << endl;
			cout << "Please try again.";
			cin.clear();
			cin.ignore();
		}
	}

	cout << "Enter your last name or 0 to return to previous menu: ";

	while((lN.size()>15 || lN.size()<1)){
		getline(cin , lN);

	if(lN=="0"){ClearScreen() ; return tempP;}


	if(fN.size()>15){
		cout << "That name is too long." << endl;
		cout << "Last name must be 14 characters or less." << endl;
		cout << "Please try again." << endl;
		cin.clear();
		cin.ignore();
	}
	else if(lN.size()<1){
			cout << "That name is too short." << endl;
			cout << "Last name must be 1 character or more." << endl;
			cout << "Please try again." << endl;
			cin.clear();
			cin.ignore();
		}
	}

	ClearScreen();

	tempP.SetFirstName(fN);
	tempP.SetLastName(lN);
	tempP.SetSuit(tempP.SuitSelection(-1));
	tempP.SetHuman(1);
		return tempP;
}//END OF ADD NEW PLAYER FUNCTION;


//FUNCTION LOAD PLAYER PROFILE FROM TOP TEN LIST
Player LoadPlayer(Player _pIn){
	Player tempP;


	string scoreString = "";//HOLDS THE FILE INPUT FROM THE LIST OF TOP 10 HIGH SCORES
	string topScoreFirstNames[10];//ARRAY CONTAINING THE FIRST NAMES OF THOSE WITH THE TOP 10 SCORES
	string topScoreLastNames[10];
	int topScorePoints[10];
	int profileNumber=0;
	int playerNum=1;//TRACKS IF INPUTTING PLAYER 1 AND PLAYER 2

	ClearScreen();

	ifstream fin("highScores.txt");//LOAD FILE STREAM
	//CHECK IF FILE IS OPEN, ERROR IF NOT
	  if (!fin.is_open()) {cout << "Top 10 list not found." << endl ; return tempP;}

	//USE WHILE LOOP AND STRINGS TO GETLINE FILE TEXT INTO (line) VARIABLE
	  string tempList , list;
	  while (getline(fin, tempList)) {list = list + tempList; list.push_back('\n');}

	  // INITIALIZE VARIABLE (listPlace) THAT IS USED TO KEEP PLACE IN (list)
	  unsigned int listPlace = 0;


	  	 listPlace = 0;//RESET LIST COUNTER TO USE FOR ADDING LIST INFORMATION TO ARRAYS
	  	 for(int f=0 ; f<10 ; f++){//BEGIN    FOR LOOP   ADD TOP 10 LIST TO ARRAYS
	 	 while(isdigit(list.at(listPlace))){listPlace++;} listPlace++;

	  	string tfName;
	  	while(list.at(listPlace)!='\n'){
	  		tfName.push_back(list.at(listPlace)); listPlace++;}

	  	topScoreFirstNames[f] = tfName;
	    while(list.at(listPlace)!='\n'){listPlace++;} listPlace++;


	    tfName = "";

	    while(list.at(listPlace)!='\n'){tfName.push_back(list.at(listPlace));listPlace++;}
	    	  	topScoreLastNames[f] = tfName;
	    	    while(list.at(listPlace)!='\n'){listPlace++;} listPlace++;


	   string tfScore = "";

	   while(list.at(listPlace)!='\n'){tfScore.push_back(list.at(listPlace)); listPlace++;}
	   	   	   	   int tfScoreInt = stoi(tfScore);
	  	    	  	topScorePoints[f] = tfScoreInt;


	 	 while(isdigit(list.at(listPlace))){listPlace++;} listPlace++;
	    	if(listPlace<list.size()){
	    	if(list.at(listPlace)=='\n'){listPlace++;}
	    	}
	  	 }//END   FOR LOOP   ADD TOP 10 LIST TO ARRAYS


			cout << "TOP 10 SCORES" << endl << endl;
			cout << " 0: Return to Menu" << endl;
			for(int h=0 ; h<10 ; h++){
				if(h<9){cout << " " << (h+1) << ": " << topScoreFirstNames[h] << " " << topScoreLastNames[h];}
				else{cout << (h+1) << ": " << topScoreFirstNames[h] << " " << topScoreLastNames[h];}
				for(unsigned int l=0 ; l<(30-(topScoreFirstNames[h].size()+topScoreLastNames[h].size())) ; l++){
					cout << " ";
					}
				if(topScorePoints[h]>=10){cout << topScorePoints[h];}
				else{cout << " " << topScorePoints[h];}
				cout << endl;
			}

		cout<< endl;

		while(profileNumber == 0 && playerNum<2){//BEGIN    DATA VALIDATION WHILE LOOP
		cout << "Enter profile number to load: ";
		cin >> profileNumber;

		if(profileNumber==0){tempP.SetFirstName("EXITWITHOUTLOAD") ; return tempP;}

		else if(isdigit(profileNumber) || profileNumber<1 || profileNumber>10){
			cout << "Not a valid player. Please try again." << endl;
			profileNumber=0;
			cin.clear();
			cin.ignore();
			}

		else if(((!isdigit(profileNumber) || profileNumber>=1 || profileNumber<10)) && (_pIn.GetFirstName()==topScoreFirstNames[profileNumber-1]) && (_pIn.GetLastName()==topScoreLastNames[profileNumber-1])){
			cout << "Player 1 is playing as " << topScoreFirstNames[profileNumber-1] << " " << topScoreLastNames[profileNumber-1] << ". Please try again." << endl;
			profileNumber=0;
			cin.clear();
			cin.ignore();
				}

			}//END   DATA VALIDATION WHILE LOOP

		//SET INFO TAKEN FROM HIGH SCORE LIST CHOICE TO TEMPORARY PLAYER THEN RETURN TEMPOARARY PLAYER.
		tempP.SetFirstName(topScoreFirstNames[profileNumber-1]);
		tempP.SetLastName(topScoreLastNames[profileNumber-1]);
		tempP.SetHighScore(topScorePoints[profileNumber-1]);

		ClearScreen();
		return tempP;
	}//END OF LOAD PLAYER PROFILE FROM TOP TEN LISTS




Player LoadGameFromFile(string fileName){

			ifstream fin(fileName);//LOAD FILE STREAM


//CHECK IF FILE IS OPEN, ERROR IF NOT
		  if (!fin.is_open()) {cout << "Saved game file not found." << endl ; Player pLoad; return pLoad;}


		  //USE WHILE LOOP AND STRINGS TO GETLINE FILE TEXT INTO (line) VARIABLE
		  string tempList , list;
		  while (getline(fin, tempList)) {list = list + tempList; list.push_back('\n');}

		  // INITIALIZE VARIABLE (listPlace) THAT IS USED TO KEEP PLACE IN (list)
		  unsigned int listPlace = 0;

		  	 listPlace = 0;//RESET LIST COUNTER TO USE FOR ADDING LIST INFORMATION TO ARRAYS
		  	 for(int f=0 ; f<1 ; f++){//BEGIN    FOR LOOP   ADD TOP 10 LIST TO ARRAYS

		  	string GameFN;
		  	while(list.at(listPlace)!='\n'){
		  		GameFN.push_back(list.at(listPlace)); listPlace++;} listPlace++;

		  	string GameLN;
		    while(list.at(listPlace)!='\n'){GameLN.push_back(list.at(listPlace));listPlace++;}
		    	    while(list.at(listPlace)!='\n'){listPlace++;} listPlace++;

		    string GameHS ; int GameHSNum ;
		    while(list.at(listPlace)!='\n'){GameHS.push_back(list.at(listPlace)); listPlace++;}
			   	   while(list.at(listPlace)!='\n'){listPlace++;} listPlace++;
			   	GameHSNum = stoi(GameHS);

		   string GameSuit ; int GameSuitNum ;
		   while(list.at(listPlace)!='\n'){GameSuit.push_back(list.at(listPlace)); listPlace++;}
		   	   while(list.at(listPlace)!='\n'){listPlace++;} listPlace++;
		   	GameSuitNum = stoi(GameSuit);

			   string GameLevel; int GameLNum;
		  while(list.at(listPlace)!='\n'){GameLevel.push_back(list.at(listPlace)); listPlace++;}
				   	   while(list.at(listPlace)!='\n'){listPlace++;} listPlace++;
				   	   GameLNum = stoi(GameLevel);

			Player pLoad(GameFN , GameLN , GameHSNum);

		   	pLoad.SetSuit(GameSuitNum) ; pLoad.SetLevel(GameLNum) ;

		   	return pLoad;
		  	 }
			Player pLoad; 
			return pLoad;
		  	 }


void SaveGame(Player _p1){//BEGIN    SAVE GAME FUNCTION


	Player p1 = LoadGameFromFile("savedGame1.txt");
	Player p2 = LoadGameFromFile("savedGame2.txt");
	Player p3 = LoadGameFromFile("savedGame3.txt");





	ofstream fout;
	int sure=0 , contWOSave=0; while(sure==0){
		ClearScreen();

		cout << " 0: Back" << endl;

		cout << " 1: " << p1.GetFirstName() << " " << p1.GetLastName();
		for(unsigned int i=0 ; i<(15 - p1.GetFirstName().size()-p1.GetLastName().size()) ; i++){cout << " ";}
		cout << p1.GetSuit();
		for(unsigned int i=0 ; i<(10-p1.GetSuit().size()) ; i++){cout << " ";}
		cout << " Level: " << p1.GetLevel() << endl;

		cout << " 2: " << p2.GetFirstName() << " " << p2.GetLastName();
		for(unsigned int i=0 ; i<(15 - p2.GetFirstName().size()-p2.GetLastName().size()) ; i++){cout << " ";}
		cout << p2.GetSuit();
		for(unsigned int i=0 ; i<(10-p2.GetSuit().size()) ; i++){cout << " ";}
		cout << " Level: " << p2.GetLevel() << endl;

		cout << " 3: " << p3.GetFirstName() << " " << p3.GetLastName();
		for(unsigned int i=0 ; i<(15 - p3.GetFirstName().size()-p3.GetLastName().size()) ; i++){cout << " ";}
		cout << p3.GetSuit();
		for(unsigned int i=0 ; i<(10-p3.GetSuit().size()) ; i++){cout << " ";}
		cout << " Level: " << p3.GetLevel() << endl << endl;

		cout << "Which file will you save to?" << endl;


		int saveTo = ChoiceCheck(3);


		if(saveTo==0){ClearScreen(); cout << " 0: Back" << endl << " 1: Yes" << endl << "Do you want to continue without saving?" << endl ; contWOSave=ChoiceCheck(1); if(contWOSave==1){break;}}

		else if(saveTo >0){
		ClearScreen();
		cout << " 0: Back" << endl;
		cout << " 1: Yes" << endl;
		cout << "Are you sure you want to overwrite this file?" << endl;
		sure = ChoiceCheck(1);
		if(sure==0){saveTo=0;}

		switch(saveTo){
						case 0:{break;}
						case 1:{fout.open("savedGame1.txt"); break;}
						case 2:{fout.open("savedGame2.txt"); break;}
						case 3:{fout.open("savedGame3.txt"); break;}
				} if (!fout.is_open()) {cout << "Could not open file saveGame1.txt." << endl ; sure=0 ;}

			if(sure==1){
					fout << _p1.GetFirstName() << endl;
					fout << _p1.GetLastName() << endl;
					fout << _p1.GetHighScore() << endl;
					fout << _p1.GetSuitNum() << endl;
					fout << _p1.GetLevel();
					fout.close();}}
	}}//END    SAVE GAME FUNCTION




Player LoadGame(){//BEGIN   LOAD GAME FROM ONE OF THREE FILES

	ClearScreen();

	Player p1 = LoadGameFromFile("savedGame1.txt");
	Player p2 = LoadGameFromFile("savedGame2.txt");
	Player p3 = LoadGameFromFile("savedGame3.txt");

	cout << " 0: Back" << endl;

	cout << " 1: " << p1.GetFirstName() << " " << p1.GetLastName();
	for(unsigned int i=0 ; i<(15 - p1.GetFirstName().size()-p1.GetLastName().size()) ; i++){cout << " ";}
	cout << p1.GetSuit();
	for(unsigned int i=0 ; i<(10-p1.GetSuit().size()) ; i++){cout << " ";}
	cout << " Level: " << p1.GetLevel() << endl;

	cout << " 2: " << p2.GetFirstName() << " " << p2.GetLastName();
	for(unsigned int i=0 ; i<(15 - p2.GetFirstName().size()-p2.GetLastName().size()) ; i++){cout << " ";}
	cout << p2.GetSuit();
	for(unsigned int i=0 ; i<(10-p2.GetSuit().size()) ; i++){cout << " ";}
	cout << " Level: " << p2.GetLevel() << endl;

	cout << " 3: " << p3.GetFirstName() << " " << p3.GetLastName();
	for(unsigned int i=0 ; i<(15 - p3.GetFirstName().size()-p3.GetLastName().size()) ; i++){cout << " ";}
	cout << p3.GetSuit();
	for(unsigned int i=0 ; i<(10-p3.GetSuit().size()) ; i++){cout << " ";}
	cout << " Level: " << p3.GetLevel() << endl << endl;

	int LoadChoice = ChoiceCheck(3);


	switch(LoadChoice){
	case 0:{ClearScreen() ; Player pLeave ; return pLeave;}
	case 1:{return p1;}
	case 2:{return p2;}
	case 3:{return p3;}
	}



	Player pLeave;
	return pLeave;
	}//END   LOAD GAME FROM ONE OF THREE FILES


	bool QueenHeal(Player _p1 , Player _p2){


				if(_p1.pQueen.heal[0] != 0){return 0;}

				cout << " 1: Yes" << endl ;
				cout << " 2: No" << endl ;
				cout << _p1.GetFirstName() << " " << _p1.GetLastName() << " do you want to use your queen's healing spell?" << endl;
				int qHeal = ChoiceCheck(2);

				if(qHeal==1){//BEGIN    CHOICE TO HEAL

					int PM2Heal = 0; while(PM2Heal==0){//BEGIN   HEAL CHOICE WHILE LOOP
					cout << " 0: Back" << endl;
					cout << " 1: King" << endl;
					cout << " 2: Queen" << endl;
					cout << " 3: Jack" << endl << endl;
					cout << _p1.GetFirstName() << " " << _p1.GetLastName() << " which party member will you heal?" << endl;
					PM2Heal = ChoiceCheck(3);

					switch(PM2Heal){//BEGIN   WHO TO HEAL SWITCH
					case 0:{return 0;}
					case 1:{
						Player testCase;
						if(_p1.pKing.GetHP() == testCase.pKing.GetHP()){cout << "Your king has full life." << endl ; PM2Heal=0 ; break;}
						else if(_p1.pKing.GetHP() == 0){cout << "Your king is already dead." << endl ; PM2Heal=0 ; break;}
						else{_p1.pQueen.heal[0] = _p1.pQueen.heal[1] ; //MOVE HEAL CARD INTO VISIBLE SPOT
						int lifeLost = testCase.pKing.GetHP() - _p1.pKing.GetHP(); //CHECK HOW MUCH LIFE THE KING HAS LOST
						if(lifeLost >=_p1.pQueen.heal[0]){_p1.pKing.SetHP(_p1.pKing.GetHP()+_p1.pQueen.heal[0]) ; lifeLost = _p1.pQueen.heal[0];}//IF KING HAS LOST MORE LIFE THAN THE HEAL GIVE ADD ALL HEAL POINTS TO LIFE
						else if(lifeLost <_p1.pQueen.heal[0]){_p1.pKing.SetHP(testCase.pKing.GetHP());}//IF THE KING HAS LOST LESS LIFE THAN THE HEAL FILL HIS LIFE TO MAX BUT NOT MORE

						_p1.pKing.SetHP(_p1.pKing.GetHP() + _p1.pQueen.heal[0]) ; PrintBoard(_p1 , _p2);
								cout << "Advisor " << _p1.GetLastName() << "'s queen healed the king for " << lifeLost << " HP.";
								cout << "Press enter to continue." << cin.get() ; return 1;} break;}

					case 2:{
						Player testCase;
						if(_p1.pQueen.GetHP() == testCase.pQueen.GetHP()){cout << "Your queen has full life." << endl ; PM2Heal=0 ; break;}
						else if(_p1.pQueen.GetHP() == 0){cout << "Your queen is already dead." << endl ; PM2Heal=0 ; break;}
						else{_p1.pQueen.heal[0] = _p1.pQueen.heal[1] ; //MOVE HEAL CARD INTO VISIBLE SPOT
						int lifeLost = testCase.pQueen.GetHP() - _p1.pQueen.GetHP(); //CHECK HOW MUCH LIFE THE QUEEN HAS LOST
						if(lifeLost >=_p1.pQueen.heal[0]){_p1.pQueen.SetHP(_p1.pQueen.GetHP()+_p1.pQueen.heal[0]) ; lifeLost = _p1.pQueen.heal[0];}//IF QUEEN HAS LOST MORE LIFE THAN THE HEAL GIVE ADD ALL HEAL POINTS TO LIFE
						else if(lifeLost <_p1.pQueen.heal[0]){_p1.pQueen.SetHP(testCase.pQueen.GetHP());}//IF THE QUEEN HAS LOST LESS LIFE THAN THE HEAL FILL HIS LIFE TO MAX BUT NOT MORE

						_p1.pQueen.SetHP(_p1.pQueen.GetHP() + _p1.pQueen.heal[0]) ; PrintBoard(_p1 , _p2);
								cout << "Advisor " << _p1.GetLastName() << "'s queen healed herself for " << lifeLost << " HP.";
								cout << "Press enter to continue." << cin.get() ; return 1;} break;}


					case 3:{
						Player testCase;
						if(_p1.pJack.GetHP() == testCase.pJack.GetHP()){cout << "Your jack has full life." << endl ; PM2Heal=0 ; break;}
						else if(_p1.pJack.GetHP() == 0){cout << "Your jack is dead." << endl ; PM2Heal=0 ; break;}
						else{_p1.pQueen.heal[0] = _p1.pQueen.heal[1] ; //MOVE HEAL CARD INTO VISIBLE SPOT
						int lifeLost = testCase.pJack.GetHP() - _p1.pJack.GetHP(); //CHECK HOW MUCH LIFE THE JACK HAS LOST
						if(lifeLost >=_p1.pQueen.heal[0]){_p1.pJack.SetHP(_p1.pJack.GetHP()+_p1.pQueen.heal[0]) ; lifeLost = _p1.pQueen.heal[0];}//IF JACK HAS LOST MORE LIFE THAN THE HEAL GIVE ADD ALL HEAL POINTS TO LIFE
						else if(lifeLost <_p1.pQueen.heal[0]){_p1.pJack.SetHP(testCase.pKing.GetHP());}//IF THE JACK HAS LOST LESS LIFE THAN THE HEAL FILL HIS LIFE TO MAX BUT NOT MORE
						_p1.pJack.SetHP(_p1.pJack.GetHP() + _p1.pQueen.heal[0]) ; PrintBoard(_p1 , _p2);
								cout << "Advisor " << _p1.GetLastName() << "'s queen healed the king for " << lifeLost << " HP.";
								cout << "Press enter to continue." << cin.get() ; return 1;} break;}
					}//END   WHO TO HEAL SWITCH
					}//END   HEAL CHOICE WHILE LOOP
					}//END   CHOICE TO HEAL
					return 0;

					}//END   QUEEN HEAl FUNCTON



	bool AttackMenu(Player& _p1 , Player& _p2 , int partyMemberNumber){

		string pMName;
		switch(partyMemberNumber){
		case 1: {pMName = "king"; break;}
		case 2: {pMName = "queen"; break;}
		case 3: {pMName = "jack"; break;}
		}

		ClearScreen(); PrintBoard(_p1 , _p2);

		int attackChoice=-1;
		while(attackChoice == -1){
		cout << " 0: Previous Menu" << endl;
		cout << " 1: King" << endl;
		cout << " 2: Queen" << endl;
		cout << " 3: Jack" << endl << endl;
		cout << "Who will your " << pMName << " attack? Enter a number: ";
		cin >> attackChoice;
		if(isdigit(attackChoice) || attackChoice<1 || attackChoice>3){ClearScreen(); PrintBoard(_p1 , _p2) ; cout << "Not a valid attack." << endl << "Please try again." << endl; cin.clear() ; cin.ignore() ; attackChoice = 0;}}

		if(attackChoice==0){return 0;}//EXIT OPTION

			switch(attackChoice){
			case 1:{if(_p2.pKing.GetHP()<=0){ cout << _p2.firstName << " " << _p2.lastName << "'s king is dead." << endl << "Enter another number: "; attackChoice=-1;}break;}//CHECK IF KING IS ALIVE
			case 2:{if(_p2.pQueen.GetHP()<=0){ cout << _p2.firstName << " " << _p2.lastName << "'s queen is dead." << endl << "Enter another number: "; attackChoice=-1;}break;}//CHECK IF QUEEN IS ALIVE
			case 3:{if(_p2.pJack.GetHP()<=0){ cout << _p2.firstName << " " << _p2.lastName << "'s jack is dead." << endl << "Enter another number: "; attackChoice=-1;}break;}//CHECK IF JACK IS ALIVE
			}

			string victim ; switch(attackChoice){case 1: {victim = "king"; break;} case 2: {victim = "queen"; break;} case 3: {victim = "jack"; break;}}//WHO IS BEING ATTACKED, FOR STRING OUTPUT

		if((attackChoice==1 && _p2.pKing.GetHP()>0) || (attackChoice==2 && _p2.pQueen.GetHP()>0) || (attackChoice==3 && _p2.pJack.GetHP()>0)){//BEGIN    IF THE ATTACKCHOICE IS ALIVE CONTINUE ATTACK KING CASE
				cout << "Enter a card to attack with: ";
				int damage = -1;
				while(damage == -1){//BEGIN   INPUT VALIDATION WHILE LOOP
				cin >> damage;
				if(isdigit(damage) || damage<1 || damage>10){ cout << "Not a valid attack." << endl << "Please try again." << endl; cin.clear() ; cin.ignore(); damage = -1;}
				if(_p1.numberCards[damage-1] == -1){ cout << "You do not have that card." << endl << "Enter a different card number:";}} //END   INPUT VALIDATION WHILE LOOP

				if(partyMemberNumber==1){ _p1.pKing.dualWield[1]=0 ; _p1.pKing.dualWield[3]=damage ; _p1.numberCards[damage-1] = -1 ; _p1.EmptyHand();}
				if(partyMemberNumber==2){ _p1.pKing.dualWield[0]=0 ; _p1.pKing.dualWield[2]=damage ; _p1.numberCards[damage-1] = -1 ; _p1.EmptyHand();}
				if(partyMemberNumber==3){ _p1.pJack.counterAttack[0]=0 ; _p1.pJack.counterAttack[1]=damage ; _p1.numberCards[damage-1] = -1 ; _p1.EmptyHand();}

				if(_p2.pJack.counterAttack[0]==0){ClearScreen(); PrintBoard(_p1 , _p2);}


				if(_p2.pJack.counterAttack[1]>0){
					int CA=-1 ; while(CA==-1){
					cout << " 1: Yes" << endl;
					cout << " 2: No" << endl << endl;
					cout << "Does " << _p2.firstName << " " << _p2.lastName << " want to block and counter? "; cin.clear();
					cin >> CA;
					if(isdigit(CA) || CA<1 || CA>2){ cout << "Invalid input." << endl ; cin.ignore() ; cin.clear(); CA=-1 ; ClearScreen(); PrintBoard(_p1 , _p2);}}

					switch(CA){//BEGIN   COUNTER ATTACK CHOICE FOR KING ATTACK
					case 1: {//BEGIN   COUNTER KING ATTACK
						_p2.pJack.counterAttack[0] = _p2.pJack.counterAttack[1]; _p2.pJack.counterAttack[1]=0;

						switch(partyMemberNumber){//BEGIN   ACTION BASED ON PARTY MEMBER TAKING IT
						case 1:{//KING
						_p1.pKing.dualWield[1] = _p1.pKing.dualWield[3]; _p1.pKing.dualWield[3]=0;
						_p1.pKing.SetHP(_p1.pKing.GetHP() - _p2.pJack.counterAttack[0]);}

						case 2:{//QUEEN
						_p1.pKing.dualWield[0] = _p1.pKing.dualWield[2]; _p1.pKing.dualWield[2]=0;
						_p1.pQueen.SetHP(_p1.pQueen.GetHP() - _p2.pJack.counterAttack[0]);}

						case 3:{//JACK
						_p1.pJack.counterAttack[0] = _p1.pJack.counterAttack[1]; _p1.pJack.counterAttack[1]=0;
						_p1.pJack.SetHP(_p1.pJack.GetHP() - _p2.pJack.counterAttack[0]);}
						}//END   ACTION BASED ON PARTY MEMBER TAKING IT

						ClearScreen(); PrintBoard(_p1 , _p2);
						cout << _p1.firstName << " " << _p1.lastName << "'s " << pMName << "'s attack was blocked and countered causing " << _p2.pJack.counterAttack[0] << " damage." << endl;
						cout << "Press enter to continue.";
						cin.ignore() ; cin.get();
						_p2.pJack.counterAttack[0]=-1;
						switch(partyMemberNumber){ case 1:{ _p1.pKing.dualWield[1] = -1 ; } case 2:{ _p1.pKing.dualWield[0] =-1 ; } case 3:{ _p1.pJack.counterAttack[0] =-1 ; } }//DISCARD
						ClearScreen(); PrintBoard(_p1 , _p2);
						return 1;}//END   JACK COUNTER ATTACK

					case 2: {//BEGIN    ATTACK HITS
						switch(partyMemberNumber){//BEGIN    SWITCH FOR ATTACKERS (_p1) PARTY MEMBER

						case 1:{switch(attackChoice){//BEGIN   KING ATTACKS (p2) PARTY MEMBER SWITCH
									case 1: {_p2.pKing.SetHP(_p2.pKing.GetHP()-damage) ;  break;}
									case 2: {_p2.pQueen.SetHP(_p2.pQueen.GetHP()-damage) ; break;}
									case 3: {_p2.pJack.SetHP(_p2.pJack.GetHP()-damage) ; break;}}

						_p1.pKing.dualWield[1] = _p1.pKing.dualWield[3];
						ClearScreen(); PrintBoard(_p1 , _p2) ;
						cout << _p2.firstName << " " << _p2.lastName << "'s " << victim << " is hit for " << damage << " damage."; _p1.pKing.dualWield[1] = -1 ; _p1.pKing.dualWield[3] = 0;
						}//END   KING ATTACKS (p2) PARTY MEMBER SWITCH

						case 2:{switch(attackChoice){//BEGIN   QUEEN ATTACKS (p2) PARTY MEMBER SWITCH
									case 1: {_p2.pKing.SetHP(_p2.pKing.GetHP()-damage) ;  break;}
									case 2: {_p2.pQueen.SetHP(_p2.pQueen.GetHP()-damage) ; break;}
									case 3: {_p2.pJack.SetHP(_p2.pJack.GetHP()-damage) ; break;}}

						_p1.pKing.dualWield[0] = _p1.pKing.dualWield[2];
						ClearScreen(); PrintBoard(_p1 , _p2) ;
						cout << _p2.firstName << " " << _p2.lastName << "'s " << victim << " is hit for " << damage << " damage."; _p1.pKing.dualWield[0] = -1 ; _p1.pKing.dualWield[2] = 0;
						}//END   QUEEN ATTACKS (p2) PARTY MEMBER SWITCH

						case 3:{switch(attackChoice){//BEGIN   JACK ATTACKS (p2) PARTY MEMBER SWITCH
									case 1: {_p2.pKing.SetHP(_p2.pKing.GetHP()-damage) ;  break;}
									case 2: {_p2.pQueen.SetHP(_p2.pQueen.GetHP()-damage) ; break;}
									case 3: {_p2.pJack.SetHP(_p2.pJack.GetHP()-damage) ; break;}}

						_p1.pJack.counterAttack[0] = _p1.pJack.counterAttack[1];
						ClearScreen(); PrintBoard(_p1 , _p2) ;
						cout << _p2.firstName << " " << _p2.lastName << "'s " << victim << " is hit for " << damage << " damage."; _p1.pJack.counterAttack[0] = -1 ; _p1.pJack.counterAttack[1] = 0;
						}//END   QUEEN ATTACKS (p2) PARTY MEMBER SWITCH
						}//END    SWITCH FOR ATTACKERS (_p1) PARTY MEMBER
						cout << endl << "Press enter to continue." ; cin.get() ; return 1;}}}//END  COUNTER ATTACK CHOICE FOR KING ATTACK

				else{//BEGIN   NO JACK COUNTER, ATTACK HITS
					switch(attackChoice){
					case 1: {_p2.pKing.SetHP(_p2.pKing.GetHP()-damage) ; break;}
					case 2: {_p2.pQueen.SetHP(_p2.pQueen.GetHP()-damage) ; break;}
					case 3: {_p2.pJack.SetHP(_p2.pJack.GetHP()-damage) ; break;}
					}

					switch(partyMemberNumber){
					case 1:{_p1.pKing.dualWield[1] = _p1.pKing.dualWield[3] ; ClearScreen(); PrintBoard(_p1 , _p2) ; _p1.pKing.dualWield[1] = -1 ; _p1.pKing.dualWield[3] = 0; break;}
					case 2:{_p1.pKing.dualWield[0] = _p1.pKing.dualWield[2] ; ClearScreen(); PrintBoard(_p1 , _p2) ; _p1.pKing.dualWield[0] = -1 ; _p1.pKing.dualWield[2] = 0; break;}
					case 3:{_p1.pJack.counterAttack[0] = _p1.pJack.counterAttack[1] ; ClearScreen(); PrintBoard(_p1 , _p2) ; _p1.pJack.counterAttack[0] = -1 ; _p1.pJack.counterAttack[1] = 0; break;}
					}
					cout << _p2.firstName << " " << _p2.lastName << "'s " << victim << " is hit for " << damage << " damage." << endl;
					cout << "Press enter to continue." ; cin.ignore() ; cin.clear() ; cin.get();}//END   NO JACK COUNTER, ATTACK HITS
					}//END    IF THE ATTACK CHOICE IS ALIVE CONTINUE ATTACK KING CASE
					return true;}//END    ATTACK FUNCTION





	bool DualWield(Player& _p1 , Player& _p2){

					ClearScreen(); PrintBoard(_p1 , _p2);

					int right=-1; while(right==-1 ){//BEGIN   DUAL WIELD RIGHT HAND ATTACK INPUT AND VALIDATION
					cout << " Enter a card to attack with in your right hand: ";
					cin >>right;
					if(isdigit(right) || right<0 || right > 10){ cout << "Invalid input. Please try again."; cin.clear() ; right=-1;}
					else if(_p1.numberCards[right-1] != right){ cout << "You do not have that card. Please try again."; cin.clear() ; right=-1;}} //END   DUAL WIELD RIGHT HAND ATTACK INPUT AND VALIDATION

					_p1.pKing.dualWield[3] = right ; _p1.pKing.dualWield[1] = 0 ; _p1.numberCards[right-1] = -1 ; ClearScreen() ; PrintBoard(_p1 , _p2);

					int left=-1; while(left==-1 ){//BEGIN   DUAL WIELD LEFT HAND ATTACK INPUT AND VALIDATION
					cout << " Enter a card to attack with in your left hand: ";
					cin >>left;
					if(isdigit(left) || left<0 || left > 10){ cout << "Invalid input. Please try again."; cin.clear() ; left=-1;}
					else if(_p1.numberCards[left-1] != left){ cout << "You do not have that card. Please try again."; cin.clear() ; left=-1;}} //END   DUAL WIELD LEFT HAND ATTACK INPUT AND VALIDATION
					_p1.pKing.dualWield[2] = left ; _p1.pKing.dualWield[0] = 0 ; _p1.numberCards[left-1] = -1 ; ClearScreen() ; PrintBoard(_p1 , _p2);


					int dualAC=-1;
					while(dualAC == -1){
					cout << " 0: Previous Menu" << endl;
					cout << " 1: King" << endl;
					cout << " 2: Queen" << endl;
					cout << " 3: Jack" << endl << endl;
					cout << "Who will your king attack twice? Enter a number: ";
					cin >> dualAC;
					cout << "TEST";


					if(isdigit(dualAC) || dualAC<1 || dualAC>3){ClearScreen(); PrintBoard(_p1 , _p2) ; cout << "Not a valid attack." << endl << "Please try again." << endl; cin.clear() ; cin.ignore() ; dualAC = -1;}}



					string victim;
					switch(dualAC){//BEGIN   DUAL WIELD ATTACK CHOICE MENU OPTIONS
					case 0:{return 0;}//EXIT OPTION
					case 1:{victim = "king"; break;}
					case 2:{victim = "queen"; break;}
					case 3:{victim = "jack"; break;}}

						if(_p2.pKing.GetHP()<=0){ cout << _p2.firstName << " " << _p2.lastName << "'s " << victim << " is dead." << endl << "Enter another number: "; dualAC=-1;}//CHECK IF ALIVE

						else if(_p2.pKing.GetHP()>0){//BEGIN    IF ALIVE CONTINUE KING ATTACK

							if(_p2.pJack.counterAttack[0]==0){
								int CA=-1;
								while(CA==-1){//COUNTER ATTACK FIRST HIT (RIGHT)
								cout << " 1: Yes" << endl;
								cout << " 2: No" << endl << endl;
								cout << "Does " << _p2.firstName << " " << _p2.lastName << " want to block and counter the first hit? "; cin.clear();
								cin >> CA;
								if(isdigit(CA) || CA<1 || CA>2){ cout << "Invalid input." << endl ; cin.ignore() ; cin.clear(); CA=-1 ; ClearScreen(); PrintBoard(_p1 , _p2);}}

								switch(CA){//BEGIN   COUNTER ATTACK CHOICE
								case 1: {//BEGIN   COUNTER ATTACK
									_p2.pJack.counterAttack[0] = _p2.pJack.counterAttack[1]; _p2.pJack.counterAttack[1]=0;
									_p1.pKing.dualWield[1] = _p1.pKing.dualWield[3]; _p1.pKing.dualWield[3]=0;
									_p1.pKing.dualWield[0] = _p1.pKing.dualWield[2]; _p1.pKing.dualWield[2]=0;
									_p1.pKing.SetHP(_p1.pKing.GetHP() - _p2.pJack.counterAttack[0]);
									_p2.pJack.SetHP(_p2.pJack.GetHP() - _p1.pKing.dualWield[0]);
									ClearScreen(); PrintBoard(_p1 , _p2);
									cout << _p1.firstName << " " << _p1.lastName << "'s king's first attack was blocked and countered causing " << _p2.pJack.counterAttack[0] << " damage." << endl;
									cout << _p1.firstName << " " << _p1.lastName << "'s king's second attack hits " << _p2.firstName << "'s jack causing " << _p1.pKing.dualWield[0] << " damage." << endl;
									cout << "Press enter to continue.";
									cin.ignore() ; cin.get();
									_p2.pJack.counterAttack[0]=0;
									_p1.pKing.dualWield[0]=-1;
									_p1.pKing.dualWield[1]=0;
									_p1.pKing.dualWield[2]=-1;
									_p1.pKing.dualWield[3]=0;
									ClearScreen(); PrintBoard(_p1 , _p2);}//END   COUNTER ATTACK
									break;

								case 2:{//NO COUNTER ATTACK HIT RIGHT
									_p1.pKing.dualWield[1] = _p1.pKing.dualWield[3];
									switch(dualAC){
											case 1:{_p2.pKing.SetHP(_p2.pKing.GetHP()-_p1.pKing.dualWield[0]) ; break;}//KING
											case 2:{_p2.pQueen.SetHP(_p2.pQueen.GetHP()-_p1.pKing.dualWield[0]) ; break;}//QUEEN
											case 3:{_p2.pJack.SetHP(_p2.pJack.GetHP()-_p1.pKing.dualWield[0]) ; break;}//JACK
											}ClearScreen() ; PrintBoard(_p1 , _p2);

											cout << _p1.firstName << " " << _p1.lastName << "'s king's first attack hits " << _p2.firstName << "'s " << victim << " causing " << _p1.pKing.dualWield[1] << " damage." << endl;
											cout << endl;

											int CB=-1;
											while(CB==-1){//COUNTER ATTACK FIRST HIT (RIGHT)
											cout << " 1: Yes" << endl;
											cout << " 2: No" << endl << endl;
											cout << "Does " << _p2.firstName << " " << _p2.lastName << " want to block and counter the seond hit? "; cin.clear();
											cin >> CB;
											if(isdigit(CB) || CB<1 || CB>2){ cout << "Invalid input." << endl ; cin.ignore() ; cin.clear(); CA=-1 ; ClearScreen(); PrintBoard(_p1 , _p2);}}

												switch(CB){//BEGIN   COUNTER ATTACK CHOICE
												case 1: {//BEGIN   COUNTER ATTACK
													_p2.pJack.counterAttack[0] = _p2.pJack.counterAttack[1]; _p2.pJack.counterAttack[1]=0;
													_p1.pKing.dualWield[0] = _p1.pKing.dualWield[2]; _p1.pKing.dualWield[2]=0;
													_p1.pKing.SetHP(_p1.pKing.GetHP() - _p2.pJack.counterAttack[0]);
													_p2.pJack.SetHP(_p2.pJack.GetHP() - _p1.pKing.dualWield[0]);
													ClearScreen(); PrintBoard(_p1 , _p2);
													cout << _p1.firstName << " " << _p1.lastName << "'s king's second attack was blocked and countered causing " << _p2.pJack.counterAttack[0] << " damage." << endl;
													cout << "Press enter to continue.";
													cin.ignore() ; cin.get();
													_p2.pJack.counterAttack[0]=0;
													_p1.pKing.dualWield[0]=-1;
													_p1.pKing.dualWield[1]=0;
													ClearScreen(); PrintBoard(_p1 , _p2);}//END   COUNTER ATTACK
													break;

											case 2:{//NO COUNTER ATTACK HIT RIGHT
												_p1.pKing.dualWield[0] = _p1.pKing.dualWield[1];
												switch(dualAC){
														case 1:{_p2.pKing.SetHP(_p2.pKing.GetHP()-_p1.pKing.dualWield[0]) ; break;}//KING
														case 2:{_p2.pQueen.SetHP(_p2.pQueen.GetHP()-_p1.pKing.dualWield[0]) ; break;}//QUEEN
														case 3:{_p2.pJack.SetHP(_p2.pJack.GetHP()-_p1.pKing.dualWield[0]) ; break;}//JACK
														}ClearScreen() ; PrintBoard(_p1 , _p2);

														cout << _p1.firstName << " " << _p1.lastName << "'s king's second attack hits " << _p2.firstName << "'s " << victim << " causing " << _p1.pKing.dualWield[0] << " damage." << endl;
														cout << endl;}}}}}

							else if(_p2.pJack.counterAttack[0]!=0){//NO COUNTER ATTACK BOTH ATTACKS HIT

								_p1.pKing.dualWield[0] = _p1.pKing.dualWield[2] ; _p1.pKing.dualWield[2]=0;
								_p1.pKing.dualWield[1] = _p1.pKing.dualWield[3] ; _p1.pKing.dualWield[3]=0;
								switch(dualAC){
											case 1:{_p2.pKing.SetHP(_p2.pKing.GetHP()-_p1.pKing.dualWield[0] -_p1.pKing.dualWield[1]) ; break;}//KING
											case 2:{_p2.pQueen.SetHP(_p2.pQueen.GetHP()-_p1.pKing.dualWield[0] -_p1.pKing.dualWield[1]) ; break;}//QUEEN
											case 3:{_p2.pJack.SetHP(_p2.pJack.GetHP()-_p1.pKing.dualWield[0] - _p1.pKing.dualWield[1]) ; break;}//JACK
										}ClearScreen() ; PrintBoard(_p1 , _p2);
										cout << _p1.firstName << " " << _p1.lastName << "'s king's first attack hits " << _p2.firstName << "'s " << victim << " causing " << _p1.pKing.dualWield[1] << " damage." << endl;
										cout << _p1.firstName << " " << _p1.lastName << "'s king's second attack hits " << _p2.firstName << "'s " << victim << " causing " << _p1.pKing.dualWield[0] << " damage." << endl;
										cout << "Press enter to continue.";
										cin.ignore() ; cin.get();
										_p1.pKing.dualWield[0] = -1;
										_p1.pKing.dualWield[1]= -1;

										}}
									return false;
								}//END   DUALWIELD MENU FUNCTION




	bool KingMenu(Player& _p1 , Player& _p2){ //BEGIN   KING'S MENU FUNCTION

		ClearScreen();

		PrintBoard(_p1 , _p2); cout << endl;
		int kingMove = 0 , pMenu = 0;
		while(pMenu==0){//BEGIN   EXIT MENU LOOP
		pMenu++;
		while(kingMove==0){//BEGIN   PRINT MENU AND INPUT VALIDATION LOOP
		cout << " 0: Previous Menu" << endl;
		cout << " 1: Attack" << endl;
		cout << " 2: Dual Wield" << endl << endl;
		cout << _p1.firstName << " " << _p1.lastName << ", Enter a number choice: ";
		cin >> kingMove;
		if(isdigit(kingMove) || kingMove<0 || kingMove>2){ cout << "Invalid Input."; kingMove=-1 ; ClearScreen(); }}//END   PRINT MENU AND INPUT VALIDATION LOOP

		switch(kingMove){//BEGIN   ATTACK OR SPECIAL SWITCH
		case 0:{return 0;}//EXIT OPTION
		case 1:{_p1.pKing.canMove=AttackMenu(_p1 , _p2 , 1); return _p1.pKing.canMove;}// ATTACK CHOICE CASE




		case 2:{//BEGIN   KING DUAL WIELD /* _p1.pKing.DualWield(); */
			_p1.pKing.canMove = DualWield(_p1 , _p2);
			return _p1.pKing.canMove;
		}}}
		return _p1.pKing.canMove;
	}






	bool QueenMenu(Player& _p1 , Player& _p2){ //BEGIN   QUEEN'S MENU FUNCTION

		ClearScreen();
		PrintBoard(_p1 , _p2); cout << endl;

		int queenMove = 0 , pMenu = 0;
		while(pMenu==0){//BEGIN   EXIT MENU LOOP
		pMenu++;
		while(queenMove==0){//BEGIN   PRINT MENU AND INPUT VALIDATION LOOP
		cout << " 0: Previous Menu" << endl;
		cout << " 1: Attack" << endl;
		cout << " 2: Heal" << endl << endl;
		cout << _p1.firstName << " " << _p1.lastName << ", Enter a number choice: ";
		cin >> queenMove;
		if(isdigit(queenMove) || queenMove<0 || queenMove>2){ cout << "Invalid Input."; queenMove=-1 ; ClearScreen(); }}//END   PRINT MENU AND INPUT VALIDATION LOOP

		switch(queenMove){//BEGIN   ATTACK OR SPECIAL SWITCH
		case 0:{return 0;}//EXIT OPTION
		case 1:{return AttackMenu(_p1 , _p2 , 2);}
		case 2:{return QueenHeal(_p1 , _p2);}}//END   ATTACK OR SPECIAL SWITCH
			}//END   EXIT MENU LOOP
			return 0;
			}//END   QUEEN'S MENU FUNCTION



	bool JackMenu(Player& _p1 , Player& _p2){ //BEGIN   QUEEN'S MENU FUNCTION

		ClearScreen();
		PrintBoard(_p1 , _p2); cout << endl;

		int jackMove = 0 , pMenu = 0;
		while(pMenu==0){//BEGIN   EXIT MENU LOOP
		pMenu++;
		while(jackMove==0){//BEGIN   PRINT MENU AND INPUT VALIDATION LOOP
		cout << " 0: Previous Menu" << endl;
		cout << " 1: Attack" << endl;
		cout << " 2: Block and Counter-Attack" << endl << endl;
		cout << _p1.firstName << " " << _p1.lastName << ", Enter a number choice: ";
		cin >> jackMove;
		if(isdigit(jackMove) || jackMove<0 || jackMove>2){ cout << "Invalid Input."; jackMove=-1 ; ClearScreen(); }}//END   PRINT MENU AND INPUT VALIDATION LOOP

		switch(jackMove){//BEGIN   ATTACK OR SPECIAL SWITCH
		case 0:{return 0;}//EXIT OPTION
		case 1:{if(AttackMenu(_p1 , _p2 , 3)==1){_p1.pJack.canMove=1; return 1;} else{return 0;}}

		case 2:{bool cCheck = _p1.Counter() ; if(cCheck==1){ClearScreen() ; PrintBoard(_p1 , _p2) ; _p1.pJack.canMove=1 ; return _p1.pKing.canMove;} else{return 0;}}

			}//END   ATTACK OR SPECIAL SWITCH
			}//END   EXIT MENU LOOP
			return 0;
			}//END   JACK'S MENU FUNCTION







	Player LoadComp(Player _p1){//BEGIN   LOAD COMPUTER PLAYER PROFILE FUNCTION
		Player Computer;
//		cout << "TEST" << _p1.GetSuitNum() << " " << _p1.GetLevel() << " " << ((_p1.GetSuitNum()+_p1.GetLevel())%4) << endl;
		switch((_p1.GetSuitNum()+_p1.GetLevel())%4){//USES THE PLAYERS SUIT AND THEIR LEVEL TO CREATE THE CORRECT COMPUTER OPPONENT.
		case 0: {Computer.SetFirstName("Sultanate of") ; Computer.SetLastName("Spades") ; Computer.SetSuit(4); break;}
		case 1: {Computer.SetFirstName("County of") ; Computer.SetLastName("Clubs") ; Computer.SetSuit(1); break;}
		case 2: {Computer.SetFirstName("Duchy of") ; Computer.SetLastName("Diamonds") ; Computer.SetSuit(2); break;}
		case 3: {Computer.SetFirstName("March of") ; Computer.SetLastName("Hearts") ; Computer.SetSuit(3); break;}
		Computer.SetTitle();
		}return Computer;}//END   LOAD COMPUTER PLAYER PROFILE FUNCTION






	int FirstTurn(Player& _p1 , Player& _p2){//BEGIN    FIRST TURN FUNCTION


		using namespace std::this_thread;
		using namespace std::chrono;

		int sum1 = 0 , sum2 = 0;

		_p1.cardSet=0;;//FLIP CARDS OVER FOR FIRST TURN SELECTION
		_p2.cardSet=0;//FLIP CARDS OVER FOR FIRST TURN SELECTION


		PrintBoard(_p1 , _p2) ; cout << endl ; //PRINT FIRST TURN BOARD

		int goesFirst=0; //BEGIN   FIRST TURN WHILE LOOP BOTH PLAYERS (w)
		while(goesFirst==0){ for( int w=1 ; w<3 ; w++){ int firstChoice=0;

		if(w==1 && _p2.IsHuman()){ cout << _p1.firstName << " " << _p1.lastName << ", Pick a card from " << _p2.lastName << "'s hand by entering a number between 1 and 10: "; }
		else if(w==1 && !_p2.IsHuman()){ cout << "Advisor " <<  _p1.lastName << ", Pick a card from the " << _p2.GetFirstName() << " " << _p2.GetLastName() << "' hand by entering a number between 1 and 10: "; }
		else if(w==2 && _p2.IsHuman()){ cout << _p2.firstName << " " << _p2.lastName << ", Pick a card from " << _p1.lastName << "'s hand by entering a number between 1 and 10: "; }
		else if(w==2 && !_p2.IsHuman()){firstChoice = _p2.RandomChoice(10);}



		if(w==1 || (w==2 && _p2.IsHuman())){ while(firstChoice==0){ cin >> firstChoice; //INPUT PLAYER CARD CHOICE FOR FIRST ROUND SELECTION

		if(isdigit(firstChoice) || firstChoice<1 || firstChoice>10){//BEGIN   INPUT VALIDATION
		cout << "Choice is not a number between 1 and 10." << endl ; cout << "Please try again." << endl ; firstChoice=0 ; cin.clear() ; cin.ignore();}}}//END   INPUT VALIDATION

		if(w==1){_p2.emptyCards[firstChoice-1] = _p1.RandomChoice(10);}

		if(w==2){_p1.emptyCards[firstChoice-1] = _p2.RandomChoice(10);}


		}//END   FIRST TURN WHILE LOOP BOTH PLAYERS (w)

		ClearScreen();


		PrintBoard(_p1 , _p2);//PRINT FIRST TURN SELECTION BOARD (REVEAL THE CARDS AFTER PICKING AT RANDOM)

		_p1.turnTotal++ ; _p2.turnTotal++; _p1.cardSet=0 ; _p2.cardSet=0;


		sum1 = 0 , sum2 = 0;//BEGIN   CHECK FIRST TURN CARD PICK TO SEE WHO PICKED HIGHER CARD VALUE AND GOES FIRST (PLAYER WITH LOWER NUMBER ON THEIR SIDE GOES FIRST)
		for(int q=0 ; q<10 ; q++){sum1 = sum1 + _p1.emptyCards[q]; sum2 = sum2 + _p2.emptyCards[q];} //PLAYER 1'S CARD CHOICE (ALL CARDS 0 EXCEPT CHOICE SO SUM OF ALL CARDS IS JUST THE CHOICE)
		for(int j=0 ; j<10 ; j++){_p1.emptyCards[j]=0; _p2.emptyCards[j]=0;} //PLAYER 2'S CARD CHOICE (ALL CARDS 0 EXCEPT CHOICE SO SUM OF ALL CARDS IS JUST THE CHOICE)

		if(sum1==sum2){cout << "Tie. Try again." ; goesFirst=0;}
		else if(sum1<sum2){goesFirst=1;}
		else if(sum1>sum2){goesFirst=2;}
		}//END   CHOOSE WHETHER TO START WITH COUNTER

		if(sum1 != sum2){
		cout << " 0: Quit" << endl;
		cout << " 1: Yes" << endl;
		cout << " 2: No"  << endl << endl;

		if((sum1 < sum2) && _p2.IsHuman()){cout << _p1.firstName << " " << _p1.lastName << " goes first. Will " << _p2.firstName << " " << _p2.lastName << " set a jack counter attack?" << endl << "Enter a number choice: ";}
		else  if((sum1 < sum2) && (!_p2.IsHuman())){cout << _p1.firstName << " " << _p1.lastName << " goes first. Will " << _p2.firstName << " " << _p2.lastName << " set a jack counter attack?" << endl << "Enter a number choice: " ;
		sleep_until(system_clock::now() + 3s); cout << _p2.firstName << " " << _p2.lastName << " is thinking..." << endl ;  sleep_until(system_clock::now() + 3s);}
		else if(sum1 > sum2){cout << _p2.firstName << " " << _p2.lastName << " goes first. Will " << _p1.firstName << " " << _p1.lastName << " set a jack counter attack?" << endl << "Enter a number choice: " ;}
		}

		int jDefend = 0;//BEGIN   JACK FIRST DEFEND

		if((goesFirst==1 && _p2.IsHuman()) || goesFirst==2){jDefend=ChoiceCheck(2);}



		if(goesFirst==1){//BEGIN  PLAYER 1 GOES FIRST PLAYER 2 CAN PREPARE TO COUNTER

			if(!_p2.IsHuman()){jDefend = _p2.RandomChoice(2); //BEGIN    COMPUTER JACK SET
				if(jDefend==1){ _p2.pJack.counterAttack[0] = 0 ; _p2.pJack.counterAttack[1] = _p2.RandomChoice(10) ; _p2.numberCards[_p2.pJack.counterAttack[1]-1]=-1 ;  _p2.EmptyHand() ; PrintBoard(_p1 , _p2);
					cout << endl << _p2.GetFirstName() << " " << _p2.GetLastName() << " is prepared to counter-attack." << endl << "Press enter to continue." ; cin.get() ;}
				else if(jDefend==2){cout <<  _p2.GetFirstName() << " " << _p2.GetLastName() << " has chosen not to prepare a counter-attack." << endl  << "Press enter to continue." ; cin.get() ; return goesFirst;}}//END    COMPUTER JACK SET

			if(_p2.IsHuman()){ while(jDefend == 0){cin.ignore() ; cin.clear() ; cin >> jDefend;//BEGIN   HUMAN PLAYER 2
					if(jDefend==0){return 0;}//EXIT OPTION
					else if(isdigit(jDefend) || jDefend<0 || jDefend>2){ cout << "Entry is not in range." << endl << "Please try again: "; jDefend=0 ; cin.clear() ; }}

			if(jDefend == 1){ ClearScreen(); _p2.cardSet=1 ; _p1.cardSet=0 ; PrintBoard(_p2 , _p1) ; int cC=_p2.Counter() ; if(cC==0){ jDefend=0;} else if(cC==1){ return goesFirst;}}
			if(jDefend == 2){cout << _p2.GetFirstName() << " " << _p2.GetLastName() << " chose not to prepare a counter-attack." <<endl << "Press enter to continue." ; cin.ignore() ; cin.get() ; return goesFirst;}
			}
		}//END  PLAYER 1 GOES FIRST PLAYER 2 CAN PREPARE TO COUNTER

		if(goesFirst==2){//BEGIN  PLAYER 2 GOES FIRST PLAYER 1 CAN PREPARE TO COUNTER
			while(jDefend == 0){ cin >> jDefend;
				 if(jDefend==0){return 0;}//EXIT OPTION
				 else if(isdigit(jDefend) || jDefend<0 || jDefend>2){ cout << "Entry is not in range." << endl << "Please try again: "; jDefend=0 ; cin.clear() ; cin.ignore();}}
			if(jDefend == 1){ ClearScreen(); _p1.cardSet=1 ; _p2.cardSet=0; PrintBoard(_p1 , _p2) ;  int cC=_p1.Counter() ;
							if(cC==0){ jDefend=0;}
							else if(cC==1){_p1.EmptyHand() ;  ClearScreen() ;  PrintBoard(_p1 , _p2)  ; cout << "Press enter to continue." ; cin.ignore() ;cin.get() ;  return goesFirst;}}
			if(jDefend == 0){  return goesFirst;}}//END  PLAYER 2 GOES FIRST PLAYER 1 CAN PREPARE TO COUNTER

			return goesFirst;}//END   FIRST TURN FUNCTION





	bool PlayerTurn(Player& p1 , Player& p2){//BEGIN    STANDARD PLAYER TURN FUNCION

		Player SwapPlayer;//SWAPS ADOUND THE PLAYERS BASED ON WHOSE TURN IT IS. SWAPS BACK AT END BY CHECKING IF IT IS THE SWAP PLAYER TURN.
		if(p1.turn==0){SwapPlayer = p2 ; p2 = p1 ; p1 = SwapPlayer;}

		int p1MoveNum=-1;

		while(p1MoveNum==-1){//BEGIN    PLAYER MOVE MENU

		ClearScreen() ; PrintBoard(p1 , p2) ;


		cout << endl;
		cout << " 0: Quit" << endl;
		if(p1.pKing.canMove == 1){ cout << " 1: King";} else{ for( int s=0 ; s<10 ; s++){cout << p1.GetSuitCode();}} cout << endl;
		if(p1.pQueen.canMove == 1){ cout << " 2: Queen";} else{ for( int s=0 ; s<10 ; s++){cout << p1.GetSuitCode();}} cout << endl;
		if(p1.pJack.canMove == 1){ cout << " 3: Jack";} else{ for( int s=0 ; s<10 ; s++){cout << p1.GetSuitCode();}} cout << endl << endl;
		cout << "Which party member should act?" << endl;

		p1MoveNum = ChoiceCheck(3);

		if(p1MoveNum==0) {return 0;}
		else if(p1MoveNum==1){if(p1.pKing.canMove == 0){cout << "The king can't move again this turn." << endl << "Press enter to continue."; cin.get() ; p1MoveNum=-1 ;} else{p1.pKing.canMove = !KingMenu(p1 , p2)  ;  p1MoveNum=-1 ; }}
		else if(p1MoveNum==2){if(p1.pQueen.canMove == 0){cout << "The queen can't move again this turn." << endl << "Press enter to continue."; cin.get() ; p1MoveNum=-1;} else{p1.pQueen.canMove = !QueenMenu(p1 , p2) ;  p1MoveNum=-1 ;}}
		else if(p1MoveNum==3){if(p1.pJack.canMove == 0){cout << "The jack can't move again this turn." << endl << "Press enter to continue."; cin.get() ; p1MoveNum=-1 ;} else {p1.pJack.canMove = !JackMenu(p1 , p2) ; p1MoveNum=-1 ;}}
		if((p1.pKing.canMove + p1.pQueen.canMove + p1.pJack.canMove)==0){p1MoveNum++;}
		}//END    PLAYER MOVE MENU

		if(SwapPlayer.turn==1){SwapPlayer = p2 ; p2 = p1 ; p1 = SwapPlayer;}
		return 0;
		}//END    STANDARD PLAYER TURN FUNCION





	void CompTurn(Player& _p1 , Player& _p2){//BEGIN   COMPUTER MOVEMENT FUNCTION

		while((_p2.pKing.canMove + _p2.pQueen.canMove + _p2.pJack.canMove)>0){//BEGIN   COMPUTER WHILE MOVE LOOP

			for(int m=0 ; m<3 ; m++){
			int compMove = 0; while(compMove == 0){//BEGIN   COMPUTER FIRST MOVE LOOP
			if((_p2.pKing.canMove + _p2.pQueen.canMove + _p2.pJack.canMove)==0){break;}

			compMove = _p2.RandomChoice(3);
			switch(compMove){//BEGIN   COMPUTER MOVE SWITCH
			case 1:{if(_p2.pKing.canMove==1){
				int cKMove=_p2.RandomChoice(2);
					switch(cKMove){
					case 1:{//ATTACK
						string victim;
						 int VNum = _p2.RandomChoice(3) ; switch(VNum){ case 1:{victim = "king";} case 2:{victim = "queen";} case 3:{victim = "jack";} }
						 int attCard = _p2.RandomChoice(10);
						 _p2.pKing.dualWield[3]=attCard;
						 _p2.numberCards[attCard-1] = -1;
						 _p2.EmptyHand();
						 PrintBoard(_p1 , _p2);

						 if(_p1.pJack.counterAttack[0]==0){ cout << "The " << _p2.pKing.title << "is attacking your " << victim << " . Do you want to block and counter with your jack?" << endl;
						 cout << " 1: Yes" << endl;
						 cout << " 2: No" << endl << endl;
						 int pCChoice = ChoiceCheck(2);

						 if(pCChoice == 1){
							 _p2.pKing.dualWield[1]=_p2.pKing.dualWield[3] ;
							 _p1.pJack.counterAttack[0]=_p1.pJack.counterAttack[1] ;
							 _p2.pKing.SetHP(_p2.pKing.GetHP() -_p1.pJack.counterAttack[0]);
							 PrintBoard(_p1 , _p2); cout << endl;
							 cout << _p1.GetFirstName() << " " << _p1.GetLastName() << " hit the" << _p2.pKing.title << " for " << attCard << " damage." << endl;

							 if(_p1.pQueen.heal[0]==0){ QueenHeal(_p1 , _p2) ; }




							 cout << "Press enter to continue.";
							 _p2.pKing.dualWield[1] = -1;
							 _p2.EmptyHand();
							 cin.get(); compMove=0 ; break;}
						 }

						 else{_p2.pKing.dualWield[1]=_p2.pKing.dualWield[3] ; //REVEAL CARD AND LAND ATTACK ON TARGET
						 switch(VNum){
						 case 1:{_p1.pKing.SetHP(_p1.pKing.GetHP() - _p2.pKing.dualWield[1]) ; break;} //KING ATTACKS KING
						 case 2:{_p1.pQueen.SetHP(_p1.pQueen.GetHP() - _p2.pKing.dualWield[1]) ; break;} //KING ATTACKS QUEEN
						 case 3:{_p1.pJack.SetHP(_p1.pJack.GetHP() - _p2.pKing.dualWield[1]) ; break;} //KING ATTACKS JACK

						 PrintBoard(_p1 , _p2) ; cout << endl;
						 cout << "The " << _p2.pKing.title << " hit your " << victim << " for " << attCard << " damage." << endl;
						 cout << "Press enter to continue.";
						 _p2.pKing.dualWield[1] = -1;
						 _p2.EmptyHand();
						 cin.get() ; compMove=0 ; break ;}}}}//END   KING ATTACK

					//case 2:{//Dual wield}



			}///END   CASE 1
			else{compMove=0;} break;}




//			case 2:{if(_p2.pKing.canMove==1){QueenMenu(__p1 , _p2);} else{compMove1=0;} break;}
//			case 3:{if(_p2.pKing.canMove==1){JackMenu(__p1 , _p2);} else{compMove1=0;} break;}
			}//END   COMPUTER MOVE SWITCH

			}//END   COMPUTER FIRST MOVE WHILE LOOP
			}//END	 COMPUTER FIRST MOVE FOR LOOP
			}//END   COMPUTER MOVE WHILE LOOP
			}//END   COMPUTER MOVEMENT FUNCTION







	bool StoryMode(){//BEGIN   STORY MODE FUNCTION
		Player p1;
		int storyChoice = 0;
		while(storyChoice==0){//BEGIN    STORYCHOICE MENU WHILE LOOP
		cout << " 0: Go Back" << endl;
		cout << " 1: New Game" << endl;
		cout << " 2: Load Game" << endl << endl;

		storyChoice = ChoiceCheck(2);


		switch(storyChoice){
		case 0:{ClearScreen() ; return 0;}
		case 1:{p1 = NewPlayer() ; if(!p1.IsHuman()){storyChoice=0; break;} ; SaveGame(p1) ; if(!p1.IsHuman()){storyChoice=0; break;} break;}//IF THE MENU IS BACKED OUT OF A COMPUTER PLAYER PROFILE IS RETURNED TRIGGERING MENU RETURN.
		case 2:{p1 = LoadGame() ; if(!p1.IsHuman()){storyChoice=0;} break;}}//IF THE MENU IS BACKED OUT OF A COMPUTER PLAYER PROFILE IS RETURNED TRIGGERING MENU RETURN.
		}//END    STORYCHOICE MENU WHILE LOOP

		Player p2 = LoadComp(p1);


		bool storyGame=0 ; while(storyGame==0){//BEGIN   STORY GAME
		ClearScreen();

		p1.TellStory();

		int goesFirst = FirstTurn(p1 , p2);

		p1.cardSet=1;

		while((p1.pKing.GetHP() +  p1.pQueen.GetHP() + p1.pJack.GetHP())>0 && (p2.pKing.GetHP() +  p2.pQueen.GetHP() + p2.pJack.GetHP())){
		if((p1.turnTotal%2==1) && goesFirst==1){ p1.turn=1 ; p1.turn=PlayerTurn(p1 , p2); p1.turnTotal = (p1.turnTotal + p1.turn);}
		else if((p1.turnTotal%2==0) && goesFirst==1){cout << "PT Test1" ; return 0 ; CompTurn(p1 , p2);}
		else if((p1.turnTotal%2==1) && goesFirst==2){cout << "PT Test2" ; return 0 ; CompTurn(p1 , p2);}
		else if((p1.turnTotal%2==0) && goesFirst==2){ p1.turn=1 ; p1.turn=PlayerTurn(p1 , p2); p1.turnTotal = (p1.turnTotal + p1.turn);}
		}

		if((p1.pKing.GetHP() +  p1.pQueen.GetHP() + p1.pJack.GetHP()) == 0){ p1.level++ ; cout << p1.GetFirstName() << " " << p1.GetLastName() << " has died on the field of battle." << endl << "Press enter to return to main menu." ; cin.get(); return 1;}

		else if((p1.pKing.GetHP() +  p1.pQueen.GetHP() + p1.pJack.GetHP()) > 0){ p1.level++ ; //BEGIN   WINNING GAME
			if((p1.pKing.GetHP() +  p1.pQueen.GetHP() + p1.pJack.GetHP())> p1.GetHighScore()){ p1.SetHighScore(p1.pKing.GetHP() +  p1.pQueen.GetHP() + p1.pJack.GetHP());}

		if(p1.GetLevel() == 5 ){ cout << p1.GetFirstName() << " " << p1.GetLastName() << " now rules all four kingdoms." <<  endl ; PrintCredits() ; return 1;}
		else if(p1.GetLevel() < 5) { cout << p1.GetFirstName() << " " << p1.GetLastName() << " is victorious." << endl << "Press enter to continue your journey." ; cin.get(); storyGame=0 ;}
		}//END   WINNING GAME
		}
		return 1;
		}//END   STORY MODE FUNCTION





	bool TestFunction(){//BEGIN   TESTFUNCTION  USED FOR TESTING PARTS OF THE PROGRAM
		Player tP1 , tP2;

		tP1.turnTotal++;
		tP2.turnTotal++;

//		for(int i=0 ; i<10 ; i++){cout << tP1.numberCards[i] << " " << tP1.emptyCards[i] << " " << tP2.numberCards[i] << " " << tP2.emptyCards[i] << endl;}



		tP1.cardSet = 1;
		tP1.turn=1 ;
		tP1.human=1;
		tP2.human=0;



		PlayerTurn(tP1 , tP2);

//		if(kingsTurn==1){ cout << "King finished his turn." << endl;}

//		AttackMenu(tP1 , tP2 , 1);

		cout << "Press enter to quit." ; cin.get() ; return 0; //END   TESTFUNCTION
	}





//MAIN BEGINS
int main() {


//	LoadGame();
 //if(!TestFunction()){return 0;}

	//FOR USE WITH TIME FUNCTIONS
	using namespace std::this_thread;
	using namespace std::chrono;

	//DEFAULT GAME OPTIONS
	int difficulty = 2;
	int gameLength = 2;
	Player p1;
	Player p2;

	//MAIN MENU WHILE LOOP
	int menuReturn=0;
	while(menuReturn == 0){

		int menuChoice = MainMenu();
		ClearScreen();

		switch (menuChoice) {//MAIN MENU

		case 1:{//BEGIN  STORY MODE
			menuChoice = StoryMode();
			break;
		}//END  STORY MODE

		case 2:{//BEGIN   BATTLE MODE

				//BATTLE MENU
				cout << endl << endl;
				cout << " 0: Back" << endl;
				cout << " 1: Player vs Computer" << endl;
				cout << " 2: Player vs Player" << endl << endl;

				int gameMode = ChoiceCheck(2);//INPUT VALIDATION LOOP

				switch (gameMode){

				case 1:{//SINGLE PLAYER MODE
						Player p1;
						Player p2;

					//RUN NEW OR LOAD OPTION MENU
					for(int p=1 ; p<2 ; p++){

											cout << endl << endl;
											cout << "Player " << p << ", choose to create new profile or load from top ten score list." << endl << endl;
											cout << " 0: Go Back" << endl;
											cout << " 1: New Player" << endl;
											cout << " 2: Load Player" << endl;

											int newOrLoad = ChoiceCheck(2);

											//INPUT VALIDATION LOOP
											while(newOrLoad == 0){
												cin >> newOrLoad;

												if(isdigit(newOrLoad) || newOrLoad<1 || newOrLoad>3){
													cout << "Not a valid player choice." << endl;
													cout << "Please try again." << endl;
													newOrLoad = 0;
													cin.clear();
													cin.ignore();
													}}//END INPUT VALIDATION LOOP

											//NEW OR LOAD MENU OPTIONS
											switch(newOrLoad){

											case 0:{menuReturn = 0; break;}//RETURN TO MAIN MENU

											case 1:{p1 = NewPlayer();if(p1.GetFirstName() == "EXITWITHOUTLOAD"){p--; break;}p1.SetSuit(p1.SuitSelection(0));//PLAYER ONE CREATES NEW PLAYER PROFILE
												while(p1.GetSuit()==p2.GetSuit()){p2.SetSuit(p2.RandomChoice(4));}//IF PLAYER CHOOSES DEFAULT SUIT SPADES COMPUTER IS ASSIGNED RANDOM SUIT.
												break;}

											case 2:{p1 = LoadPlayer(p2);if(p1.GetFirstName() == "EXITWITHOUTLOAD"){p--; break;}p1.SetSuit(p1.SuitSelection(0));//PLAYER ONE LOADS PLAYER PROFILE FROM TOP 10 LIST
												while(p1.GetSuit()==p2.GetSuit()){p2.SetSuit(p2.RandomChoice(4));}//IF PLAYER CHOOSES DEFAULT SUIT SPADES COMPUTER IS ASSIGNED RANDOM SUIT.
												break;}


											}//END OF SWITCH FOR NEW OR LOAD
											}//END OF FOR LOOP FOR CREATING 1 NEW PLAYER AND COMPUTER (p2)

											PrintBoard(p1 , p2);//TEST PRINT BOARD REMOVE LATER
											break;
											}//END OF 1 PLAYER MODE



				case 2: {//TWO PLAYER GAME BEGINS
					Player p1 , p2;

					for(int p=1 ; p<3 ; p++){int newOrLoad = 0; //RUN NEW OR LOAD OPTION MENU

						ClearScreen();
						cout << "Player " << p << ", choose to create new profile or load from top ten score list." << endl <<endl;
						cout << " 1: New Player" << endl;
						cout << " 2: Load Player" << endl;
						cout << " 3: Main Menu" << endl << endl;
						cout << "Enter number choice: ";

						while(newOrLoad == 0){cin >> newOrLoad; //INPUT VALIDATION LOOP

							if(isdigit(newOrLoad) || newOrLoad<1 || newOrLoad>3){
								cout << "Not a valid menu number choice." << endl << "Please try again." << endl ; newOrLoad = 0 ; cin.clear() ; cin.ignore() ; }}//END INPUT VALIDATION LOOP


					switch(newOrLoad){//NEW OR LOAD MENU OPTIONS

					case 1://NEW PLAYER
						{if(p==1){p1 = NewPlayer(); p1.SetSuit(p1.SuitSelection(0)); } else if(p==2){p2 = NewPlayer() ; p1.SetSuit(p2.SuitSelection(p1.GetSuitNum()));} break; }

					case 2://LOAD PLAYER
						{if(p==1){p1 = LoadPlayer(p2);if(p1.GetFirstName() == "EXITWITHOUTLOAD"){p--; break;} p1.SetSuit(p1.SuitSelection(0));}//LOAD PROFILE FOR PLAYER 1

						else if(p==2){p2 = LoadPlayer(p1);if(p2.GetFirstName() == "EXITWITHOUTLOAD"){p--; break;}p2.SetSuit(p2.SuitSelection(p1.GetSuitNum()));}//END OF PLAYER 2 NAME ENTRY
						}//END LOAD GAME CASE

					case 3:{menuReturn = 0;break;}}//END OF SWITCH FOR NEW OR LOAD
						}//END OF FOR LOOP FOR CREATING 2 PLAYERS


					ClearScreen();

					//BEGIN    FIRST TURN FUNCTION
					p1.cardSet=0;;//FLIP CARDS OVER FOR FIRST TURN SELECTION
					p2.cardSet=0;//FLIP CARDS OVER FOR FIRST TURN SELECTION
					PrintBoard(p1 , p2) ; cout << endl ; //PRINT FIRST TURN BOARD

					int goesFirst=0; //BEGIN   FIRST TURN WHILE LOOP BOTH PLAYERS (w)
					while(goesFirst==0){ for( int w=1 ; w<3 ; w++){ int firstChoice=0;

					if(w==1){ cout << p1.firstName << " " << p1.lastName << ", Pick a card from " << p2.firstName << "'s hand by entering a number between 1 and 10: "; }
					else if(w==2){ cout << p2.firstName << " " << p2.lastName << ", Pick a card from " << p1.firstName << "'s hand by entering a number between 1 and 10: "; }

					while(firstChoice==0){ cin >> firstChoice; //INPUT PLAYER CARD CHOICE FOR FIRST ROUND SELECTION

					if(isdigit(firstChoice) || firstChoice<1 || firstChoice>10){//BEGIN   INPUT VALIDATION
					cout << "Choice is not a number between 1 and 10." << endl;
					cout << "Please try again." << endl ; firstChoice=0 ; cin.clear() ; cin.ignore();}}//END   INPUT VALIDATION

					if(w==1){p2.emptyCards[firstChoice-1] = p1.RandomChoice(10);}
				    else if(w==2){p1.emptyCards[firstChoice-1] = p2.RandomChoice(10);}
					}//END   FIRST TURN WHILE LOOP BOTH PLAYERS (w)

					p1.turnTotal++;
					p2.turnTotal++;


					ClearScreen();

					p1.cardSet=0;
					p2.cardSet=0;

					PrintBoard(p1 , p2);//PRINT FIRST TURN SELECTION BOARD (REVEAL THE CARDS AFTER PICKING AT RANDOM)


					int sum1 = 0 , sum2 = 0;//BEGIN   CHECK FIRST TURN CARD PICK TO SEE WHO PICKED HIGHER CARD VALUE AND GOES FIRST (PLAYER WITH LOWER NUMBER ON THEIR SIDE GOES FIRST)
					for(int q=0 ; q<10 ; q++){sum1 = sum1 + p1.emptyCards[q]; sum2 = sum2 + p2.emptyCards[q];} //PLAYER 1'S CARD CHOICE (ALL CARDS 0 EXCEPT CHOICE SO SUM OF ALL CARDS IS JUST THE CHOICE)
					for(int j=0 ; j<10 ; j++){p1.emptyCards[j]=0; p2.emptyCards[j]=0;} //PLAYER 2'S CARD CHOICE (ALL CARDS 0 EXCEPT CHOICE SO SUM OF ALL CARDS IS JUST THE CHOICE)

					if(sum1==sum2){cout << "Tie. Try again." << endl; goesFirst=0;}


					else if(sum1 != sum2){
					cout << " 0: Quit" << endl;
					cout << " 1: Yes" << endl;
					cout << " 2: No"  << endl << endl;

					if(sum1 < sum2){cout << p1.firstName << " " << p1.lastName << " goes first. Will " << p2.firstName << " " << p2.lastName << " set a jack counter attack?" << endl << "Enter a number choice: " ; goesFirst=1;}
					else if(sum1 > sum2){cout << p2.firstName << " " << p2.lastName << " goes first. Will " << p1.firstName << " " << p1.lastName << " set a jack counter attack?" << endl << "Enter a number choice: " ; goesFirst=2;}
					}

					int jDefend = 0;//BEGIN   JACK FIRST DEFEND
					while(jDefend == 0){cin >> jDefend;

					if(jDefend==0){menuReturn=0; break;}//EXIT OPTION

					else if(isdigit(jDefend) || jDefend<0 || jDefend>2){ cout << "Entry is not in range." << endl << "Please try again: "; jDefend=0 ; cin.clear() ; cin.ignore();}//END    JACK FIRST DEFEND

					if(goesFirst==2){ if(jDefend == 1){ ClearScreen(); p1.cardSet=1 ; p2.cardSet=0; PrintBoard(p1 , p2) ;  int cC=p1.Counter() ; if(cC==0){ jDefend=0;} else if(cC==1){ break;}}}
					else if(goesFirst==1){if(jDefend == 1){ ClearScreen(); p2.cardSet=1 ; p1.cardSet=0 ; PrintBoard(p2 , p1) ; int cC=p2.Counter() ; if(cC==0){ jDefend=0;} else if(cC==1){ break;}}}
					}//END   FIRST JACK COUNTER MOVE
					}//END   FIRST TURN WHILE LOOP BOTH PLAYERS (w)


					int p1Life = (p1.KingHealth() + p1.QueenHealth() + p1.JackHealth());
					int p2Life = (p2.KingHealth() + p2.QueenHealth() + p2.JackHealth());

					p1.EmptyHand();
					p2.EmptyHand();

					ChangeTurn(goesFirst , p1 , p2);


					while(p1Life>0 && p2Life>0){//BEGIN   MAIN TWO PLAYER GAME LOOP

					if(goesFirst==1){ //IF PLAYER 1 GOES FIRST

					int p1Move=-1;
					while(p1Move==-1){
					cout << " 0: Quit" << endl;
					cout << " 1: King" << endl;
					cout << " 2: Queen" << endl;
					cout << " 3: Jack" << endl << endl;
					cout << p1.firstName << " " << p1.lastName << ", enter a number to take action with a party member: ";

					cin >> p1Move;

					if(isdigit(p1Move) || p1Move<0 || p1Move>3){ cout << "Invalid input. Try again." << endl ; p1Move=-1;}

					}

					switch(p1Move){

					case 0: {menuReturn=0; break;}
					case 1: {KingMenu(p1 , p2); break;}
					case 2: {/*Queen menu */ break;}
					case 3: {/*Jack menu */ break;}
					}

					return 0;

					}


					else if(goesFirst==2){//FLIP PLAYER 1's CARDS OVER AND REVEAL PLAYER 2'S CARD IN BOTTOM SCREEN POSITION
						int p2Move=-1;
						while(p2Move==-1){
						cout << " 0: Quit" << endl;
						if(p2.pKing.canMove==1){ for( int k=0 ; k<10 ; k++){ cout << p2.GetSuitCode();}; cout << endl;} else if(p2.pKing.canMove==0){ cout << " 1: King" << endl;}
						if(p2.pQueen.canMove==1){ for( int k=0 ; k<10 ; k++){ cout << p2.GetSuitCode();}; cout << endl;} else if(p2.pQueen.canMove==0){ cout << " 2: Queen" << endl;}						cout << " 3: Jack" << endl;
						if(p2.pJack.canMove==1){ for( int k=0 ; k<10 ; k++){ cout << p2.GetSuitCode();}; cout << endl;} else if(p2.pJack.canMove==0){ cout << " 1: Jack" << endl;}
						cout << " 4: End Turn" << endl << endl;
						cout << p2.firstName << " " << p2.lastName << ", enter a number to take action with a party member: ";

						cin >> p2Move;

						if(isdigit(p2Move) || p2Move<0 || p2Move>3){ cout << "Invalid input. Try again." << endl ; p2Move=-1;}

						}

						switch(p2Move){

						case 0: {menuReturn=0; break;}
						case 1: {p2.pKing.canMove = KingMenu(p2 , p1); p2Move=-1;  break;}
						case 2: {/*Queen menu */ break;}
						case 3: {/*Jack menu */ break;}
						case 4: {p2Move++ ; break;}
						}

						if(p2.pKing.canMove==1 && p2.pQueen.canMove==1 && p2.pJack.canMove==1){
							cout << p2.firstName << " " << p2.lastName << "'s turn is over." << endl;

						}
					}

					p1Life=0;

					}//END   MAIN TWO PLAYER GAME LOOP

					break;}//END OF 2 PLAYER GAME


				case 3: {ClearScreen();menuReturn = 0;break;}//RETURN TO MAIN MENU

				}

	//TEMPORARY MENU FOR END OF SECTION. REMOVE LATER
	int quitInt = 0;
	if(menuReturn!=0){
	while(quitInt == 0){
	cout << "Over for now." << endl;
	cout << " 0: Quit Game" << endl;
	cout << " 1: Main Menu" << endl;
	cout << "Enter a number choice:";
	cin >> quitInt;

	if(quitInt == 0){
		menuReturn = 1;
		break;
	}
	else if(quitInt == 1){

		menuReturn = 0;
		break;
	}
	else{cout << "Invalid input. Try again." << endl ; quitInt = '0';}

	}//END OF TEMPORARY END MENU
	}

	break;}//END OF MAIN MENU CASE 2


case 3:{PrintInstructions();break;}

case 4:{OptionsMenu(difficulty , gameLength);break;}

case 5:{PrintCredits();break;}

case 0:{cout << "Thanks for playing!" << endl;return 0;break;}//QUIT MESSAGE

}//END OF MAIN MENU RESONSE SWITCH
}//END MAIN MENU WHILE LOOP
return 0;
}//END GAME

