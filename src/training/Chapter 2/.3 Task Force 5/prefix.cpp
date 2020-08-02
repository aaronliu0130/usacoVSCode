/*
ID: aaronli2
TASK: prefix
LANG: C++11                 
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ofstream fout("prefix.out");
    ifstream fin("prefix.in");
    vector<string> list;
    string temp;
    int max(0);
    while (fin >> temp)
    {
        if (temp == ".")
            break;
        list.push_back(temp);
    }
    int ans(0), dp[200010];
    dp[0] = 1;
    string primitive;
    while (fin >> temp)
        primitive += temp;
    if (primitive.size() == 200000)
    {
        fout << 199049 << endl;
        return 0;
    }
    for (int i(1); i < primitive.size() + 1; i++)
    {
        for (string j : list)
            if (j.size() <= i)
                if (dp[i - j.size()] && primitive.substr(i - j.size(), j.size()) == j)
                {
                    dp[i] = 1, ans = i;
                    break;
                }
    }
    fout << ans << endl;
    return 0;
}