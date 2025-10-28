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

const int N = 200009;

void solve()
{
    int n;
    cin >> n;

    string s;
    cin >> s;

    map <char , int> freq;

    for (int i = 0 ; i < n ; i ++)
        freq[s[i]]++;

    bool ok = true;
    bool NS = false;
    bool EW = false;

    for (auto x : freq)
    {
        if (x.S % 2 == 0)
            continue;
        
        if (x.F == 'N')
        {
            if (freq['S'] % 2)
                NS = true;
            else 
                ok = false;
        }
        if (x.F == 'S')
        {
            if (freq['N'] % 2)
                NS = true;
            else 
                ok = false;
        }
        if (x.F == 'E')
        {
            if (freq['W'] % 2)
                EW = true;
            else 
                ok = false;    
        }
        if (x.F == 'W')
        {
            if (freq['E'] % 2)
                EW = true;
            else 
                ok = false;
        }
    }

    if (!ok)
    {
        cout << "NO" << endl;
        return ;
    }

    string ans;

    map <char , int> t = freq;

    for (int i = 0 ; i < n ; i ++)
    {
        if (s[i] == 'N' || s[i] == 'S')
        {
            if (freq[s[i]] - t[s[i]] < freq[s[i]] / 2 + NS)
                ans += 'R';
            else 
                ans += 'H';
        }
        else
        {
            if (freq[s[i]] - t[s[i]] < freq[s[i]] / 2 + EW)
                ans += 'R';
            else 
                ans += 'H';
        }

        t[s[i]] --;
    }

    int cnt = 0;
    for (int i = 0 ; i < n ; i ++)
        cnt += ans[i] == 'R';

    if (cnt == n)
    {
        if (NS)
        {
            cnt -= 2;
            for (int i = 0 ; i < n ; i ++)
            {
                if (ans[i] == 'R' && s[i] == 'N')
                {
                    ans[i] = 'H';
                    break;
                }
            }
            for (int i = 0 ; i < n ; i ++)
            {
                if (ans[i] == 'R' && s[i] == 'S')
                {
                    ans[i] = 'H';
                    break;
                }
            }
        }
        else if (EW)
        {
            cnt -= 2;
            for (int i = 0 ; i < n ; i ++)
            {
                if (ans[i] == 'R' && s[i] == 'W')
                {
                    ans[i] = 'H';
                    break;
                }
            }
            for (int i = 0 ; i < n ; i ++)
            {
                if (ans[i] == 'R' && s[i] == 'E')
                {
                    ans[i] = 'H';
                    break;
                }
            }
        }
        else 
        {cout << "NO" << endl; return;}

    }
    else if (cnt == 0)
    {
        if (NS)
        {
            cnt += 2;
            for (int i = 0 ; i < n ; i ++)
            {
                if (ans[i] == 'H' && s[i] == 'N')
                {
                    ans[i] = 'R';
                    break;
                }
            }
            for (int i = 0 ; i < n ; i ++)
            {
                if (ans[i] == 'H' && s[i] == 'S')
                {
                    ans[i] = 'R';
                    break;
                }
            }
        }
        else if (EW)
        {
            cnt += 2;
            for (int i = 0 ; i < n ; i ++)
            {
                if (ans[i] == 'H' && s[i] == 'W')
                {
                    ans[i] = 'R';
                    break;
                }
            }
            for (int i = 0 ; i < n ; i ++)
            {
                if (ans[i] == 'H' && s[i] == 'E')
                {
                    ans[i] = 'R';
                    break;
                }
            }
        }
        else 
        {cout << "NO" << endl; return;}
    }

    if (cnt % n != 0)
        cout << ans << endl;
    else 
        cout << "NO" << endl;
}

int main()
{
    // IO("name");
    IOS;

    int t = 1;
    cin >> t;

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