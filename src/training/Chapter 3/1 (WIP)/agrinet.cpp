/*
ID: aaronli2
TASK: agrinet
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <array>
#include <map>
#include <utility>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ofstream fout("agrinet.out");
    ifstream fin("agrinet.in");
    int n, ans(0);
    map<pair<int, int>, int> dis;
    fin >> n;
    array<int, 100> md, s;
    array<bool, 100> it;
    md.fill(INT32_MAX);
    md[1] = 0;
    it.fill(0);
    s.fill(1);
    for (int i(1); i <= n; i++)
        for (int j(1); j <= n; j++)
            fin >> dis[make_pair(i, j)];
    for (int i(1); i <= n; i++) {
        int k(0);
        for (int j(1); j <= n; j++)
            if (!it[j] && md[j] < md[k])
                k = j;
        it[k] = 1;
        for (int j(1); j <= n; j++)
            if (!it[j] && dis[make_pair(k, j)] < md[j])
                md[j] = dis[make_pair(k, j)];
    }
    for (int i(1); i <= n; i++)
        ans += md[i];
    fout << ans << '\n';
    return 0;
}
