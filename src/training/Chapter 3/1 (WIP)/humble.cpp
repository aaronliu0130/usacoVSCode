/*
 ID: aaronli2
 TASK: humble
 LANG: C++11
 */
#include <algorithm>    // std::sort
#include <fstream>
#include <queue>
#include <vector>
using namespace std;
class node {
public:
	node(int prime) :next(1), prime(prime), pos(0) {}
	long long next;
	int prime;
	int pos;
	node* update(long long new_val){
		next=new_val*prime;
		++pos;
		return this;
	}
};
int main() {
	ofstream fout("humble.out");
	ifstream fin("humble.in");
	int k, n, p;
	fin >> k >> n;
	auto comp = [](const node *lth, const node *rth) {
		return lth->next > rth->next;
	};
	vector<node> nodes(k,0);
	priority_queue<node*, vector<node*>, decltype( comp )> q(comp);
	for (int i = 0; i < k; ++i) {
		fin >> p;
		nodes[i]=node(p);
		q.push(&nodes[i]);
	}
	node *nd;
	vector<long long> ans(n);
	for (int i = 0; i < n; ++i)
		for (ans[i] = q.top()->next; ans[i] == (nd = q.top())->next; q.pop())
			q.push(nd->update(ans[nd->pos]));
	fout << q.top()->next << '\n';
	return 0;
}
