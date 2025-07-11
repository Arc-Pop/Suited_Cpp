#include "player.h"

#include <string>
#include <iostream>

#ifndef PRINT_H_
#define PRINT_H_


void CenterPrint(const std::string centerThis);

void ClearScreen();

int MainMenu();

int PlayGame();

void PrintBoard(Player _p1 , Player _p2);

void PrintInstructions();

void OptionsMenu();


#endif

