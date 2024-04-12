#include "BinaryConverter.h"

#include <iostream>
#include <string>

int main() {
	int num;

	std::cout << "Please enter a number 0 or greater: ";
	std::cin >> num;

	// std::string binaryString1 = convertToBinaryByte(num);
	std::string binaryString2 = convertToBinary(num);

	// std::cout << "Binary Conversion 1: " << binaryString1 << std::endl;
	std::cout << "Binary Conversion 2: " << binaryString2 << std::endl;

	return 0;
}