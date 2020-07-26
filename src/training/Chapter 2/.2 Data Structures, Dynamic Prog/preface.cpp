/*
ID: aaronli2
TASK: preface
LANG: C++11                 
*/
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
int n;
int i[20],v[20],x[20],l[20],c[20],d[20],m[20],A[20];
int ansi,ansv,ansx,ansl,ansc,ansd,ansm;
void mem(){
    A[1]=1;i[1]=1;
    A[2]=4;i[2]=1;v[2]=1;
    A[3]=5;v[3]=1;
    A[4]=9;i[4]=1;x[4]=1;
    A[5]=10;x[5]=1;
    A[6]=40;x[6]=1;l[6]=1;
    A[7]=50;l[7]=1;
    A[8]=90;x[8]=1;c[8]=1;
    A[9]=100;c[9]=1;
    A[10]=400;c[10]=1;d[10]=1;
    A[11]=500;d[11]=1;
    A[12]=900;c[12]=1;m[12]=1;
    A[13]=1000;m[13]=1;
}
void add(int b,int num){
    ansi+=i[b]*num;
    ansv+=v[b]*num;
    ansx+=x[b]*num;
    ansl+=l[b]*num;
    ansc+=c[b]*num;
    ansd+=d[b]*num;
    ansm+=m[b]*num;
    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ofstream fout("preface.out");
    ifstream fin("preface.in");
    fin>>n;
    mem();
    for (int j=1;j<=n;j++){
        int temp=j,now=13;
        while (temp){
            while (temp<A[now]) now--;
            add(now,temp/A[now]);
            temp%=A[now];
        }
    }
    if (ansi) fout<<"I "<<ansi<<"\n";
    if (ansv) fout<<"V "<<ansv<<"\n";
    if (ansx) fout<<"X "<<ansx<<"\n";
    if (ansl) fout<<"L "<<ansl<<"\n";
    if (ansc) fout<<"C "<<ansc<<"\n";
    if (ansd) fout<<"D "<<ansd<<"\n";
    if (ansm) fout<<"M "<<ansm<<"\n";
    return 0;
}