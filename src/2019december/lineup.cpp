#if 1
/*
ID: aaronli2
TASK: lineup
LANG: C++11                 
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

vector<int> solve(const vector<pair<int, int>>& constraints, int n = 8) {
	vector<int> res;
	map<int, set<int> > cons;
	for (auto c : constraints) {
		cons[c.first].insert(c.second);
		cons[c.second].insert(c.first);
	}
	for (int i = 0; i < n; ++i)
		if (!cons.count(i))
			cons[i]= {};
	while (!cons.empty()) {
		auto h = cons.begin();
		for (; h != cons.end() && h->second.size() > 1; ++h)
			;
		res.push_back(h->first);
		while (!h->second.empty()) {
			auto next = *h->second.begin();
			res.push_back(next);
			h->second.erase(next);
			cons[next].erase(h->first);
			if (h->second.empty())
				cons.erase(h);
			h = cons.find(next);
		}
		cons.erase(h);
	}

	return res;
}
int test() {
	return 1;
	auto tmp = solve( { { 1, 2 }, { 3, 1 }, { 0, 7 }, { 0, 6 } });
	tmp = solve( { { 6, 2 }, { 5, 2 }, { 7, 0 } });
	tmp = solve( { { 2, 3 }, { 6, 2 }, { 7, 1 } });
	return 0;
}
int main() {
	if (test()) {
    ofstream fout ("lineup.out");
    ifstream fin ("lineup.in");
    
    int n;
    fin>>n;
		vector<pair<int, int>> constraints(n);
		vector<string> cows = { "Bessie", "Buttercup", "Belinda", "Beatrice",
				"Bella", "Blue", "Betsy", "Sue" };
		std::sort(cows.begin(), cows.end());
	for (auto i = 0; i < n; ++i) {
		string tmp;
		fin>>tmp;
			constraints[i].first = std::find(cows.begin(), cows.end(), tmp)
					- cows.begin();
			fin >> tmp >> tmp >> tmp >> tmp >> tmp;
			constraints[i].second = std::find(cows.begin(), cows.end(), tmp)
					- cows.begin();
	}
	auto res = solve(constraints);
	for (auto c : res)
			fout << cows[c] << '\n';
	}
    return 0;
}
#endif
