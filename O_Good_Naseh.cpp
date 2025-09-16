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

int GPF[N];

void precalc()
{
    for (int i = 2 ; i < N ; i ++)
        if (!GPF[i])
            for (int j = i ; j < N ; j += i)
                GPF[j] = i;
}


vector <int> factorize(int n)
{
    vector <int> fact;

    while (n > 1)
    {
        int d = GPF[n];

        while (n % d == 0)
        {
            n /= d;
        }

        fact.push_back(d);
    }

    return fact;
}

void solve()
{
    precalc();

    int n;
    cin >> n;

    vector <int> a(n);
    vector <int> cnt(1e5 + 1 , 0);

    for (int i = 0 ; i < n ; i ++)
    {
        cin >> a[i];
        cnt[a[i]] = 1;
    }

    int ans = 0;
    
    vector <vector<int>> mult(1e5 + 1 , {0});

    for (int i : a)
    {
        vector <int> fact = factorize(i);
            
        int mx = 0;

        for (int d : fact)
        {
            int j = mult[d].back();    
            mx = max(mx , cnt[j]);

            mult[d].push_back(i);
        }

        cnt[i] += mx;

        ans = max(ans , cnt[i]);
    }

    cout << ans << endl;
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