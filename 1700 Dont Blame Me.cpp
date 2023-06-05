#include <string> // insert(position, count, value), find, 
#include <vector> // push_back, pop_back, find(begin, end, value), insert, erase
#include <algorithm> // swap, reverse, sort, make_heap(begin, end), push_heap(begin, end), pop_heap(begin, end)
#include <unordered_set> // insert, erase, find
#include <bitset> 
#include <iostream> 
#include <unordered_map> // insert, erase, find
#include <queue> // front, back, insert (end), pop (front)
#include <deque> // (push, pop) front, (push, pop) back, 
#include <stack>
#include <cmath> // abs, pow(x, y) = x^y, floor, ceil, 
#include <numeric>

#define ll long long

const int mod = 1000000007;

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

bool havekbits(int a, int k) {
	int count = 0;
	while (a > 0) {
		if (a % 2 == 1) count++;
		a = a / 2;
	}
	return (count == k);
}

int main() {
	int tt;
	char nl = '\n';
	cin >> tt;

	while (tt--) {
		int n, k, i, j;
		unordered_map<int, int> d;
		cin >> n >> k;
		vector<int> a(n), l;

		for (i = 0; i < n; i++) {
			cin >> a[i];
			if (d.find(a[i]) == d.end())
				d.insert(pair<int, int>(a[i], 0));
			d[a[i]]++;
		}

		for (auto e : d)
			if (havekbits(e.first, k))
				l.push_back(e.first);

		vector<vector<int>> bitset(64);
		for (i = 0; i < 64; i++) {
			j = i;
			bitset[i] = { 0, 0, 0, 0, 0, 0 };
			for (int l = 5; l > -1; l--) {
				bitset[i][l] = j % 2;
				j = j / 2;
			}
		}

		vector<long long> p2(n + 1);
		long long ans = 0, curr = 1;
		p2[0] = 1;
		for (i = 1; i < n + 1; i++) {
			curr = (curr * 2) % mod;
			p2[i] = curr;
		}


		for (int e : l) {
			curr = 1;
			for (auto item : d)
				if (item.first != e) {
					bool check = false;
					for (i = 0; i < 6; i++)
						if (bitset[item.first][i] != bitset[e][i] and bitset[e][i] == 1)
							check = true;
					if (not check)
						curr += p2[d[item.first]];
				}
			ans = (ans + (p2[d[e]] - 1) * (curr)) % mod;
		}

		if (k == 0) {
			vector<vector<vector<int>>> comb;
			comb.push_back({});
			for (i = 1; i < 64; i++) {
				comb.push_back({ {} });
				if (d.find(i) != d.end()) comb[i][0].push_back(i);
				for (j = 1; j < i; j++) {
					int l = i - j;
					if (l != j and !comb[j].empty() and (d.find(l) != d.end())) {
						for (vector<int> li : comb[j]) {
							li.push_back(j);
							comb[i].push_back(li);
						}
					}
				}
			}
			for (vector<int> list : comb[63]) {
				curr = 1;
				for (auto e : list)
					curr = (curr * (p2[d[e]] - 1)) % mod;
				ans = (ans + curr) % mod;
			}
		}
		cout << ans << nl;
	}
}

