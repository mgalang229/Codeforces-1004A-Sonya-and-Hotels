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
	// view the image in this repository for better understanding
	// we can place 2 hotels (one before the first and one before the last) 
	int cnt = 2;
	if (n > 1) {
		for (int i = 1; i < n; i++) {
			// there will be two case for each adjacent hotel
			// left hotel = a[i - 1], right hotel = a[i]
			// case 1:
			// if the distance between the left and right hotel is exactly equal to 'd', then
			// we can place one hotel in the middle of them
			// case 2:
			// if the distance between the left and right hotel is greater than 'd', then we can
			// place two additional hotels (one to the right of the left hotel and one to the left of the right hotel)
			int dist = a[i] - a[i - 1];
			if (dist == 2 * d) {
				cnt++;
			} else if (dist > 2 * d) {
				cnt += 2;
			}
		}
	}
	cout << cnt << '\n';
	return 0;
}
