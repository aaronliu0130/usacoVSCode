/*
ID: aaronli2
TASK: stamps
LANG: C++11
COMMENT: Work in progress.
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ofstream fout("stamps.out");
	ifstream fin("stamps.in");
	int k, n;
	vector<int> val;
	fin >> k >> n;
	for (int i(0), temp; i < n; i++) {
		fin >> temp;
		val.push_back(temp);
	}
	sort(val.begin(), val.end());
	vector<int> dp;
	dp.push_back(0);
	dp.push_back(0);
	int i(0);
	while (dp[i++] <= k) {
		dp.push_back(0);
		dp[i] = INT32_MAX;
		for (int j(0); j < n && val[j] <= i; j++)
			if (dp[i] > dp[i - val[j]] + 1)
				dp[i] = dp[i - val[j]] + 1;
	}
	fout << i - 1 << '\n';
	return 0;
}
