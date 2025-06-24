#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int Binary(vector<int>& v2, int left, int right, int findIdx) {
	while (left <= right) {
		int mid = (left + right) / 2;

		if (v2[mid] > findIdx) {
			right = mid - 1;
		}
		else if (v2[mid] < findIdx) {
			left = mid + 1;
		}
		else {
			return mid;
		}
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, a, temp, maxIdx = 0;
	cin >> n;
	vector<int> v1;
	vector<int> v2;
	for (int i = 0; i < n; i++) {
		
		cin >> a;
		v1.push_back(a);
		v2.push_back(a);
	}

	sort(v2.begin(), v2.end());

	for (int i = 0; i < n; i++) {
		temp = Binary(v2, 0, n - 1, v1[i]);
		maxIdx = max(i - temp, maxIdx);
	}

	cout << maxIdx;
}