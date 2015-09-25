// Definition of class Hand, but only function prototypes included
// (header file)

#include <vector>
#include <string>

class Hand 
{
private:
   std::vector <std::string> card_types;   // the card names in the hand 
   std::vector <int> card_values;   //  the card values in the hand
   std::string hand_holder;  // either 'Player' or 'Dealer'
   int number_of_aces;  //  the number of aces, useful for calculating hand value

public:
   explicit Hand(std::string);  // constructor, sets hand_holder and calls addCard twice
   void addCard();  //  adds a randomly chosen card to the hand
   void printHand();  //  prints the card_types vector
   void printFirstCard();  // prints only the first card in the hand (used for dealer)
   int handValue();  // calculates the hand's value
   
};
