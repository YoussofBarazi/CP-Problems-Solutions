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

    string s , t;
    cin >> s;

    t = s;

    sort(all(t));

    deque <int> ndx;
    vector <bool> pushed(n , false);

    int x = 0;
    int ans = 0;
    bool notbiggest = false;

    for (char c = 'z' ; c >= 'a' ; c--)
    {
        int cnt = 0;
        
        for (int i = 0 ; i < n ; i ++)
        {
            if (c == s[i] && i >= x)
            {
                cnt ++;
                x = i;
                pushed[i] = true;
                ndx.pb(i);
            }
        }

        if (notbiggest)
            ans += cnt;
        if (cnt > 0)
            notbiggest = true;
    }

    for (int i = 0 ; i < n ; i ++)
    {
        if (s[i] == t[i] && !pushed[i])
            continue;
        
        if (ndx.size())
        {
            if (s[ndx.back()] == t[i])
            {
                ndx.pop_back();
            }
            else 
            {
                cout << -1 << endl;
                return;
            }
        }
        else
        {
            cout << -1 << endl;
            return;
        }
    }

    cout << ans << endl;
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