#include <vector>
#include <string>
#include <iostream>
#include "Hand.h"
using namespace std;

int main()
{
    int PlayerTotal;
    int DealerTotal;
    int Fail = 0;
    int Balance = 300;
    int Round = 1;
    int Wager = 1;
    char Option;
    char DoubleWager;
    int Flag;
    cout << "Player starts with " << Balance << " dollars" << endl;
    cout << endl;
    while (1) {
        int Cards = 2;
        Hand Player("Player");
        Hand Dealer("Dealer");
        Option = 'h';
        PlayerTotal = 0;
        DealerTotal = 0;
        Flag = 0;
        if (Balance == 0)
        {
            cout << "Better Luck Next Time. Go home!" << endl;
            cout << endl;
            exit(0);
        }
        
        if (Fail != 1) {
            cout << "Round " << Round << endl;
        }
        
        cout << "Enter Wager in dollars, 0 to quit: ";
        cin >> Wager;
        if (cin.fail()) {
            cin.clear();
            cin.ignore();
            cout << "Only whole numbers work." << endl<< endl;
            Fail = 1;
        } else if (Wager > Balance ) {
            cout << "Not enough money. Try lowering your bet." << endl << endl;
            Fail = 1;
        } else if (Wager == 0) {
            break;
        }
        else {
            Fail = 0;
            cout << "Dealer's first card is: ";
            Dealer.printFirstCard();
            cout << endl;
            cout << endl;
            
            cout << "Player's hand is: ";
            Player.printHand();
            cout << endl;
            cout << "Player's hand value is " << Player.handValue() << endl;
            PlayerTotal = Player.handValue();
            if (Wager*2 > Balance) {
                cout << "Can't Double Down" << endl;;
                DoubleWager = 'n';
            } else if (PlayerTotal != 21) {
                cout << "Double Down? (y) or (n): ";
                cin >> DoubleWager;
                while (DoubleWager != 'y' && DoubleWager != 'n') {
                    cout << "Wrong input!" << endl;
                    cout << "Double Down? (y) or (n): ";
                    cin >> DoubleWager;
                }
            }
            
            
            if (DoubleWager == 'y') {
                Wager = Wager*2;
                Player.addCard();
                Cards++;
                PlayerTotal = Player.handValue();
                cout << "Player's hand is: ";
                Player.printHand();
                cout << endl;
                cout << "Player's hand value is " << Player.handValue() << endl;
                
                DoubleWager = 'n';
                Flag = 1;
                
            }
            
            if (DoubleWager == 'n') {
                if (Flag == 0) {
                    while (Option != 's' && PlayerTotal < 21) {
                        
                        
                        cout << "What would you like to do?  Enter (h)it or (s)tand: ";
                        
                        cin >> Option;
                        switch (Option) {
                            case 'h':
                                Player.addCard();
                                Cards++;
                                cout << endl;
                                PlayerTotal = Player.handValue();
                                cout << "Player's hand is: ";
                                Player.printHand();
                                cout << endl;
                                cout << "Player's hand value is " << Player.handValue() << endl;
                                break;
                            case 's':
                                PlayerTotal = Player.handValue();
                                break;
                            default:
                                cout << "Wrong input!" << endl;
                                break;
                        }
                        
                    }
                }
                cout << endl;
                cout << "Dealer's hand is: ";
                Dealer.printHand();
                cout << endl;
                cout << "Dealer's hand value is " << Dealer.handValue() << endl;
                cout << endl;
                
                while (DealerTotal < 17 & PlayerTotal <= 21) {
                    Dealer.addCard();
                    cout << "Dealer's hand is: ";
                    Dealer.printHand();
                    cout << endl;
                    cout << "Dealer's hand value is " << Dealer.handValue() << endl;
                    DealerTotal = Dealer.handValue();
                    cout << endl;
                }
                
                if (PlayerTotal > 21) {
                    cout << "Player's hand is bust." << endl;
                    Balance = Balance - Wager;
                    cout << "Player has " << Balance << " dollars" << endl;
                    cout << endl;
                } else if (DealerTotal > 21) {
                    if (PlayerTotal == 21 && Cards == 2) {
                        cout << "Player has BlackJack!" << endl;
                        Balance = Balance + 1.5 * Wager;
                    } else {
                        cout << "Dealer's hand is bust. Player wins!" << endl;
                        Balance = Balance + Wager;
                    }
                    cout << "Player has " << Balance << " dollars" << endl;
                    cout << endl;
                } else if (PlayerTotal > DealerTotal) {
                    
                    if (PlayerTotal == 21 && Cards == 2) {
                        cout << "Player wins with a BlackJack!" << endl;
                        Balance = Balance + 1.5 * Wager;
                    } else {
                        cout << "Player wins!" << endl;
                        Balance = Balance + Wager;
                    }
                    cout << "Player has " << Balance << " dollars" << endl;
                    cout << endl;
                }
                
                else if (PlayerTotal == DealerTotal) {
                    cout << "Push." << endl;
                    cout << "Player has " << Balance << " dollars" << endl;
                    cout << endl;
                }
                
                else if (DealerTotal > PlayerTotal) {
                    cout << "Dealer wins." << endl;
                    Balance = Balance - Wager;
                    cout << "Player has " << Balance << " dollars" << endl;
                    cout << endl;
                }
                
            }
        }
        if (Fail != 1) {
            Round ++;
            
        }
        
    }
    
    return 0;
}
