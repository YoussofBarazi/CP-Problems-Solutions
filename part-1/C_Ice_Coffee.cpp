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

const int N = 10000009;

int GPF[N];

void precalc()
{
    for(int i = 2 ; i < N ; i ++)
        if (!GPF[i])
            for (int j = i ; j < N ; j += i)
                GPF[j] = i;
}

vector <int> factorization(int x)
{
    vector <int> fact;

    while (x > 1)
    {
        fact.pb(GPF[x]);
        x /= GPF[x];
    }

    return fact;
}

void solve()
{
    int n;
    cin >> n;

    vector <int> a(n) , b(n);

    for (auto &x : a)
        cin >> x;

    for (auto &x : b)
        cin >> x;

    int ans = 0;

    for (int i = 0 ; i < n ; i ++)
    {
        vector <int> fact1 = factorization(a[i]),
                     fact2 = factorization(b[i]);

        // reverse(all(fact1));
        // reverse(all(fact2));

        while (a[i] != b[i])
        {
            if (a[i] > b[i])
                a[i] /= fact1.back() , fact1.pop_back();
            else 
                b[i] /= fact2.back() , fact2.pop_back();

            ans ++;
        }
    }

    cout << ans << endl;
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