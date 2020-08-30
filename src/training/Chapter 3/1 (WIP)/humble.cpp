/*
 ID: aaronli2
 TASK: humble
 LANG: C++11
 */
#include <algorithm>    // std::sort
#include <fstream>
#include <queue>
#include <vector>
using namespace std;

int main() {
	ofstream fout("humble.out");
	ifstream fin("humble.in");
	int k, n, p;
	fin >> k >> n;
	auto comp = [](const vector<long long> &lth, const vector<long long> &rth) {
		return lth[0] > rth[0];
	};
	priority_queue<vector<long long>, vector<vector<long long>>,
			decltype( comp )> q(comp);
	for (int i = 0; i < k; ++i) {
		fin >> p;
		q.push( { p, p, 0 });
	}

	vector<long long> next, ans(n);
	ans[0] = 1;
	for (int i = 1; i < n; ++i)
		for (ans[i] = q.top()[0]; ans[i] == (next = q.top())[0];
				q.pop())
			q.push( { next[1] * ans[next[2]], next[1], next[2] + 1 });
	fout << q.top()[0] << '\n';
	return 0;
}
