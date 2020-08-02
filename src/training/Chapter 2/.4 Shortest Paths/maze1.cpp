/*
ID: aaronli2
TASK: maze1
LANG: C++11
Very mean, USACO. Very,very,mean.
*/
#include <iostream>
#include <fstream>
#include <queue>
#include <cstring>
using namespace std;
struct node
{
    int x, y, sum;
} temp, now;
int n, m, sx[3], sy[3], dis[208][90];
char map[208][90];
bool f[208][90];
queue<node> q;
void BFS(int num)
{
    int dx[5] = {0, 2, 0, -2}, dy[5] = {2, 0, -2, 0}, rx[5] = {0, 1, 0, -1}, ry[5] = {1, 0, -1, 0};
    memset(f, 0, sizeof(f));
    while (!q.empty())
        q.pop();
    f[sx[num]][sy[num]] = 1;
    temp.sum = 0, temp.x = sx[num], temp.y = sy[num];
    q.push(temp);
    while (!q.empty())
    {
        now = q.front();
        int x = now.x, y = now.y, s = now.sum;
        q.pop();
        dis[x][y] = min(s, dis[x][y]);
        for (int i = 0; i < 4; i++)
        {
            int xx = dx[i] + x, yy = dy[i] + y;
            int zx = rx[i] + x, zy = ry[i] + y;
            if (!f[xx][yy] && map[xx][yy] == ' ' && xx <= 2 * n + 1 && xx > 0 && yy <= 2 * m + 1 && yy > 0 && map[zx][zy] == ' ' && (x != sx[num] || y != sy[num]))
            {
                f[xx][yy] = 1;
                temp.x = xx, temp.y = yy, temp.sum = s + 1;
                q.push(temp);
            }
            if (!f[zx][zy] && map[zx][zy] == ' ' && x == sx[num] && y == sy[num] && zx <= 2 * n + 1 && zy <= 2 * m + 1 && zx > 0 && zy > 0)
            {
                f[zx][zy] = 1;
                temp.x = zx, temp.y = zy, temp.sum = s + 1;
                q.push(temp);
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ofstream fout("maze1.out");
    ifstream fin("maze1.in");
    int cnt, ans;
    fin >> m >> n;
    for (int i = 1; i <= 2 * n + 1; i++)
    {
        for (int j = 1; j <= 2 * m + 1; j++)
        {
            dis[i][j] = INT32_MAX;
        }
    }
    string temp;
    getline(fin, temp);
    strcpy(map[0], temp.c_str());
    for (int i = 1; i <= 2 * n + 1; i++)
    {
        getline(fin, temp);
        strcpy(map[i] + 1, temp.c_str());
        for (int j = 1; j <= 2 * m + 1; j++)
        {
            if (i == 1 || j == 1 || i == 2 * n + 1 || j == 2 * m + 1)
                if (map[i][j] == ' ')
                {
                    sx[++cnt] = i;
                    sy[cnt] = j;
                }
        }
    }
    BFS(1);
    BFS(2);
    for (int i = 1; i <= 2 * n + 1; i++)
    {
        for (int j = 1; j <= 2 * m + 1; j++)
        {
            if (dis[i][j] != INT32_MAX)
                ans = max(ans, dis[i][j]);
        }
    }
    fout << ans << '\n';
    return 0;
}