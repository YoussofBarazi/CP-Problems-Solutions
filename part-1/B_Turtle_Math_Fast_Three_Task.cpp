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

    vector <int> a(n);

    for (auto &x : a)
        cin >> x;

    map <int , int> freq;

    int sum = 0;
    for (int i : a)
    {
        if (i % 3)
            freq[i % 3] ++;

        sum += i;
    }

    if (sum % 3 == 0)
    {
        cout << 0 << endl;
    }
    else if (sum % 3 == 1)
    {
        if (freq[1])
            cout << 1 << endl;
        else 
        {
            cout << min(n , 2) << endl;
        }
    }
    else 
    {    
        cout << 1 << endl;
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