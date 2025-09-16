#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vl vector<ll>
#define pi pair<int, int>
#define pl pair<ll, ll>
#define pb push_back
#define F first
#define S second
#define all(v) v.begin(), v.end()
#define allrev(v) v.rbegin(), v.rend()
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
using namespace std;

const int N = 200009;

void solve()
{
    int m;
    string s;
    cin >> s >> m;
    
    set <int> zero = {-1} , one = {-1};
    set <pair<int , pair<int, int>>> st;

    for (int i = 0 ; i < s.size() ; i ++)
    {
        if (s[i] == '0')
            zero.insert(i);
        else 
            one.insert(i);
    }

    for (int i = 0 ; i < s.size() ;)
    {
        int cnt = 0 , j = i;
        while (i < s.size() - 1 && s[i] == s[j])
            j ++ , cnt ++;

        st.insert({j - i + 1 , {i , j}});
        i = j;
    }

    while (m --)
    {
        int i;
        cin >> i;

        i --;

        if (s[i] == '1')
        {
            zero.insert(i);
            one.erase(i);
            
            auto l = one.upper_bound(i);
            auto r = l;
            
            l --;

            auto x = st.find({*r - *l - 1 , {*l + 1 , *r - 1}});

            if (x != st.end())
                st.erase(x);

        }   
        else 
        {

        }    
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