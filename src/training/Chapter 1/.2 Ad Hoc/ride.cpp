/*
ID: aaronli2
TASK: ride
LANG: C++11                 
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ofstream fout("ride.out");
    ifstream fin("ride.in");
    string a, b;
    int ans = 1, num = 1;
    fin >> a >> b;
    for (int i = 0; i < a.length(); i++)
        ans *= a[i] - 'A' + 1;
    for (int i = 0; i < b.length(); i++)
        num *= b[i] - 'A' + 1;
    if (ans % 47 == num % 47)
        fout << "GO" << endl;
    else
        fout << "STAY" << endl;
    return 0;
}
