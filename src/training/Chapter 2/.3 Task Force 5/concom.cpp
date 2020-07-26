/*
ID: aaronli2
TASK: concom
LANG: C++11
*/
#include <iostream>
#include <fstream>
using namespace std;
int a[120][120], b[120][120], ak[120][120], a0[120], j, o, p, m, ret;
//Got lazy finding out a variable needs to be global and pasting it here again and again. Why not just put them all here? I'm aware of this being bad code style.
int dfs(int x, int y)
{
    for (int w = 1; w <= a0[y]; w++)
    {
        a[x][ak[y][w]] += a[y][ak[y][w]];
        if (a[x][ak[y][w]] >= 50 && b[x][ak[y][w]] != 1)
        {
            b[x][ak[y][w]] = 1;
            ret = dfs(x, ak[y][w]);
        }
    }
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ofstream cout("concom.out");
    ifstream cin("concom.in");
    cin >> m;
    for (int i(1); i <= m; i++)
    {
        cin >> o >> p >> a[o][p];
        ak[o][++a0[o]] = p;
    }

    for (int i(1); i <= 100; i++)
    {
        b[i][i] = 1;
        if (ak[i][1] != 0)
            for (int j(1); j <= a0[i]; j++)
            {
                if (a[i][ak[i][j]] >= 50 && b[i][ak[i][j]] != 1 && i != ak[i][j])
                {
                    b[i][ak[i][j]] = 1;
                    ret = dfs(i, ak[i][j]);
                }
            }
    }
    for (int i(1); i <= 100; i++)
        for (int j(1); j <= 100; j++)
            if (b[i][j] == 1 && i != j)
            {
                cout << i << ' ' << j << '\n';
            }
    return 0;
}