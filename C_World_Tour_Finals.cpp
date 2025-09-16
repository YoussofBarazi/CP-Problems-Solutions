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

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<int> a(m);
    for (int &x : a)
        cin >> x;

    vector<string> s(n);
    for (auto &x : s)
        cin >> x;

    int max_score = 0;
    vector<int> scores(n);
    for (int i = 0; i < n; i++)
    {
        int score = 0;
        for (int j = 0; j < m; j++)
        {
            score += (s[i][j] == 'o') * a[j];
        }
        score += i + 1;
        scores[i] = score;
        max_score = max(score, max_score);
    }

    for (int i = 0; i < n; i++)
    {
        int cnt = 0;
        if (scores[i] == max_score)
        {
            cout << 0 << endl;
            continue;
        }

        while (scores[i] <= max_score)
        {
            int mx = 0, ind = 0;
            for (int j = 0; j < n; j++)
            {
                if (mx < a[j] && s[i][j] == 'x')
                    mx = a[j], ind = j;
            }
            cnt++;
            scores[i] += mx;
            s[i][ind] = 'o';
        }

        cout << cnt << endl;
    }
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