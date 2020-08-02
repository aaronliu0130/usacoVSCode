/*
ID: jerron1
TASK: transform
LANG: C++11                 
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class Square
{
	size_t sz;
	vector<string> sq;

public:
	Square(size_t size) : sz(size), sq(size) {}
	istream &read(istream &is)
	{
		for (auto i = sz - sz; i < sz; ++i)
			is >> sq[i];
		return is;
	}
	size_t size() const
	{
		return sz;
	}
	static vector<string> transform(size_t op, const vector<string> &sq)
	{
		auto sz = sq.size();
		vector<string> nsq(sz, string(sz, 0));
		auto proj = [&nsq, &op, &sz](int i, int j) -> decltype(nsq[0][0]) {
			switch (op)
			{
			case 1: //90
				return nsq[j][sz - 1 - i];
			case 2: //180
				return nsq[sz - 1 - i][sz - 1 - j];
			case 3: //270
				return nsq[sz - 1 - j][i];
			case 4: //reflection
				return nsq[i][sz - 1 - j];
			}
			return nsq[0][0];
		};
		for (auto i = sz - sz; i < sz; ++i)
			for (auto j = sz - sz; j < sz; ++j)
				proj(i, j) = sq[i][j];
		return nsq;
	}
	bool equal(const Square &rhs) const
	{
		return rhs.equal(sq);
	}
	bool equal(const vector<string> &rhs) const
	{
		if (rhs.size() != sz)
			return false;
		for (auto i = sz - sz; i < sz; ++i)
			if (sq[i] != rhs[i])
				return false;
		return true;
	}
	int match(const Square &target);
};
inline bool operator==(const Square &lhs, const Square &rhs)
{
	return lhs.equal(rhs);
}
inline bool operator==(const Square &lhs, const vector<string> &rhs)
{
	return lhs.equal(rhs);
}
inline istream &operator>>(istream &is, Square &sq)
{
	return sq.read(is);
}
int Square::match(const Square &target)
{
	vector<string> tmp(sz);
	for (auto i = 1; i <= 4; ++i)
	{
		tmp = transform(i, sq);
		if (target == tmp)
			return i;
	}
	for (auto i = 1; i <= 3; ++i)
		if (target == transform(i, tmp))
			return 5;
	if (equal(target))
		return 6;
	return 7;
}

int main()
{
	ofstream fout("transform.out");
	ifstream fin("transform.in");
	int s;
	fin >> s;
	Square source(s), target(s);
	fin >> source >> target;
	fout << source.match(target) << endl;
	return 0;
}
