/*
 ID: aaronli2
 TASK: cowtour
 LANG: C++11
 */
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <functional>
#include <iomanip>
#include <array>
using namespace std;
typedef struct point {
    int x, y;
} point;
double operator-(const point b, const point a) {
    return sqrt(
        static_cast<double>(b.x - a.x) * (b.x - a.x)
        + static_cast<double>(b.y - a.y) * (b.y - a.y));
}
void mark(int &i, int &nf, array<int, 160> &f,
    array<array<double, 160>, 160> &dis, int &n) {
    if (f[i] != -1)
        return;
    f[i] = nf;
    for (int j(0); j < n; j++) {
        if (dis[i][j] < INT32_MAX / 2)
            mark(j, nf, f, dis, n);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ofstream fout("cowtour.out");
    ifstream fin("cowtour.in");
    int n;
    array<array<double, 160>, 160> dis;
    array<point, 160> p;
    fin >> n;
    for (int i(0); i < n; i++) {
        fin >> p[i].x >> p[i].y;
    }
    string temp;
    for (int i(0); i < n; i++) {
        fin >> temp;
        for (int j(0); j < n; j++) {

            if (i == j)
                dis[i][j] = 0;
            else if (temp[j] == '0')
                dis[i][j] = INT32_MAX;
            else
                dis[i][j] = p[j] - p[i];
        }
    }
    for (int k(0); k < n; k++) {
        for (int i(0); i < n; i++) {
            for (int j(0); j < n; j++) {
                if (dis[i][k] + dis[k][j] < dis[i][j])
                    dis[i][j] = dis[i][k] + dis[k][j];
            }
        }
    }
    int nf(0);
    array<int, 160> f;
    f.fill(-1);
    for (int i(0); i < n; i++) {
        if (f[i] == -1) {
            mark(i, nf, f, dis, n);
            nf++;
        }
    }
    double d[160] ={ 0 }, fd[160] ={ 0 }, ans;
    for (int i(0); i < n; i++) {
        for (int j(0); j < n; j++) {
            if (d[i] < dis[i][j] && dis[i][j] < INT32_MAX / 2)
                d[i] = dis[i][j];
        }
        if (d[i] > fd[f[i]])
            fd[f[i]] = d[i];
    }
    ans = INT32_MAX;
    double di;
    for (int i(0); i < n; i++) {
        for (int j(0); j < n; j++) {
            if (f[i] == f[j])
                continue;
            di = d[i] + d[j] + (p[j] - p[i]);
            if (di < fd[f[i]])
                di = fd[f[i]];
            if (di < fd[f[j]])
                di = fd[f[j]];
            if (di < ans)
                ans = di;
        }
    }
    fout << fixed << setprecision(6) << ans << '\n';
    return 0;
}
