/*
ID: aaronli2
TASK: lamps
LANG: C++11
*/
#include <queue>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;
vector<int> light, dark;
int n, c;
priority_queue<string, vector<string>, greater<string>> ans;
inline bool check(int i, int j, int k, int l, int num)
{
    int g = num & 1;
    if ((i + (j & g) + (k & (!g)) + ((num % 3 == 1) & l)) & 1)
        return 1;
    return 0;
}
inline void count_(int i, int j, int k, int l)
{
    for (int q = 0; q < light.size(); q++)
        if (check(i, j, k, l, light[q]))
            return;
    for (int q = 0; q < dark.size(); q++)
        if (!check(i, j, k, l, dark[q]))
            return;
    string a;
    for (int v = 1; v <= n; v++)
    {
        if (check(i, j, k, l, v))
            a = a + '0';
        else
            a = a + '1';
    }
    ans.push(a);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ofstream fout("preface.out");
    ifstream fin("preface.in");
    int x;
    fin >> n >> c >> x;
    while (x != -1)
    {
        light.push_back(x);
        scanf("%d", &x);
    }
    scanf("%d", &x);
    while (x != -1)
    {
        dark.push_back(x);
        scanf("%d", &x);
    }
    for (int i = 0; i <= 1; i++)
    {
        for (int j = 0; j <= 1; j++)
        {
            for (int k = 0; k <= 1; k++)
            {
                int res = c - i - j - k;
                if (res < 0)
                    continue;
                res %= 2;
                count_(i, j, k, res);
            }
        }
    }
    if (ans.empty())
    {
        fout << "IMPOSSIBLE\n";
    }
    else
    {
        while (!ans.empty())
        {
            fout << ans.top() << '\n';
            ans.pop();
        }
    }
    return 0;
}