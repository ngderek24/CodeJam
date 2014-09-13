/*Little John likes palindromes, and thinks them to be fair (which is a fancy word for nice). A palindrome is just an 
integer that reads the same backwards and forwards - so 6, 11 and 121 are all palindromes, while 10, 12, 223 and 2244 are
not (even though 010=10, we don't consider leading zeroes when determining whether a number is a palindrome). He recently 
became interested in squares as well, and formed the definition of a fair and square number - it is a number that is a 
palindrome and the square of a palindrome at the same time. For instance, 1, 9 and 121 are fair and square (being palindromes 
and squares, respectively, of 1, 3 and 11), while 16, 22 and 676 are not fair and square: 16 is not a palindrome, 22 is not a 
square, and while 676 is a palindrome and a square number, it is the square of 26, which is not a palindrome. Now he wants to 
search for bigger fair and square numbers. Your task is, given an interval Little John is searching through, to tell him how 
many fair and square numbers are there in the interval, so he knows when he has found them all. */

#include <iostream>
#include <cmath>
#include <sstream>
using namespace std;

bool isPalindrome(int num);
bool isPerfectSquare(int square);

int main() {
	int lowerBound, upperBound;
	cout << "Enter the lower bound: ";
	cin >> lowerBound;
	cout << "Enter the upper bound: ";
	cin >> upperBound;

	int counter = 0;
	for (int n = lowerBound; n <= upperBound; n++) {
		if (isPalindrome(n) && (isPerfectSquare(n) && isPalindrome(sqrt(n))))
			counter++;
	}

	cout << counter;
}

bool isPalindrome(int num) {
	string result;
	ostringstream convert;
	convert << num;
	result = convert.str();

	int k = result.size()-1;
	for (size_t n = 0; n < result.size()/2; n++) {
		if (result[n] != result[k])
			return false;
		k--;
	}
	return true;
}

bool isPerfectSquare(int square) {
	if (square < 0)
		return false;
	int root = floor(sqrt(square));
	return square == root * root;
} 
