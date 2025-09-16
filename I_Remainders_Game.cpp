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
    int n , k;
    cin >> n >> k;

    vector <int> div;
    vector <int> a(n);

    for (auto &x : a)
        cin >> x;

    for (int i = 2 ; i <= k ; i ++)
    {
        int num = 1;
        
        while (k % i == 0)
        {
            num *= i;
            k /= i;
        }

        if (num > 1)
            div.pb(num);
    }

    if (k > 1)
        div.pb(k);

    for (int d : div)
    {
        bool ok = false;
        for (int x : a)
        {
            if (x % d == 0)
            {
                ok = true;
                break;
            }
        }

        if (!ok)
        {
            cout << "No" << endl;
            return;
        }
    }

    cout << "Yes" << endl;
}

int main()
{
    // IO("name");
    IOS;

    int t = 1;
    //cin >> t;

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