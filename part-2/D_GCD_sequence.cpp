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

bool check(int pos , vector <int> &a)
{
    vector <int> newA;

    for (int i = 0 ; i < a.size() ; i ++)
    {
        if (pos != i) newA.push_back(a[i]);
    }

    int lastpair = 0;

    for (int i = 0 ; i < newA.size() - 1 ; i ++)
    {
        if (lastpair > gcd(newA[i] , newA[i + 1]))
            return false;
        
        lastpair = gcd(newA[i] , newA[i + 1]);
    }

    return true;
}

void solve()
{
    int n;
    cin >> n;

    vector <int> a(n) , b;
    for (auto &x : a)
        cin >> x;

    for (int i = 0 ; i < n - 1 ; i ++)
    {
        b.push_back(gcd(a[i] , a[i + 1]));
    }

    int pos = -1;

    for (int i = 0 ; i < b.size() - 1 ; i ++)
    {
        if (b[i] > b[i + 1])
        {
            pos = i;
        }
    }

    if (pos == -1 || check(pos - 1 , a) || check(pos , a) || check(pos + 1 , a) || check(pos + 2 , a))
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