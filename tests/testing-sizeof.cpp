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

template <typename T>
void logArraySizes1D(T &array1D);

template <typename T>
void logArraySizes2D(T &array2D);

template <typename T>
void logArraySizes3D(T &array3D);

int main()
{
	/** 
	 * these numbers don't mean anything - 
	 * they just were copy-pasted from our
	 * pin numbers & their angles
	 * (that's why we needed this test)
	 */
	const double array2DDoubles[9][2] = {
			{17, -90},
			{16, -50},
			{18, -15},
			{20, 0},
			{19, 0},
			{33, 0},
			{21, 15},
			{23, 50},
			{22, 90}};

	std::cout << "\ndoubles:";
	logArraySizes2D(array2DDoubles);
	/**
	 * 9 elements * 2 elements * 8 bytes (double) = 144 bytes
	 */

	const int array2DInts[9][2] = {
			{17, -90},
			{16, -50},
			{18, -15},
			{20, 0},
			{19, 0},
			{33, 0},
			{21, 15},
			{23, 50},
			{22, 90}};

	std::cout << "\n\nints:";
	logArraySizes2D(array2DInts);
	/**
	 * 9 elements * 2 elements * 4 bytes (int) = 72 bytes
	 */

	return 0;
}

template <typename T>
void logArraySizes1D(T &array1D)
{
	std::cout << "\nsizeof(array1D) = " << sizeof(array1D)
						<< "\nsizeof(array1D[0]) = " << sizeof(array1D[0]);
}

template <typename T>
void logArraySizes2D(T &array2D)
{
	std::cout << "\nsizeof(array2D) = " << sizeof(array2D)
						<< "\nsizeof(array2D[0]) = " << sizeof(array2D[0])
						<< "\nsizeof(array2D[0][0]) = " << sizeof(array2D[0][0]);
}

template <typename T>
void logArraySizes3D(T &array3D)
{
	std::cout << "\nsizeof(array3D) = " << sizeof(array3D)
						<< "\nsizeof(array3D[0]) = " << sizeof(array3D[0])
						<< "\nsizeof(array3D[0][0]) = " << sizeof(array3D[0][0])
						<< "\nsizeof(array3D[0][0][0]) = " << sizeof(array3D[0][0][0]);
}