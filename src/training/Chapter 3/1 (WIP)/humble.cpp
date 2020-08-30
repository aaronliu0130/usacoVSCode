/*
ID: aaronli2
TASK: humble
LANG: C++11
*/
#include <algorithm>    // std::sort
#include <fstream>
#include <set>
#include <vector>
using namespace std;

int main() {
	ofstream fout("humble.out");
	ifstream fin("humble.in");
	int k, n;
	fin >> k >> n;
	vector<long long> primes(k);
	set<long long> q;
	for (int i=0; i < k; ++i){
		fin >> primes[i];
		q.insert(primes[i]);
	}
	sort(primes.begin(),primes.end());
	long long ans=0,cap=ans,next;
	for (int i=0; i < n; ++i) {
		ans=*q.begin();
		q.erase(q.begin());
		if(q.size()<=n-i){
			cap=max(cap,ans*primes[k-1]);
			for (int j=0;j<k;++j)
				q.insert(ans*primes[j]);
		}
		else
		for (int j=0;j<k;++j){
			next=ans*primes[j];
			if(next>cap)
				break;
			q.insert(next);
		}
	}
	fout << ans << '\n';
	return 0;
}
