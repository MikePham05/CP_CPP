#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

void solve(int n) {
	if (n == 1) {
		cout << "1" << '\n';
	} else if (n % 2 == 1) {
		cout << -1 << "\n";
	}
	else {
		vector<int> ans, r;
		cout << n << " ";
		for (int i = 0; i < n / 2; i++) {
			r.push_back(i);
			r.push_back(n - 1 - i);
		}
		for (int i = 0; i < n - 1; i++) {
			cout << (r[i + 1] % n - r[i] + n) % n << " ";
		}
		cout << '\n';
	}
}

void p() {
	int num_test, n;
	cin >> num_test;
	for (int i = 0; i < num_test; i++) {
		cin >> n;
		solve(n);
	}
}