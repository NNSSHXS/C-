#include <iostream>
#include "Rational.h"
#include <cassert>

//���������������(ŷ������㷨) 
int gcd(int a, int b) {
	if (b == 0) {
		return a;
	}
	return gcd(b, a % b);
}
//Rational��Ĺ��캯�� 
Rational::Rational(int numer, int denom) : numerator(numer), denominator(denom) {
	optimize(*this);	//ÿ�δ���Rational���󼰶Զ���������ʱ�������Ż���������֤���ӷ�ĸ���أ���ͬ(ע���Ż������Ĳ���) 
}
//��������� + (�����������ӷ����弴��) 
Rational Rational::operator + (const Rational &r) {
	int newNumerator = (numerator * r.denominator) + (r.numerator * denominator);
	int newDenominator = denominator * r.denominator;
	optimize(*this);	//�Ż����� 
	return Rational(newNumerator, newDenominator);
}
//��������� - (�����������������弴��) 
Rational Rational::operator - (const Rational &r) {
	int newNumerator = (numerator * r.denominator) - (r.numerator * denominator);
	int newDenominator = denominator * r.denominator;
	optimize(*this);	//�Ż����� 
	return Rational(newNumerator, newDenominator);
}
//��������� * (�����������˷����弴��) 
Rational Rational::operator * (const Rational &r) {
	int newNumerator = numerator * r.numerator;
	int newDenominator = denominator * r.denominator;
	optimize(*this);	//�Ż����� 
	return Rational(newNumerator, newDenominator);
}
//��������� / (�����������������弴��) 
Rational Rational::operator / (const Rational &r) {
	int newNumerator = numerator * r.denominator;
	int newDenominator = denominator * r.numerator;
	optimize(*this);	//�Ż����� 
	return Rational(newNumerator, newDenominator);
}
//��������� ==, �ж��߼��Ƿ�������ҷ�ĸ���(�Ƚ�ǰ�������Ż�, �Ƚ϶�����ӷ�ĸ�ػ���) 
bool Rational::operator == (const Rational &r) {
	return (numerator == r.numerator && denominator == r.denominator);
}
//��������ת����ʵ�� 
double Rational::convertToReal() {
	assert(denominator != 0);
	return (((double)numerator / denominator));
}
//��������� >>, ��ֱ�Ӷ�����������  
std::istream & operator >> (std::istream &in, Rational &r) {
	in >> r.numerator >> r.denominator;
	optimize(r);	//�Ż����� 
	return in;
}
//��������� <<, ��ֱ�����������  
std::ostream & operator << (std::ostream &out, const Rational &r) {
	out << r.numerator << "/" << r.denominator;
	return out;
}
//�Ż�����, ����gcd��������ӷ�ĸ���������, Ȼ����ӷ�ĸͬ��֮ 
void optimize(Rational &r) {
	int getGcd = gcd(r.numerator, r.denominator);
	r.numerator /= getGcd;
	r.denominator /= getGcd;
}
//������������� 
void Rational::display() {
	std::cout << *this << std::endl;
}
