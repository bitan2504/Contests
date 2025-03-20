/**
 * code by bitandas
 */
#include <bits/stdc++.h>
using namespace std;
#define bitandas ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long

// Main solve function
void solve() {
    int n, k; cin >> n >> k;
    int a, b;
    a = 1, b = 2 * k + 1;
    if (b <= n) {
        cout << a << " " << b << endl;
        return ;
    }
    a = 2, b = k + 2;
    if (b % 2 == 0) b++;
    if (b > n) {
        cout << "-1 -1" << endl;
        return ;
    }
    cout << a << " " << b << endl;
}

int main() {
    bitandas
    int t = 1;
    cin >> t; // For multiple test cases
    while (t--) solve();
    return 0;
}