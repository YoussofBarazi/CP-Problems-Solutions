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
    int n;
    string s;
    cin >> n >> s;

    int i = 0;
    while (i < s.size() && s[i] == '1')
        i ++;

    int c = i - 1;
    int r = s.size() / c;

    if (i == s.size() && sqrt(s.size()) == int(sqrt(s.size())) && s.size() < 9)
        cout << "Yes" << endl;
    else if (c == r)
        cout << "Yes" << endl;
    else 
        cout << "No" << endl;
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