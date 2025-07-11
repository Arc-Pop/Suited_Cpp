#include <iostream>
#include <vector>
#include <string>

#include "../lib/print.h"
#include "../lib/player.h"

using namespace std;

int main()
{
    
    int menuSelection=0;
    
    while(menuSelection!=4){
    menuSelection = MainMenu();

    switch(menuSelection){
        case 1:
        PlayGame();
        break;

        case 2:
        PrintInstructions();
        break;

        case 3:
        OptionsMenu();
        break;
    }


    }
    return 0;
}