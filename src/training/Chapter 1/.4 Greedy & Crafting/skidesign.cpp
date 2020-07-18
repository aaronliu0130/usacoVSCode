#if 1
/*
ID: aaronli2
TASK: skidesign
LANG: C++11                 
*/
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int min=(INT32_MAX),n;
    cin>>n;
    int a[n+10];
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=a[1];i<=a[n];i++)
    {
        int s(0);
        for(int j=1;j<=n;j++)
        {
            if(a[j]<i) s+=(i-a[j])*(i-a[j]);
            else if(a[j]>i+17) s+=(a[j]-i-17)*(a[j]-i-17);
        }
        if(s<min) min=s;
    }
    cout<<min<<endl;
    return 0;
}
#endif