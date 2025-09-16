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

const int N = 20;

struct Point {
    int x , y;
    Point() {};
    Point(int xx , int yy) {
        x = xx , y = yy;
    }
};

long double dis(const Point& a , const Point& b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int n, s , t;
long double ans = 1e9;
Point a[N] , b[N];

void calc(vector<int>&ndx, Point prev, int i = 0, long double res = 0) {
    if (i == n) {
        ans = min(ans , res);
        return ;
    }

    calc(ndx, a[ndx[i]], i + 1, res + dis(a[ndx[i]], b[ndx[i]]) / t + dis(prev, b[ndx[i]]) / s);
    calc(ndx, b[ndx[i]], i + 1, res + dis(a[ndx[i]], b[ndx[i]]) / t + dis(prev, a[ndx[i]]) / s);
}

void solve()
{
    cin >> n >> s >> t;

    for (int i = 0 ; i < n ; i ++) {
        cin >> a[i].x >> a[i].y >> b[i].x >> b[i].y;
    }
    vector <int> ndx(n);
    for (int i = 0 ; i < n ; i ++) {
        ndx[i] = i;
    }


    do {

        calc(ndx, Point(0, 0));

    } while (next_permutation(all(ndx)));

    cout << fixed <<setprecision(20);
    cout << ans << endl;
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