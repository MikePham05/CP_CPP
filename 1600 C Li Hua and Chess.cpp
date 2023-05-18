#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <bitset>
#include <iostream>
#include <unordered_map>
#include <queue>
#include <deque>

using namespace std;

void ask(int a, int b) {
	cout << "? " << a << " " << b << "\n";
	cout.flush();
}

void ans(int a, int b) {
	cout << "! " << a << " " << b << "\n";
	cout.flush();
}

int main() {
	int tt;
	cin >> tt;
	int m, n, f1, f2, f3;

	while (tt--) {
		cin >> m >> n;
		ask(1, 1);
		cin >> f1;
		if (f1 == 0) {
			ans(1, 1);
		}
		else if (f1 + 1 > m) { // f1 is col
			ask(1, f1 + 1);
			cin >> f2;
			ans(f2 + 1, f1 + 1);
		}
		else if (f1 + 1 > n) { // f1 is row
			ask(f1 + 1, 1);
			cin >> f2;
			ans(f1 + 1, f2 + 1);
		}
		else {
			ask(f1 + 1, f1 + 1);
			cin >> f2;
			if (f2 == 0)
				ans(f1 + 1, f1 + 1);
			else {
				ask(f1 + 1, f1 + 1 - f2); // test f1 row, f2 col
				cin >> f3;
				if (f3 == 0) ans(f1 + 1, f1 + 1 - f2); else ans(f1 + 1 - f2, f1 + 1);
			}
		}
	}
}