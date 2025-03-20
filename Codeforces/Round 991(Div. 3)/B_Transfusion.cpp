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

// Main solve function
void solve() {
    ll n; cin >> n;
    ll sum = 0;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
    }
    if (sum % n){
        cout << "NO" << endl;
        return ;
    }
    ll req = sum / n;
    for (int i = 0; i < n - 2; i++) {
        ll delta = arr[i] - req;
        arr[i] = req;
        arr[i + 2] += delta;
    }
    string ans = "NO";
    if (arr[n - 1] == req && arr[n - 2] == req) {
        ans = "YES";
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