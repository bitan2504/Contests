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
    ll n, k; cin >> n >> k;
    string s; cin >> s;
    int zer = 0, one = 0;
    stack<pair<int, int>> st;
    s[0] == '0' ? zer++ : one++;
    for (int i = 1; i < n; i++) {
        if (s[i] == '0') {
            if (!zer)
                st.push({one, 1}), one = 0;
            zer++;
        } else {
            if (!one)
                st.push({zer, 0}), zer = 0;
            one++;
        }
    }
    if (!one)
        st.push({zer, 0});
    else 
        st.push({one, 1});

    // while (st.size()) {
    //     cerr << st.top().first << " " << st.top().second << endl; st.pop();
    // }
    // cerr << endl;

    ll sum = 0;
    one = zer = 0;
    while (st.size() && sum < k) {
        auto it = st.top(); st.pop();
        int cnt = it.first, ch = it.second;
        if (ch == 1) {
            int val = cnt + one - zer;
            one += cnt;
            while (val > 0 && sum < k && cnt) {
                sum += val; cnt--;
            }
        } else {

        }
    }

    cout << (sum < k ? -1 : sum) << endl;
}

int main() {
    bitandas
    int t = 1;
    cin >> t; // For multiple test cases
    while (t--) solve();
    return 0;
}