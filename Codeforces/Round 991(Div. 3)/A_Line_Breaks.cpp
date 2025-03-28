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
    ll n, m; cin >> n >> m;
    ll x = 0, sum = 0;
    int i;
    for (i = 0; i < n; i++) {
        string s; cin >> s;
        // cerr << s.size() << endl;
        if (sum + s.size() <= m) {
            x++;
            sum += s.size();
        } 
        else {
            i++;
            break;
        }
    }
    for ( ; i < n; i++) {
        string s; cin >> s;
    }
    cout << x << endl;
}

int main() {
    bitandas
    int t = 1;
    cin >> t; // For multiple test cases
    while (t--) solve();
    return 0;
}