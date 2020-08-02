/*
ID: aaronli2
TASK: numtri
LANG: C++11                 
*/
#include <iostream>
#include <fstream>
#include <string>
int n, map[1001][1001], used[1001][1001], count;
using namespace std;
int dfs(int x, int y)
{
    int ret(0);
    if (x == n)
        return map[x][y];
    if (used[x + 1][y] == -1)
        used[x + 1][y] = dfs(x + 1, y);
    if (used[x + 1][y + 1] == -1)
        used[x + 1][y + 1] = dfs(x + 1, y + 1);
    ret = used[x + 1][y + 1] > used[x + 1][y] ? used[x + 1][y + 1] + map[x][y] : used[x + 1][y] + map[x][y];
    return ret;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ofstream fout("numtri.out");
    ifstream fin("numtri.in");
    fin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++)
        {
            fin >> map[i][j];
            used[i][j] = -1;
        }
    fout << dfs(1, 1) << endl;
    return 0;
}