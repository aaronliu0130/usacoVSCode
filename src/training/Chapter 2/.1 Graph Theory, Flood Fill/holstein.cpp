/*
ID: aaronli2
TASK: holstein
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>
#include <bitset>
#include <functional>
#include <vector>
using namespace std;
int popcount(int n)
{ //https://stackoverflow.com/questions/14682641/count-number-of-1s-in-binary-format-of-decimal-number 32 should be enough.
    bitset<32> b(n);
    return b.count();
}

int v, g, bes = (1 << 16) - 1, req[25], val[15][25];

void dfs(int ind, int use)
{
    bool bad = 0;
    for (int i = 0; i < v; i++)
        if (req[i] > 0)
            bad = 1;
    if (!bad)
    {
        if (popcount(use) < popcount(bes))
            bes = use;
        else if (popcount(use) == popcount(bes))
            bes = min(bes, use);
        return;
    }
    if (ind < g)
    {
        dfs(ind + 1, use);
        for (int i = 0; i < v; i++)
            req[i] -= val[ind][i];
        dfs(ind + 1, use ^ (1 << ind));
        for (int i = 0; i < v; i++)
            req[i] += val[ind][i];
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ofstream fout("holstein.out");
    ifstream fin("holstein.in");

    fin >> v;
    for (int i = 0; i < v; i++)
        fin >> req[i];
    fin >> g;
    for (int i = 0; i < g; i++)
        for (int j = 0; j < v; j++)
            fin >> val[i][j];

    dfs(0, 0);
    fout << __builtin_popcount(bes);
    for (int i = 0; i < g; i++)
        if (bes & (1 << i))
            fout << " " << i + 1;
    fout << "\n";
}
/*original c++ attempt
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ofstream fout("holstein.out");
    ifstream fin("holstein.in");
    int v, g; //Thought of first three letters of "amount", "amo", so "ammo" just for fun
    vector<int> req(30);
    vector<vector<int>> ammo(20, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0});
    fin >> v;
    for (int i = 0; i < v; i++)
        fin >> req[i];
    fin >> g;
    for (int i = 0; i < g; i++)
        for (int j = 0; j < v; j++)
            fin >> ammo[i][j];
    int min = INT32_MAX;
    function<void(int, int)> dfs = [&v, &req, &dfs, &min, &g, &ammo](int n, int step) -> void {
        bool flag(1);
        for (int i = 0; i < v; i++)
            if (req[i] > 0)
                flag = 0;
        if (flag)
        {
            if (popCount(step) < popCount(min))
                min = step;
            else if (popCount(step) == popCount(min))
                if (step < min)
                    min = step;
            return;
        }
        if (n < g)
        {
            dfs(n + 1, step);
            for (int i = 0; i < v; i++)
                req[i] -= ammo[n][i];
            dfs(n + 1, step ^ (2 ^ n));
            for (int i = 0; i < v; i++)
                req[i] += ammo[n][i];
        }
    };
    dfs(0, 0);
    fout << popCount(min);
    for (int i = 0; i < g; i++)
        if (min & (2 ^ i))
            fout << " " << i + 1;
    fout << endl;
    return 0;
}
*/