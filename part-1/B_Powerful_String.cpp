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

void solve()
{
    int n;
    string s;
    cin >> n >> s;

    vector <vector<int>> freq(26 , vector <int> (n + 1 , 0)) , ndx(26) , _ndx(26);

    for (int i = 0 ; i < n ; i ++)
    {
        freq[s[i] - 'a'][i + 1] ++;
        ndx[s[i] - 'a'].push_back(i + 1);
        _ndx[s[i] - 'a'].push_back(- i - 1);
    }

    for (int i = 0 ; i < 26 ; i ++)
    {
        if (_ndx[i].size())
            sort(all(_ndx[i]));

        for (int j = 1 ; j <= n ; j ++)
        {
            freq[i][j] += freq[i][j - 1]; 
        }
    }
     
    int q;
    cin >> q;

    while (q --)
    {
        int l , r;
        cin >> l >> r;

        vector <array<int , 3>> chars;

        for (int c = 0 ; c < 26 ; c ++)
        {
            int f = freq[c][r] - freq[c][l - 1];
            
            if (f > 0)
            {
                auto last = lower_bound(all(_ndx[c]) , -r);

                auto first = lower_bound(all(ndx[c]) , l);

                chars.push_back({f , *first , -*last});
            }
        }

        if (chars.size() <= 1)
        {
            cout << "NO" << endl;
            continue;
        }

        sort(allr(chars));

        // for (auto x : chars)
        // {
        //     cout << x[0] << " " << x[1] << " " << x[2] << endl;
        // }

        bool ok = false;

        for (int i = 0 ; i < chars.size() ; i ++)
        {
            for (int j = i + 1 ; j < chars.size() ; j ++)
            {
                if (chars[i][1] < chars[j][2] && chars[i][0] > chars[j][0])
                {
                    cout << "YES" << endl;
                    ok = true;
                    break;
                }
            }
        }

        if (!ok)
        {
            cout << "NO" << endl;
        }
    }
}

int main()
{
    // IO("name");
    IOS;

    int t = 1;

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