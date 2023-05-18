#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <bitset>
#include <iostream>
#include <unordered_map>
#include <queue>
#include <deque>
#include <numeric>
#include <cmath>

using namespace std;


int main() {
	int tt, i, j, m, n;
	vector<int> a;

	unordered_map<int, int> d;
	cin >> tt;
	while (tt--) {
		cin >> n;
		a.clear();
		d.clear();
		for (i = 0; i < n; i++) {
			cin >> m;
			if (d.find(m) == d.end()) d.insert(pair<int, int>(0, 0));
			d[m] += 1;
		}

		int k, v;
		long long ans = 0;
		for (auto p : d) {
			k = p.first;
			v = p.second;
			if (v >= 3) ans += (long long)v * (v - 1) * (v - 2);
			for (i = 2; i <= sqrt(k); i++) {
				j = i * i;
				if ((k % i == 0 and d.find(k / i) != d.end()) and (k % j == 0 and d.find(k / j) != d.end()))
					ans += (long long)d[k] * d[k / i] * d[k / j];
			}
		}

		cout << ans << "\n";
	}

}