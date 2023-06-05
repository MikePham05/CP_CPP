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

vector<int> operation(int l, int r, vector<int>& a) {
	int n = a.size();
	vector<int> b(n), ans;
	for (int i = 0; i < n; i++)
		b[i] = a[i];
	for (int i = r + 1; i < n; i++)
		ans.push_back(b[i]);
	for (int i = r; i >= l; i--)
		ans.push_back(b[i]);
	for (int i = 0; i < l; i++)
		ans.push_back(b[i]);

	return ans;
}

int main() {
	int tt;
	int n, m, i, j, k;
	char nl = '\n';
	cin >> tt;

	while (tt--) {
		cin >> n;
		vector<int> a(n);
		int pos_max = 0;
		for (i = 0; i < n; i++) {
			cin >> a[i];
			if (a[i] == n)
				pos_max = i;
		}

		if (n == 1) {
			cout << 1 << nl;
			continue;
		}

		if (n == 2) {
			cout << a[1] << " " << a[0] << nl;
			continue;
		}

		vector<int> ans(n);

		if (pos_max == n - 1) {
			int r = n - 1;
			int l = r;
			while (l - 1 > -1 and a[l - 1] > a[0]) l--;
			ans = operation(l, r, a);
		}
		else if (pos_max == 0) {
			int l = 1, r = l;
			while (l < n and a[l] == n - l) l++;
			if (l == n) {
				ans = operation(0, 0, a);
			}
			else {
				int cmax = 0;
				for (i = 1; i < n; i++)
					if (a[i] > cmax) {
						r = i;
						cmax = a[i];
					}
				if (r < n - 1)
					ans = operation(r - 1, r - 1, a);
				else
					ans = operation(r, r, a);
			}
		}
		else {
			int r = pos_max - 1;
			int l = r;
			while (l - 1 > -1 and a[l - 1] > a[0]) l--;
			ans = operation(l, r, a);
		}

		for (int e : ans)
			cout << e << " ";

		cout << nl;
	}
}
