#include "Card.h"
#include <iostream>
#include <string>
#include <fstream>
#include <cassert>
#include <vector>
#include "King.h"
#include "Queen.h"
#include "Jack.h"
#include <chrono>


using namespace std;

Card::Card(){
    suit = "Spades" ; suitCode = spade ; suitNum = 4 ;
    for(unsigned int i=1 ; i<11 ; i++){ numberCards[i-1] = i ; emptyCards[i-1] = 0 ; tempCards[i-1] = 0 ; }}



Card::Card(int p1S){
SetSuit(p1S) ; suitCode = spade ; suitNum = 4;
for(unsigned int i=1 ; i<11 ; i++){ numberCards[i-1] = i ; tempCards[i-1] = 0;} }



string Card::GetSuit(){return suit;}



int Card::GetSuitNum(){ return suitNum;}



string Card::GetSuitCode(){ return suitCode;}



void Card::SetSuit(int p1S){
	switch (p1S){

	case 1:{ suit = "Clubs" ; suitNum = 1 ; suitCode = club ; break ; }

	case 2:{ suit = "Diamonds" ; suitNum = 2 ; suitCode = diamond ; break ; }

	case 3:{ suit = "Hearts" ; suitNum = 3 ; suitCode = heart ; break;}

	case 4:{ suit = "Spades" ; suitNum = 4 ; suitCode = spade ; break;}}}



void Card::Print(){
    cout << suit << endl;
}



//FUNCTION: PRINT PARTY CARDS
void Card::PrintParty(string suitName){
	ifstream fin("cardASCI.txt");
	string cardString = "";
	while(getline(fin , cardString)){
		cout << center("" , 52);
		for(unsigned int i=0 ; i<cardString.size() ; i++){
			if(cardString.at(i) == 'S'){
				if(suit=="Clubs"){cout << club;}
				else if(suit=="Diamonds"){cout << diamond;}
				else if(suit=="Hearts"){cout << heart;}
				else if(suit=="Spades"){cout << spade;}
				}
			else{ cout << cardString[i];}
	}
		cout << endl;

}
	fin.close();
}





/*
 FUNCTION for centering text. TAKEN from this website:
 https://stackoverflow.com/questions/17512825/align-text-to-center-in-string-c
 */
string Card::center(const std::string& s, unsigned width)
{
    assert (width > 0);
    if (int padding = width - s.size (), pad = padding >> 1; pad > 0)
        return std::string (padding, ' ').insert (pad, s);
    return s;
}



int Card::SuitSelection(int takenSuit){//BEGIN   FUNCTION: MENU FOR SELECTING A SUIT

	int pSuitNum = 0 ; while(pSuitNum == 0){//BEGIN    PRINT MENU UNTIL IN RANGE OPTION IS SELECTED

	if(takenSuit != 1){cout << " 1: Clubs" << endl;}
	else{ for(unsigned int i=0 ; i<11 ; i++){ cout << "\u2667"; } cout << endl;}

	if(takenSuit != 2){cout << " 2: Diamonds" << endl;}
	else{ for(unsigned int i=0 ; i<11 ; i++){ cout << "\u2666"; } cout << endl;}

	if(takenSuit != 3){cout << " 3: Hearts" << endl;}
	else{ for(unsigned int i=0 ; i<11 ; i++){ cout << "\u2665"; } cout << endl;}

	if(takenSuit != 4){cout << " 4: Spades" << endl;}
	else{ for(unsigned int i=0 ; i<11 ; i++){ cout << "\u2664"; } cout << endl;}

	cout << endl << "Enter a number to choose suit: ";

	cin >> pSuitNum;

	//CHECK IF SUIT SELECTION IS IN RANGE
	if(isdigit(pSuitNum) || pSuitNum < 1 || pSuitNum > 4){ cout << "Invalid choice entered. Please try again." << endl ; cin.clear() ; cin.ignore() ; pSuitNum=0 ; }
	else if(pSuitNum == takenSuit && pSuitNum!=0){ cout << "Suits taken! Please pick a different suit." << endl << endl ; cin.clear() ; cin.ignore() ; pSuitNum=0 ; }
	}//END    PRINT MENU UNTIL IN RANGE OPTION IS SELECTED
	return pSuitNum;}//END   FUNCTION: MENU FOR SELECTING A SUIT




void Card::CardSwap(int cardSet1[] , int cardSet2[]){
	int swapCards[10];
	for(int i=0 ; i<10 ; i++){
		swapCards[i] = cardSet1[i];
		cardSet1[i] = cardSet2[i];
		cardSet2[i] = swapCards[i];
	}
}



