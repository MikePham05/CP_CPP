#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solve(int n, int k, vector<int>& p) {
	vector<int> pos(n + 1);
	int ans = 0;
	for (int i = 0; i < n; i++)
		pos[p[i]] = i;

	for (int i = 0; i < n; i++) {
		if (p[i] % k != (i + 1) % k) {
			ans = 1;
			int j = i;
			while (j + 1 < n and p[j + 1] % k == (j + 2) % k) j++;
			if (j >= n) return -1;
			j++;
			swap(p[i], p[j]);
			break;
		}
	}

	for (int i = 0; i < n; i++)
		if (p[i] % k != (i + 1) % k)
			return -1;
	
	return ans;
}

int main() {
	int num_test, n, d, k;
	vector<int> p;
	cin >> num_test;
	for (int i = 0; i < num_test; i++) {
		cin >> n >> k;
		p.clear();
		for (int j = 0; j < n; j++) {
			cin >> d;
			p.push_back(d);
		}
		cout << solve(n, k, p) << '\n';
	}
}