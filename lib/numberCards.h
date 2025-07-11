#ifndef NUMBERCARDS_H_
#define NUMBERCARDS_H_

#include "card.h"

class NumberCards : public Card{
public:

    NumberCards();

	virtual ~NumberCards();

    int numberCards[10];

    int emptyCards[10];

    int tempCards[10];

private:

protected:

};

#endif /* NUMBERCARDS_H_ */