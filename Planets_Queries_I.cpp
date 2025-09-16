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

const int N = 200009 , LOG = 31;

int jump[N][LOG];

void solve()
{
    int n , q;
    cin >> n >> q;

    vector <int> to (n + 1);

    for (int i = 1 ; i <= n ; i ++) {
        cin >> to[i];
        jump[i][0] = to[i];
    } 

    for (int j = 1 ; j < LOG ; j ++) {
        for (int i = 1 ; i <= n ; i ++) {
            jump[i][j] = jump[jump[i][j - 1]][j - 1];
        } 
    }

    while (q --) {
        int x , k;
        cin >> x >> k;

        for (int i = 0 ; i < LOG ; i ++) {
            if (k & (1 << i)) {
                x = jump[x][i];
            }
        }

        cout << x << endl;
    }
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