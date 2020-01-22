#if 0
/*
ID: aaronli2
TASK: palsquare
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
    ofstream fout ("palsquare.out");
    ifstream fin ("palsquare.in");
    int base;
    fin>>base;
    for(int i=1;i<=300;i++){
        string n=baseConv(i,base), n2=baseConv(i*i,base);
        if(n2==rev(n2))fout<<n<<" "<<n2<<endl;
    }
    return 0;
}
#endif