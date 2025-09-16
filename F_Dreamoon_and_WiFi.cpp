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

int target;
string s , t;

long double O_O (int i , int cur)
{
    if (i == t.size())
        return cur == target;

    long double ans = 0;

    if (t[i] == '?')
        ans = O_O(i + 1 , cur + 1) / 2 + O_O(i + 1 , cur - 1) / 2;
    else 
        ans = O_O(i + 1 , cur + ((t[i] == '+')? 1 : - 1));

    return ans;
}

void solve()
{
    cin >> s >> t;

    for (int i = 0 ; i < s.size() ; i ++)
        target += s[i] == '+' , target -= s[i] == '-';

    cout << fixed << setprecision(12);
    cout << O_O(0 , 0) << endl;
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