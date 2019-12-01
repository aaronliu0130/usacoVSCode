/*
ID: aaronli2
TASK: transform
LANG: C++11                 
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
void reverse(int &s,vector<vector<char>> &map){
    for(int i=0;i<s;i++)
        for(int j=0;j<s%2?s/2+1:s/2;j++)
            swap(map[i][j],map[i][j-1-i]);
}
void rot(int &s,vector<vector<char>> &map){
    vector<vector<char>> bckup=map;
    for(int i=0;i<s;i++)
        for(int j=0;j<s;j++){
            map[i][j]=bckup[j][i];
        }
    reverse(s,map);
}

int main() {
    ofstream fout ("transform.out");
    ifstream fin ("transform.in");
    int s;
    fin>>s;
    vector<vector<char>> map(s), target(s);
    for(int i=0;i<s;i++)
        for(int j=0;j<s;j++)
    return 0;
}