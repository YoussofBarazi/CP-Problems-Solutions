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

struct suffix_array 
{
    int n;
    vector <int> p , c;
    vector <pii> t;
    
    suffix_array (string &s)
    {
        s += '$';
        n = s.size();
        p.resize(n) , c.resize(n) , t.resize(n);
        for (int i = 0 ; i < n ; i ++) t[i] = {s[i] , i};
        sort(all(t));
        for (int i = 0 ; i < n ; i ++) p[i] = t[i].S;
        c[p[0]] = 0;
        for (int i = 1 ; i < n ; i ++) c[p[i]] = c[p[i - 1]] + (t[i].F != t[i - 1].F);
        int k = 0;
        while ((1 << k) < n)
        {
            for (int i = 0 ; i < n ; i ++) p[i] = (p[i] - (1 << k) + n) % n;
            count_sort(p , c);
            vector <int> new_c(n);
            new_c[p[0]] = 0;
            for (int i = 1 ; i < n ; i ++) 
            {
                pii now = {c[p[i]] , c[(p[i] + (1 << k)) % n]};
                pii prev = {c[p[i - 1]] , c[(p[i - 1] + (1 << k)) % n]};
                new_c[p[i]] = new_c[p[i - 1]] + (now != prev);
            }
            c = new_c;
            k ++;
        }
    }
    void count_sort(vi &p , vi &c)
    {
        vector <int> new_p(n) , pos(n , 0) , cnt(n , 0);
        for (int x : c) cnt[x] ++;
        for (int i = 1 ; i < n ; i ++) pos[i] = pos[i - 1] + cnt[i - 1];
        for (int x : p)
        {
            int i = c[x];
            new_p[pos[i]] = x;
            pos[i]++;
        }
        p = new_p;
    }
    bool substr_search(string &t , string &s)
    {
        int l = 0 , r = s.size() - 1;

        while (l <= r)
        {
            int mid = (l + r) / 2;
            string sub = s.substr(p[mid] , t.size());

            if (sub == t)
                return true;
            else if (sub < t)
                l = mid + 1;
            else 
                r = mid - 1;
        }

        return false;
    }
};

void solve()
{
    string s; int q;
    cin >> s >> q;

    suffix_array suf(s);

    while (q --)
    {
        string t;
        cin >> t;

        if (suf.substr_search(t , s))
            cout << "Yes\n";
        else 
            cout << "No\n" ;
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