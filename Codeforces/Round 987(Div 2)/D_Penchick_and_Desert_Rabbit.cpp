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

ll arr[((int)5e5 + 5)]; 
class DisjointSet {
public:
	vector<long long> parents;

	DisjointSet(long long size) : parents(size) {
		for (long long i = 0; i < size; i++) { parents[i] = i; }
	}

	/** @return the "representativAe" node in x's component */
	long long find(long long x) { return parents[x] == x ? x : (parents[x] = find(parents[x])); }

	/** @return whether the merge changed connectivity */
	bool unite(long long x, long long y) {
		long long x_root = find(x);
		long long y_root = find(y);
		if (x_root == y_root) { return false; }
        if (arr[y_root] > arr[x_root]) swap(x_root, y_root);
		parents[y_root] = x_root;
		return true;
	}

	/** @return whether x and y are in the same connected component */
	bool connected(long long x, long long y) { return find(x) == find(y); }
};

// Main solve function
void solve() {
    ll n; cin >> n;
    rep(i, 0, n) cin >> arr[i];
    DisjointSet DSU = DisjointSet(n);
    stack<int> st;
    rep(i, 0, n) {
        int maxi = arr[i], mind = i;
        while (st.size() && arr[i] < arr[st.top()]) {
            int x = st.top(); st.pop();
            DSU.unite(i, x);
            if (arr[x] > maxi) maxi = arr[x], mind = x;
        }
        st.push(mind);
    }
    for (int i = 0; i < n; i++) {
        cout << arr[DSU.find(i)] << " ";
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