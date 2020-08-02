/*
ID: aaronli2
TASK: money
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ofstream fout("money.out");
    ifstream fin("money.in");
    long long v, n, h[30], dp[10005] = {1};
    fin >> v >> n;
    for (int i = (0); i < v; i++)
        fin >> h[i];
    for (int i = (0); i < v; i++)
        for (int j = h[i]; j <= n; j++)
            dp[j] += dp[j - h[i]];
    fout << dp[n] << '\n';
    return 0;
}