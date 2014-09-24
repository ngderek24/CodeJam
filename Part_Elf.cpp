/*Being part Elf works the way you probably expect. People who are Elves, Humans and part-Elves are all created in the same way:
two parents get together and have a baby. If one parent is A/B Elf, and the other parent is C/D Elf, then their baby will be 
(A/B + C/D) / 2 Elf. For example, if someone who is 0/1 Elf and someone who is 1/2 Elf have a baby, that baby will be 1/4 Elf.
Vida is certain about one thing: 40 generations ago, she had 240 different ancestors, and each one of them was 1/1 Elf or 0/1 
Elf. Vida says she's P/Q Elf. Tell her what is the minimum number of generations ago that there could have been a 1/1 Elf in 
her family. If it is not possible for her to be P/Q Elf, tell her that she must be wrong!
Input
The first line of the input gives the number of test cases, T. T lines follow. Each contains a fraction of the form P/Q, where
P and Q are integers. */

#include <iostream>
using namespace std;

int gcd(int num, int denom) {
	for (int j = num; j > 0; j--) {
		if (num % j == 0 && denom % j == 0)
			return j;
	}
	return 0;
}

int main() {
	int p,q;
	cin >> p >> q;
	int red = gcd(p, q);
	p /= red;
	q /= red;

	if (q & (q-1))
		cout << "impossible";
	else {
		int ans = 0;
		while (p < q) {
			p *= 2;
			ans++;
		}
		cout << ans;
	}
}
