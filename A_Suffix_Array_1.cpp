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

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

const int N = 200009;

void count_sort(vector <int> &p , vector <int> &c)
{
    int n = p.size();

    vector <int> cnt(n);
    for (auto x : c)
        cnt[x] ++;
    
    vector<int> p_new(n);
    vector <int> pos(n);
    pos[0] = 0;

    for (int i = 1 ; i < n ; i ++)
        pos[i] = pos[i - 1] + cnt[i - 1];
    
    for (auto x : p)
    {
        int i = c[x];
        p_new[pos[i]] = x;
        pos[i]++;
    }

    p = p_new;
}

void solve()
{
    string s;
    cin >> s;

    s += '$';
    int n = s.size();

    vector<int> p(n), c(n);
    vector<pair<char, int>> t(n);

    for (int i = 0; i < n; i++)
    {
        t[i] = {s[i], i};
    }
    
    sort(all(t));
    
    for (int i = 0; i < n; i++)
    {
        p[i] = t[i].S;
    }

    c[p[0]] = 0;
    
    for (int i = 1; i < n; i++)
    {
        if (t[i].F == t[i - 1].F)
        {
            c[p[i]] = c[p[i - 1]];
        }
        else
        {
            c[p[i]] = c[p[i - 1]] + 1;
        }
    }

    int k = 0;

    while ((1 << k) < n)
    {
        for (int i = 0 ; i < n ; i ++)
        {
            p[i] = (p[i] - (1 << k) + n) % n;
        }

        count_sort(p , c);

        vector <int> c_new(n);       
        c_new[p[0]] = 0;
        
        for (int i = 1; i < n; i++)
        {
            pair<int, int> now = {c[p[i]] , c[(p[i] + (1 << k)) % n]};
            pair<int, int> prev = {c[p[i - 1]] , c[(p[i - 1] + (1 << k)) % n]};
            
            c_new[p[i]] = c_new[p[i - 1]];
            c_new[p[i]] += (now != prev);
        }

        c = c_new;
        k++;
    }

    for (auto x : p)
        cout << x << " " ;
    cout << endl;
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