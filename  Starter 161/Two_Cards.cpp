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
    pair<int, int> arr[n];
    rep(i, 0, n) cin >> arr[i].ff;
    rep(i, 0, n) cin >> arr[i].ss;
    sort(arr, arr + n, [](const pii &a, const pii &b) {
        if (a.ff == b.ff) return a.ss > b.ss;
        return a.ff > b.ff;
    });
    string ans = "No";
    for (int i = 1; i < n; i++) {
        if (max(arr[i].ff, arr[i].ss) > max(arr[0].ff, arr[0].ss)) {
            ans = "Yes"; break;
        }
    }
    if (max(arr[1].ff, arr[1].ss) < max(arr[0].ff, arr[0].ss)) {
        ans = "Yes"; 
    }
    cout << ans << endl;
}

int main() {
    bitandas
    int t = 1;
    cin >> t; // For multiple test cases
    while (t--) solve();
    return 0;
}