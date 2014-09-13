/*There were two very important rules involved in this procedure. First, in order to ensure that all discs could be labeled 
clearly, Adam would never place more than two files on the same disc. Second, he would never divide a single file over multiple
discs. Happily, the discs he was using were always large enough to make this possible. Thinking back, Adam is now wondering 
whether he arranged his files in the best way, or whether he ended up wasting some Compact Discs. He will provide you with the
capacity of the discs he used (all his discs had the same capacity) as well as a list of the sizes of the files that he stored. Please help Adam out by determining the minimum number of discs needed to store all his files—following the two very important rules, of course.
Input
The first line of the input gives the number of test cases, T. T test cases follow. Each test case begins with a line
containing two integers: the number of files to be stored N, and the capacity of the discs to be used X (in MBs). The next 
line contains the N integers representing the sizes of the files Si (in MBs), separated by single spaces. */

#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int numDiscs, cap;
	double sum = 0;
	int discs[100];
	cin >> numDiscs >> cap;
	for (int i = 0; i < numDiscs; i++) {
		cin >> discs[i];
		sum += discs[i];
	}
	int atLeast = (numDiscs/2) + (numDiscs%2);
	int maxSize = atLeast * cap;
	if (sum <= maxSize)
		cout << atLeast;
	else 
		cout << ceil(sum/cap);
}
