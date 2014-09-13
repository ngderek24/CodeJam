#include <iostream>
#include <string>
#include <cctype>
using namespace std;

void insertWord(string word, string& accum);

int main() {
	string sentence;
	cout << "Enter a sentence to be reversed: ";
	getline(cin, sentence);

	string word, finalSentence;
	for(int n = 0; n < sentence.size()+1; n++) {
		if(isalpha(sentence[n])) {
			word += sentence[n];
			continue;
		}
		insertWord(word, finalSentence);
		word = "";
	}

	cout << finalSentence << endl;
}

void insertWord(string word, string& accum) {
	word += " ";
	accum = word + accum;
}
