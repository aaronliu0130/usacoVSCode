/*
ID: aaronli2
TASK: castle
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#define FOR(i, a, b) for (int i = a; i < b; i++)
using namespace std;
int a[51][51] = {0}, comp[51][51], s[2501], num, xdet[4] = {-1, 0, 1, 0}, ydet[4] = {0, 1, 0, -1};
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
                if (comp[k.first + xdet[z]][k.second + ydet[z]] == 0)
                    todo.push(make_pair(k.first + xdet[z], k.second + ydet[z]));
    }
}
void floodFill(int i, int j)
{
    ++num;
    queue<pair<int, int>> q;
    q.push(make_pair(i, j));
    while (q.size())
    {
        pair<int, int> u = q.front();
        q.pop();
        if (comp[u.first][u.second] || u.first < 0 || u.second < 0)
            continue;
        comp[u.first][u.second] = num, ++s[num];
        for (int k = 0; k < 4; k++)
            if ((a[u.first][u.second] & (2 ^ k)) == 0)
                if (comp[u.first + xdet[k]][u.second + ydet[k]] == 0)
                    q.push(make_pair(u.first + xdet[k], u.second + ydet[k]));
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
                    if (i + xdet[z] >= 0 && i + xdet[z] < m)
                        if (j + ydet[z] >= 0 && j + ydet[z] < n)
                        {
                            int ans = s[comp[i + xdet[z]][j + ydet[z]]];
                            if (comp[i + xdet[z]][j + ydet[z]] != comp[i][j])
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