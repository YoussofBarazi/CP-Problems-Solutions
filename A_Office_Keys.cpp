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

const int N = 1009;

int n , k , p;
vector <int> a , b;
int mem[N][2 * N];

int dp(int i , int j)
{
    if (i == n)
        return 0;
    if (j == k)
        return 2e9;

    int &ret = mem[i][j];

    if (ret != -1)
        return ret;

    ret = min(dp(i , j + 1) , max(dp(i + 1 , j + 1) , abs(a[i] - b[j]) + abs(p - b[j])));

    return ret;
}

void solve()
{
    cin >> n >> k >> p;

    a.resize(n) , b.resize(k);
    
    for (auto &x : a)
        cin >> x;
    for (auto &x : b)
        cin >> x;

    for (int i = 0 ; i < n ; i ++)
        for (int j = 0 ; j < k ; j ++)
            mem[i][j] = -1;

    cout << dp(0 , 0) << endl;
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