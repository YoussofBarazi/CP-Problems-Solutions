#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vl vector<ll>
#define pi pair<int, int>
#define pl pair<ll, ll>
#define pb push_back
#define F first
#define S second
#define all(v) v.begin(), v.end()
#define allrev(v) v.rbegin(), v.rend()
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
using namespace std;

const int N = 200009;

bool cmp(pair<int, int> a, pair<int, int> b)
{
    if (a.F != b.F)
        return a.F < b.F;

    return a.S > b.S;
}

void solve()
{
    int n;
    cin >> n;

    vector<string> s(n);
    for (int i = 0; i < n; i++)
        cin >> s[i];

    vector<pair<int, int>> st;
    for (int i = 0; i < n; i++)
    {
        int cnt = 0;
        for (int j = 0; j < n; j++)
        {
            cnt += s[i][j] == 'o';
        }

        st.push_back({cnt, i + 1});
    }

    sort(all(st), cmp);

    for (int i = n - 1; i >= 0; i--)
        cout << st[i].S << " ";
    cout << endl;
}

int main()
{
    IOS;

    int t = 1;

    while (t--)
    {
        solve();
    }

    return 0;
}