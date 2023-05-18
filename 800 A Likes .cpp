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

int main() {
	int tt;
	int n;
	cin >> tt;

	while (tt--) {
		cin >> n;
		vector<int> a(n);
		int c0 = 0, c1 = 0, i;
		for (i = 0; i < n; i++) {
			cin >> a[i];
			if (a[i] > 0) c1 += 1; else c0 += 1;
		}
		// max line first
		i = 1;
		while (i <= c1) {
			cout << i << " ";
			i++;
		}
		int curr = i - 1;
		while (i <= n) {
			curr--;
			cout << curr << " ";
			i++;
		}
		cout << "\n";
		// min
		i = 1;
		while (i <= 2 * c0) {
			if (i % 2 == 0) cout << 0; else cout << 1;
			cout << " ";
			i++;
		}
		curr = 0;
		while (i <= n) {
			curr++;
			cout << curr << " ";
			i++;
		}
		cout << "\n";
	}
}