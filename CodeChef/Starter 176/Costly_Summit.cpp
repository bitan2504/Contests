/**
 * code by bitandas
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define bitandas                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
template <typename T1, typename T2>
void swap(T1 &a, T2 &b)
{
    T1 temp = a;
    a = b;
    b = temp;
}
template <typename T1, typename T2>
auto max(T1 a, T2 b) -> decltype(a > b ? a : b) { return (a > b) ? a : b; }
template <typename T1, typename T2>
auto min(T1 a, T2 b) -> decltype(a < b ? a : b) { return (a < b) ? a : b; }

const int N = 13;
int n, c;
string s;
int a[N], dp[N][N][2][2][2][2][2];
bool ln[5];

int f(int i, int cnt)
{
    if (i == n)
        return 0;
    if (dp[i][cnt][ln[0]][ln[1]][ln[2]][ln[3]][ln[4]] != -1)
        return dp[i][cnt][ln[0]][ln[1]][ln[2]][ln[3]][ln[4]];
    int take = 0, nottake = 0;
    nottake = cnt + f(i + 1, cnt + 1);
    if (!ln[a[i]])
    {
        ln[a[i]] = 1;
        take = c + f(i + 1, cnt);
        ln[a[i]] = 0;
    }
    else
    {
        take = f(i + 1, cnt);
    }
    return dp[i][cnt][ln[0]][ln[1]][ln[2]][ln[3]][ln[4]] = min(take, nottake);
}

// Main solve function
void solve()
{
    cin >> n >> c >> s;
    for (int i = 0; i < n; i++)
        a[i] = s[i] - 'A';
    memset(ln, 0, sizeof(ln));
    memset(dp, -1, sizeof(dp));
    int ans = f(0, 1);
    cout << ans << endl;
}

int main()
{
    bitandas int t = 1;
    cin >> t; // For multiple test cases
    while (t--)
        solve();
    return 0;
}