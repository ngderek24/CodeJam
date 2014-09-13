/*Fegla and Omar like to play games every day. But now they are bored of all games, and they would like to play a new game. 
So they decided to invent their own game called "The Repeater". They invented a 2 player game. Fegla writes down N strings. 
Omar's task is to make all the strings identical, if possible, using the minimum number of actions (possibly 0 actions) of 
the following two types:

    Select any character in any of the strings and repeat it (add another instance of this character exactly after it). 
	For example, in a single move Omar can change "abc" to "abbc" (by repeating the character 'b').
    Select any two adjacent and identical characters in any of the strings, and delete one of them. For example, in a 
	single move Omar can change "abbc" to "abc" (delete one of the 'b' characters), but can't convert it to "bbc".

The 2 actions are independent; it's not necessary that an action of the first type should be followed by an action of the 
second type (or vice versa). Help Omar to win this game by writing a program to find if it is possible to make the given 
strings identical, and to find the minimum number of moves if it is possible.*/

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
using namespace std;

int averageLength(vector<string> vect);

int main() {
	int stringNum;
	cout << "Enter the number of strings: ";
	cin >> stringNum;
	cin.ignore(10000, '\n');

	vector<string> strings;
	for (int n = 0; n < stringNum; n++) {
		string text;
		getline(cin, text);
		strings.push_back(text);
	}

	int pivot = 0;
	for (int k = 0; k < strings.size()-1; k++) {
		for (int i = 0; i < strings[k].size(); i++) {
			pivot = strings[stringNum-1].find(strings[k][i], pivot);
			if (pivot == -1) {
				cout << "Impossible!";
				return 1;
			}
		}
	}

	int average = averageLength(strings);
	int result = 0;
	for (int j = 0; j < strings.size(); j++) {
		if (strings[j].size() > average)
			result += (strings[j].size() - average);
		else
			result += (average - strings[j].size());
	}

	cout << result;
}

int averageLength(vector<string> vect) {
	int avg, total = 0;
	for (int k = 0; k < vect.size(); k++)
		total += vect[k].size();

	avg = total/vect.size();
	return avg;
}
