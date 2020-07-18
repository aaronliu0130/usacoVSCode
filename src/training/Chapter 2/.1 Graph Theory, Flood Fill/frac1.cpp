/*
ID: aaronli2
TASK: frac1
LANG: C++11                 
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
vector<pair<float, float>> a;
void solve(int n)
{
    for (float j = 1.0; j <= n; j += 1)
        for (float i = 0.0; i <= n; i += 1)
        {
            if (i / j > 1)
                continue;
            a.push_back(make_pair(i, j));
        }
}
bool comp(pair<float, float> a, pair<float, float> b)
{
    return ((a.first / a.second) < (b.first / b.second));
}
bool equal(pair<float, float> a, pair<float, float> b)
{
    return ((a.first / a.second) == (b.first / b.second));
}
bool dupeComp(pair<float, float> a, pair<float, float> b)
{
    return ((a.first + a.second) < (b.first + b.second));
}
void rmdupe()
{
    for (int i = 0; i <= a.size() - 2; i++)
    {
        if (equal(a[i], a[i + 1]))
        {
            a.erase(a.begin() + i + dupeComp(a[i], a[i + 1]));
            i--;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ofstream fout("frac1.out");
    ifstream fin("frac1.in");
    int n;
    fin >> n;
    solve(n);
    sort(a.begin(), a.end(), comp);
    rmdupe();
    for (auto i : a)
    {
        fout << i.first << '/' << i.second << endl;
    }
    return 0;
}