#include "BinaryConverter.h"

#include <array>
#include <math.h>

std::string convertToBinaryByte(int num)
{
	// If value is larger than 1 byte or invalid, print error
	if (num < 0 || num > 255) {
		return "ERROR: Invalid input.";
	}

	int binaryArray[8] = { 0 }; // initialize an array with 8 indexes whose value is 0
	int quotient = num; // set initial quotient to the argument passed to function
	int count = 0; // iterator for do-while loop

	do {
		int remainder = quotient % 2; // returns 0 or 1, used to construct binary number
		binaryArray[8 - ++count] = remainder; // set appropriate index to 0 or 1 in array
		quotient = quotient / 2; // set value of quotient for next iteration
	} while (quotient != 0);

	std::string binaryString = ""; // initialize an empty string

	for (int i = 0; i < 8; i++) {
		binaryString += std::to_string(binaryArray[i]); // interpolate string of 0's and 1's to make binary string
	}

	return binaryString;
}

std::string convertToBinary(int num)
{
	int minBits = log10(double(num)) / log10(2.0); // gets minimum number of bits needed to store the number
	int numBytes = int(ceil(minBits / 8.0)); // finds rounds up num bytes needed to whole integer, converts to int
	int numBits = numBytes * 8; // number of bits needed for adequate number of bytes

	int* binaryArray = new int(numBits); // create pointer to array with adequate memory to store num
	
	int quotient = num; // set initial quotient to the argument passed to function
	int count = 0; // iterator for do-while loop

	do {
		if (quotient != 0) {
		int remainder = quotient % 2; // returns 0 or 1, used to construct binary number
		binaryArray[numBits - ++count] = remainder; // set appropriate index to 0 or 1 in array
		quotient = quotient / 2; // set value of quotient for next iteration

		}
		else {
			binaryArray[numBits - ++count] = 0; // set remaining index locations to 0
		}

	} while (numBits > count);

	std::string binaryString = ""; // initialize an empty string

	for (int i = 0; i < numBits; i++) {
		binaryString += std::to_string(*(binaryArray + i)); // interpolate string of 0's and 1's to make binary string
	}

	return binaryString;
}
