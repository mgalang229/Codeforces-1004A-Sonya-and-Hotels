#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, d;
	cin >> n >> d;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	set<int> s;
	for (int i = 0; i < n; i++) {
		// calculate the left and right numbers that are 'd' places away from the current element,
		// then check if the minimum distance of these numbers from all the other elements is equal 'd'
		int left = a[i] - d;
		int right = a[i] + d;
		int left_min_dist = INT_MAX;
		int right_min_dist = INT_MAX;
		for (int j = 0; j < n; j++) {
			left_min_dist = min(left_min_dist, abs(left - a[j]));
			right_min_dist = min(right_min_dist, abs(right - a[j]));
		}
		if (left_min_dist == d) {
			s.insert(left);
		}
		if (right_min_dist == d) {
			s.insert(right);
		}
	}
	cout << (int) s.size() << '\n';
	return 0;
}
