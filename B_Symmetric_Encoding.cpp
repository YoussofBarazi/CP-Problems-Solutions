#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vl vector<ll>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pb push_back
#define F first
#define S second
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
    int n;
    cin >> n;

    string s;
    cin >> s;

    string r;
    set <char> dist;

    for (int i = 0 ; i < n ; i ++)
    {
        if (dist.count(s[i]))
            continue;
        
        dist.insert(s[i]);
        r.push_back(s[i]);
    }

    sort(all(r));

    for (int i = 0 ; i < n ; i ++)
    {
        int ndx = r.find(s[i]);

        cout << r[r.size() - ndx - 1];
    }
    cout << endl;
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