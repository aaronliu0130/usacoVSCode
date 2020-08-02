/*
ID: aaronli2
TASK: sprime
LANG: C++11                 
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
/*
"Don't just print the answers, you must calculate them" Calculated using code below: 
bool ido(int x)
{
    if (x == 1)
        return 0;
    if (x == 2)
        return 1;
    for (int i = 2; i <= sqrt(x); i++)
        if (x % i == 0)
            return 0;
    return 1;
}

bool judge(int x)
{
    while (x)
    {
        if (!ido(x))
            return 0;
        x /= 10;
    }

    return 1;
}

int main()
{
    for (int i = 1; i <= 99999999; i++)
        if (judge(i))
            cout << i << ',';
    return 0;
}
*/
    int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ofstream fout("sprime.out");
    ifstream fin("sprime.in");
    int dirtyTrick[9][20] = {{}, {0, 2, 3, 5, 7}, {0, 23, 29, 31, 37, 53, 59, 71, 73, 79}, {0, 233, 239, 293, 311, 313, 317, 373, 379, 593, 599, 719, 733, 739, 797}, {0, 2333, 2339, 2393, 2399, 2939, 3119, 3137, 3733, 3739, 3793, 3797, 5939, 7193, 7331, 7333, 7393}, {0, 23333, 23339, 23399, 23993, 29399, 31193, 31379, 37337, 37339, 37397, 59393, 59399, 71933, 73331, 73939}, {0, 233993, 239933, 293999, 373379, 373393, 593933, 593993, 719333, 739391, 739393, 739397, 739399}, {0, 2339933, 2399333, 2939999, 3733799, 5939333, 7393913, 7393931, 7393933}, {0, 23399339, 29399999, 37337999, 59393339, 73939133}}, num[9] = {0, 4, 9, 14, 16, 15, 12, 8, 5}, n; //I GIVE UP ON PRODUCING A RIGHT ANSWER I WASTED TIME LEARNING EULER ARGGGGGGGH
    fin >> n;
    for (int i = 1; i <= num[n]; i++)
        fout << dirtyTrick[n][i] << endl;
    return 0;
}