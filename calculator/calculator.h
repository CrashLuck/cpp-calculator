#pragma once

#include <string>
#include <optional>
#include <cmath>
#include "rational.h"
#include "pow.h"

using Error = std::string;


// Реализация шаблонного калькулятора.
template <typename Number>
class Calculator{
    std::optional<Number>mem_ = std::nullopt;
    Number n_{};
public:
    inline void Save(){
        mem_ = n_;
    }
    inline void Load(){
        if(mem_.has_value()){
            n_ = mem_.value();
        }
    }
    inline bool GetHasMem(){
        return mem_.has_value();
    }
    inline std::optional<Error> Set(Number n){
        this->n_ = n;
        return std::nullopt;
    }
    inline Number GetNumber() const{
        return n_;
    }
    inline std::optional<Error> Add(Number n){
        n_ += n;
        return std::nullopt;
    }
    inline std::optional<Error> Sub(Number n){
        n_ -= n;
        return std::nullopt;
    }
    inline std::optional<Error> Div(Number n){
        if constexpr(std::is_floating_point_v<Number>){
            n_ /= n;
            return std::nullopt;
        }
        else{
            if(n == Number{0}){
                return "Division by zero";
            }
        n_ /= n;
        return std::nullopt;
        }
    }
    inline std::optional<Error> Mul(Number n){
        n_ *= n;
        return std::nullopt;
    }
    inline std::optional<Error> Pow(Number n){
        auto is_zero = [this, n](){return n_ == Number{0} && n == Number{0};};

        if constexpr(std::is_integral_v<Number>){
            if(is_zero()){
                return "Zero power to zero";
            }
            if(n < Number{0}){
                return "Integer negative power";
            }
            n_ = IntegerPow(n_, n);
            return std::nullopt;
        }
        else if constexpr(std::is_same_v<Number, Rational>){
            if(is_zero()){
                return "Zero power to zero";
            }
            if(n.GetDenominator() != 1){
                return "Fractional power is not supported";
            }
            n_ = ::Pow(n_, n);
            return std::nullopt;
        }
        else{
            n_ = std::pow(n_, n);
            return std::nullopt;
        }
    }

    inline std::string GetNumberRepr() const{
        return std::to_string(n_);
    }

};

