#include <iostream>
#include "Rational.h"

int main() {
	Rational r0;
	Rational r1(12,15), r2(4,6);
	bool result = r1 == r2;
	std::cout << "Please enter the numerator and the denominator(split by a blank):";
	std::cin >> r0;
	std::cout << "r0 = ";
	r0.display();
	
	std::cout << "r1 = " << r1 << ", r2 = " << r2 << std::endl;
	std::cout << "The result of r1 == r2 is " << result << std::endl;
	std::cout << "r1 + r2 = " << r1 + r2 << std::endl;
	std::cout << "r1 - r2 = " << r1 - r2 << std::endl;
	std::cout << "r1 * r2 = " << r1 * r2 << std::endl;
	std::cout << "r1 / r2 = " << r1 / r2 << std::endl;
	std::cout << "convert r1 to real is " << r1.convertToReal() << std::endl;
	std::cout << "convert r2 to real is " << r2.convertToReal() << std::endl;
	
	return 0;
}
