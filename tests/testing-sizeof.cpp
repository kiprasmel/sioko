// testing-sizeof.cpp
//
// compile with:
// $ g++ testing-sizeof.cpp -o testing-sizeof
//
// run with:
// $ ./testing-sizeof.exe
//
// combined:
// $ g++ testing-sizeof.cpp -o testing-sizeof && ./testing-sizeof.exe
//
// Copyright (c) 2019 Kipras Melnikovas
//

#include <iostream>

int main() {
	/** 
	 * these numbers don't mean anything - 
	 * they just were copy-pasted from our
	 * pin numbers & their angles
	 * (that's why we needed this test)
	 */
	const double array2d[9][2] = {
			{17, -90},
			{16, -50},
			{18, -15},
			{20, 0},
			{19, 0},
			{33, 0},
			{21, 15},
			{23, 50},
			{22, 90}};

	std::cout << "\nsizeof(array2d) = " << sizeof(array2d) // 144
						<< "\nsizeof(array2d[0]) = " << sizeof(array2d[0]) // 16
						<< "\nsizeof(array2d[0][0]) = " << sizeof(array2d[0][0]); // 8

	/**
	 * 9 elements * 2 elements * 8 bytes (double) = 144 bytes
	 */

	return 0;
}