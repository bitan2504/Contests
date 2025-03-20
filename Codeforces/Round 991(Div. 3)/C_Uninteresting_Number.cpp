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
    string s; cin >> s;
    ll sum = 0;
    vector<int> st;
    for (auto c : s) {
        sum += c - '0';
        sum %= 9;
        if (c == '2') st.push_back(2);
        if (c == '3') st.push_back(6);
    }
    sort(st.rbegin(), st.rend());
    ll req = (9 - sum) % 9;
    if (req & 1) req += 9;
    string ans = "NO";
    for (auto i : st) {
        if (!req) break;
        if (req - i >= 0) req -= i;
    }
    cout << (!req ? "YES" : "NO") << endl;
}

int main() {
    bitandas
    int t = 1;
    cin >> t; // For multiple test cases
    while (t--) solve();
    return 0;
}