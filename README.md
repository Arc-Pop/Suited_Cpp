History:
Suited is a playing card game which was inspired by classic RPG video games where 3 member parties battle each other in turn based combat.

I created the Suited card game several years ago when I was involved in a table top game group which led me to think about how to make a game that was more accessible than the ones we were playing which often involved many trading cards, models, or other game components.

During my second semester as a Computer Engineering student I took a class called "Introduction to Programming" in which I learned C++ and the final project was to develop a simple text based game. I decided to make a version of the Suited card game using text based graphics using unicode symbols. The starting point for this repository is the final result from that class which is a working game that got me an "A" but which in hindsight has cluttered code and could be better. The computer opponent doesn't have any artifical intelligence and makes random choices.

I'm publishing the original working version first, but I've already begun work on remaking the game, cleaning up the code and eventually I plan to improve the way the computer opponent works. I will immediately create a new branch from the work I've done so far which isn't yet a complete program but which will run and all new development will be to that branch. When all the basic features of the game are working in the new branch I will merge it into the main.

This game is primarily played by running the program in an IDE but the end goal is to have a game that can be played in a Linux terminal.


How to Play Suited:
Suited can be played with 2 to 4 players but this implemention is limited to either 2 players against each other of 1 vs computer.
The game is played by first selecting one of the four suits of cards, spades, clubs, hearts, or diamonds. Gather all the cards of that suit into your hand. Place the king, queen, and jack in front of you facing up. This is your party each of who you can choose to attack with or use their special ability.

The king is a mighty warrior who can duel wield.
The queen a wise witch with healing magic.
The jack a loyal guard who can block and counter attack.

You hold your 10 number cards (ace is 1) in your hand. Your turn begins by choosing a character to act with and ends when you have played for each character in your party.
You do not have to play each character during every turn.
To take action with a character you decide which character you want to use, whether to attack with them or use their special and then use you number cards for the value of their turn.

For example, you may choose to select the king first and use his duel wield special ability to attack the opponent's queen.
You pick an 8 and a 7 hitting her for 15 damage. 
Now you lay the 8 and 7 face down on the table and can't use them again until you begin a turn with no cards in your hand.

During the opponents turn the queen heals herself for 10 then the player uses their jacks special ability by placing a card face down below the jack.
This card is used to deal counter attack damage during an opponents attack which is blocked dealing no damage.
The jack's special move can be used in response to any opponents attack on any party member.
The jack blocks that party member from taking damage while also dealing the damage of the card played face down on him.

If you run out of cards before taking action with each character your turn ends and on your next turn all 10 cards return to your hand.
The health of the party can vary to shorten or extend games. The recommended health levels are Jack 40 , Queen 45 , King 50. 
The game is over when only one player has party members left.

Select an unseen card from the opponents hand and whoever has the highest number goes first.
Repeat if the cards are the same value until a winner is decided.
Let the games, BEGIN!
