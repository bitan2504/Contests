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

bool is_prime(ll n) {
    if (n <= 3)
        return n <= 1 ? false : true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    for (ll i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}

int32_t main() {
    fast_io();
    int tt = 1;
    cin >> tt; // For multiple test cases
    while (tt--) {
        // Main solve function
        int x, k; cin >> x >> k;
        if (x == 1) {
            cout << (k == 2 ? "YES" : "NO") << endl;
            continue;
        }
        if (k != 1) {
            cout << "NO" << endl;
            continue;
        }
        cout << (is_prime(x) ? "YES" : "NO") << endl;
    }
    return 0;
}