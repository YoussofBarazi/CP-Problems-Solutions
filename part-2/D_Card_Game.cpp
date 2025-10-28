#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vl vector<ll>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pb push_back
#define F first
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
using namespace std;

const int N = 200009;

void solve()
{
    int n; char t;
    cin >> n >> t;

    map <char , vector <string>> m;

    for (int i = 0 ; i < n * 2 ; i ++)
    {
        string s;
        cin >> s;

        m[s[1]].pb(s);
    }

    int cnt = 0;

    for (auto &x : m)
    {
        if (x.F != t)
            cnt += x.second.size() % 2;

        sort(all(x.second));
    }


    if (cnt > m[t].size() || (m[t].size() - cnt) % 2)
    {
        cout << "IMPOSSIBLE" << endl;
        return ;
    }

    for (auto x : m)
    {
        if (t != x.F)
        {
            for (int i = 1 ; i < x.second.size() ; i += 2)
            {
                cout << x.second[i - 1] << " " << x.second[i] << endl;
            }
        }
    }

    for (auto x : m)
    {
        if (t != x.F && x.second.size() % 2)
        {
            cout << x.second.back() << " " << m[t].back() << endl;
            m[t].pop_back();
        }
    }

    for (int i = 1 ; i < m[t].size() ; i += 2)
    {
        cout << m[t][i - 1] << " " << m[t][i] << endl;
    }
}

int main()
{
    // IO("name");
    IOS;

    int t = 1;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}

void IO(string name = "") {

	cin.tie(0)->sync_with_stdio(0);
	if (name.size()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}

}