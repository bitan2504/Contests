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

auto min_kadane = [](vector<int> a) -> int {
    int n = a.size();
    int sum = 0, mini = 0;
    for (int r = 0; r < n; r++) {
        sum += a[r];
        if (sum > 0) {
            sum = 0;
        }
        mini = min(mini, sum);
    }
    return mini;
};

auto max_kadane = [](vector<int> a) -> int {
    int n = a.size();
    int sum = 0, maxi = 0;
    for (int r = 0; r < n; r++) {
        sum += a[r];
        if (sum < 0) {
            sum = 0;
        }
        maxi = max(maxi, sum);
    }
    return maxi;
};

// Main solve function
void solve() {
    ll n; cin >> n;
    vector<int> a(n);
    int v = -1;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (abs(a[i]) != 1) v = i;
    }

    set<int> st;
    
    if (v != -1) {
        int mini = min_kadane(vector (a.begin(), a.begin() + v));
        int maxi = max_kadane(vector (a.begin(), a.begin() + v));
        for (int i = mini; i <= maxi; i++) {
            st.insert(i);
        }
    }
    int mini = min_kadane(vector (a.begin() + v + 1, a.end()));
    int maxi = max_kadane(vector (a.begin() + v + 1, a.end()));
    for (int i = mini; i <= maxi; i++) {
        st.insert(i);
    }

    int amini = 0, amaxi = 0;
    int bmini = 0, bmaxi = 0;
    int sum = 0;
    for (int i = v - 1; i >= 0; i--) {
        sum += a[i];
        amini = min(amini, sum);
        amaxi = max(amaxi, sum);
    }
    sum = 0;
    for (int i = v + 1; i < n; i++) {
        sum += a[i];
        bmini = min(bmini, sum);
        bmaxi = max(bmaxi, sum);
    }
    if (v != -1) {
        for (int i = amini + bmini; i <= amaxi + bmaxi; i++) {
            st.insert(i + a[v]);
        }
    }

    cout << st.size() << endl;
    for (auto i: st) cout << i << " ";
    cout << endl;
}

int main() {
    bitandas
    int t = 1;
    cin >> t; // For multiple test cases
    while (t--) solve();
    return 0;
}