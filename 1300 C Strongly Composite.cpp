#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <cmath>
using namespace std;

const int limit = 10000000;

int solve(int n, vector<int>& a, unordered_set<int>& prime, vector<int>& p_list) {
	int ans = 0, com_count = 0, num, cc = 0, odd = 0, mul = 0, d;
	unordered_map<int, int> count;
	unordered_map<int, int> count_prime;
	for (int num : a) {
		if (count.find(num) == count.end()) {
			count.insert(pair<int, int>(num, 0));
		}
		count[num]++;
	}

	for (auto& e : count) {
		num = e.first;
		int i, j = 0;

		while (j < p_list.size() and p_list[j] <= num and num > 1) {
			i = p_list[j];
			mul = 0;
			while (num % i == 0) {
				mul++;
				num = num / i;
			}
			count_prime[i] += e.second * mul;
			j++;
		}
	}

	for (auto& e : count_prime) {
		ans += e.second / 2;
		odd += e.second % 2;
	}
	
	ans += odd / 3;

	return ans;
}

void sieve(unordered_set<int>& p, vector<int>& p_list) {
	vector<bool> t(limit);
	for (int i = 2; i < limit; i++) 
		if (not t[i]) {
			p.insert(i);
			p_list.push_back(i);
			if ((long long) i * i < limit)
				for (int j = i * i; j < limit; j += i)
					t[j] = true;
		}
}

int main() {
	vector<int> a, prime_list;
	unordered_set<int> prime;
	sieve(prime, prime_list);
	int test, n, d;
	cin >> test;
	for (int i = 0; i < test; i++) {
		cin >> n;
		a.clear();
		for (int j = 0; j < n; j++) {
			cin >> d;
			a.push_back(d);
		}
		cout << solve(n, a, prime, prime_list) << '\n';
	}
}