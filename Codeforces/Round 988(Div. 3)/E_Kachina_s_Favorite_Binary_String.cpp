#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<ll>;
#define bitandas ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define pb push_back
#define ff first
#define ss second
#define rep(i, a, b) for (ll i = a; i < b; ++i)
#define per(i, a, b) for (ll i = a; i >= b; --i)
template <typename T1, typename T2> void swap(T1 &a, T2 &b) { T1 temp = a; a = b; b = temp; }
template <typename T1, typename T2> auto max(T1 a, T2 b) -> decltype(a > b ? a : b) { return (a > b) ? a : b; }
template <typename T1, typename T2> auto min(T1 a, T2 b) -> decltype(a < b ? a : b) { return (a < b) ? a : b; }

int ask(int i, int j) {
    int x;
    cout << "? " << i + 1 << " " << j + 1 << endl << endl;
    cout.flush();
    cin >> x;
    return x;
}

void imp() {
    cout << "! IMPOSSIBLE\n\n";
    cout.flush();
}

// Main solve function
void solve() {
    int n; cin >> n;
    vector<char> s(n, '0');
    int last = ask(0, n - 1);
    if (!last) {
        imp(); return ;
    }

    int flag = 1, l = 0, r = n - 2;
    while (flag == 1 && r > l) {
        int x = ask(l, r);
        if (x == last) s[r + 1] = '0';
        else s[r + 1] = '1';
        if (x > 0) {
            last = x;
        } else {
            flag = 2;
            break;
        }
        r--;
    }
    if (flag == 1) s[r + 1] = '1';
    r++; l++;
    while (flag == 2 && l < r) {
        int x = ask(l, r);
        if (x > 0) {
            if (x == last) s[l - 1] = '1';
            else s[l - 1] = '0';
            last = x;
        } else {
            imp(); return ;
        }
        l++;
    }

    cout << "! ";
    for (auto i : s) cout << i ;
    cout << endl << endl;
    cout.flush();
}

int main() {
    bitandas
    int t = 1;
    cin >> t; // For multiple test cases
    while (t--) solve();
    return 0;
}