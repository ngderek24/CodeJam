/*Jeff is a part of the great Atlantean orchestra. Each player of the orchestra has already decided what sound will he play (for
the sake of simplicity we assume each player plays only one sound). We say two sounds are in harmony if the frequency of any 
one of them divides the frequency of the other (that's a pretty restrictive idea of harmony, but the Atlanteans are known to 
be very conservative in music). Jeff knows that the notes played by other players are not necessarily in harmony with each 
other. He wants his own note to improve the symphony, so he wants to choose his note so that it is in harmony with the notes 
all the other players play. Now, this sounds simple (as all the frequencies are positive integers, it would be enough for Jeff 
to play the note with frequency 1, or, from the other side, the Least Common Multiple of all the other notes), but 
unfortunately Jeff's instrument has only a limited range of notes available. Help Jeff find out if playing a note harmonious 
with all others is possible.
Input
The first line of the input gives the number of test cases, T. T test cases follow. Each test case is described by two lines. 
The first contains three numbers: N, L and H, denoting the number of other players, the lowest and the highest note Jeff's 
instrument can play. The second line contains N integers denoting the frequencies of notes played by the other players. */

#include <iostream>
using namespace std;

int main() {
	int nPlayer, low, high, a[20], res = 0;
	cin >> nPlayer >> low >> high;
	for (int i = 0; i < nPlayer; i++)
		cin >> a[i];

	while (low <= high) {
		for (int j = 0; j < nPlayer; j++) {
			if (a[j] % low != 0 && low % a[j] != 0)
				break;
			if (j == nPlayer-1)
				res = low;
		}
		if (res != 0)
			break;
		low++;
	}
	if (res == 0)
		cout << "NO";
	else
		cout << res;
}
