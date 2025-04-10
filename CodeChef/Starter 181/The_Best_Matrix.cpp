/**
 * code by bitandas
 */
#include <bits/stdc++.h>
#define int long long
#define ll long long
#define uint unsigned long long
#define umap unordered_map
#define uset unordered_set
#define heap priority_queue
#define all(x) (x).begin(), (x).end()
#define sz(x) (long long)(x).size()
#define INF (long long)1e9
#ifdef LOCAL
#include "debug.hpp"
#else
#define debug(...)
#endif

using namespace std;
typedef vector<int> vint;
typedef vector<vint> vvint;
typedef vector<bool> vbool;
typedef vector<string> vstr;
typedef pair<int, int> pii;

template <typename T> inline void read(vector<T> &a, int i, int n) {
    while (i < n)
        cin >> a[i++];
}

void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int32_t main() {
    vvint d = {{1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
    fast_io();
    int tt = 1;
    cin >> tt; // For multiple test cases
    while (tt--) {
        // Main solve function
        int n, m;
        cin >> n >> m;
        vvint mat(n, vint(m));
        for (int i = 0; i < n; i++)
            read(mat[i], 0, m);

        int ans = 0;
        for (auto dd : d) {
            auto a = mat;
            int di = dd[0];
            int dj = dd[1];

            int cnt = 0;
            map<int, int> mpp;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    mpp[mat[i][j] - i * di - j * dj]++;
                    cnt = max(cnt, mpp[mat[i][j] - i * di - j * dj]);
                }
            }
            ans = max(ans, cnt);
        }
        // cerr << endl;
        cout << n * m - ans << endl;
    }
    return 0;
}