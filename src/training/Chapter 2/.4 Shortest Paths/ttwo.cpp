/*
ID: aaronli2
TASK: ttwo
LANG: C++11
*/
#include <iostream>
#include <fstream>
using namespace std;
char map[10][10];
void move(int *x, int *y, int *face)
{
    const int dx[] = {0, 1, 0, -1}, dy[] = {-1, 0, 1, 0};
    int xx(*x + dx[*face]), yy(*y + dy[*face]);
    if (xx < 0 || yy < 0 || xx >= 10 || yy >= 10 || map[yy][xx] == '*')
    {
        *face = ++*face % 4;
    }
    else
    {
        *x = xx, *y = yy;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ofstream fout("ttwo.out");
    ifstream fin("ttwo.in");
    int cx, cy, cf(0), fx, fy, ff(0);
    for (int i(0); i < 10; i++)
    {
        for (int j(0); j < 10; j++)
        {
            fin >> map[i][j];
            if (map[i][j] == 'C')
            {
                cx = j, cy = i;
            }
            if (map[i][j] == 'F')
            {
                fx = j, fy = i;
            }
        }
    }
    int i(0);
    for (; i < 160000 && !(cx == fx && cy == fy); i++)
    {
        move(&cx, &cy, &cf), move(&fx, &fy, &ff);
    }
    if (cx == fx && cy == fy)
    {
        fout << i << '\n';
    }
    else
    {
        fout << '0' << '\n';
    }
    return 0;
}