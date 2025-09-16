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
    int n , q; string a , b;
    cin >> n >> q >> a >> b;

    vector <vi> freq1(26 , vector <int> (n + 1 , 0));
    vector <vi> freq2(26 , vector <int> (n + 1 , 0));

    for (int i = 0 ; i < n ; i ++)
    {
        freq1[a[i] - 'a'][i + 1] ++;
        freq2[b[i] - 'a'][i + 1] ++;
    }

    for (int c = 0 ; c < 26 ; c ++)
        for (int i = 1 ; i <= n ; i ++)
        {
            freq1[c][i] += freq1[c][i - 1];
            freq2[c][i] += freq2[c][i - 1];
        }
    while (q--)
    {
        int l , r;
        cin >> l >> r;

        int ans = 0;

        for (int i = 0 ; i < 26 ; i ++)
        {
            int cnt1 = freq1[i][r] - freq1[i][l - 1];
            int cnt2 = freq2[i][r] - freq2[i][l - 1];
            
            if (cnt1 < cnt2)
                ans += cnt2 - cnt1;
        }

        cout << ans << endl;
    }
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