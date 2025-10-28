#include <bits/stdc++.h>

#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
using namespace std;

const int N = 200009;

int T, P;
vector<int> E;
vector<int> D;
vector<int> S;
int mem[109][109][1 << 11];

int dp(int i, int energy, int mask)
{
    if (i == P)
        return 0;

    int &ans = mem[i][energy][mask];

    if (ans != -1)
        return ans;

    ans = dp(i + 1, energy, mask);

    if (energy >= D[i])
        ans = max(dp(i + 1, energy - D[i], mask) + S[i], ans);

    for (int j = 0; j < T; j++)
    {
        if (!(mask & (1 << j)))
            ans = max(dp(i, E[j], mask | (1 << j)), ans);
    }

    return ans;
}

void solve()
{
    cin >> T >> P;

    E.resize(T);
    D.resize(P);
    S.resize(P);

    for (auto &x : E)
        cin >> x;
    for (auto &x : D)
        cin >> x;
    for (auto &x : S)
        cin >> x;

    for (int i = 0; i < P; i++)
        for (int j = 0; j < 105; j++)
            for (int k = 0; k < (1 << T); k++)
                mem[i][j][k] = -1;

    cout << dp(0, 0, 0) << endl;
}

int main()
{
    IOS;

    int t = 1;
    /// cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}