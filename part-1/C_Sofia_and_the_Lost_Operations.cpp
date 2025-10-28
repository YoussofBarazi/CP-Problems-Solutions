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

int dx[] = {-1 , 0 , 1 , 0};
int dy[] = {0 , 1 , 0 , -1};

const int N = 200009;

bool cmp(pii &a , pii &b)
{
    if (a.F != b.F)
        return a.F < b.F;
    
    return a.S > b.S;
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

    multiset <int> d;
    map <int , vector<int>> ndx;
    int m , mx = -1;
    cin >> m;

    for (int i = 0 ; i < m ; i ++)
    {
        int x;
        cin >> x;

        d.insert(x);
        ndx[x].push_back(i);
    }

    for (int i = 0 ; i < n ; i ++)
    {
        if (a[i] != b[i])
        {
            if (d.find(b[i]) != d.end())
            {
                d.erase(d.find(b[i]));
                mx = max(ndx[b[i]].back() , mx);
                ndx[b[i]].pop_back();
            }
            else 
            {
                cout << "NO" << endl;
                return ;
            }
        }
    }

    for (int i = 0 ; i < n ; i ++)
    {
        if (a[i] == b[i])
        {
            if (d.find(b[i]) != d.end())
            {
                d.erase(d.find(b[i]));
                mx = max(mx , ndx[b[i]].back());
                ndx[b[i]].pop_back();
            }
        }
    }

    //cout << mx << endl;

    for (auto x : ndx)
    {
        for (auto y : x.S)
        {
            if (y > mx)
            {
                cout << "NO" << endl;
                return ;
            }
        }
    }

    cout << "YES" << endl;
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