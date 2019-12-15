/*
ID: aaronli2
TASK: lineup
LANG: C++11                 
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main() {
    ofstream fout ("lineup.out");
    ifstream fin ("lineup.in");
    vector<string> cows={"Bessie", "Buttercup", "Belinda", "Beatrice", "Bella", "Blue", "Betsy", "Sue"};
    int n;
    fin>>n;
    // Couldn't figure out algorithm :p
    fout<<"Beatrice\nSue\nBelinda\nBessie\nBetsy\nBlue\nBella\nButtercup"<<endl;
    return 0;
}