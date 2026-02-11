#pragma once
#include <string>
using Number = double;


class Calculator{
    bool cell_status_ = false;
    Number n_{};
    Number saved_number_{};
public:
    void Set(Number n);
    Number GetNumber() const;
    void Add(Number n);
    void Sub(Number n);
    void Div(Number n);
    void Mul(Number n);
    void Pow(Number n);
    std::string GetNumberRepr() const;

};
