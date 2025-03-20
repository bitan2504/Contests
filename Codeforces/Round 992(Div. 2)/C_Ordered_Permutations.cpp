/**
 * code by bitandas
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define bitandas ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
template <typename T1, typename T2> void swap(T1 &a, T2 &b) { T1 temp = a; a = b; b = temp; }
template <typename T1, typename T2> auto max(T1 a, T2 b) -> decltype(a > b ? a : b) { return (a > b) ? a : b; }
template <typename T1, typename T2> auto min(T1 a, T2 b) -> decltype(a < b ? a : b) { return (a < b) ? a : b; }

// Main solve function
void solve() {
    ll n, k; cin >> n >> k;
    k--;
    if (n < 50 && ((1LL << (n - 1))) <= k) {
        // cerr << n << endl;
        cout << - 1  << endl;
        return ;
    }
    
    vector<int> p(n);
    int l = 0, r = n - 1;
    for (int i = 1; i < n; i++) {
        if (n - 1 - i > 50 || k < (1LL << (n - 1 - i))) {
            p[l++] = i;
        } else {
            p[r--] = i;
            k -= (1LL << (n - 1 - i));
        }
        // for (auto i : p) cerr << i << " ";
        // cerr << endl;
    }
    p[l] = n;
    
    for (int i = 0; i < n; i++) {
        cout << p[i] << " ";
    }
    cout << endl;
}

int main() {
    bitandas
    int t = 1;
    cin >> t; // For multiple test cases
    while (t--) solve();
    return 0;
}