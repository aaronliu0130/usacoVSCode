/*
ID: aaronli2
TASK: fracdec
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ofstream fout("fracdec.out");
    ifstream fin("fracdec.in");
    int n, d, sum, len;
    string ans;
    int pd[100005] = {0};
    fin >> n >> d;
    int k(n / d), w(-1);
    do
    {
        ans += char(k % 10 + '0');
        k /= 10;
    } while (k > 0);
    reverse(ans.begin(), ans.end());
    ans += '.';
    n %= d;
    do
    {
        if (pd[n] != 0)
        {
            w = pd[n];
            break;
        }

        else
            pd[n] = ans.size();

        n *= 10;

        k = n / d;
        ans += char(k + '0');
        n = n % d;

    } while (n != 0);

    if (w != -1)
        ans += ')';

    len = ans.size();
    for (int i = 0; i < len; i++) //Char by char for 76
    {
        if (i == w)
        {
            fout << '(';
            i--;
            w = -1;
        }

        else
            fout << ans[i];
        sum++;
        if (sum % 76 == 0)
            fout << '\n';
    }
    fout << '\n';
    return 0;
}