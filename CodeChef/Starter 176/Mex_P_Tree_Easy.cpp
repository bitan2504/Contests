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

vector<bool> sieve(ll n) {
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (ll i = 2; i * i <= n; i++) {
        if (is_prime[i]) {
            for (ll j = i * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }
    return is_prime;
}

const int N = 1e3 + 9;
int n;
vector<int> a, mexp;
vector<vector<int>> adj;
vector<bool> vis;
set<int> primes;

int findmexp(int x) {
    for (auto i: primes) {
        if (x % i) return i;
    }
}

int f(int u, int x) {
    vis[u] = 1;
    x = min(x, mexp[u]);
    int sum = x;
    // cerr << u << " " << x << endl;
    for (auto v: adj[u]) {
        if (!vis[v]) {
            sum += f(v, x);
        }
    }
    return sum;
}

// Main solve function
void solve() {
    cin >> n;
    adj = vector<vector<int>> (n);
    a = vector<int> (n);
    mexp = vector<int> (n);
    vector<int> ans(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0, u, v; i < n - 1; i++) {
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 0; i < n; i++) {
        mexp[i] = findmexp(a[i]);
        // cerr << mexp[i] << " ";
    }
    // cerr << endl;

    for (int i = 0; i < n; i++) {
        vis = vector<bool> (n);
        int x = f(i, 1e9);
        // cerr << endl;
        // cerr << x << endl;
        ans[i] = x;
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}

int main() {
    bitandas
    vector<bool> is_prime = sieve(1e5);
    for (int i = 2; i < 1e5; i++) {
        if (is_prime[i]) primes.insert(i);
    }
    int t = 1;
    cin >> t; // For multiple test cases
    while (t--) solve();
    return 0;
}