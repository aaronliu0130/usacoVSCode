/*
ID: aaronli2
TASK: milk2
LANG: C++11                 
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
struct milking
{
    int start, end;
    bool operator<(const milking m) const
    {
        return start < m.start;
    }
};
int main()
{
    ofstream fout("milk2.out");
    ifstream fin("milk2.in");
    int n;
    fin >> n;
    vector<milking> a;
    for (int i = 0; i < n; i++)
    {
        milking temp;
        fin >> temp.start >> temp.end;
        a.push_back(temp);
    }
    sort(a.begin(), a.end());
    for (int i = 1; i < a.size(); i++)
        if (a[i].start <= a[i - 1].end)
        {
            a[i - 1].end = a[i].end > a[i - 1].end ? a[i].end : a[i - 1].end;
            a.erase(a.begin() + i--);
        }
    int maxa = 0, maxin = 0;
    for (int i = 0; i < a.size(); i++)
    {
        a[i].end > a[i].start + maxa ? maxa = a[i].end - a[i].start : maxa = maxa;
        if (!i)
            continue;
        maxin = a[i].start - a[i - 1].end > maxin ? a[i].start - a[i - 1].end : maxin;
    }
    fout << maxa << " " << maxin << endl;
    return 0;
}