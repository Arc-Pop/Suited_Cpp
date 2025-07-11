#include "../lib/numberCards.h"


NumberCards::NumberCards() {

    for(int i=0; i<10; i++){
        numberCards[i] = i+1;
        emptyCards[i] = 0;
        tempCards[i] = 0;
    }

}

NumberCards::~NumberCards() {
	// TODO Auto-generated destructor stub
}

