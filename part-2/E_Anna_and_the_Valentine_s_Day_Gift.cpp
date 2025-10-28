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
    int n , m;
    cin >> n >> m;

    vector <string> s(n);
    vector <int> a;
    int d = 0;
    for (auto &x : s)
    {
        cin >> x;
        int cnt = 0;
        d += x.size();
        for (int i = x.size() - 1 ; i >= 0 ; i --)
        {
            if (x[i] != '0')
                break;
            cnt ++;
        }

        a.pb(cnt);
    }


    sort(allr(a));

    for (int i = 0 ; i < a.size() ; i += 2)
    {
        d -= a[i];
    }

    if (m < d)
        cout << "Sasha" << endl;
    else 
        cout << "Anna" << endl;
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