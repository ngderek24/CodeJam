/*You are playing a card game, where each card has an integer number written on it. To play the game, you are given some cards — 
your hand. Then you arrange the cards in your hand into straights. A straight is a set of cards with consecutive values; e.g. 
the three cards {3, 4, 5}, or the single card {7}. You then receive a number of dollars equal to the length of the shortest 
straight. If you have no cards, you can form no straights, so you get zero dollars. You will be given a series of test cases, 
each of which describes the cards you will have in your hand. Find the maximum number of dollars you can receive for each test 
case.
Input
The first line of the input contains the number of test cases, T. Each test case consists of one line. Each line contains N, 
the number of cards in your hand, followed by N integers giving the numbers on those cards. These numbers are all 
space-separated. */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, pos, cnt, ans;
	int a[10000];
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> pos;
		a[pos]++;
	}

	vector<int> inc, dec;
	for (int j = 0; j < 10000; j++) {
		if (a[j] < a[j+1]) {
			cnt = a[j+1] - a[j];
			while (cnt--)
				inc.push_back(j);
		} else {
			cnt = a[j] - a[j+1];
			while (cnt--)
				dec.push_back(j);
		}
	}

	ans = 10000;
	for (int k = 0; k < inc.size(); k++)
		ans = min(ans, dec[k]-inc[k]);
	if (n == 0)
		ans = 0;
	cout << ans << endl;
}
