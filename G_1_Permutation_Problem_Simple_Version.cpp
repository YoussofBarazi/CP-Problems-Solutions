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
    cin >> n;

    ll ans = 0;
    vector <int> a(n + 1 , 0) , b(n + 1 , 0) , cnt(n + 1 , 0);
    vector <vi> A(n + 1) , B(n + 1);

    for (int i = 1 ; i <= n ; i ++)
    {
        cin >> a[i];

        int g = gcd(a[i] , i);

        a[i] /= g;
        b[i] = i / g;

        A[a[i]].push_back(i);
        B[b[i]].push_back(i);

        ans -= (b[i] == 1);
    }

    vector <int> res(n + 1 , 0) , ready(n + 1 , 0);

    for (int i = 1 ; i <= n ; i ++)
    {
        if (B[i].size() == 0)
            continue;

        for (auto x : B[i])
            cnt[a[x]] ++;

        for (int j = i ; j <= n ; j += i)
        {
            for (auto y : A[j])
            {
                if (ready[b[y]] != i)
                {
                    res[b[y]] = 0;

                    for (int k = b[y] ; k <= n ; k += b[y])
                        res[b[y]] += cnt[k];

                    ready[b[y]] = i;
                }

                ans += res[b[y]];
            }
        }

        for (auto x : B[i])
            cnt[a[x]] --;
    }

    cout << ans / 2 << endl;
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