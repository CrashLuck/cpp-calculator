#pragma once
#include <string>

using Number = double;

bool RunCalculatorCycle();

bool ReadNumber(Number& result);

bool CalculatorCommand(std::string token, Number& number);
