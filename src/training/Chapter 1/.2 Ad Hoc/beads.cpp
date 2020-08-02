/*
ID: aaronli2
TASK: beads
LANG: C++11                 
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ofstream fout("beads.out");
    ifstream fin("beads.in");
    int n;
    string beads;
    fin >> n >> beads;
    int count, res(0);
    char take;
    bool flag;
    for (int i = 0; i < n; i++)
    {
        count = 0, take = 'w', flag = 0;
        for (int j = 0; j < n; j++)
        {
            const char current = beads[(i + j) % n];
            if (current != 'w')
            {
                if (take == 'w')
                    take = current;
                else if (take != current)
                {
                    if (flag)
                        break;
                    else
                        take = current, flag = 1;
                }
            }
            count++;
        }
        count > res ? res = count : res = res;
    }
    fout << res << endl;
    return 0;
}
