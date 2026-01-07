#include "calculator.h"
#include <cmath>
#include <iostream>
#include <string>

using Number = double;

bool ReadNumber(Number& result){
    if (!(std::cin >> result)) {
            std::cerr << "Error: Numeric operand expected" << std::endl;
            return false;
    }
    return true;
}
bool CalculatorCommand(){
    bool flag = false;

    Number number;

    if(!ReadNumber(number)){
        return false;
    }

    std::string token;
    Number saved_number;
    Number second_number;
    while(std::cin >> token){
     
        if(token == "q"){
            return true;
        }
        if(token == "="){
            std::cout << number << std::endl;
            continue;
        }
        if(token == "c"){
            number = 0;
            continue;
        }
        if(token == "s"){
            saved_number = number;
            flag = true;
            continue;
        }
        if(token == "l"){
            if(!flag){
                std::cerr << "Error: Memory is empty" << std::endl;
                return false;
            }
            else number = saved_number;
            continue;
        }

        if(token == "+" || token == "-" ||
           token == "*" || token == "/" ||
           token == "**" || token == ":"){
            if (!(std::cin >> second_number)) {
                std::cerr << "Error: Numeric operand expected" << std::endl;
                return false;
            }
            if(token == "+"){
                number += second_number;
                continue;
            }
            if(token == "-"){
                number -= second_number;
                continue;
            }
            if(token == "*"){
                number *= second_number;
                continue;
            }
            if(token == "/"){
                number /= second_number;
                continue;
            }
            if(token == "**"){
                number = std::pow(number, second_number);
                continue;
            }
            if(token == ":"){
                number = second_number;
                continue;
            }
        }
        else{
            std::cerr << "Error: Unknown token " + token << std::endl;
            return false;
        }  
    }
    return false;
}

bool RunCalculatorCycle(){
    return CalculatorCommand();
}