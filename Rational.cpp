#include <iostream>
#include "Rational.h"
#include <cassert>

//求两数的最大公因数(欧几里得算法) 
int gcd(int a, int b) {
	if (b == 0) {
		return a;
	}
	return gcd(b, a % b);
}
//Rational类的构造函数 
Rational::Rational(int numer, int denom) : numerator(numer), denominator(denom) {
	optimize(*this);	//每次创建Rational对象及对对象做运算时都调用优化函数，保证分子分母互素，下同(注意优化函数的参数) 
}
//重载运算符 + (根据有理数加法定义即可) 
Rational Rational::operator + (const Rational &r) {
	int newNumerator = (numerator * r.denominator) + (r.numerator * denominator);
	int newDenominator = denominator * r.denominator;
	optimize(*this);	//优化函数 
	return Rational(newNumerator, newDenominator);
}
//重载运算符 - (根据有理数减法定义即可) 
Rational Rational::operator - (const Rational &r) {
	int newNumerator = (numerator * r.denominator) - (r.numerator * denominator);
	int newDenominator = denominator * r.denominator;
	optimize(*this);	//优化函数 
	return Rational(newNumerator, newDenominator);
}
//重载运算符 * (根据有理数乘法定义即可) 
Rational Rational::operator * (const Rational &r) {
	int newNumerator = numerator * r.numerator;
	int newDenominator = denominator * r.denominator;
	optimize(*this);	//优化函数 
	return Rational(newNumerator, newDenominator);
}
//重载运算符 / (根据有理数除法定义即可) 
Rational Rational::operator / (const Rational &r) {
	int newNumerator = numerator * r.denominator;
	int newDenominator = denominator * r.numerator;
	optimize(*this);	//优化函数 
	return Rational(newNumerator, newDenominator);
}
//重载运算符 ==, 判断逻辑是分子相等且分母相等(比较前已做过优化, 比较对象分子分母必互素) 
bool Rational::operator == (const Rational &r) {
	return (numerator == r.numerator && denominator == r.denominator);
}
//将有理数转换成实数 
double Rational::convertToReal() {
	assert(denominator != 0);
	return (((double)numerator / denominator));
}
//重载运算符 >>, 以直接读读入有理数  
std::istream & operator >> (std::istream &in, Rational &r) {
	in >> r.numerator >> r.denominator;
	optimize(r);	//优化函数 
	return in;
}
//重载运算符 <<, 以直接输出有理数  
std::ostream & operator << (std::ostream &out, const Rational &r) {
	out << r.numerator << "/" << r.denominator;
	return out;
}
//优化函数, 调用gcd函数求分子分母的最大公因数, 然后分子分母同除之 
void optimize(Rational &r) {
	int getGcd = gcd(r.numerator, r.denominator);
	r.numerator /= getGcd;
	r.denominator /= getGcd;
}
//有理数输出函数 
void Rational::display() {
	std::cout << *this << std::endl;
}
