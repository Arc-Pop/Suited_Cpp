// This file contains definitions for functions used to print text and unicode symbols to the terminal for the game Suited.

#include "../lib/print.h"

#include "../lib/player.h"

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <chrono>
#include <thread>


std::string heart = "\u2665";
std::string diamond = "\u2666";
std::string club = "\u2667";
std::string spade = "\u2664";
std::string shield = "\u26CA";
int difficulty;
int gameLength;




void CenterPrint(const std::string centerThis){                             // Function for printing centered relative to the width of the game. 

    const int screenWidth = 160;                                            // The layout of the game when played is 160 characters wide.

    int centerSize = centerThis.size();                                     // Size of the string used to determine the center position.

    int nonASCII = 0;                                                       // Counts non-ASCII characters for adjustments unicode adjustments

    for (unsigned char c : centerThis) {                                    // For each character in the text to be centered
        if (c > 127) {                                                      // If that character has an integer value greater than 127 it is non-ASCII
            nonASCII++;                                                     // Increase the count of non-ASCII characters
            if(nonASCII==3){ centerSize-=2; nonASCII=0;}                    // 3 non-ASCII characters is equivalent to 1 ASCII, subtract 2 from the size and reset count
        }
    }

    int spaceSize = (screenWidth - centerSize) / 2;                         // Calculate the number of spaces to add to the front of the string to be centered

    std::string space = "";                                                 // Variable for holding the space needed to be added to the string to be centered

    for(int i=0; i<spaceSize; i++){ space.append(" "); }                    // Add the required blank spaces to  the space variable

    std::string centered = centerThis;                                      // Pass text from constant to temporary variable which will have space added to it

    centered.insert(0, space);                                              // Add the blank space needed to center to the front of the string

    std::cout << centered << std::endl;                                     // Print the centered string

}


void ClearScreen(){                                                         // Function for clearing screen by pushing previous table layouts offscreen
    for(unsigned int i = 0 ; i<40 ; i++){                                   // Print 40 new lines to clear screen
        std::cout << std::endl;
    } 
    std::cout << "\r";                                                      // Carriage return to leave input in correct place
}


int ChoiceCheck(int numChoices){                                            // Function for taking input and checking if it is in range

	std::string usrChoice;
	int usrChoiceNumber=0;
	int numberCheck=0;

	while(numberCheck==0){

	std::cout << "Enter a number choice: ";
	std::cin >> usrChoice;


	for(unsigned int i=0 ; i<usrChoice.size() ; i++){
        if(!isdigit(usrChoice.at(i))){numberCheck++;}
    }
	
    if(numberCheck==0){usrChoiceNumber = stoi(usrChoice);}

	if(usrChoiceNumber > 0 && usrChoiceNumber < (numChoices+1)){return usrChoiceNumber;}

	std::cout << "Invalid input. Please try again." << std::endl;
	numberCheck=0;
	}
    return 0;}//END   FUNCTION FOR TAKING AND CHECKING USER INPUT TO CHECK IF IT IS A NUMBER IN THE RANGE OF CHOICES


//FUNCTION: GETTING MENU OPTION
int MainMenu(){

	ClearScreen();

    std::string borderTop = heart + club + diamond + spade + heart + club + diamond + spade + heart;
    std::string borderBottom = heart + spade + diamond + club + heart + spade + diamond + club + heart;

    CenterPrint(borderTop); 
	CenterPrint("SUITED" + shield); 
    CenterPrint(borderBottom);
	
    std::ifstream fin("assets/cardASCI.txt");
	std::string cardString = "";
	while(std::getline(fin , cardString)){
        std::string cardLine="";
		for(unsigned int i=0 ; i<cardString.size() ; i++){
			if(cardString.at(i) == 'S'){ cardLine.append(spade); }
			else{ cardLine+=cardString[i]; }
	    }
    CenterPrint(cardLine);
    }
	fin.close();
    std::cout << std::endl;

	std::cout << "Select an option by typing a number and then press Enter" << std::endl << std::endl;//BEGIN   PRINT THE MAIN MENU
	std::cout << " 1: Play" << std::endl;
	std::cout << " 2: Instructions" << std::endl;
	std::cout << " 3: Options" << std::endl;
	std::cout << " 4: Quit" << std::endl << std::endl;

	int option = ChoiceCheck(4);
	return option;
}


int PlayGame(){

	Player Player1;
	Player1.MakePlayer();

	if(Player1.GetFirstName() == "" || Player1.GetLastName() == ""){ // Player exited without completing MakePlayer function so return to main menu.
		return 0;
	}

	int computerSuit = Player1.Cards.King.GetSuitNum();

	while(computerSuit == Player1.Cards.King.GetSuitNum()){		// Select a random suit for the computer to play.
		computerSuit = (std::rand() % 4) + 1;
	}

	Player Computer("King's", "Advisor", computerSuit);	// Create a computer oponent.

	PrintBoard( Player1, Computer);

	return 0;
}


int FirstTurn(Player& _p1 , Player& _p2){//BEGIN    FIRST TURN FUNCTION
/*
	int sum1 = 0 , sum2 = 0;

	_p1.cardSet=0;;//FLIP CARDS OVER FOR FIRST TURN SELECTION
	_p2.cardSet=0;//FLIP CARDS OVER FOR FIRST TURN SELECTION


	PrintBoard(_p1 , _p2) ; 
	cout << endl ; //PRINT FIRST TURN BOARD

	int goesFirst=0; //BEGIN   FIRST TURN WHILE LOOP BOTH PLAYERS (w)
	while(goesFirst==0){ 
		for( int w=1 ; w<3 ; w++){ 
			int firstChoice=0;

			if(w==1 && _p2.IsHuman()){ 
				cout << _p1.GetFirstName() << " " << _p1.GetLastName() << ", Pick a card from ";
				cout << _p2.GetLastName() << "'s hand by entering a number between 1 and 10: "; 
			}
			else if(w==1 && !_p2.IsHuman()){ 
				cout << "Advisor " <<  _p1.GetLastName() << ", Pick a card from the ";
				cout << _p2.GetFirstName() << " " << _p2.GetLastName() << "' hand by entering a number between 1 and 10: "; 
			}
			else if(w==2 && _p2.IsHuman()){ 
				cout << _p2.GetFirstName() << " " << _p2.GetLastName() << ", Pick a card from ";
				cout << _p1.lastName << "'s hand by entering a number between 1 and 10: "; 
			}
			else if(w==2 && !_p2.IsHuman()){
				firstChoice = _p2.RandomChoice(10);
			}


			if(w==1 || (w==2 && _p2.IsHuman())){ 
				while(firstChoice==0){ 
					cin >> firstChoice; //INPUT PLAYER CARD CHOICE FOR FIRST ROUND SELECTION

					if(isdigit(firstChoice) || firstChoice<1 || firstChoice>10){//BEGIN   INPUT VALIDATION
						cout << "Choice is not a number between 1 and 10." << endl; 
						cout << "Please try again." << endl; 
						firstChoice=0 ; 
						cin.clear() ; cin.ignore();
					} //END   INPUT VALIDATION
				}
			}

			if(w==1){
				_p2.Cards.Number.emptyCards[firstChoice-1] = _p1.RandomChoice(10);
			}
			if(w==2){
				_p1.Cards.Number.emptyCards[firstChoice-1] = _p2.RandomChoice(10);
			}

		}//END   FIRST TURN WHILE LOOP BOTH PLAYERS (w)

		ClearScreen();

		PrintBoard(_p1 , _p2);//PRINT FIRST TURN SELECTION BOARD (REVEAL THE CARDS AFTER PICKING AT RANDOM)

		_p1.turnTotal++ ; _p2.turnTotal++; 
		_p1.cardSet=0 ; _p2.cardSet=0;

		sum1 = 0 , sum2 = 0;//BEGIN   CHECK FIRST TURN CARD PICK TO SEE WHO PICKED HIGHER CARD VALUE AND GOES FIRST (PLAYER WITH LOWER NUMBER ON THEIR SIDE GOES FIRST)
		for(int q=0 ; q<10 ; q++){
			sum1 = sum1 + _p1.Cards.Number.emptyCards[q]; 
			sum2 = sum2 + _p2.Cards.Number.emptyCards[q];
		} //PLAYER 1'S CARD CHOICE (ALL CARDS 0 EXCEPT CHOICE SO SUM OF ALL CARDS IS JUST THE CHOICE)
		for(int j=0 ; j<10 ; j++){
			_p1.Cards.Number.emptyCards[j]=0; 
			_p2.Cards.Number.emptyCards[j]=0;
		} //PLAYER 2'S CARD CHOICE (ALL CARDS 0 EXCEPT CHOICE SO SUM OF ALL CARDS IS JUST THE CHOICE)

		if(sum1==sum2){
			cout << "Tie. Try again." ; 
			goesFirst=0;
		}
		else if(sum1<sum2){
			goesFirst=1;
		}
		else if(sum1>sum2){
			goesFirst=2;
		}
	}//END   CHOOSE WHETHER TO START WITH COUNTER

	if(sum1 != sum2){
		cout << " 0: Quit" << endl;
		cout << " 1: Yes" << endl;
		cout << " 2: No"  << endl << endl;

	if((sum1 < sum2) && _p2.IsHuman()){
		cout << _p1.GetFirstName() << " " << _p1.GetLastName() << " goes first."; 
		cout << "Will " << _p2.GetFirstName() << " " << _p2.GetLastName() << " set a jack counter attack?" << endl;
		cout << "Enter a number choice: ";
	}
	else  if((sum1 < sum2) && (!_p2.IsHuman())){
		cout << _p1.GetFirstName() << " " << _p1.GetLastName() << " goes first.";
		cout << "Will " << _p2.GetFirstName() << " " << _p2.GetLastName() << " set a jack counter attack?" << endl; 
		cout << "Enter a number choice: " ;
		std::this_thread::sleep_until(chrono::system_clock::now() + 3s); 
		cout << _p2.GetFirstName() << " " << _p2.GetLastName() << " is thinking..." << endl ;  
		std::this_thread::sleep_until(chrono::system_clock::now() + 3s); 
	}
	else if(sum1 > sum2){
		cout << _p2.GetFirstName() << " " << _p2.GetLastName() << " goes first.";
		cout << "Will " << _p1.GetFirstName() << " " << _p1.GetLastName() << " set a jack counter attack?" << endl << "Enter a number choice: " ;
	}
	}

	int jDefend = 0;//BEGIN   JACK FIRST DEFEND

	if((goesFirst==1 && _p2.IsHuman()) || goesFirst==2){
		jDefend=ChoiceCheck(2);
	}

	if(goesFirst==1){//BEGIN  PLAYER 1 GOES FIRST PLAYER 2 CAN PREPARE TO COUNTER

		if(!_p2.IsHuman()){ //BEGIN    COMPUTER JACK SET
			jDefend = _p2.RandomChoice(2); 
			if(jDefend==1){ 
				_p2.pJack.counterAttack[0] = 0 ; 
				_p2.pJack.counterAttack[1] = _p2.RandomChoice(10); 
				_p2.numberCards[_p2.pJack.counterAttack[1]-1]=-1;  
				_p2.EmptyHand(); 
				PrintBoard(_p1 , _p2);
				cout << endl << _p2.GetFirstName() << " " << _p2.GetLastName() << " is prepared to counter-attack." << endl;
				cout << "Press enter to continue."; 
				cin.get() ;
			}
			else if(jDefend==2){
				cout <<  _p2.GetFirstName() << " " << _p2.GetLastName() << " has chosen not to prepare a counter-attack." << endl;
				cout << "Press enter to continue."; 
				cin.get(); 
				return goesFirst;
			}
		}//END    COMPUTER JACK SET

		if(_p2.IsHuman()){ //BEGIN   HUMAN PLAYER 2
			while(jDefend == 0){
				cin.ignore() ; cin.clear(); 
				cin >> jDefend;
				if(jDefend==0){
					return 0;
				}//EXIT OPTION
				else if(isdigit(jDefend) || jDefend<0 || jDefend>2){ 
					cout << "Entry is not in range." << endl << "Please try again: "; 
					jDefend=0; 
					cin.clear(); 
				}
			}

			if(jDefend == 1){ 
				ClearScreen(); 
				_p2.cardSet=1; 
				_p1.cardSet=0; 
				PrintBoard(_p2 , _p1); 
				int cC=_p2.Counter(); 
				if(cC==0){ 
					jDefend=0;
				} 
				else if(cC==1){ 
					return goesFirst;
				}
			}

			if(jDefend == 2){
				cout << _p2.GetFirstName() << " " << _p2.GetLastName() << " chose not to prepare a counter-attack." << endl; 
				cout << "Press enter to continue."; 
				cin.ignore(); cin.get(); 
				return goesFirst;
			}
		}
	}//END  PLAYER 1 GOES FIRST PLAYER 2 CAN PREPARE TO COUNTER

	if(goesFirst==2){//BEGIN  PLAYER 2 GOES FIRST PLAYER 1 CAN PREPARE TO COUNTER
		while(jDefend == 0){ 
			cin >> jDefend;
			if(jDefend==0){
				return 0;
			}//EXIT OPTION
			else if(isdigit(jDefend) || jDefend<0 || jDefend>2){ 
				cout << "Entry is not in range." << endl << "Please try again: "; 
				jDefend=0 ; 
				cin.clear() ; cin.ignore();
			}
		}
		if(jDefend == 1){ 
			ClearScreen(); 
			_p1.cardSet=1 ; 
			_p2.cardSet=0; 
			PrintBoard(_p1 , _p2);  
			int cC=_p1.Counter();

			if(cC==0){ 
				jDefend=0;
			}
			
			else if(cC==1){
				_p1.EmptyHand();  
				ClearScreen();  
				PrintBoard(_p1 , _p2);
				cout << "Press enter to continue."; 
				cin.ignore();
				cin.get();  
				return goesFirst;
			}
		}

		if(jDefend == 0){
			return goesFirst;
		}
	}//END  PLAYER 2 GOES FIRST PLAYER 1 CAN PREPARE TO COUNTER

	return goesFirst;

	*/
	return 0; //REMOVE AFTER CORRECTING FUNCTION
}//END   FIRST TURN FUNCTION



void PrintBoard(Player _p1 , Player _p2){

	//SWITCHES TO DISPLAY EMPTY SET DEPENDING ON TURN AS INDICATED BY (cardSet) VARIABLE. (cardSet=0) MEANS DISPLAY CARD BACK.
	//	if(_p1.cardSet == 0){ for(int i=0 ; i<10 ; i++){ _p1.Cards.Number[i] = _p1.Cards.Number.emptyCards[i];}}
	//	if(_p2.cardSet == 0){ for(int i=0 ; i<10 ; i++){ _p2.Cards.Number[i] = _p2.Cards.Number.emptyCards[i];}}

	int ftn=1;
	int ftN=1;

	//THESE VALUES ARE THE CARD OVER DISTANCE AND THE CARD UNDER DISTANCE.
	int cO=16;	//CARD OVER SPACE FROM THE BEGINNING OF ONE CARD TO THE NEXT

	int oP =0; //OFF PRINT TURNS OFF NORMAL PRINT ELSE CONDITIONAL

	int p1ScoreSum = _p1.Cards.King.GetHP() + _p1.Cards.Queen.GetHP() + _p1.Cards.Jack.GetHP();		//PLAYER 1 SCORE TOTAL SUM OF PLAYER HEALTH
	int p2ScoreSum = _p2.Cards.King.GetHP() + _p2.Cards.Queen.GetHP() + _p2.Cards.Jack.GetHP();	//PLAYER 2 SCORE TOTAL SUM OF PLAYER HEALTH

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


	ifstream fin("assets/cardTable.txt");//BEGIN   READ FILE INTO (cardString) STRING VARIABLE
	string cardString , tempLine; 
	while (getline(fin, tempLine)) {
		cardString = cardString + tempLine; cardString.push_back('\n');
	}
	fin.close();//END   READ FILE INTO (cardString) STRING VARIABLE

	for(unsigned int cP=0 ; cP<cardString.size() ; cP++){ //BEGIN  PRINT BOARD LOOP *************** 
		oP=0;

		for(int n=0 ; n<10 ; n++){//BEGIN   NUMBER CARD LOOP FOR NUMBER CARDS 1 TO 10
			//PLAYER 2 NUMBER CARDS
			if(_p2.Cards.Number.numberCards[n]==-1){//BEGIN   EMPTY CARD SPOT
				for(int r=0 ; r<15 ; r++){
					if( (cP < p2RR[0]) && (cP==(n*cO)+p2NR[r])){//AREA OF CARD, ROW
						for(int l=0 ; l<15 ; l++){//LENGTH OF BLANK SPACE
							std::cout << " "; cP++; oP++;
						}
					}
				}
			}//END   EMPTY CARD SPOT
			
			else if(_p2.Cards.Number.numberCards[n]==0){//BEGIN   BACK OF CARD
				for(int l=2 ; l<9 ; l++){//ROWS TO PRINT X
					if((cP > (p2NR[l] + cO*n + 1)) && (cP < (p2NR[l] + cO*n) + 10)){//THE AREA OF THE CARD TO PRINT ON (CARD NUMBER)
						for(int k=0 ; k<11 ; k++){
							std::cout << "X"; 
							cP++ ; 
							oP++ ;
						}//COLUMN TO PRINT, PRINT, INCREMENT COUNTER
						cP--;
					}
				}
			}//END   BACK OF CARD, REMOVES THE LAST INCREMENT FROM THE LOOP FOR CORRECT SPACING

			else if(_p2.Cards.Number.numberCards[n]>0 && _p2.Cards.Number.numberCards[n]<11){//BEGIN   PRINT NUMBER CARD
				if(_p2.Cards.Number.numberCards[n]!=n+1){
					for(int l=2 ; l<11 ; l++){//ROWS TO PRINT
						if((cP > (p2NR[l] + cO*n)-1) && (cP < (p2NR[l] + cO*n) + 10)){//THE AREA OF THE CARD TO PRINT ON (CARD NUMBER)
							for(int k=0 ; k<13 ; k++){
								if((cardString.at(p2NR[l] + k + (_p2.Cards.Number.numberCards[n]-1)*cO))=='o'){
									std::cout << _p2.Cards.King.GetSuitCode(); 
									cP++; 
									oP++;
									}
								else{
									std::cout << cardString.at(p2NR[l] + k + (_p2.Cards.Number.numberCards[n]-1)*cO); 
									cP++;
									oP++;
								}//COLUMN TO PRINT, PRINT, INCREMENT COUNTER
								cP--;
							}
						}
					}
				}//END   BACK OF CARD, REMOVES THE LAST INCREMENT FROM THE LOOP FOR CORRECT SPACING
			}//END   PRINT NUMBER CARD


			//PLAYER 1 NUMBER CARDS

			if(_p1.Cards.Number.numberCards[n]==-1){//BEGIN   EMPTY CARD SPOT
				for(int r=0 ; r<15 ; r++){
					if( (cP > p1RR[9]) && (cP==(n*cO)+p1NR[r])){//AREA OF CARD, ROW
						for(int l=0 ; l<15 ; l++){//LENGTH OF BLANK SPACE
							std::cout << " "; 
							cP++; 
							oP++;
						}
					}
				}
			}//END   EMPTY CARD SPOT

			if(_p1.Cards.Number.numberCards[n]==0){//BEGIN   BACK OF CARD
				for(int l=2 ; l<9 ; l++){//ROWS TO PRINT X
					if((cP > (p1NR[l] + cO*n + 1)) && (cP < (p1NR[l] + cO*n) + 10)){//THE AREA OF THE CARD TO PRINT ON (CARD NUMBER)
						for(int k=0 ; k<11 ; k++){
							std::cout << "X" ; 
							cP++ ; 
							oP++ ;
						}//COLUMN TO PRINT, PRINT, INCREMENT COUNTER
						cP--;
					}
				}
			}//END   BACK OF CARD, REMOVES THE LAST INCREMENT FROM THE LOOP FOR CORRECT SPACING

			else if(_p1.Cards.Number.numberCards[n]>0 && _p1.Cards.Number.numberCards[n]<11){//BEGIN   PRINT NUMBER CARD
				if(_p1.Cards.Number.numberCards[n]!=n+1){
					for(int l=2 ; l<11 ; l++){//ROWS TO PRINT X
						if((cP > (p1NR[l] + cO*n)-1) && (cP < (p1NR[l] + cO*n) + 10)){//THE AREA OF THE CARD TO PRINT ON (CARD NUMBER)
							for(int k=0 ; k<13 ; k++){
								if((cardString.at(p1NR[l] + k + _p1.Cards.Number.numberCards[n]*cO))=='S'){
									std::cout << _p1.Cards.King.GetSuitCode(); 
									cP++; 
									oP++;
								}
								else{
									std::cout << cardString.at(p1NR[l] + k + _p1.Cards.Number.numberCards[n]*cO); 
									cP++; 
									oP++;
								}//COLUMN TO PRINT, PRINT, INCREMENT COUNTER
							cP--;
							}
						}
					}
				}//END   BACK OF CARD, REMOVES THE LAST INCREMENT FROM THE LOOP FOR CORRECT SPACING
			}//END   PRINT NUMBER CARD
		}//END   NUMBER CARD LOOP FOR NUMBER CARDS 1 TO 10


		if(cP==p2RR[jL2]){ //BEGIN   P2 JACK LOOP COUNTER-ATTACK
			jL2++;

			if(_p2.Cards.Jack.GetCounter()==0){//BEGIN   HIDDEN JACK COUNTER SHOW BACK OF CARD
				if(jL2==1){
					std::cout<<" "; 
					for(int p=0 ; p<13 ; p++){
						std::cout << "_"; 
						oP++; cP++;
					}
					cP++;
				}//PRINT TOP LINE OF CARD

				if(jL2==2){
					std::cout << "|"; 
					for(int p=0 ; p<13 ; p++){
						std::cout << " ";
						oP++; cP++;
					}
					std::cout << "|"; 
					cP++; cP++;
				}//PRINT SECOND LINE OF CARD

				if(jL2>2 && jL2<10){
					std::cout << "| "; 
					oP++; cP++; oP++; cP++; 
					for(int k=0 ; k<11 ; k++){
						std::cout << "X" ; 
						oP++; cP++;
					}
					std::cout << " |";
					oP++; cP++;oP++; cP++;
				}

				if(jL2==10){std::cout << "|"; cP++;
					for(int d=0 ; d<13 ; d++){
						std::cout << "_";
						cP++;
					} 
					std::cout<<"|";
					cP++;
				}
			}//END   HIDDEN JACK COUNTER SHOW BACK OF CARD

			else if(_p2.Cards.Jack.GetCounter()>0 && _p2.Cards.Jack.GetCounter()<11){//BEGIN   JACK COUNTER CARD
				for(int k=0 ; k<15 ; k++){//LENGTH OF CARD
					if(cardString.at(p2NR[jL2-1] + k + (_p2.Cards.Jack.GetCounter()-1)*cO) == 'o'){
						std::cout << _p2.Cards.Jack.GetSuitCode();
						oP++; cP++;
					}
					else{
						std::cout << cardString.at(p2NR[jL2-1] + k + (_p2.Cards.Jack.GetCounter()-1)*cO); 
						oP++; cP++;
					}
				}
			}//END   JACK COUNTER CARD

			oP++; oP++;
		}//END   P2 JACK LOOP COUNTER-ATTACK

		if(cP==p1RR[jL1]){ //BEGIN  P1 JACK LOOP
			jL1++;
			if(_p1.Cards.Jack.GetCounter()==0){//BEGIN   JACK COUNTER REVERSE SIDE
				if(jL1==1){
					std::cout<<" "; 
					for(int p=0 ; p<13 ; p++){
						std::cout << "_"; 
						oP++; cP++;
					}
					cP++;
				}//PRINT TOP LINE OF CARD

				if(jL1==2){
					std::cout << "|"; 
					for(int p=0 ; p<13 ; p++){
						std::cout << " ";
						oP++; cP++;
					}
					std::cout << "|"; 
					cP++;cP++;
				}//PRINT SECOND LINE OF CARD

				if(jL1>2 && jL1<10){
					std::cout << "| "; 
					oP++; cP++; oP++; cP++; 
					for(int k=0 ; k<11 ; k++){
						std::cout << "X" ; 
						oP++; cP++;
					}
					std::cout << " |";
					oP++; cP++;oP++; cP++;
				}

				if(jL1==10){
					std::cout << "|"; 
					cP++;
					for(int d=0 ; d<13 ; d++){
						std::cout << "_";
						cP++;
					} 
					std::cout<<"|";
					cP++;
				}
			}//END   JACK COUNTER REVERSE SIDE

			else if(_p1.Cards.Jack.GetCounter()>0 && _p1.Cards.Jack.GetCounter()<11){//JACK COUNTER REVERSE SIDE
				for(int k=0 ; k<15 ; k++){//LENGTH OF CARD
					if(cardString.at(p1NR[jL1-1] + k + (_p1.Cards.Jack.GetCounter()-1)*cO) == 'S'){
						std::cout << _p1.Cards.Jack.GetSuitCode();
						oP++; cP++;
					}
					else{
						std::cout << cardString.at(p1NR[jL1-1] + k + (_p1.Cards.Jack.GetCounter()-1)*cO); 
						oP++; cP++;
					}
				}
			}//END   JACK COUNTER CARD

			oP++; oP++;
		}//END   P1 JACK LOOP

		if(cP==p2RR[qL2]+cO*2+1){
			qL2++;//BEGIN   PLAYER 2 QUEEN LOOP
			if(_p2.Cards.Queen.heal==0){//BEGIN   QUEEN REVERSE
				if(qL2==1){
					std::cout<<" "; 
					for(int p=0 ; p<13 ; p++){
						std::cout << "_"; 
						oP++; cP++;
					}
					cP++;
				}//PRINT TOP LINE OF CARD

				if(qL2==2){
					std::cout << "|"; 
					for(int p=0 ; p<13 ; p++){
						std::cout << " ";
						oP++; cP++;
					}
					std::cout << "|"; 
					cP++;cP++;
				}//PRINT SECOND LINE OF CARD

				if(qL2>2 && qL2<10){
					std::cout << "| "; 
					oP++; cP++; oP++; cP++; 
					for(int k=0 ; k<11 ; k++){
						std::cout << "X" ; 
						oP++; cP++;
					}
					std::cout << " |";
					oP++; cP++;oP++; cP++;
				}

				if(qL2==10){
					std::cout << "|"; 
					cP++;
					for(int d=0 ; d<13 ; d++){
						std::cout << "_";
						cP++;
					}
				}
			}//END   QUEEN REVERSE

			else if(_p2.Cards.Queen.heal[0]>0 && _p2.Cards.Queen.heal[0]<11){//BEGIN   QUEEN NUMBER UP
				for(int k=0 ; k<15 ; k++){//LENGTH OF CARD
					if(cardString.at(p2NR[qL2-1] + k + ((_p2.Cards.Queen.heal[0] - 1)*cO)) == 'o'){
						std::cout << _p2.Cards.Queen.GetSuitCode();
						oP++;cP++;
					}					
					else{
						std::cout << cardString.at(p2NR[qL2-1] + k + (_p2.Cards.Queen.heal[0]-1)*cO); 
						oP++; cP++;
					}
				}
			}//END   QUEEN NUMBER UP
			oP++; oP++;cP--;
		}//END   PLAYER 2 QUEEN LOOP

		if(cP==p1RR[qL1]+cO*2+1){ //BEGIN   PLAYER 1 QUEEN LOOP
			qL1++;
			if(_p1.Cards.Queen.heal[0]==0){//BEGIN   QUEEN REVERSE
				if(qL1==1){ //PRINT TOP LINE OF CARD
					std::cout<<" "; 
					for(int p=0 ; p<13 ; p++){
						std::cout << "_"; 
						oP++; cP++;
					}
					cP++;
				}
				if(qL1==2){
					std::cout << "|"; 
					for(int p=0 ; p<13 ; p++){
						std::cout << " ";
						oP++; cP++;
					}
					std::cout << "|"; 
					cP++;cP++;
				}//PRINT SECOND LINE OF CARD

				if(qL1>2 && qL1<10){
					std::cout << "| "; 
					oP++; cP++; oP++; cP++; 
					for(int k=0 ; k<11 ; k++){
						std::cout << "X"; 
						oP++; cP++;
					}
					std::cout << " |";
					oP++; cP++;oP++; cP++;
				}

				if(qL1==10){
					std::cout << "|"; 
					cP++;
					for(int d=0 ; d<13 ; d++){
						std::cout << "_";
						cP++;
					}
				}
			}//END   QUEEN REVERSE

			else if(_p1.Cards.Queen.heal[0]>0 && _p1.Cards.Queen.heal[0]<11){//BEGIN   QUEEN NUMBER UP
				for(int k=0 ; k<15 ; k++){//LENGTH OF CARD
					if(cardString.at(p1NR[qL1-1] + k + ((_p1.Cards.Queen.heal[0]-1)*cO)) == 'S'){
						std::cout << _p1.Cards.Queen.GetSuitCode();
						oP++;cP++;
					}
					else{
						std::cout << cardString.at(p1NR[qL1-1] + k + (_p1.Cards.Queen.heal[0]-1)*cO); 
						oP++; cP++;
					}
				}
			}//END   QUEEN NUMBER UP
			oP++; oP++;cP--;
		}//END   PLAYER 1 QUEEN LOOP

		if(cP==p2RR[kL2]+cO*4+1){
			kL2++;//BEGIN   PLAYER 2 KING LEFT
			if(_p2.Cards.King.dualWield[0]==0){//BEGIN   KING LEFT REVERSE
				if(kL2==1){std::cout<<" "; 
					for(int p=0 ; p<13 ; p++){
						std::cout << "_"; 
						oP++; cP++;
					}
					cP++;
				}//PRINT TOP LINE OF CARD

				if(kL2==2){
					std::cout << "|"; 
					for(int p=0 ; p<13 ; p++){
						std::cout << " ";
						oP++; cP++;
					}
					std::cout << "|"; 
					cP++;cP++;
				}//PRINT SECOND LINE OF CARD

				if(kL2>2 && kL2<10){
					std::cout << "| "; 
					oP++; cP++; oP++; cP++; 
					for(int k=0 ; k<11 ; k++){
						std::cout << "X" ; 
						oP++; cP++;
					}
					std::cout << " |";
					oP++; cP++;oP++; cP++;
				}

				if(kL2==10){
					std::cout << "|"; 
					cP++;
					for(int d=0 ; d<13 ; d++){
						std::cout << "_";
						cP++;
					} 
					std::cout << "|"; 
					cP++;
				}
				cP--;
			}//END   KING LEFT REVERSE

			else if(_p2.Cards.King.dualWield[0]>0 && _p2.Cards.King.dualWield[0]<11){//NUMBER UP
				for(int k=0 ; k<15 ; k++){//LENGTH OF CARD
					if(cardString.at(p2NR[kL2-1] + k + ((_p2.Cards.King.dualWield[0]-1)*cO)) == 'o'){
						std::cout << _p2.Cards.King.GetSuitCode();
						oP++;cP++;
					}
					else{
						std::cout << cardString.at(p2NR[kL2-1] + k + (_p2.Cards.King.dualWield[0]-1)*cO); 
						oP++; cP++;
					}
				}
			}//END   p2 KING LEFT CARD
			oP++; oP++;cP--;
		}//END   PLAYER 2 KING LEFT


		if(cP==p1RR[kL1]+cO*4+1){ //BEGIN   PLAYER 1 KING LEFT
			kL1++;
			if(_p1.Cards.King.dualWield[0]==0){//BEGIN   KING LEFT REVERSE
				if(kL1==1){
					std::cout<<" ";
					cP++; 
					for(int p=0 ; p<13 ; p++){
						std::cout << "_"; 
						oP++; cP++;
					}
					cP++;
				}
				//PRINT TOP LINE OF CARD

				if(kL1==2){
					std::cout << "|";
					cP++; 
					for(int p=0 ; p<13 ; p++){
						std::cout << " ";
						oP++; cP++;
					}
					std::cout << "|"; 
					cP++;cP++;
				}//PRINT SECOND LINE OF CARD

				if(kL1>2 && kL1<10){
					std::cout << "| ";
					cP++; oP++; cP++; oP++; cP++; 
					for(int k=0 ; k<11 ; k++){
						std::cout << "X" ; 
						oP++; cP++;
					}
					std::cout << " |";
					oP++; cP++;oP++; cP++;
				}

				if(kL1==10){
					cP++;
					std::cout << "|"; 
					cP++;
					for(int d=0 ; d<13 ; d++){
						std::cout << "_";
						cP++;
					} 
					std::cout << "|"; 
					cP++;
				}
				cP--;
			}//END   KING LEFT REVERSE

			else if(_p1.Cards.King.dualWield[0]>0 && _p1.Cards.King.dualWield[0]<11){//BEGIN   p1 KING LEFT FRONT
				for(int k=0 ; k<15 ; k++){//LENGTH OF CARD
					if(cardString.at(p1NR[kL1-1] + k + ((_p1.Cards.King.dualWield[0]-1)*cO)) == 'S'){
						std::cout << _p1.Cards.King.GetSuitCode();
						oP++;cP++;
					}
					else{
						std::cout << cardString.at(p1NR[kL1-1] + k + (_p1.Cards.King.dualWield[0]-1)*cO); 
						oP++; cP++;
					}
				}
			}//END   p1 KING LEFT FRONT
			oP++; oP++;cP--;
		}//END   PLAYER 1 KING LEFT

		if(cP==p2RR[kR2]+cO*6+1){
			kR2++;//BEGIN   PLAYER 2 KING RIGHT

			if(_p2.Cards.King.dualWield[1]==0){//BEGIN   KING RIGHT REVERSE
				if(kR2==1){
					std::cout<<" "; 
					for(int p=0 ; p<13 ; p++){
						std::cout << "_"; 
						oP++; cP++;
					}
					cP++;
				}//PRINT TOP LINE OF CARD

				if(kR2==2){
					std::cout << "|"; 
					for(int p=0 ; p<13 ; p++){
						std::cout << " ";
						oP++; cP++;
					}
					std::cout << "|"; 
					cP++;cP++;
				}//PRINT SECOND LINE OF CARD

				if(kR2>2 && kR2<10){
					std::cout << "| "; 
					oP++; cP++; oP++; cP++; 
					for(int k=0 ; k<11 ; k++){
						std::cout << "X"; 
						oP++; cP++;
					}
					std::cout << " |";
					oP++; cP++;oP++; cP++;
				}

				if(kR2==10){
					std::cout << "|"; 
					cP++;
					for(int d=0 ; d<13 ; d++){
						std::cout << "_";
						cP++;
					} 
					std::cout << "|"; 
					cP++;
				}
				cP--;
			}//END   KING LEFT REVERSE

			else if(_p2.Cards.King.dualWield[1]>0 && _p2.Cards.King.dualWield[1]<11){//NUMBER UP
				for(int k=0 ; k<15 ; k++){//LENGTH OF CARD
					if(cardString.at(p2NR[kR2-1] + k + ((_p2.Cards.King.dualWield[1]-1)*cO)) == 'o'){
						std::cout << _p2.Cards.King.GetSuitCode();
						oP++;cP++;
					}
					else{
						std::cout << cardString.at(p2NR[kR2-1] + k + (_p2.Cards.King.dualWield[1]-1)*cO); 
						oP++; cP++;
					}
				}
				cP--;
			}//END   p2 KING LEFT CARD
			oP++; oP++;
		}//END   PLAYER 2 KING RIGHT

		if(cP==p1RR[kR1]+cO*6+1){
			kR1++;//BEGIN   PLAYER 1 KING RIGHT
			if(_p1.Cards.King.dualWield[1]==0){//BEGIN   KING RIGHT REVERSE
				if(kR1==1){std::cout<<" "; 
					for(int p=0 ; p<13 ; p++){
						std::cout << "_"; 
						oP++; cP++;
					}
					cP++;
				}//PRINT TOP LINE OF CARD

				if(kR1==2){
					std::cout << "|"; 
					for(int p=0 ; p<13 ; p++){
						std::cout << " ";
						oP++; cP++;
					}
					std::cout << "|"; 
					cP++;cP++;
				}//PRINT SECOND LINE OF CARD

				if(kR1>2 && kR1<10){
					std::cout << "| "; 
					oP++; cP++; oP++; cP++; 
					for(int k=0 ; k<11 ; k++){
						std::cout << "X" ; 
						oP++; cP++;
					}
					std::cout << " |";
					oP++; cP++;oP++; cP++;
				}

				if(kR1==10){
					std::cout << "|"; 
					cP++;
					for(int d=0 ; d<13 ; d++){
						std::cout << "_";
						cP++;
					} 
					std::cout << "|"; 
					cP++;
				}
				cP--;
			}//END   KING LEFT REVERSE

			else if(_p1.Cards.King.dualWield[1]>0 && _p1.Cards.King.dualWield[1]<11){//NUMBER UP
				for(int k=0 ; k<15 ; k++){//LENGTH OF CARD
					if(cardString.at(p1NR[kR1-1] + k + ((_p1.Cards.King.dualWield[1]-1)*cO)) == 'S'){
						std::cout << _p1.Cards.King.GetSuitCode();
						oP++;cP++;
					}
					else{
						std::cout << cardString.at(p1NR[kR1-1] + k + (_p1.Cards.King.dualWield[1]-1)*cO); 
						oP++; cP++;
					}
				}
				cP--;
			}//END   p1 KING LEFT CARD
			oP++; oP++;
		}//END   PLAYER 1 KING RIGHT


		//BEGIN   PRINT PLAYER NAMES ON BOARD
		if(cP==2185  - ((_p2.GetFirstName().size()/2) + (_p2.GetFirstName().size()%2)) ){
			for(unsigned int k=0 ; k<_p2.GetFirstName().size() ; k++){
				std::cout<< _p2.GetFirstName().at(k); 
				cP++;
			} 
			cP--;
		}//PRINT PLAYER 2 FIRST NAME

		else if(cP==2459 - ((_p2.GetLastName().size()/2) + (_p2.GetLastName().size()%2))){
			for(unsigned int k=0 ; k<_p2.GetLastName().size() ; k++){
				std::cout<< _p2.GetLastName().at(k); 
				cP++;
			} 
			cP--;
		}//PRINT PLAYER 2 LAST NAME

		else if(cP==3772 - ((_p1.GetFirstName().size()/2) + (_p1.GetFirstName().size()%2)) ){
			for(unsigned int k=0 ; k<_p1.GetFirstName().size() ; k++){
				std::cout<< _p1.GetFirstName().at(k); 
				cP++;
			} 
			cP--;
		}//PRINT PLAYER 1 FIRST NAME

		else if(cP==4046 - ((_p1.GetLastName().size()/2) + (_p1.GetLastName().size()%2)) ){
			for(unsigned int k=0 ; k<_p1.GetLastName().size() ; k++){
				std::cout<< _p1.GetLastName().at(k) ; 
				cP++;
			} 
			cP--;
		}//PRINT PLAYER 2 LAST NAME
		//END OF NAME PRINT PART OF PRINTBOARD FUNCTION

		//BEGIN    PRINT NORMAL CARD FUNCTION
		else if(cardString.at(cP) == 'S'){ 
			std::cout << _p1.Cards.King.GetSuitCode();
		}
		else if(cardString.at(cP) == 'o'){ 
			std::cout << _p2.Cards.King.GetSuitCode();
		}
		else if(cardString.at(cP) == 'c'){ 
			if(_p2.Cards.King.GetHP()<9){
				std::cout << _p2.Cards.King.GetHP() << " "; 
				cP++;
			} 
			else{
				std::cout << _p2.Cards.King.GetHP();
			}
			cP++;
		}
		else if(cardString.at(cP) == 'C'){ 
			if(_p1.Cards.King.GetHP()<9){
				std::cout << _p1.Cards.King.GetHP() << " "; 
				cP++;
			} 
			else{
				std::cout << _p1.Cards.King.GetHP();
			}
			cP++;
		}
		else if(cardString.at(cP) == 'v'){ 
			if(_p2.Cards.Queen.GetHP()<9){
				std::cout << _p2.Cards.Queen.GetHP() << " "; 
				cP++;
			} 
			else{
				std::cout << _p2.Cards.Queen.GetHP();
			}
			cP++;
		}
		else if(cardString.at(cP) == 'V'){ 
			if(_p1.Cards.Queen.GetHP()<9){
				std::cout << _p1.Cards.Queen.GetHP() << " "; 
				cP++;
			} 
			else{
				std::cout << _p1.Cards.Queen.GetHP();
			}
			cP++;
		}
		else if(cardString.at(cP) == 'z'){ 
			if(_p2.Cards.Jack.GetHP()<9){
				std::cout << _p2.Cards.Jack.GetHP() << " "; 
				cP++;
			} 
			else{
				std::cout << _p2.Cards.Jack.GetHP();
			}
			cP++;
		}
		else if(cardString.at(cP) == 'Z'){ 
			if(_p1.Cards.Jack.GetHP()<9){
				std::cout << _p1.Cards.Jack.GetHP() << " "; 
				cP++;
			} 
			else{
				std::cout << _p1.Cards.Jack.GetHP();
			}
			cP++;
		}
		else if(cardString.at(cP) == 'u'){
			std::cout << p2ScoreSum << " " << "points";
			if(p2ScoreSum>100){
				for(int g=0 ; g<9 ; g++){ 
					cP++;
				}
			}
			else if(p2ScoreSum<100){
				for(int  g=0 ; g<8 ; g++){ 
					cP++;
				}
			}
			else if(p2ScoreSum<10){
				for(int  g=0 ; g<7 ; g++){ 
					cP++;
				}
			}
		}

		else if(cardString.at(cP) == 'U'){
			std::cout << p1ScoreSum << " " << "points";
			if(p2ScoreSum>100){
				for(int g=0 ; g<9 ; g++){ 
					cP++;
				}
			}
			else if(p2ScoreSum<100){
				for(int  g=0 ; g<8 ; g++){ 
					cP++;
				}
			}
			else if(p2ScoreSum<10){
				for(int  g=0 ; g<7 ; g++){ 
					cP++;
				}
			}
		}

		else if((_p2.turnTotal == 0)&&(cardString.at(cP) == 'n')){
			if(ftn>9){
				std::cout << ftn; 
				ftn++; 
				cP++;
			}
			else{
				std::cout << " " << ftn; 
				ftn++; 
				cP++;
			}
		}
		else if((_p2.turnTotal > 0)&&(cardString.at(cP) == 'n')){
			std::cout << " "; 
			cP++; 
			ftn++;
		}
		else if((_p1.turnTotal == 0)&&(cardString.at(cP)) == 'N'){
			if(ftN>9){
				std::cout << ftN; 
				ftN++; 
				cP++;
			}
			else{
				std::cout << " " << ftN; 
				ftN++; 
				cP++;
			}
		}
		else if((_p1.turnTotal > 0)&&(cardString.at(cP) == 'N')){
			std::cout << " "; 
			cP++; 
			ftN++; 
		}
		else if(oP==0){
			std::cout << cardString[cP];
		}
	}
}//END   PRINT BOARD FUNCTION


void PrintInstructions(){

std::cout << std::endl;

std::cout << "Suited is written to replicate a card game that uses a standard deck of playing cards. " << std::endl;
std::cout << "The card game is modeled on classic rpg video games in which you control a party of three characters in turn based combat." << std::endl;
std::cout << "Up to 4 people can play at once but this program is single player vs computer." << std::endl;
std::cin.ignore();
std::cout << "Press enter to continue...";
std::cin.get();
std::cout << std::endl;

std::cout << "The game is played by first selecting one of the four suits of cards, " << std::endl;
std::cout << "spades, clubs, hearts, or diamonds. Gather all the cards of that " << std::endl;
std::cout << "suit into your hand. Place the king, queen, and jack in front of you facing up." << std::endl; 
std::cout << "This is your party each of whom you can choose to attack" << std::endl;
std::cout << "with or to use their special ability." << std::endl;
std::cout << std::endl;

std::cout << "The king is a mighty warrior who can duel wield." << std::endl;
std::cout << "The queen a wise witch with healing magic." << std::endl;
std::cout << "The jack a loyal guard who can block and counter attack." << std::endl;
std::cout << std::endl;

std::cout << "Press enter to continue...";
std::cin.get();
std::cout << std::endl;

std::cout << "You hold your 10 number cards (ace is 1) in your hand." << std::endl;
std::cout << "Your turn begins by choosing a character to act with and" << std::endl;
std::cout << "ends when you have played for each character in your party." << std::endl;
std::cout << "You do not have to play each character during every turn." << std::endl;
std::cout << std::endl;

std::cout << "To take action with a character you decide which character you want to use," << std::endl;
std::cout << "whether to attack with them or use their special" << std::endl;
std::cout << "and then use you number cards for the value of their turn." << std::endl;
std::cout << std::endl;

std::cout << "Press enter to continue...";
std::cin.get();
std::cout << std::endl;

std::cout << "For example, you may choose to select the king first and use " << std::endl;
std::cout << "his duel wield special ability to attack the opponent's queen. " << std::endl;
std::cout << "You pick an 8 and a 7 hitting her for 15 damage. " << std::endl;
std::cout << "Now you lay the 8 and 7 face down on the table and can't use them again" << std::endl; 
std::cout << "until you begin a turn with no cards in your hand." << std::endl;
std::cout << std::endl;

std::cout << "During the opponents turn the queen heals herself for 10" << std::endl;
std::cout <<	"then the player uses their jacks special ability by placing a card face down below the jack." << std::endl;
std::cout << "This card is used to deal counter attack damage during an opponents attack which is blocked dealing no damage." << std::endl;
std::cout << std::endl;
std::cout <<	"The jack's special move can be used in response to any opponents attack on any party member." << std::endl;
std::cout << "The jack blocks that party member from taking damage while also dealing the damage of the card played face down on him." << std::endl;
std::cout << std::endl;

std::cout << "Press enter to continue...";
std::cin.get();
std::cout << std::endl;

std::cout << "If you run out of cards before taking action with each character your turn ends and on your next turn all 10 cards return to your hand." << std::endl;
std::cout << std::endl;
std::cout << "The health of the party can vary to shorten or extend games. " << std::endl;
std::cout << "The recommended health levels are Jack 40 , Queen 45 , King 50." << std::endl;
std::cout << "The game is over when only one player has party members left." << std::endl;
std::cout << std::endl;
std::cout << "Select an unseen card from the opponents hand and whoever has the highest number goes first." << std::endl;
std::cout << "Repeat if the cards are the same value until a winner is decided." << std::endl;
std::cout << std::endl;
std::cout << "Let the games, BEGIN!";
std::cout << std::endl;

std::cout << "Press enter to return to menu." << std::endl;
std::cin.get();
std::cout << std::endl;
}//END OF INSTRUCTIONS FUNCTION


//FUNCTION FOR OPTIONS
void OptionsMenu(){
	int opMChoice;

	int loopLeave=0;

	while(loopLeave == 0){

	std::cout << "You've Got Options" << std::endl;
	std::cout << std::endl;
	std::cout << "1: Difficulty" << std::endl;
	std::cout << "2: Life Points" << std::endl;
	std::cout << "3: Back" << std::endl;
	std::cout << "Enter your choice: " ; std::cin >> opMChoice;

	if(isdigit(opMChoice) || opMChoice < 1 || opMChoice > 3){ std::cout << "Not an option." << std::endl; loopLeave=0 ; std::cin.clear() ; std::cin.ignore();}

	switch (opMChoice){

	case 1:{//BEGIN   CASE 1 DIFFICULTY LEVEL
		difficulty = 0;
		while(isdigit(difficulty) || difficulty<1 || difficulty>3){
		std::cout << "Enter a difficulty level." << std::endl;
		std::cout << "1: Easy" << std::endl;
		std::cout << "2: Normal" << std::endl;
		std::cout << "3: Hard" << std::endl;
		std::cout << "Enter difficulty choice: ";
		std::cin >> difficulty;

		std::cout << std::endl;

		if(isdigit(difficulty) || difficulty<1 || difficulty>3){
		std::cout << "Not a valid difficulty level." << std::endl;
		std::cout << "Please try again." << std::endl;
		difficulty = 0;}} break; } //END   CASE 1 DIFFICULTY LEVEL


	case 2:{//BEGIN   CASE 2 GAME LENGTH
		gameLength = 0;
		while(isdigit(gameLength) || gameLength<1 || gameLength>3){
		std::cout << "Adjust Game Length By Choosing Party Life Points." << std::endl;
		std::cout << "1: King - 45HP   Queen - 40HP   Jack - 35HP" << std::endl;
		std::cout << "2: King - 50HP   Queen - 45HP   Jack - 40HP" << std::endl;
		std::cout << "3: King - 55HP   Queen - 50HP   Jack - 45HP" << std::endl;
		std::cout << "Enter Life Choice: ";
		std::cin >> gameLength ; std::cout << std::endl;

		if(isdigit(gameLength) || gameLength<1 || gameLength>3){
            std::cout << "Not a valid life choice." << std::endl << "Please try again." << std::endl ; 
            std::cin.clear() ; 
            std::cin.ignore() ; 
            gameLength = 0;}
		} break; }//END   CASE 2 GAME LENGTH

	case 3:{loopLeave = 1;break;}
	}}
    
    }


