#if 0
/*
ID: aaronli2
TASK: gymnastics
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ofstream fout("gymnastics.out");
    ifstream fin("gymnastics.in");
    int k, n;
    fin >> k >> n;
    vector<vector<int>> rank(k);
    int temp;
    vector<vector<bool>> greater(n);
    for (int i = 0; i < k; i++)
        for (int j = 0; j < n; j++)
        {
            fin >> temp;
            rank[i].push_back(temp);
        }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            greater[i].push_back(i == j ? 0 : 1);
        }
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int jj = 0; jj < n; jj++)
            {
                if (j == jj)
                    continue;
                if (j > jj && greater[rank[i][j] - 1][rank[i][jj] - 1])
                {
                    greater[rank[i][j] - 1][rank[i][jj] - 1] = 0;
                }
            }
        }
    }
    int res(0);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (greater[i][j])
                res++;
        }
    }
    fout << res << endl;
    return 0;
}
#endif
