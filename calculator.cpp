#include "calculator.h"

void Calculator::Set(Number n){
    this->n_ = n;
}
Number Calculator::GetNumber() const{
    return n_;
}
void Calculator::Add(Number n){
    n_ += n;
}
void Calculator::Sub(Number n){
    n_ -= n;
}
void Calculator::Div(Number n){
    n_ /= n;
}
void Calculator::Mul(Number n){
    n_ *= n;
}
void Calculator::Pow(Number n){
    Number a = n_;
    for(size_t i{1}; i != n; ++i){
        n_ *= a;
    }
}

std::string Calculator::GetNumberRepr() const{
    return std::to_string(n_);
}
