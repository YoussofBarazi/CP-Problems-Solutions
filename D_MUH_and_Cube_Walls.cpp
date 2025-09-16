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
    int n , w;
    cin >> n >> w;

    vector <int> a(n) , b(w);
    for (auto &x : a)
        cin >> x;
    for (auto &x : b)
        cin >> x;

    if (w == 1)
    {
        cout << n << endl;
        return;
    }

    vector <int> x;

    for (int i = 0 ; i < w - 1 ; i ++)
    {
        x.push_back(b[i + 1] - b[i]);
    }
    x.push_back(INT_MAX);
    for (int i = 0 ; i < n - 1 ; i ++)
    {
        x.push_back(a[i + 1] - a[i]);
    }

    vector <int> kmp(x.size() , 0);
    kmp[0] = 0;

    int cnt = 0;

    for (int i = 1 ; i < x.size() ; i ++)
    {
        int j = kmp[i - 1];

        while (j > 0 && x[i] != x[j])
            j = kmp[j - 1];

        j += (x[i] == x[j]);
        cnt += j == (w - 1);

        if (j == (w - 1))
            j = kmp[j - 1];
            
        kmp[i] = j;
    }

    cout << cnt << endl;
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