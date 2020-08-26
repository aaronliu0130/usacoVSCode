/*
ID: aaronli2
TASK: humble
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <queue>
#include <set>
#include <array>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ofstream fout("humble.out");
	ifstream fin("humble.in");
	int k, n;
	array<int, 101> a;
	fin >> k >> n;
	for (int i(1); i <= k; i++)
		fin >> a[i];
	priority_queue<long long, vector<long long>, greater<long long>> q;
	set<long long> s;
	q.push(1);
	s.insert(1);
	long long ans;
	for (int i(0); i <= n; i++) {
		ans = q.top();
		q.pop();
		for (int j(1); j <= k; j++) {
			long long num(ans * a[j]);
			if (!s.count(num)) {
				q.push(num);
				s.insert(num);
			}
		}
	}
	fout << ans << '\n';
	return 0;
}
