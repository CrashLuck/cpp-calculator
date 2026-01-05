#include "calculator.h"
#include <cmath>
#include <iostream>
#include <vector>

bool ReadNumber(Number& result){
    if (!(std::cin >> result)) {
            std::cerr << "Error: Numeric operand expected" << std::endl;
    }
    return true;
}
bool CalculatorCommand(std::string token, Number& number){
    std::vector<Number> arr;
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
            arr.push_back(number);
            continue;
        }
        if(token == "l"){
            if(arr.empty()){
                std::cerr << "Error: Memory is empty" << std::endl;
                return false;
            }
            else number = arr.back();
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
    Number number;
    ReadNumber(number);
    std::string token;
    CalculatorCommand(token, number);
    return true;
}
