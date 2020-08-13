/*
ID: aaronli2
TASK: swap
LANG: C++11                 
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ofstream fout ("swap.out");
    ifstream fin ("swap.in");
    int n,k,a1,a2,b1,b2;
    fin>>n>>k>>a1>>a2>>b1>>b2;
    vector<int>cows(n);
    for(int i=1;i<=n;i++)cows[i-1]=i;
    if(a1==b1&&a2==b2)for(auto i:cows)fout<<i<<"\n";;
    for(int i=0;i<k;i++){
        reverse(cows.begin()+(a1-1),cows.begin()+a2);
        reverse(cows.begin()+(b1-1),cows.begin()+b2);
    }for(auto i:cows)fout<<i<<"\n";
    return 0;
}