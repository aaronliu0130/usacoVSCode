/*
ID: aaronli2
TASK: sort3
LANG: C++11                 
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
//Not my thinking, but my code. Kudos to https://auto-mation.blog.luogu.org/solution-p1459 for great thinking.
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ofstream fout("sort3.out");
    ifstream fin("sort3.in");
    int n, a[1005], index(0), cur(0), ans(0), sum(0), diff2(0), sum2(0), diffn2(0);
    fin >> n;
    for (int i = 1; i <= n; i++)
    {
        fin >> a[++index];
        if (a[index] == 1)
        {
            bool temp = (a[++cur] == 3);
            ans += (a[cur] == (2 + temp));
            diff2 += temp;
        }
        else
            sum2 += (a[index] == 2);
    }
    for (int i = cur + 1; i <= cur + sum2; i++)
        ans += (a[i] == 3);
    for (int i = cur + sum2 + 1; i <= index; i++)
        diffn2 += (a[i] == 1);
    fout << ans + ((diff2 > diffn2) ? diff2 - diffn2 : 0) << endl;
    return 0;
}