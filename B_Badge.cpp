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

    vector <int> p(n + 1);
    for (int i = 1 ; i <= n ; i ++)
    {
        cin >> p[i];
    }


    for (int i = 1 ; i <= n ; i ++)
    {
        int a = p[i] , b = p[p[i]];

        while (a != b)
        {
            a = p[a];
            b = p[p[b]];
        }

        a = i;

        while (a != b)
        {
            a = p[a];
            b = p[b];
        }

        cout << a << " " ;
    }
    cout << endl;
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