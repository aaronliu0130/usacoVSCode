/*
ID: aaronli2
TASK: milk
LANG: C++11                 
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ofstream fout("milk.out");
    ifstream fin("milk.in");
    int n, m;
    fin >> n >> m;
    int ava[1001] = {0};
    for (int i = 0; i < m; i++)
    {
        int p, a;
        fin >> p >> a;
        ava[p % 1001] += a;
    }
    int res;
    for (int i = 0; i < 1001; ++i)
    {
        if (ava[i])
        {
            if (ava[i] >= n)
            {
                res += i * n;
                break;
            }
            else
                res += i * ava[i], n -= ava[i];
        }
    }
    fout << res << endl;
    return 0;
}