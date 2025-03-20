/**
 * code by bitandas
 */
#include <bits/stdc++.h>
using namespace std;
#define bitandas ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long

// Main solve function
void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    if (n >= 100) {
        for (int i = 0; i < n; i++) cout << 0;
        cout << endl;
        return ;
    }

    for (int i = 0; i < n; i++) {
        vector<int> b;
        for (int j = 0; j < n; j++) {
            if (i != j) b.push_back(a[j]);
        }
        
        auto f = [&](auto&& self, vector<int> &a) -> bool {
            int n = a.size();
            if (n == 1) return true;
            vector<int> b;
            for (int i = 1; i < n; i++) {
                if (a[i] <= a[i - 1]) return false;
                b.push_back(a[i] - a[i - 1]);
            }
            return self(self, b);
        };
        if (f(f, b)) cout << 1;
        else cout << 0;
    }
    cout << endl;
}

int main() {
    bitandas
    int t = 1;
    cin >> t; // For multiple test cases
    while (t--) solve();
    return 0;
}