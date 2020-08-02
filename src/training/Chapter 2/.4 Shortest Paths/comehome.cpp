/*
ID: aaronli2
TASK: comehome
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
int dis[100], map[100][100];
int vis[100];
void mapper(int x, int y, int w)
{

    if (!map[x][y])

    {
        map[x][y] = w;
        map[y][x] = w;
    }
    if (w < map[x][y])
    {
        map[x][y] = w;
        map[y][x] = w;
    }
}
void dijkstra()
{

    int u, min;

    for (int i = 1; i <= 51; i++)
    {
        min = INT32_MAX;
        for (int j = 1; j <= 51; j++)
        {
            if (!vis[j] && dis[j] < min)
            {
                min = dis[j];
                u = j;
            }
        }
        vis[u] = 1;
        for (int v = 1; v <= 51; v++)
        {
            if (dis[v] > dis[u] + map[u][v] && !vis[v] && map[u][v] < INT32_MAX)
                dis[v] = dis[u] + map[u][v];
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ofstream fout("comehome.out");
    ifstream fin("comehome.in");
    int p;
    char r;
    fin >> p;
    for (int i = 1; i <= 52; i++)
        for (int j = 1; j <= 51; j++)
            map[i][j] = INT32_MAX;
    vis[52] = 1;
    for (int i = 1; i <= p; i++)
    {
        char x, y;
        int weight;
        int xx, yy;
        fin >> x >> y >> weight;
        if (x >= 'a' && x <= 'z')
            xx = x - 'a' + 1;
        else
            xx = x - 'A' + 27;
        if (y >= 'a' && y <= 'z')
            yy = y - 'a' + 1;
        else
            yy = y - 'A' + 27;
        mapper(xx, yy, weight);
    }
    for (int i = 1; i <= 51; i++)
        dis[i] = map[52][i];
    dijkstra();
    int hh = INT32_MAX, point;
    for (int i = 1; i <= 51; i++)
    {
        if (dis[i] < hh && i >= 27)
        {
            hh = dis[i];
            point = i;
        }
    }
    r = point - 27 + 'A';
    fout << r << ' ' << hh << '\n';
    return 0;
}