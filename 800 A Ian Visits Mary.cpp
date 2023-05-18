#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <bitset>
#include <iostream>
using namespace std;

int main() {
	int tt, a, b;
	string s;
	cin >> tt;

	while (tt--) {
		cin >> a >> b;
		if (a == 2 and b == 2) {
			cout << 2 << "\n";
			cout << "1 3" << "\n";
			cout << "2 2" << "\n";
		}
		else if (a == 1 or b == 1) {
			cout << 1 << "\n";
			cout << a << " " << b << "\n";
		}
		else {
			cout << 2 << "\n";
			cout << a - 1 << " " << 1 << "\n";
			cout << a << " " << b << "\n";
		}
	}
}