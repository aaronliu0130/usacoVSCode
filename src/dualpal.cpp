/*
ID: aaronli2
TASK: dualpal
LANG: C++11                 
*/
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;
string baseConv(int n,const int base){
    string res;
    int slasher=base;
    while(slasher<n)slasher*=base;
    slasher/=base;
    while(1){
        res+=n/slasher>=10?n/slasher-10+'A':n/slasher+'0';
        n%=slasher;
        if(slasher<2)break;
        slasher/=base;
    }
    return res;
}
string rev(string str){
    reverse(str.begin(),str.end());
    return str;
}
int main() {
    ofstream fout ("dualpal.out");
    ifstream fin ("dualpal.in");
    int n;
    fin>>n;
    int s;
    fin>>s;
    ++s;//FAIL: It's >, not >=
    for(;n&&s<=100000;++s){//Still not used to ++i in for loops
        int times(0);
        for(int base=2;base<=10;++base){
            string str=baseConv(s,base);
            if(str==rev(str)&&++times>=2){
                --n;fout<<s<<endl;
                break;
            }
        }
    }
    return 0;
}