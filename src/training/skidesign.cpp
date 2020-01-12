#if 0
/*
ID: aaronli2
TASK: skidesign
LANG: C++11                 
*/
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int sqr(int a) {return a*a;}
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ofstream fout("skidesign.out");
    ifstream fin("skidesign.in");
    int min=(INT32_MAX),n;
    fin>>n;
    int a[n+10];
    for(int i=1;i<=n;i++) fin>>a[i];
    sort(a+1,a+n+1);
    for(int i=a[1];i<=a[n];i++)
    {
        int s(0);
        for(int j=1;j<=n;j++)
        {
            if(a[j]<i) s+=sqr(i-a[j]);
            else if(a[j]>i+17) s+=sqr(a[j]-i-17);
        }
        if(s<min) min=s;
    }
    fout<<min<<endl;
    return 0;
}
#endif