/*
ID: aaronli2
TASK: combo
LANG: C++11                 
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ofstream fout("combo.out");
    ifstream fin("combo.in");
    int n, a, b, c, d, e, f, ans(0); //Note that "abc" is farmer john's combo, and "def" is the lockmaster's combo(to not get me mixed up in the future in this mess)
    fin >> n >> a >> b >> c >> d >> e >> f;
    bool used[101][101][101];
    for (int i = a - 2; i <= a + 2; ++i)
        for (int j = b - 2; j <= b + 2; ++j)
            for (int k = c - 2; k <= c + 2; ++k)
                if (!used[(i + n) % n][(j + n) % n][(k + n) % n])
                    ans++, used[(i + n) % n][(j + n) % n][(k + n) % n] = 1;
    for (int i = d - 2; i <= d + 2; ++i)
        for (int j = e - 2; j <= e + 2; ++j)
            for (int k = f - 2; k <= f + 2; ++k)
                if (!used[(i + n) % n][(j + n) % n][(k + n) % n])
                    ans++, used[(i + n) % n][(j + n) % n][(k + n) % n] = 1;
    fout << ans << endl;
    return 0;
}