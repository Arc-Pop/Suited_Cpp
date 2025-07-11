#include "../lib/player.h"

#include "../lib/print.h"

#include <iostream>
#include <string>
#include <fstream>
#include <cassert>
#include <vector>
#include <chrono>
#include <thread>


Player::Player() {
	firstName = "King's";
	lastName = "Advisor";
	turnTotal = 0;
	cardSet = 0;
}


Player::Player(string _firstName , string _lastName, int _suit){
	firstName = _firstName;
	lastName = _lastName;

	this->Cards.King.SetSuit(_suit);
	this->Cards.Queen.SetSuit(_suit);
	this->Cards.Jack.SetSuit(_suit);
	this->Cards.Number.SetSuit(_suit);
}


Player::~Player() {
	// TODO Auto-generated destructor stub
}


string Player::GetFirstName(){return firstName;}


string Player::GetLastName(){return lastName;}


void Player::MakePlayer(){

	ClearScreen();

	std::string fN="";//FIRST NAME
	std::string lN="";//LAST NAME

	while(fN.size()>15 || fN.size()<1){
		std::cout << "Enter your first name or 0 to return to previous menu: ";		
		std::cin.clear();
		std::cin.ignore();
		std::getline(cin , fN);

		if(fN=="0"){
			ClearScreen();
			return;
		}

		if(fN.size()>15){
			std::cout << "That name is too long." << std::endl;
			std::cout << "First name must be 14 characters or less." << std::endl;
			std::cout << "Please try again.";
			std::cin.clear();
			std::cin.ignore();
		}
	

		if(fN.size()<1){
			std::cout << "That name is too short." << std::endl;
			std::cout << "First name must be 1 character or more." << std::endl;
			std::cout << "Please try again.";
			std::cin.clear();
			std::cin.ignore();
		}

		int nameCheck = 0;
		while(nameCheck != 1 && nameCheck != 2){
		std::cout << "Your first name is " << fN << ". ";
		std::cout << "Is that correct? " << std::endl;
		std::cout << "1: Yes" << std::endl;
		std::cout << "2: No" << std::endl;
		std::cout << "Type 1 or 2 and then press Enter: ";
		std::cin >> nameCheck;
			if(nameCheck != 1 && nameCheck != 2){ 
				std::cout << "Invalid input." << std::endl << std::endl;
				std::cin.clear();
				std::cin.ignore();
			}
			else if(nameCheck == 2){ 
				fN = "";
			}
		}
		std::cout << std::endl;
	}

	while((lN.size()>15 || lN.size()<1)){
		std::cout << "Enter your last name or 0 to return to previous menu: ";
		std::cin.clear();
		std::cin.ignore();
		std::getline(cin , lN);

		if(lN=="0"){
			ClearScreen() ; 
			return;
		}


		if(fN.size()>15){
			std::cout << "That name is too long." << endl;
			std::cout << "Last name must be 14 characters or less." << endl;
			std::cout << "Please try again." << endl;
			std::cin.clear();
			std::cin.ignore();
		}
		else if(lN.size()<1){
				std::cout << "That name is too short." << endl;
				std::cout << "Last name must be 1 character or more." << endl;
				std::cout << "Please try again." << endl;
				std::cin.clear();
				std::cin.ignore();
			}

		int nameCheck = 0;
		while(nameCheck != 1 && nameCheck != 2){
		std::cout << "Your last name is " << lN << ". ";
		std::cout << "Is that correct? " << std::endl;
		std::cout << "1: Yes" << std::endl;
		std::cout << "2: No" << std::endl;
		std::cout << "Type 1 or 2 and then press Enter: ";
		std::cin >> nameCheck;
			if(nameCheck != 1 && nameCheck != 2){ 
				std::cout << "Invalid input." << std::endl << std::endl;
				std::cin.clear();
				std::cin.ignore();
			}
			else if(nameCheck == 2){ 
				lN = "";
			}
		}
		std::cout << std::endl;
	}
	
	int suitChoice=0;

	while(suitChoice<1 || suitChoice>4){

		std::cout << "1: Clubs" << std::endl;
		std::cout << "2: Diamonds" << std::endl;
		std::cout << "3: Hearts" << std::endl;
		std::cout << "4: Spades" << std::endl;
		std::cout << "Please choose a card suit or 0 to return to previous menu: ";

		std::cin.clear();
		std::cin.ignore();
		std::cin >> suitChoice; 

		if(suitChoice==0){
			return;
		}
		else if(suitChoice<1 || suitChoice>4){
			std::cout << "Invalid input." << std::endl << std::endl;
			std::cin.clear();
			std::cin.ignore();
		}
		
		std::string suitType;

		switch(suitChoice){
			case 1: suitType = "Clubs"; break;
			case 2: suitType = "Diamonds"; break;
			case 3: suitType = "Hearts"; break;
			case 4: suitType = "Spades"; break;
		}

		int suitCheck = 0;
		while(suitCheck != 1 && suitCheck != 2){
		std::cout << "Your suit choice is " << suitType << ". ";
		std::cout << "Is that correct? " << std::endl;
		std::cout << "1: Yes" << std::endl;
		std::cout << "2: No" << std::endl;
		std::cout << "Type 1 or 2 and then press Enter: ";
		std::cin >> suitCheck;
			if(suitCheck != 1 && suitCheck != 2){ 
			std::cout << "Invalid input." << std::endl << std::endl;
			std::cin.clear();
			std::cin.ignore();
			}
			else if(suitCheck == 2){ 
				suitChoice = 0;
			}
		}

	}

	this->firstName = fN;
	this->lastName = lN;

	this->Cards.King.SetSuit(suitChoice);
	this->Cards.Queen.SetSuit(suitChoice);
	this->Cards.Jack.SetSuit(suitChoice);
	this->Cards.Number.SetSuit(suitChoice);

	ClearScreen();

	return;
}