/**
 * code by bitandas
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define bitandas                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);

// Main solve function
void solve()
{
    ll n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) a[i] = i;
    int p;
    for (p = 1; p < n; p++) {
        if (p % k != 0 && ((p + n - 1) % n) % k != (n - 1) % k) break;
    }

    if (p == n) {
        cout << -1<< endl;
    } else {
        for (int i = 0; i < n; i++) {
            cout << p + 1 << " ";
            p = (p + 1) % n;
        }
        cout << endl;
    }
}

int main()
{
    bitandas int t = 1;
    cin >> t; // For multiple test cases
    while (t--)
        solve();
    return 0;
}