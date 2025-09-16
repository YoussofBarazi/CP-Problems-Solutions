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
    int n , q;
    scanf("%d%d" , &n , &q);

    vector <vector<int>> cnt(n + 1 , vector<int> (1024 , 0));

    for (int i = 1 ; i <= n ; i ++)
    {
        int x;
        scanf("%d" , &x);

        for (int j = 1 ; j < 1024 ; j ++)
        {
            cnt[i][j] = cnt[i - 1][j];
            bool divisble = false;

            for (int k = 0 ; k < 10 ; k ++)
                divisble |= ((j & (1 << k)) && x % (k + 1) == 0);

            cnt[i][j] += divisble;
        }
    }

    for (int i = 0 ; i < q ; i ++)
    {
        int s , l , r;
        scanf("%d%d%d" , &l , &r , &s);

        int ans = cnt[r][s] - cnt[l - 1][s];

        printf("%d\n" , ans);
    }
}

int main()
{
    // IO("name");
    IOS;

    int t = 1;
    scanf("%d" , &t);

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