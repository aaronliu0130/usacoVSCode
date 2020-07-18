/*
ID: aaronli2
PROB: nocows
LANG: C++11
*/
#include<fstream>
using namespace std;
int main() {
	ifstream cin ("nocows.in");
	ofstream cout ("nocows.out");
    int n,h,dparr[201][110]={0};
	cin >> n >> h;
    for(int i(1); i <= h; i++)
    {
        dparr[1][i]=1;
    }for(int i(1); i <= h; i++)
    {
        for(int j(3); j <= n; j+=2)
        {
            for(int k(1); k < j; k+=2)
            {
                (dparr[j][i]+=dparr[k][i-1]*dparr[j-k-1][i-1])%=9901;
            }
        }
    }
    cout << (dparr[n][h]-dparr[n][h-1]+9901) % 9901 << endl;
    return 0;
}