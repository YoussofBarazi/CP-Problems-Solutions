#include <bits/stdc++.h>
#define vi vector<int>
#define ll long long
#define vl vector<ll>
#define pi pair<int, int>
#define pl pair<ll, ll>
#define oo INT_MAX
#define OO LONG_MAX
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

struct st
{
    int time, pos;
    char c1, c2;
};

void solve()
{
    string s[3];
    int t, q;
    cin >> s[1] >> s[2];
    cin >> t >> q;

    int cnt = 0;
    for (size_t i = 0; i < s[1].size(); i++)
    {
        if (s[1][i] == s[2][i])
            cnt++;
    }

    queue<st> blocked;
    for (int i = 0; i < q; i++)
    {
        int type;
        cin >> type;

        if (blocked.size() > 0 && blocked.front().time == i - t)
        {
            st x = blocked.front();

            if (x.c1 != x.c2)
                cnt--;

            blocked.pop();
        }

        if (type == 1)
        {
            int pos;
            cin >> pos;

            pos--;

            st x = {i, pos, s[1][pos], s[2][pos]};

            blocked.push(x);

            if (x.c1 != x.c2)
                cnt++;
        }
        else if (type == 2)
        {
            int n1, pos1, n2, pos2;
            cin >> n1 >> pos1 >> n2 >> pos2;

            pos1--, pos2--;

            bool ok1 = false, ok2 = false;
            if (s[1][pos1] == s[2][pos1])
                ok1 = true;
            if (s[1][pos2] == s[2][pos2])
                ok2 = true;

            swap(s[n1][pos1], s[n2][pos2]);

            if (s[1][pos1] == s[2][pos1] && !ok1)
                cnt++;
            if (s[2][pos2] == s[1][pos2] && !ok2)
                cnt++;
            if (s[1][pos1] != s[2][pos1] && ok1)
                cnt--;
            if (s[2][pos2] != s[1][pos2] && ok2)
                cnt--;
        }
        else if (cnt == (int)s[1].size())
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}

int main()
{
    IOS;

    int t = 1;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}