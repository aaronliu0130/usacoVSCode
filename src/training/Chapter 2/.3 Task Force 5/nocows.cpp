/*
ID: aaronli2
PROB: nocows
LANG: C++11
*/
#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ifstream fin("nocows.in");
    ofstream fout("nocows.out");
    int n, h, dparr[201][110] = {0};
    fin >> n >> h;
    for (int i(1); i <= h; i++)
    {
        dparr[1][i] = 1;
    }
    for (int i(1); i <= h; i++)
    {
        for (int j(3); j <= n; j += 2)
        {
            for (int k(1); k < j; k += 2)
            {
                (dparr[j][i] += dparr[k][i - 1] * dparr[j - k - 1][i - 1]) %= 9901;
            }
        }
    }
    fout << (dparr[n][h] - dparr[n][h - 1] + 9901) % 9901 << endl;
    return 0;
}