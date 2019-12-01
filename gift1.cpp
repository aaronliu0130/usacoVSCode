/*
ID: aaronli2
TASK: gift1
LANG: C++11                 
*/
#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

int main() {
    ofstream fout ("gift1.out");
    ifstream fin ("gift1.in");
    int NP;
    fin>>NP;
    string group[NP];
    for(int i=0;i<NP;i++)fin>>group[i];
    map<string,int> balance;
    string sender,recipent;int withdraw,NG;
    for(int i=0;i<NP;i++){
        fin>>sender>>withdraw>>NG;
        if(NG>0){
            balance[sender]-=withdraw-withdraw%NG;
            for(int j=0;j<NG;j++){
                fin>>recipent;
                balance[recipent]+=withdraw/NG;
            }
        }
    }
    for(int i=0;i<NP;i++)fout<<group[i]<<" "<<balance[group[i]]<<endl;
    return 0;
}