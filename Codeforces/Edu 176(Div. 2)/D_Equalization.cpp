/**
 * code by bitandas
 */
#pragma GCC optimize("O3,unroll-loops,Ofast")
#include <bits/stdc++.h>
using namespace std;
static const auto fast_io = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

/*************************************************************************************************/

#define MOD mod
#define ll long long
#define ull unsigned long long
#define mp(x, y) make_pair(x, y)
#define count_set_bits(x) __builtin_popcountll(x)
#define endl '\n'
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define all(x) (x).begin(), (x).end()
#define pii pair<int, int>
#define pll pair<ll, ll>
#define tiii tuple<int, int, int>
#define tlll tuple<ll, ll, ll>
#define pqueue priority_queue
#define INF 1000000000
#define LINF 1000000000000000000
#define IMAX INT_MAX
#define IMIN INT_MIN
#define LMAX LONG_LONG_MAX
#define LMIN LONG_LONG_MIN

/*************************************************************************************************/
// cutsom hash function
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = 0xDEADBEEFCAFEBABE;
        return splitmix64(x + FIXED_RANDOM);
    }
};

// find first set bit
inline int first_set_bit(unsigned x) { return x ? 31 - __builtin_clz(x) : -1; }
inline int first_set_bit(ull x) { return x ? 63 - __builtin_clzll(x) : -1; }

// max element
template <typename T1, typename T2> inline auto max_element(map<T1, T2> &a) {
    auto maxi = a.begin();
    for (auto &it : a) {
        if (it.ss > maxi->second)
            maxi = it;
    }
    return maxi;
}

template <typename T1, typename T2> inline auto max_element(unordered_map<T1, T2> &a) {
    auto maxi = a.begin();
    for (auto &it : a) {
        if (it.ss > maxi->second)
            maxi = it;
    }
    return maxi;
}

template <typename T1, typename T2>
auto lower_bound_sorted(vector<T1> &a, T2 target, int l, int r) {
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (a[m] < target)
            l = m + 1;
        else
            r = m - 1;
    }
    return l + a.begin();
}

template <typename T1, typename T2>
auto upper_bound_sorted(vector<T1> &a, T2 target, int l, int r) {
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (a[m] <= target)
            l = m + 1;
        else
            r = m - 1;
    }
    return l + a.begin();
}

template <typename T1, typename T2>
auto just_smaller_sorted(vector<T1> &a, T2 target, int l, int r) {
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (a[m] < target)
            l = m + 1;
        else
            r = m - 1;
    }
    return r + a.begin();
}

template <typename T1, typename T2>
auto smaller_equal_sorted(vector<T1> &a, T2 target, int l, int r) {
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (a[m] <= target)
            l = m + 1;
        else
            r = m - 1;
    }
    return r + a.begin();
}

vector<bool> sieve(ll n) {
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (ll i = 2; i * i <= n; i++) {
        if (is_prime[i]) {
            for (ll j = i * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }
    return is_prime;
}

bool is_prime(ll n) {
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    for (ll i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}

/*************************************************************************************************/
// debug
#ifdef LOCAL
// --- Trait to detect if T is a container (excluding std::string) ---
template <typename T, typename _ = void> struct is_container : false_type {};

template <typename T>
struct is_container<
    T, typename enable_if<
           !is_same<T, string>::value &&
           (is_same<decltype(begin(declval<T>())), typename T::iterator>::value ||
            is_same<decltype(begin(declval<T>())), typename T::const_iterator>::value)>::type>
    : true_type {};

// --- Overload for containers ---
template <typename T>
typename enable_if<is_container<T>::value, ostream &>::type operator<<(ostream &os,
                                                                       const T &container) {
    os << "{ ";
    for (const auto &elem : container)
        os << elem << " ";
    os << "}";
    return os;
}

// --- Overload for pair ---
template <typename A, typename B> ostream &operator<<(ostream &os, const pair<A, B> &p) {
    return os << "(" << p.first << ", " << p.second << ")";
}

// --- Recursive helper for printing tuples ---
template <class Tuple, size_t N> struct TuplePrinter {
    static void print(const Tuple &t, ostream &os) {
        TuplePrinter<Tuple, N - 1>::print(t, os);
        os << ", " << get<N - 1>(t);
    }
};

template <class Tuple> struct TuplePrinter<Tuple, 1> {
    static void print(const Tuple &t, ostream &os) { os << get<0>(t); }
};

template <typename... Args> ostream &operator<<(ostream &os, const tuple<Args...> &t) {
    os << "(";
    if constexpr (sizeof...(Args) > 0)
        TuplePrinter<tuple<Args...>, sizeof...(Args)>::print(t, os);
    os << ")";
    return os;
}

// --- Debug Macros ---
#define dbg(x) cerr << #x << " = " << (x) << "\n"
#define dbg2(x, y) cerr << #x << " = " << (x) << " | " << #y << " = " << (y) << "\n"
#define dbg3(x, y, z)                                                                              \
    cerr << #x << " = " << (x) << " | " << #y << " = " << (y) << " | " << #z << " = " << (z) << "\n"

#else
#define dbg(x)
#define dbg2(x, y)
#define dbg3(x, y, z)
#endif

/*************************************************************************************************/
const static int mod = 1000000007;
// const static int mod = 998244353;

int main() {
    int tt = 1;
    cin >> tt; // For multiple test cases
    vector<vector<ll>> prev(65, vector<ll>(65, LINF));
    vector<vector<ll>> curr(65, vector<ll>(65, LINF));
    prev[1][1] = 0;
    for (int kk = 1; kk <= 60; kk++) {
        for (int i = 1; i <= 60; i++) {
            for (int j = 1; j <= 60; j++) {
                curr[i][j] = prev[i][j];
                if (kk < i) {
                    curr[i][j] = min(curr[i][j], (1LL << kk) + prev[i - kk][j]);
                }
                if (kk < j) {
                    curr[i][j] = min(curr[i][j], (1LL << kk) + prev[i][j - kk]);
                }
            }
        }
        prev = curr;
    }
    while (tt--) {
        ll x, y;
        cin >> x >> y;
        int i, j;
        ll ans = LINF;
        for (i = 0; i < 63; i++) {
            for (j = 0; j < 63; j++) {
                if ((x >> i) == (y >> j)) {
                    ans = min(ans, curr[i + 1][j + 1]);
                    dbg2(i, j);
                }
            }
            if ((x >> i) == (y >> j))
                break;
        }
        cout << ans << endl;
    }
    return 0;
}