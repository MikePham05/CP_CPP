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

long long pow_mod(long long x, long long n, long long m) {
	long long y = 1;
	while (n > 0) {
		if (n % 2 == 1)
			y = (y % m * x) % m;
		n = n / 2;
		if (x > m)
			x = x % m;
		x = (x % m * x % m) % m;
	}
	return y % m;
}

long long dfs(int n, int node, unordered_map<int, vector<int>>& c, vector<long long>& d, long long& p, vector<bool>& t) {
	t[node] = true;
	vector<int> actual_child;
	for (int child : c[node])
		if (not t[child]) {
			d[node] += dfs(n, child, c, d, p, t);
			actual_child.push_back(child);
		}
	p += d[node] * (n - d[node] - 1) + n - 1;
	d[node]++;
	long long curr = 0;
	for (int child : actual_child)
		curr += (d[child]) * (d[node] - 1 - d[child]);
	p += curr / 2;
	return d[node];
}

int main() {
	int tt, k, p1, p2;
	long long n, p, q;
	long long modulo = 1000000007;
	tt = 1;
	while (tt--) {
		cin >> n >> k;
		vector<bool> track(n + 1);
		unordered_map<int, vector<int>> c;
		for (int i = 0; i < n - 1; i++) {
			cin >> p1 >> p2;
			if (c.find(p1) == c.end()) c.insert(pair<int, vector<int>>(p1, {}));
			if (c.find(p2) == c.end()) c.insert(pair<int, vector<int>>(p2, {}));
			c[p1].push_back(p2);
			c[p2].push_back(p1);
		}
		if (k == 1) {
			p = n;
			q = n;
		}
		else if (k == 3) {
			p = n;
			q = n;
		}
		else {
			p = 0;
			q = n * (n - 1) / 2;
			vector<long long> d(n + 1);
			dfs(n, 1, c, d, p, track);
		}
		long long inv_q = pow_mod(q, modulo - 2, modulo);
		inv_q = inv_q % modulo;
		p = p % modulo;
		cout << (p * inv_q) % modulo;
		long long g = modulo - 1;
		// find x such that x * q = 1 (mod M)
		// x = x * p (mod M);
	}
}