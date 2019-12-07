/*
ID: aaronli2
TASK: transform
LANG: C++11                 
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
string rot(const string map,const int s,const int times){
    string res;
    for(int k=0;k<times;k++)
        for(int i=0;i<s;i++)
            for(int j=0;j<s;j++)res[(s-1-i)+j*s]=map[i*s+j];
    return res;
}
string rev(const string map,const int s){
    string res;
    for(int i=0;i<s;i++)
        for(int j=0;j<s;j++)res[i*s+(s-1-j)]=map[i*s+j];
    return res;
}
using namespace std;
int main() {
    ofstream fout ("transform.out");
    ifstream fin ("transform.in");
    int s;
    fin>>s;
    string map,target,temp;
    for(int i=0;i<s;i++)fin>>map[s*i];
    for(int i=0;i<s;i++)fin>>target[s*i];
    int res;
    if(!strcmp(rot(map,s,1).c_str,target.c_str))res=1;
    else if(!strcmp(rot(map,s,2).c_str,target.c_str))res=2;
    else if(!strcmp(rot(map,s,3).c_str,target.c_str))res=3;
    else if(!strcmp(rev(map,s).c_str,target.c_str))res=4;
    fout<<res<<endl;
    return 0;
}