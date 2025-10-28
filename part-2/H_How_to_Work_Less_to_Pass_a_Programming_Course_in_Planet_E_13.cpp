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
int n, g, min_size, sum;

vector<int> p;
vector<int> tmp;
set<pair<pair<int, vector<int>>, int>> ans;

void combine(int i, int gained, vector<int> cmp, ll x)
{
    int grade = double(gained) / double(sum) * 100;

    if (cmp.size() == min_size && grade >= g)
    {
        ans.insert({{x, cmp}, grade});
        return;
    }

    if (i == n)
        return;

    combine(i + 1, gained, cmp, x);
    cmp.pb(i + 1);
    x += 1 << (i);
    combine(i + 1, gained + p[i], cmp, x);
}

void solve()
{
    cin >> n >> g;
    p.resize(n);
    tmp.resize(n);

    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
        tmp[i] = p[i];
        sum += p[i];
    }
    sort(allrev(tmp));

    int gained = 0;
    for (int i = 0; i < n; i++)
    {
        gained += tmp[i];

        int grade = double(gained) / double(sum) * 100;
        if (grade >= g)
        {
            min_size = i + 1;
            break;
        }
    }

    combine(0, 0, {}, 0);

    cout << min_size << " " << ans.size() << endl;
    for (auto x : ans)
    {
        cout << x.S << " ";
        for (int i = 0; i < x.F.S.size(); i++)
        {
            cout << x.F.S[i];
            if (i == x.F.S.size() - 1)
                cout << endl;
            else
                cout << " ";
        }
    }
}

int main()
{
    IOS;

    int t = 1;
    // cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}