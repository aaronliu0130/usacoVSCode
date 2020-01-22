/*
ID: aaronli2
TASK: hamming
LANG: C++11                 
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <bitset>
using namespace std;
int popCount(int n){//https://stackoverflow.com/questions/14682641/count-number-of-1s-in-binary-format-of-decimal-number 32 should be enough.
    bitset<32> b(n);
    return b.count();
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ofstream fout ("hamming.out");
    ifstream fin ("hamming.in");
    int n,b,d;
    vector<int> ans;
    fin>>n>>b>>d;
    ans.push_back(0);
    int i(1);
    while(ans.size()<n){
        bool flag=0;
        for(int j=ans.size();j>=1;j--)
            if(popCount(ans[j]^i)<d){//Sacrificing beauty for more beauty
                flag=1;
                break;
            }
        if(!flag)ans.push_back(i);
        i++;
    }
    for(int cnt=0;cnt<n;cnt++)
        fout<<ans[cnt]<<(cnt%10==9||cnt==n-1/*Fail #2: at end of output _\n instead of \n*/?"\n":" ");//Fail: "_\n" instead of "\n". USACO training does way better than official USACO online contests! Told difference with underscores as spaces.
    return 0;
}