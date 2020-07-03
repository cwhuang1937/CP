#include <iostream>
using namespace std;

long long FastPowerModular(int base, int power, int mod) {
	base %= mod;
	long long answer = 1, twosPowers[32] = { base }, pointer = 1, buffer = 2;
	while (buffer <= power)
		buffer <<= 1, twosPowers[pointer] = (twosPowers[pointer - 1] * twosPowers[pointer - 1]) % mod, pointer++;
	pointer = 0;
	while (power) {
		if (power & 1)
			answer = (answer * twosPowers[pointer]) % mod;
		power >>= 1, pointer++;
	}
	return answer;
}

bool MillerRabinPrimalityTest(int number) {
	if (number == 2)
		return true;
	if (number < 2 || !(number & 1))
		return false;
	int bases[3] = { 2, 7, 61 }, buffer = number - 1, twosPower = 0, i, j;
	while (!(buffer & 1))
		buffer >>= 1, twosPower++;
	for (i = 0; i < 3; i++) {
		long long powers = FastPowerModular(bases[i], buffer, number);
		if (powers == 1 || powers == number - 1 || !powers)
			continue;
		for (j = 0; j < twosPower; j++) {
			powers *= powers, powers %= number;
			if (powers == 1)
				return false;
			if (powers == number - 1)
				break;
		}
		if (j == twosPower)
			return false;
	}
	return true;
}

int main() {
	cin.sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int number;
	while (cin >> number)
		cout << (MillerRabinPrimalityTest(number) ? "質數\n" : "非質數\n");
}
