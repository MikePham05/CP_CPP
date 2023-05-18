#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <bitset>
using namespace std;

int main() {
	int tt;
	string s;
	cin >> tt;
	unordered_set<char> t;
	while (tt--) {
		cin >> s;
		t.clear();
		for (char c : s)
			if (t.find(c) == t.end())
				t.insert(c);

		int curr = 0, i = 0, n = s.size(), max_curr = 0, ans = n;
		for (char c : t){
			i = 0;
			int co = 0;
			max_curr = 0;
			while (i < n) {
				if (s[i] == c) {
					co = 0;
					while (curr > 0) {
						curr /= 2;
						co++;
					}
					max_curr = max(max_curr, co);
					curr = 0;
				}
				else curr++;
				i++;
			}
			co = 0;
			while (curr > 0) {
				curr /= 2;
				co++;
			}
			max_curr = max(max_curr, co);
			ans = min(ans, max_curr);
		}

		cout << ans << "\n";
	}
}