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
    string s; cin >> s;
    map<char, int> mpp;
    for (auto c : s) mpp[c]++;
    char maxi = s[0], mini = s[0];
    vector<pair<ll, char>> arr;
    for (auto it : mpp) {
        // auto cnt = it.second;
        // if (mpp[maxi] < cnt) maxi = it.first;
        // if (mpp[mini] >= cnt) mini = it.first;
        arr.emplace_back(it.second, it.first);
    }
    sort(arr.begin(), arr.end());
    for (auto &c : s) {
        if (c == arr[0].second) {
            c = arr.back().second;
            break;
        }
    }
    cout << s << endl;
}

int main() {
    bitandas
    int t = 1;
    cin >> t; // For multiple test cases
    while (t--) solve();
    return 0;
}