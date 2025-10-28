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
    int n , m;
    cin >> n >> m;

    int total2 = 0 , total1 = 0;

    for (int i = 0 ; i < n ; i ++)
    {
        string s1 , s2;
        cin >> s1 >> s2;

        int t1 = (s1[0] - '0') * 10 + (s1[1] - '0');
        t1 *= 60;
        t1 += (s1[3] - '0') * 10 + (s1[4] - '0');

        int t2 = (s2[0] - '0') * 10 + (s2[1] - '0');
        t2 *= 60;
        t2 += (s2[3] - '0') * 10 + (s2[4] - '0');

        total1 += t1;
        total2 += t2; 
    }

    int minutes = total2 - total1;

    if ((minutes / 60) >= m)
    {
        cout << "YES" << endl;
    }   
    else 
    {
        cout << "NO" << endl;
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