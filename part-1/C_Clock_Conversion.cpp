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
    string t;
    cin >> t;

    int hour = (t[0] - '0') * 10 + t[1] - '0';
    int minute = (t[3] - '0') * 10 + t[4] - '0';
    bool PM = (hour >= 12);
    if (hour > 12)
        hour -= 12;
    else if (hour == 0)
        hour += 12;

    cout << ((hour < 10)? "0" : "") << hour << ":" << ((minute < 10)? "0" : "") << minute << ((!PM)? " AM" : " PM") << endl;
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