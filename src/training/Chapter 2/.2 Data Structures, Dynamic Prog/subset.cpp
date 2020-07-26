/*
ID: aaronli2
TASK: subset
LANG: C++11                 
*/
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ofstream fout("subset.out");
    ifstream fin("subset.in");
    int n;
    fin >> n;
    int m(n * (n + 1) / 2);
    long long int ans[m + 1] = {0};
    if (m % 2)
    {
        fout << 0 << endl;
        return 0;
    }
    m /= 2;
    ans[0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = m; j >= i; j--)
            ans[j] += ans[j - i];
    fout << ans[m] / 2 << endl;
    return 0;
}