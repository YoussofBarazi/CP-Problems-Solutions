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

const int N = 1009;


void solve()
{
    int n;
    cin >> n;

    vector <int> a(n);
    vector <string> s(n);
    map <string , int> m;

    for (int i = 0 ; i < n ; i ++)
    {    
        cin >> a[i] >> s[i];
        sort(all(s[i]));
        
        if (m.count(s[i]))
            m[s[i]] = min(m[s[i]] , a[i]);
        else 
            m[s[i]] = a[i];
    }

    int ans = 1e9;

    if (m["A"] && m["B"] && m["C"])
        ans = m["A"] + m["B"] + m["C"];
    if (m["AB"] && m["C"])
        ans = min(ans , m["AB"] + m["C"]);
    if (m["AC"] && m["B"])
        ans = min(ans , m["AC"] + m["B"]);
    if (m["BC"] && m["A"])
        ans = min(ans , m["BC"] + m["A"]);
    if (m["AB"] && m["BC"])
        ans = min(ans , m["AB"] + m["BC"]);
    if (m["AB"] && m["AC"])
        ans = min(ans , m["AB"] + m["AC"]);
    if (m["AC"] && m["BC"])
        ans = min(ans , m["AC"] + m["BC"]);
    if (m["ABC"])
        ans = min(ans , m["ABC"]);

    if (ans == 1e9)
        ans = -1;
        
    cout << ans << endl;
}

int main()
{
    // IO("name");
    IOS;

    int t = 1;

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