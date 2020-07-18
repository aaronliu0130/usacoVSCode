/*
ID: aaronli2
TASK: holstein
LANG: C++11

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <functional>
using namespace std;
int popCount(int n){//https://stackoverflow.com/questions/14682641/count-number-of-1s-in-binary-format-of-decimal-number 32 should be enough.
    bitset<32> b(n);
    return b.count();
}
bool comp(vector<int> now,vector<int> cow,int v){
    for(int i=0;i<v;i++)if(now[i]<cow[i])return false;
    return true;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ofstream fout ("holstein.out");
    ifstream fin ("holstein.in");
    ofstream debug ("debug.out");#define debug/**
    int v,g,t;
    fin>>v;
    vector<int> cow,now;
    for(int i=0;i<v;i++){
        fin>>t;
        cow.push_back(t);
    }
    //debug<<"UH-OH"<<endl;
    fin>>g;
    vector<vector<int>> vita;
    for(int i=0;i<g;i++){
        vita.push_back({});
        for(int j=0;j<v;j++){
            fin>>t;
            vita[i].push_back(t);
        }
    }
    vector<int> id(30,0),ans(30,0);
    int min(INT32_MAX);
    //debug<<"MAYBE"<<endl;
    function<void(int,int)> dfs=[&id,&now,&cow,&v,&g,&min,&ans,&vita,&dfs,&debug](int s,int n) -> void {
        id[s-1]=n;
        if(comp(now,cow,v)&&s<min){
            min=s;
            debug<<"WOW "<<s<<" "<<n;
            for(int i=0;i<min;i++){
                ans[i]=id[i];
                debug<<" "<<ans[i]<<" "<<id[i];
            }
            debug<<endl;
        }for(int i=n+1;i<g;i++){
            for(int j=0;j<v;j++)now[j]+=vita[i][j];
            dfs(s+1,i);
            for(int j=0;j<v;j++)now[j]-=vita[i][j];
        }
    };
    for(int i=0;i<g;i++){
        for(int j=0;j<v;j++)now.push_back(vita[i][j]);
        //debug<<"GOTIT "<<i<<endl;
        dfs(1,i);
        for(int j=0;j<v;j++)now[j]-=vita[i][j];
        //debug<<"DONIT "<<i<<endl;
    }
    fout<<min;
    for(int i=0;i<min;i++)fout<<" "<<ans[i]+1;
    fout<<endl;
    return 0;
}*//*
ID: aaronli2
TASK: holstein
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>
#include <bitset>
#include <functional>
#include <vector>
using namespace std;
int popCount(int n){//https://stackoverflow.com/questions/14682641/count-number-of-1s-in-binary-format-of-decimal-number 32 should be enough.
    bitset<32> b(n);
    return b.count();
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ofstream fout ("holstein.out");
    ifstream fin ("holstein.in");
    int v,g;//Thought of first three letters of "amount", "amo", so "ammo" just for fun
    vector<int> req(30);
    vector<vector<int>> ammo(20,{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0});
    fin>>v;
    for(int i=0;i<v;i++)fin>>req[i];
    fin>>g;
    for(int i=0;i<g;i++)
        for(int j=0;j<v;j++)
            fin>>ammo[i][j];
    int min=INT32_MAX;
    function<void(int,int)> dfs=[&v,&req,&dfs,&min,&g,&ammo](int n,int step)->void{
        bool flag(1);
        for(int i=0;i<v;i++)
            if(req[i]>0)
                flag=0;
        if(flag){
            if(popCount(step)<popCount(min))min=step;
            else if(popCount(step)==popCount(min))
                if(step<min)min=step;
            return;
        }if(n<g){
            dfs(n+1,step);
            for(int i=0;i<v;i++)req[i]-=ammo[n][i];
            dfs(n+1,step^(2^n));
            for(int i=0;i<v;i++)req[i]+=ammo[n][i];
        }
    };
    dfs(0,0);
    fout<<popCount(min);
    for(int i=0;i<g;i++)
        if(min&(2^i))fout<<" "<<i+1;
    fout<<endl;
    return 0;
}