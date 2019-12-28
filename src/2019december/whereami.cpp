#if 0
/*
ID: jerron
TASK: whereami
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cassert>				//assert

using namespace std;

int solve(const string & street){
	int k = 0;
	for (int i = 1; i < street.size(); ++i) {
		for (; k <= i; ++k)
			if (street.substr(0, i).find(street.substr(i - k + 1, k))
					== string::npos)
				break;
    }
	return k;
}

int test(){
	return 1;
	assert(solve("ABCDABC") == 4);
	assert(solve("A") == 0);
	assert(solve("AB") == 1);
	assert(solve("AA") == 2);
	assert(solve("ABB") == 2);
	assert(solve("ABBCC") == 2);
	assert(solve("") == 0);
    cout<<"ok";
    return 0;
}

int main() {
	if(test()){
    ofstream fout ("whereami.out");
    ifstream fin ("whereami.in");
    int n;
    fin>>n;
    string street;
    fin>>street;

    fout<<solve(street);
	}
    return 0;
}
#endif
