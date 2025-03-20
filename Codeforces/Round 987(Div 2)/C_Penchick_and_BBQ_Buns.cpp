#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<ll>;
#define bitandas ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define pb push_back
#define ff first
#define ss second
#define rep(i, a, b) for (ll i = a; i < b; ++i)
#define per(i, a, b) for (ll i = a; i >= b; --i)
template <typename T1, typename T2> void swap(T1 &a, T2 &b) { T1 temp = a; a = b; b = temp; }
template <typename T1, typename T2> auto max(T1 a, T2 b) -> decltype(a > b ? a : b) { return (a > b) ? a : b; }
template <typename T1, typename T2> auto min(T1 a, T2 b) -> decltype(a < b ? a : b) { return (a < b) ? a : b; }

// Main solve function
void solve() {
    ll n; cin >> n;
    vll ans(n + 1);
    if (n % 2 && n <= 26) {
        cout << -1 << endl;
        return ;
    }
    else {
        ll p = 2;
        if (n % 2) {
            ans[1] = ans[10] = ans[26] = 1;
            ans[23] = ans[27] = 2;
            p = 6;
        }
        for (ll i = 1; i <= n; i++) {
            if (ans[i]) continue;
            ans[i] = p/2;
            p++;
        }
    }
    for (ll i = 1; i <= n; i++) cout << ans[i] << " ";
    cout << endl;
}

int main() {
    bitandas
    int t = 1;
    cin >> t; // For multiple test cases
    while (t--) solve();
    return 0;
}