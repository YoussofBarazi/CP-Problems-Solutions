#include <bits/stdc++.h>

#define F first
#define S second
#define ll long long
#define pb push_back
#define vl vector<ll>
#define vi vector<int>
#define pll pair<ll, ll>
#define pii pair<int, int>
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



void solve()
{
    int n , m; 
    string s;
    
    cin >> n >> m >> s;

    vector <int> ind(m);
    string t;

    for (auto &x : ind)
        cin >> x;

    cin >> t;

    sort(all(t));
    sort(all(ind));

    m = unique(all(ind)) - ind.begin();

    for (int i = 0 ; i < m ; i ++)
    {
        s[ind[i] - 1] = t[i];
    }

    cout << s << endl;
}

int main()
{
    IOS;

    int t = 1;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}