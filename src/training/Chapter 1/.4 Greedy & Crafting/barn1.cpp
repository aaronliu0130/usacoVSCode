/*
ID: aaronli2
TASK: barn1
LANG: C++11                 
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
bool cmp(int x, int y) { return x > y; }
int main()
{
    ofstream fout("barn1.out");
    ifstream fin("barn1.in");
    int m, s, c;
    fin >> m >> s >> c;
    if (m > c)
    {
        printf("%d\n", c);
        return 0;
    }
    int a[c + 1];
    for (int i = 1; i <= c; i++)
        fin >> a[i];
    sort(a + 1, a + c + 1);
    int ans(a[c] - a[1] + 1);
    int d[c + 1];
    for (int i = 2; i <= c; i++)
        d[i - 1] = a[i] - a[i - 1];
    sort(d + 1, d + c, cmp);
    for (int i = 1; i <= m - 1; i++)
        ans -= d[i] + 1;
    fout << ans << endl;
    return 0;
}