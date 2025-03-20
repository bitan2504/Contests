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
    ll n, m, L; cin >> n >> m >> L;
    pii h[n];
    rep(i, 0, n) {
        cin >> h[i].ff >> h[i].ss;
    }

    int i = 0, p = 0;
    ll sum = 0, cnt = 0, flag = 1;
    priority_queue<ll> q;
    while (p < m && i < n && flag) {
        ll x, v; cin >> x >> v;
        while (flag && i < n && x > h[i].ff) {
            ll req = h[i].ss - h[i].ff + 1;
            while (q.size() && sum < req) {
                sum += q.top(); q.pop(); cnt++;
                // cerr << i << " " << cnt << " " << sum << endl;
            }
            if (sum < req) flag = 0;
            i++;
        }
        q.push(v);
        p++;
    }
    while (p < m) {
        ll x, v; cin >> x >> v;
        p++;
    }
    while (flag && i < n) {
        ll req = h[i].ss - h[i].ff + 1;
        while (q.size() && sum < req) {
            sum += q.top(); q.pop(); cnt++;
        }
        if (sum < req) flag = 0;
        i++;
    }
    cout << (flag ? cnt : -1) << endl;
}

int main() {
    bitandas
    int t = 1;
    cin >> t; // For multiple test cases
    while (t--) solve();
    return 0;
}