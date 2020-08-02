/*
ID: aaronli2
TASK: crypt1
LANG: C++11                 
*/
#include <iostream>
#include <fstream>
#include <string>
bool bucket[15];
using namespace std;
bool chkNum(int n)
{
    while (n)
    {
        if (!bucket[n % 10])
            return 0;
        n /= 10;
    }
    return 1;
}
bool chkTimes(int x, int y)
{
    int part1 = x * (y % 10), part2 = x * (y / 10), sum = x * y;
    if (part1 > 999 || part2 > 999 || sum > 9999)
        return 0;
    if (chkNum(x) && chkNum(y) && chkNum(part1) && chkNum(part2) && chkNum(sum))
        return 1;
    else
        return 0;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ofstream fout("crypt1.out");
    ifstream fin("crypt1.in");
    int n;
    fin >> n;
    int bucketi;
    for (int i = 0; i < n; i++)
    {
        fin >> bucketi;
        bucket[bucketi] = 1;
    }
    int res(0);
    for (int i = 100; i < 1000; i++)
        for (int j = 10; j < 100; j++)
            if (chkTimes(i, j))
                res++;
    fout << res << endl;
    return 0;
}