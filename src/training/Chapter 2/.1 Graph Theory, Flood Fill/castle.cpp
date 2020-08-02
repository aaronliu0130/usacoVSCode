/*
ID: aaronli2
TASK: castle
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>
#include <queue>
using namespace std;
int a[51][51] = {0}, comp[51][51], s[2501], num, dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
void flood_fill(int i, int j)
{
    num++;
    queue<pair<int, int>> todo;
    todo.push(make_pair(i, j));
    while (todo.size())
    {
        pair<int, int> k = todo.front();
        todo.pop();
        if (comp[k.first][k.second])
            continue;
        comp[k.first][k.second] = num, ++s[num];
        for (int z = 0; z < 4; z++)
            if ((a[k.first][k.second] & (1 << z)) == 0)
                if (comp[k.first + dx[z]][k.second + dy[z]] == 0)
                    todo.push(make_pair(k.first + dx[z], k.second + dy[z]));
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ofstream fout("castle.out");
    ifstream fin("castle.in");
    int m, n;
    fin >> m >> n;
    for (int j = n - 1; j >= 0; j--)
        for (int i = 0; i < m; i++)
            fin >> a[i][j];
    for (int j = 0; j < n; j++)
        for (int i = 0; i < m; i++)
            if (!comp[i][j])
                flood_fill(i, j);
    fout << num << "\n";
    int x(0);
    for (int i = 1; i < num + 1; i++)
        x = s[i] > x ? s[i] : x;
    fout << x << "\n";
    int max(0);
    pair<pair<int, int>, int> p;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            for (int z = 0; z < 4; z++)
                if (a[i][j] & (1 << z))
                    if (i + dx[z] >= 0 && i + dx[z] < m)
                        if (j + dy[z] >= 0 && j + dy[z] < n)
                        {
                            int ans = s[comp[i + dx[z]][j + dy[z]]];
                            if (comp[i + dx[z]][j + dy[z]] != comp[i][j])
                                ans += s[comp[i][j]];
                            if (ans > max)
                            {
                                p = make_pair(make_pair(i, j), z);
                                max = ans;
                            }
                        }
    fout << max << "\n";
    char compass[4] = {'W', 'N', 'E', 'S'};
    fout << (n - p.first.second) << " " << (p.first.first + 1) << " " << compass[p.second] << endl;
    return 0;
}