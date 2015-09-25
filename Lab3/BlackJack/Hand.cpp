#include "Hand.h"
#include <vector>
#include <string>
#include <stdlib.h>
#include <iostream>
#include <ctime>


Hand::Hand(std::string holder)
    :hand_holder(holder), number_of_aces(0)
{
    addCard();
   
    addCard();
}

void Hand::addCard() {
    int temp;
    //srand((unsigned)time(0));
    temp = rand() % 13 + 1;
    switch (temp)
    {
        case 1:
            card_types.push_back("Ace");
            number_of_aces++;
            break;
        case 2:
            card_types.push_back("Two");
            card_values.push_back(2);
            break;
        case 3:
            card_types.push_back("Three");
            card_values.push_back(3);
            break;
        case 4:
            card_types.push_back("Four");
            card_values.push_back(4);
            break;
        case 5:
            card_types.push_back("Five");
            card_values.push_back(5);
            break;
        case 6:
            card_types.push_back("Six");
            card_values.push_back(6);
            break;
        case 7:
            card_types.push_back("Seven");
            card_values.push_back(7);
            break;
        case 8:
            card_types.push_back("Eight");
            card_values.push_back(8);
            break;
        case 9:
            card_types.push_back("Nine");
            card_values.push_back(9);
            break;
        case 10:
            card_types.push_back("Ten");
            card_values.push_back(10);
            break;
        case 11:
            card_types.push_back("Jack");
            card_values.push_back(10);
            break;
        case 12:
            card_types.push_back("Queen");
            card_values.push_back(10);
            break;
        case 13:
            card_types.push_back("King");
            card_values.push_back(10);
            break;
        default:
            std::cout << "No Card Type";
            break;
            }
    }

    void Hand::printHand (){
        unsigned long size;
        size = card_types.size();
        int i;
        for (i = 0; i < size; i++) {
            std::cout << card_types[i] << " ";
        }

        
    }
    
    void Hand::printFirstCard () {
        std::cout << card_types[0];
    }
    
    int Hand::handValue() {
        unsigned long size;
        size = card_values.size();
        int Value = 0;
        int Temp;
        int i;
        for (i = 0; i < size; i++) {
            Value = Value + card_values[i];
        }
        for (i = 0; i < number_of_aces; i++) {
            Temp = Value + 11;
            if (Temp > 21)
                Value = Value + 1;
            else
                Value = Value + 11;
        }
        return Value;
    }








