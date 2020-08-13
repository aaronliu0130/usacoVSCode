#include<iostream>
using namespace std;
int k(0),f[10001];
int find(int k){
    if(f[k]==k)return k;
    return f[k]=find(f[k]);
}int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)f[i]=i;
    for(int i=1;i<=m;i++){
        int z,x,y;
        cin>>z>>x>>y;
        if(z==1)f[find(x)]=find(y);
        else if(find(x)==find(y))cout<<"Y\n";
        else cout<<"N\n";
    }
    return 0;
}