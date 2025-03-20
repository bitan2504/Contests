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
    ll k; cin >> k;
    map<int, int> mpp;
    rep(i, 0, k) {
        ll x; cin >> x;
        mpp[x]++;
    }
    k-=2;
    ll m, n;
    rep(i, 1, k + 1) {
        if (k%i == 0) {
            if (i * i == k) {
                if (mpp[i] >= 2) {
                    n = m = i; break;
                }
            } else {
                if (mpp[i] && mpp[static_cast<int>(k/i)]) {
                    n = i, m = k/i;
                    break;
                }
            }
        }
    }
    cout << n << " " << m << endl;
}

int main() {
    bitandas
    int t = 1;
    cin >> t; // For multiple test cases
    while (t--) solve();
    return 0;
}