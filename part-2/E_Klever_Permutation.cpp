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

    int mx = n , mn = 1;

    vector <int> ans(n);
    vector <bool> used(n + 1 , false);

    for (int i = 0 ; i < k ; i ++)
    {
        for (int j = i ; j < n ; j += k)
        {
            if (i % 2)
            {
                if (!used[mn]) used[mn] = true , ans[j] = mn ++;
            }
            else 
            {
                if (!used[mx]) used[mx] = true , ans[j] = mx --;
            }
        }
    }

    for (auto x : ans)
        cout << x << " ";
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