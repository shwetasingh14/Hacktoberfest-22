#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
const int N = 1e5 + 10;

vector<vector<ll>> dp;

ll func(ll i, ll j, vector<ll> &a)
{
    if (i > j)
    {
        return 0;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    ll first, second;
    if (i + 2 <= j)
    {
        first = a[i] + min(func(i + 2, j, a), func(i + 1, j - 1, a));
    }
    else
    {
        first = a[i] + func(i + 1, j - 1, a);
    }
    if (j - 2 >= i)
    {
        second = a[j] + min(func(i + 1, j - 1, a), func(i, j - 2, a));
    }
    else
    {
        second = a[j] + func(i + 1, j - 1, a);
    }

    return dp[i][j] = max(first, second);
}

int main()
{
    std::ios::sync_with_stdio(false), cin.tie(__null), cout.tie(__null);

    ll n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    dp.resize(n, vector<ll>(n, -1));

    cout << func(0, n - 1, a);

    return 0;
}
