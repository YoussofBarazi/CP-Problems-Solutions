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

const int N = 5000009;

int GPF[N] , cnt[N];
void precalc()
{
    for (int i = 2 ; i < N ; i ++)
        if (!GPF[i])
            for (int j = i ; j < N ; j += i)
                GPF[j] = i;

    for (int i = 2 ; i < N ; i ++)
    {
        int t = i;

        while (t > 1)
        {
            cnt[i] ++;
            t /= GPF[t];
        }
    }

    for (int i = 2 ; i < N ; i ++)
        cnt[i] += cnt[i - 1];
}

void solve()
{
    int a , b;
    cin >> a >> b;

    cout << cnt[a] - cnt[b] << endl; 
}

int main()
{
    // IO("name");
    IOS;

    precalc();

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