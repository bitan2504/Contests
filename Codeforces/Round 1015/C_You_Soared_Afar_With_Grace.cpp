/**
 * code by bitandas
 */
#include <bits/stdc++.h>
#define int long long
#define ll long long
#define uint unsigned long long
#define umap unordered_map
#define uset unordered_set
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
typedef priority_queue<int> max_heap;
typedef priority_queue<int, vint, greater<vint>> min_heap;

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
    fast_io();
    int tt = 1;
    cin >> tt; // For multiple test cases
    while (tt--) {
        // Main solve function
        int n;
        cin >> n;
        vector<pii> a(n);
        map<pii, int> mpp;
        int f = 2, ind = -1;
        for (int i = 0; i < n; i++)
            cin >> a[i].first;
        for (int i = 0; i < n; i++)
            cin >> a[i].second;
        for (int i = 0; i < n; i++) {
            mpp[a[i]] = i;
            if (a[i].first == a[i].second) {
                f--;
                ind = i;
            }
            if (!f)
                break;
        }
        if ((n % 2 && f != 1) || (n % 2 == 0 && f != 2)) {
            cout << "-1" << endl;
            continue;
        }

        for (auto &it : mpp) {
            pii a = it.first;
            pii b = {a.second, a.first};
            if (mpp.find(b) == mpp.end()) {
                cout << -1 << endl;
                f = 0;
                break;
            }
        }
        if (f <= 0)
            continue;

        vector<pii> ans;
        if (n % 2 && ind != n / 2) {
            ans.push_back({ind + 1, n / 2 + 1});
            swap(mpp[a[ind]], mpp[a[n / 2]]);
            swap(a[ind], a[n / 2]);
        }
        for (int i = 0; i < n / 2; i++) {
            pii x = a[i];
            pii y = {a[i].second, a[i].first};
            pii z = a[n - i - 1];
            int j = mpp[y];
            int k = n - i - 1;
            if (j == k)
                continue;
            ans.push_back({j + 1, k + 1});
            swap(mpp[y], mpp[z]);
            swap(a[j], a[k]);
        }

        cout << ans.size() << endl;
        for (auto it : ans) {
            cout << it.first << " " << it.second << endl;
        }
    }
    return 0;
}