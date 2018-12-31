//Rational.h
#ifndef RATIONAL_H
#define RATIONAL_H
#include <iostream>

//��������(Rational)������ 
class Rational {
	public :
		Rational(int numer = 0, int denom = 1);
		Rational operator + (const Rational &r);	//���ز����� + 
		Rational operator - (const Rational &r);	//���ز����� - 
		Rational operator * (const Rational &r);	//���ز����� * 
		Rational operator / (const Rational &r);	//���ز����� / 
		bool operator == (const Rational &r);		//���ز����� == 
		double convertToReal();						//��������ת��Ϊʵ�� 
		friend void optimize(Rational &r);			//�Ż�������ʹ�����ķ��ӷ�ĸ����������(������) 
		friend std::istream & operator >> (std::istream &in, Rational &r); 	//���ز����� >> 
		friend std::ostream & operator << (std::ostream &out, const Rational &r);	//���ز����� <<
		void display();								//��������� 
	private :
		int numerator;		//���� 
		int denominator;	//��ĸ 
};
int gcd(int a, int b);		//��������������� 

#endif
