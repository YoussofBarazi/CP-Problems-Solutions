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
    int n , k;
    cin >> k >> n;

    map <string , priority_queue <int>> f;
    vector <vector<int>> t;

    for (int i = 0 ; i < k ; i ++)
    {
        string s;
        int x;
        cin >> s >> x;

        f[s].push(x);
    }

    ll ans = 0;

    for (auto &x : f)
    {
        string rev = x.F;
        reverse(all(rev));

        if (rev == x.F)
        {
            vector <int> tmp;

            while (x.S.size())
                tmp.push_back(x.S.top()) , x.S.pop();

            t.push_back(tmp);

            continue;
        }        

        while (x.S.size() && f[rev].size() && x.S.top() + f[rev].top() > 0)
        {
            ans += x.S.top() + f[rev].top();
            x.S.pop(); 
            f[rev].pop();
        }
    }

    int possible_mid = 0;

    for (int i = 0 ; i < t.size() ; i ++)
    {
        for (int j = 0 ; j < t[i].size() ; j += 2)
        {
            if (j + 1 < t[i].size() && t[i][j] + t[i][j + 1] >= 0)
            {
                ans += t[i][j] + t[i][j + 1];
            
                if (t[i][j] > 0 && t[i][j + 1] <= 0)
                {    
                    possible_mid = max(possible_mid , -t[i][j + 1]);
                    break;
                }
            }
            else 
            {
                possible_mid = max(possible_mid , t[i][j]);
            }
        }
    }

    cout << max(0ll , ans + possible_mid) << endl;
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