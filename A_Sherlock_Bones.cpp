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
    int n;
    cin >> n;

    string s;
    cin >> s;

    vector <int> pos1;

    for (int i = 0 ; i < n ; i ++)
    {
        if (s[i] == '1')
            pos1.push_back(i);
    }

    int cnt_odd = 0 , cnt1 = 0 , cnt_even = 0 , j = pos1.size() - 1;

    vector <ll> even(n , 0);
    vector <ll> odd(n , 0);

    for (int i = n - 1 ; i >= 0 ; i --)
    {
        cnt1 += s[i] == '1';

        if (cnt1 % 2)
        {
            cnt_odd += s[i] == '0';
        }
        else 
        {
            cnt_even += s[i] == '0';
        }

        if (s[i] == '1')
        {
            even[i] = cnt_even;
            odd[i] = cnt_odd;

            j --;
        }
    }

    /*for (int i = n - 2 ; i >= 0 ; i --)
    {
        even[i] += even[i + 1];
        odd[i] += odd[i + 1];
    }*/

    for (int i : pos1)
    {
        cout << odd[i] << " ";
    }
    cout << endl;

    int cnt0 = 0;
    cnt1 = 0 , j = 0;

    ll ans = 0;

    for (int i = 0 ; i < n ; i ++)
    {
        cnt1 += s[i] == '1';
        cnt0 += s[i] == '1';

        if (s[i] == '1')
        {
            if (cnt1 % 2)
            {
                ans += (cnt0) * odd[i];
            }
            else 
            {
                ans += (cnt0) * even[i];
            }

            cnt0 = 0;
        }
    }

    cout << ans << endl;
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