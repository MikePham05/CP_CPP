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
	char nl = '\n';
	cin >> tt;

	while (tt--) {
		int n, first_node, i, j;
		cin >> n;
		vector<int> adj(n + 1), count(n + 1);
		for (i = 0; i < n; i++) {
			cin >> adj[i + 1];
			count[adj[i + 1]]++;
		}


		int hc = 0, fc = 0;
		vector<int> passed(n + 1);
		for (i = 1; i < n + 1; i++)
			if (passed[i] == 0) {
				int last;
				first_node = i;
				j = i;
				hc++;
				while (passed[j] == 0) {
					passed[j]++;
					last = j;
					j = adj[j];
				}
				if (j == first_node) {// fc
					if (adj[adj[j]] != j) {
						hc--;
						fc++;
					}
				}
				else if (adj[j] != last) hc--;
			}

		cout << fc + min(hc, 1) << " " << fc + hc << "\n";
	}
}

