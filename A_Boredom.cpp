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

const int N = 100009;

int n;
int freq[N];
vector <ll> mem(N , -1);

ll dp (int i)
{
    if (i > 1e5)
        return 0;

    if (mem[i] != -1)
        return mem[i];

    mem[i] = max(dp(i + 2) + 1ll * i * freq[i] , dp(i + 1));

    return mem[i];
}

void solve()
{
    cin >> n;

    for(int i = 0 ; i < n ; i ++)
    {
        int x;
        cin >> x;

        freq[x] ++;
    }

    cout << dp(1) << endl;
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