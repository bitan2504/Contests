/**
 * code by bitandas
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define bitandas ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

// Main solve function
void solve() {
    ll n; cin >> n;
    string s; cin >> s;
    vector<pair<int, int>> c;
    int a = 0, b = 0, cnt = 0;
    int s = 0, e = 0;
    for (auto c : s) {
        if (c == 'A') {
            if (!b) cnt++;
            else b--;
            a++;
        } else {
            if (!a) cnt++;
            else a--;
            b++;
        }
    }
    cout << cnt << endl;
}

int main() {
    bitandas
    int t = 1;
    cin >> t; // For multiple test cases
    while (t--) solve();
    return 0;
}