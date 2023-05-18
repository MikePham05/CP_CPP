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

int main() {
	int tt;
	int n, m, i, j, k;
	char nl = '\n';
	cin >> tt;

	while (tt--) {
		cin >> n >> k;
		string s, t;
		cin >> s;
		cin >> t;
		bool ans = true;
		unordered_map<char, int> d;
		for (char c : s)
			d[c] += 1;
		for (char c : t) {
			d[c] -= 1;
			if (d[c] < 0) {
				ans = false;
				break;
			}
		}
		k = min(n, k);
		for (i = 0; i < k - 1; i++)
			if (ans and s[k] != t[k]) {
				for (j = n - 1; j > n - k - 1; j--)
					if (s[j] != t[j]) {
						ans = false;
						break;
					}	
			}

		if (ans) cout << "YES"; else cout << "NO";
		cout << nl << nl;
	}
}










/*
		int ans = 1;
		string s;
		cin >> s;
		int j = 0;
		string p = s.substr(0, 2), rp = "", t = "";
		rp = rp + s[1] + s[0];
		int f = 0;
		for (i = 1; i < n - 1; i++) {
			t = s.substr(i, 2);
			if (t == p or t == rp) {
				continue;
			}
			else {
				p = t;
				rp = "" + t[1] + t[0];
				ans += 1;
			}
		}
		cout << ans << nl << nl;*/
