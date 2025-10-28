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

    map <int , priority_queue<int>> m;
    vector <int> a(n);

    for (int i = 0 ; i < n ; i ++)
    {
        cin >> a[i];

        m[a[i]].push(i);
    }

    for (int i = 0 ; i < n ; i ++)
    {
        int mn = a[i] , ndx = -1; 
        
        for (int j = 0 ; j < 4 ; j ++)
        {
            int x = a[i] ^ j;

            while (m[x].size() && m[x].top() <= i)
                m[x].pop();

            if (mn > x && m[x].size())
                mn = x , ndx = m[x].top();
        }

        if (ndx != -1)
        {
            m[a[i]].push(ndx);
            swap(a[i] , a[ndx]);
            m[mn].pop();
        }
    }


    for (auto x : a)
        cout << x << " ";
    cout << endl;
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