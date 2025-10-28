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

const int N = 1000009;

vector<ll> pre1(N), pre2(N), p1(N), p2(N);
ll base = 29;
 
pair<ll, ll> calc(string s)
{
    pre1[0] = pre2[0] = 0, p1[0] = p2[0] = 1;
 
    for (int i = 1; i < s.size(); i++)
    {
        p1[i] = p1[i - 1] * base;
        p2[i] = p2[i - 1] * base;
 
        pre1[i] = pre1[i - 1] * base + s[i] - 'a' + 1;
        pre2[i] = pre2[i - 1] * base + s[i] - 'a' + 1;
    }
 
    return {pre1[s.size() - 1], pre2[s.size() - 1]};
}
 
pair<ll, ll> get_ans(int l, int r)
{
    ll x = (pre1[r] - pre1[l - 1] * p1[r - l + 1]);
    ll y = (pre2[r] - pre2[l - 1] * p2[r - l + 1]);
 
    return {x, y};
}

void solve()
{
    string s;
    cin >> s;

    s = '#' + s;
    calc(s);

    int n = s.size() - 1;

    for (int i = 1 ; i <= n ; i ++)
    {
        bool ok = true;
        for (int j = i ; j <= n ; j += i)
        {
            if (get_ans(j - i + 1 , j) != get_ans(1 , i))
            {
                ok = false;
                break;
            }
        }

        if (ok)
        {
            if (n % i)
            {
                if (get_ans(1 , n % i) == get_ans(n - n % i + 1 , n))
                    cout << i << " ";
            }
            else 
            {
                cout << i << " ";
            }
        }
    }
    cout << endl;
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