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
    int n , m , k;
    cin >> n >> m >> k;

    vector <int> a(k + 1 , 0) , b(k + 1 , 0);
    set <int> x , y;
    
    for (int i = 0 ; i < n ; i ++)
    {
        int t;
        cin >> t;

        x.insert(t);
    }
    for (int i = 0 ; i < m ; i ++)
    {
        int t;
        cin >> t;

        y.insert(t);
    }

    for (int i = 1 ; i <= k ; i ++)
    {
        if (x.find(i) != x.end())
            a[i] ++;
        if (y.find(i) != y.end())
            b[i] ++;
    }

    int cnt1 = 0 , cnt2 = 0 , cnt3 = 0;

    for (int i = 1 ; i <= k ; i ++)
    {
        if (a[i] && b[i])
            cnt3 ++;
        else if (a[i])
            cnt1 ++;
        else if (b[i])
            cnt2 ++;
    }

    if (cnt1 + cnt2 + cnt3 == k && cnt1 <= k / 2 && cnt2 <= k / 2)
        cout << "YES" << endl;
    else 
        cout << "NO" << endl;

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