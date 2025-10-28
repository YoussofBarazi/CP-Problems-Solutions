#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vl vector<ll>
#define pi pair<int, int>
#define pl pair<ll, ll>
#define pb push_back
#define m first
#define t second
#define all(v) v.begin(), v.end()
#define allrev(v) v.rbegin(), v.rend()
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
using namespace std;

const int N = 200009;

int n, m, d, s;

int personDrink[1001], milkDrink[1001], timeDrink[1001];

int personSick[51], timeSick[51];

bool drankBefore(int person, int milkType, int time)
{
    for (int i = 1; i <= d; i++)
        if (personDrink[i] == person && milkDrink[i] == milkType && timeDrink[i] < time)
            return true;

    return false;
}

bool milkBad(int milkType)
{
    for (int i = 1; i <= s; i++)
        if (!drankBefore(personSick[i], milkType, timeSick[i]))
            return false;

    return true;
}

int countDrink(int milkType)
{
    vector<bool> didDrink(51);

    for (int i = 1; i <= d; i++)
    {
        if (milkDrink[i] == milkType)
            didDrink[personDrink[i]] = 1;
    }

    int cnt = 0;

    for (int i = 1; i <= 50; i++)
        cnt += didDrink[i];

    return cnt;
}

void solve()
{
    cin >> n >> m >> d >> s;

    for (int i = 1; i <= d; i++)
        cin >> personDrink[i] >> milkDrink[i] >> timeDrink[i];
    for (int i = 1; i <= m; i++)
        cin >> personSick[i] >> timeSick[i];

    int ans = 0;
    for (int i = 1; i <= m; i++)
        if (milkBad(i))
            ans = max(ans, countDrink(i));

    cout << ans << endl;
}

int main()
{
    IOS;

    int tt = 1;

    while (tt--)
    {
        solve();
    }

    return 0;
}