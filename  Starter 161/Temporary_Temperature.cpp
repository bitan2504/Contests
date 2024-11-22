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
    ll n, k; cin >> n >> k;
    ll arr[n]; rep(i, 0, n) cin >> arr[i];
    int l = 0, r = 1e9, m, ans;
    while (l <= r) {
        m = l + (r - l)/2;
        int mini = arr[0], maxi = arr[0], cnt = 0, temp = 0;
        bool f = 1;
        rep(i, 0, n) {
            mini = min(arr[i], mini);
            maxi = max(arr[i], maxi);
            if (maxi - mini > 2 * m) {
                cnt++;
                mini = maxi = arr[i];
                if (cnt > k) {
                    f = 0; break;
                }
            }
        }
        if (f) r = m - 1, ans = m;
        else l = m + 1;
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