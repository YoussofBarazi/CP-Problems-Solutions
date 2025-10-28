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
    int n , h;
    cin >> h >> n;

    priority_queue <pair<pll , int>> ready;
    vector <int> a(n);
    vector <int> c(n);
    for (int i = 0 ; i < n ; i ++)
    {
        cin >> a[i];
    }

    for (int i = 0 ; i < n ; i ++)
    {
        cin >> c[i];

        ready.push({{a[i] , c[i]} , i});
    }

    priority_queue<pair<pll , int>, vector<pair<pll , int>>, greater<pair<pll , int>>> cooled;

    ll turns = 1;
    while (h > 0)
    {
        while (cooled.size() && turns >= cooled.top().F.F)
        {
            pair<pll , int> t = cooled.top();
            ready.push({{t.F.S , t.F.F} , t.S});
            cooled.pop();
        }

        if (ready.size() == 0)
        {
            turns = cooled.top().F.F;
        }
        else 
        {
            pair<pll , int> t = ready.top();
            h -= t.F.F;

            if (h <= 0)
            {
                break;
            }

            cooled.push({{c[t.S] + turns , t.F.F} , t.S});
            ready.pop();
        }
    }

    cout << turns << endl;
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