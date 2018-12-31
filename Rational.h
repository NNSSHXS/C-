//Rational.h
#ifndef RATIONAL_H
#define RATIONAL_H
#include <iostream>

//有理数类(Rational)的声明 
class Rational {
	public :
		Rational(int numer = 0, int denom = 1);
		Rational operator + (const Rational &r);	//重载操作符 + 
		Rational operator - (const Rational &r);	//重载操作符 - 
		Rational operator * (const Rational &r);	//重载操作符 * 
		Rational operator / (const Rational &r);	//重载操作符 / 
		bool operator == (const Rational &r);		//重载操作符 == 
		double convertToReal();						//将有理数转换为实数 
		friend void optimize(Rational &r);			//优化函数，使分数的分子分母不含公因数(即互素) 
		friend std::istream & operator >> (std::istream &in, Rational &r); 	//重载操作符 >> 
		friend std::ostream & operator << (std::ostream &out, const Rational &r);	//重载操作符 <<
		void display();								//有理数输出 
	private :
		int numerator;		//分子 
		int denominator;	//分母 
};
int gcd(int a, int b);		//求两数的最大公因数 

#endif
