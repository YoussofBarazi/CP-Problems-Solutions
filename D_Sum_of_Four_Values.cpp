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
    int n , x;
    cin >> n >> x;

    vector <int> a(n);
    for (int &x : a)
        cin >> x;
    
    map <int , vector<pair<int , int>>> m;

    for (int i = 0 ; i < n ; i ++)
    {
        for (int j = i + 1 ; j < n ; j ++)
        {
            m[a[i] + a[j]].push_back({i , j});
        }
    }

    for (int i = 0 ; i < n ; i ++)
    {
        for (int j = i + 1 ; j < n ; j ++)
        {
            if (m.count(x - a[i] - a[j]))
            {
                for (auto w : m[x - a[i] - a[j]])
                {
                    if (w.F != i && w.S != j && w.S != i && w.F != j)
                    {
                        cout << i + 1 << " " << j + 1 << " " << w.F + 1 << " " << w.S + 1 << endl;
                        return;
                    }
                }
            }
        }
    }

    cout << -1 << endl;
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