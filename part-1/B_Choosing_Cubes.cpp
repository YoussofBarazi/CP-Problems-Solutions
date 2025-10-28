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

void solve()
{
    int n , f , k;
    cin >> n >> f >> k;

    vector <int> a(n);

    for (auto &x : a)
        cin >> x;

    int v = a[f - 1];

    sort(allr(a));

    a.push_back(0);

    if (a[k - 1] == v && a[k] == v)
    {
        cout << "MAYBE\n";
    }
    else if (a[k - 1] <= v)
    {
        cout << "YES\n";
    }
    else 
    {
        cout << "NO\n";
    }
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