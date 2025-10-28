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

int dx[] = {-1 , 0 , 1 , 0};
int dy[] = {0 , 1 , 0 , -1};

const int N = 200009;

vector <ll> x(N , 0) , y(N , 0);

void solve()
{
    ll n;
    cin >> n;

    ll ans = 1 + x[n] * n + y[n];

    cout << ans << endl;
}

int main()
{
    // IO("name");
    IOS;

    vector <bool> add(N , true);

    for (int i = 2 ; i <= 1e5 ; i ++)
    {   
        if (add[i])
        {
            x[i] ++;
        }
        else 
        {
            y[i] ++;
        }

        ll t = i;
        if (t * t < N)
        {
            add[t * t] = false;
        }

        x[i] += x[i - 1];
        y[i] += y[i - 1];
    }

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