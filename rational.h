#pragma once
#include <numeric>
#include <iostream>
#include <cstdint>

//класс Rational.
class Rational {
public:
    Rational() = default;
    Rational(int num) : numerator_(num) {};
    Rational(int num, int denum) : numerator_(num), denominator_(denum) {
        if (denominator_ == 0) {
            abort();
        }
        Reduction();
    };
    Rational(const Rational& rt) {
        numerator_ = rt.numerator_;
        denominator_ = rt.denominator_;
    }

    //operator +-/*
    inline Rational operator+(const Rational& rt) const{
        int numerator = numerator_ * rt.denominator_ + denominator_ * rt.numerator_;
        int denominator = denominator_ * rt.denominator_;
        Rational result(numerator, denominator);
        result.Reduction();
        return result;
    }
    inline Rational operator-(const Rational& rt) const{
        int numerator = numerator_ * rt.denominator_ - denominator_ * rt.numerator_;
        int denominator = denominator_ * rt.denominator_;
        Rational result(numerator, denominator);
        result.Reduction();
        return result;
    }
    inline Rational operator*(const Rational & rt) const{
        int numerator = numerator_ * rt.numerator_;
        int denominator = rt.denominator_ * denominator_;
        Rational result(numerator, denominator);
        result.Reduction();
        return result;
    }
    inline Rational operator/(const Rational& rt) const{
        int numerator = numerator_ * rt.denominator_;
        int denominator = denominator_ * rt.numerator_;
        Rational result(numerator, denominator);
        result.Reduction();
        return result;
    }

    //operator += -= *= /=
    inline Rational& operator+=(const Rational& rt){
        numerator_ = numerator_ * rt.denominator_ + denominator_ * rt.numerator_;
        denominator_ = denominator_ * rt.denominator_;
        Reduction();
        return *this;
    }
    inline Rational& operator-=(const Rational& rt){
        numerator_ = numerator_ * rt.denominator_ - denominator_ * rt.numerator_;
        denominator_ = denominator_ * rt.denominator_;
        Reduction();
        return *this;
    }
    inline Rational& operator*=(const Rational& rt){
        numerator_ = numerator_ * rt.numerator_;
        denominator_ = rt.denominator_ * denominator_;
        Reduction();
        return *this;
    }
    inline Rational& operator/=(const Rational& rt){
        numerator_ = numerator_ * rt.denominator_;
        denominator_ = denominator_ * rt.numerator_;
        Reduction();
        return *this;
    }

    //operator =
    inline Rational& operator=(const Rational& rt) {
        numerator_ = rt.numerator_;
        denominator_ = rt.denominator_;
        return *this;
    }

    //operator -+
    inline Rational operator-() const{
        return Rational(-numerator_, denominator_);
    }
    inline Rational operator+() const{
        return *this;
    }

    //operator << >>
    friend std::istream& operator>>(std::istream& is, Rational& rt);
    friend std::ostream& operator<<(std::ostream& os, const Rational& rt);


    inline Rational Inv() const {
        return Rational(denominator_, numerator_);
    }
    int GetNumerator() const {
        return numerator_;
    }
    int GetDenominator() const {
        return denominator_;
    }

    //operator == <=>

private:
    inline void Reduction(){
        if (denominator_ < 0) {
            numerator_ = -numerator_;
            denominator_ = -denominator_;
        }
        const int divisor = std::gcd(numerator_, denominator_);
        numerator_ /= divisor;
        denominator_ /= divisor;
    }
    int numerator_{};
    int denominator_ = 1;
};

inline std::istream& operator>>(std::istream& is, Rational& rt) {
    int a, b = 1;
    char c;
    if (!(is >> a)) {
        return is;
    }
    if (is >> c) {
        if (c == '/') {
            if (!(is >> b)) {
                return is;
            }
            if (b == 0) {
                is.setstate(std::ios::failbit);
                return is;
            }
        }
        else is.unget();
    }
    else is.clear();
    rt.numerator_ = a;
    rt.denominator_ = b;
    return is;
}

inline std::ostream& operator<<(std::ostream& os, const Rational& rt) {
    if (rt.denominator_ == 1) {
        os << rt.numerator_;
        return os;
    }
    os << rt.numerator_ << " / " << rt.denominator_;
    return os;
}
//operator <=> ==
inline auto operator<=>(const Rational& rt1, const Rational& rt2) {
    std::int64_t a = static_cast<std::int64_t>(rt1.GetNumerator()) * rt2.GetDenominator();
    std::int64_t b = static_cast<std::int64_t>(rt1.GetDenominator()) * rt2.GetNumerator();
    return a <=> b;
}
inline bool operator==(const Rational& rt1, const Rational& rt2) {
    std::int64_t a = static_cast<std::int64_t>(rt1.GetNumerator()) * rt2.GetDenominator();
    std::int64_t b = static_cast<std::int64_t>(rt1.GetDenominator()) * rt2.GetNumerator();
    return a == b;
}
