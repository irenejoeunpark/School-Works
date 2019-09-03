// TODO: insert header files
#include "Fraction.h"
#include <iostream>
using namespace std;

// TODO: continue the namespace
namespace sict {


	// TODO: implement the default constructor
	Fraction::Fraction() {

		this->numerator = 0;
		this->denominator = 0;


	}
	// TODO: implement the two-argument constructor

	Fraction::Fraction(int n, int d) {
		if (n >= 0 && d > 0) {
			this->numerator = n;
			this->denominator = d;
			reduce();
		}
		else {
			this->numerator = 0;
			this->denominator = 0;
		}

	}

	
	
	
	// TODO: implement the max query
	int Fraction::max() const
	{

		int result;
		if (this->numerator > this->denominator) {
			result = this->numerator;
		}
		else if (this->numerator < this->denominator) {
			result = this->denominator;
		}
		else {

			result = this->denominator;
		}

		return result;
	}

    // TODO: implement the min query
	int Fraction::min() const
	{

		int result;
		if (this->numerator > this->denominator)
			result = this->denominator;
		else if (this->numerator < this->denominator)
			result = this->numerator;
		else
			result = this->denominator;


		return result;

	}
	// gcd returns the greatest common divisor of num and denom
    //
    int Fraction::gcd() const
	{
        int mn = min();  // min of numerator and denominator
        int mx = max();  // max of numerator and denominator
        int gcd_1 = 1;
        bool found = false;

        for (int x = mn; !found && x > 0; --x) { // from mn decrement until divisor found
            if (mx % x == 0 && mn % x == 0) {
                found = true;
                gcd_1 = x;
            }
        }
        return gcd_1;
    }

    // TODO: implement the reduce modifier
	void Fraction::reduce()
	{

		int reduceRate = gcd();
		this->numerator = this->numerator / reduceRate;
		this->denominator = this->denominator / reduceRate;

	}

    // TODO: implement the display query

	void Fraction::display() const
	{

		if (not(isEmpty()) && this->denominator != 1){
			cout << this->numerator << "/" << this->denominator;
			
		}
		else if (this->denominator == 1)
		{
			cout << this->numerator;
		}
		else
		{
			cout << "no fraction stored";
		}

	}
    // TODO: implement the isEmpty query

	bool Fraction::isEmpty() const {
		bool result = false;
		if (this->numerator == 0 && this->denominator == 0) {
			result = true;
		}
		return result;

	}

    // TODO: implement the + operator

	Fraction Fraction::operator+(const Fraction& rhs) const {

		Fraction result(0,0);

		if (isEmpty() == false && rhs.isEmpty() == false) {
			result.numerator = ((this->numerator * rhs.denominator ) + (this->denominator *rhs.numerator));
			result.denominator = (this->denominator* rhs.denominator);
		}
		return result;
	}
    
    
    Fraction Fraction::operator*(const Fraction& rhs) const{
        Fraction result(0,0);
        
        if (isEmpty() == true || rhs.isEmpty() == true) {
            result = Fraction();
        }
        else {
            int n = this->numerator * rhs.numerator;
            int d = this->denominator * rhs.denominator;
            result = Fraction(n, d);
        }
        return result;
        
    }
    
    
    bool Fraction::operator==(const Fraction& rhs) const{
        bool result = false;
        if (not (isEmpty() == true && rhs.isEmpty() == true)){
            if(this->numerator == rhs.numerator && this->denominator == rhs.denominator){
                  result = true;
            }

        }

        return result;
        
    }
    
    bool Fraction::operator!=(const Fraction& rhs) const{
        bool result = true;
        if (isEmpty() == true || rhs.isEmpty() == true) {
            result =  false;
        }
        else {
            if (this->numerator == rhs.numerator && this->denominator == rhs.denominator){
                 result = false;
            }
        }
        return result;
        
    }
    
    Fraction& Fraction::operator+=(const Fraction& rhs){
        
        this->numerator = this->numerator * rhs.denominator + this->denominator * rhs.numerator;
        this->denominator = this->denominator * rhs.denominator;
        reduce();
        return *this;
        
    }
        
    
    
}


