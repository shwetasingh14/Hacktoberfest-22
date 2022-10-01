#include <bits/stdc++.h>

using namespace std;
#define ll long long

ll dp[5001][5001];

ll ans(string &s1, string &s2, ll x, ll y)
{
    if (dp[x][y] != -1)
    {
        return dp[x][y];
    }

    if (x == 0)
    {
        return dp[x][y] = y;
    }

    if (y == 0)
    {
        return dp[x][y] = x;
    }

    if (s1[x - 1] == s2[y - 1])
    {
        return dp[x][y] = ans(s1, s2, x - 1, y - 1);
    }
    else
    {
        return dp[x][y] = 1 + min({ans(s1, s2, x - 1, y - 1), ans(s1, s2, x - 1, y), ans(s1, s2, x, y - 1)});
    }
    return dp[x][y];
}


signed main()
{
    std::ios::sync_with_stdio(false), cin.tie(__null), cout.tie(__null);

    memset(dp, -1, sizeof(dp));

    string s1, s2;
    cin >> s1 >> s2;
    ll x = s1.size();
    ll y = s2.size();

    ll res = ans(s1, s2, x, y);
    cout << res << "\n";

    return 0;
}
