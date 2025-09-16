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
    string s, t;
    cin >> s >> t;

    if (s == t) {
        cout << 0 << endl;
        return ;
    }

    int i;

    for (i = 0 ; i < (int)min(s.size() , t.size()) ; i ++) {
        if (s[i] != t[i]) {
            break;
        }
    }

    cout << i + 1 << endl;
}

int main()
{
    IOS;

    int t = 1;

    while (t--)
    {
        solve();
    }

    return 0;
}