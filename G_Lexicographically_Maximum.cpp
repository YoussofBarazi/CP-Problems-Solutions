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

const int N = 1000009;

int n;

struct SegTree
{
    #define lc (id << 1)
    #define rc (lc | 1)
    #define mid ((l + r) >> 1)

    vector <int> seg;

    SegTree()
    {
        seg.assign((N << 2) + 100 , 0);
    }

    void update(int v , int ndx , int id = 1 , int l = 1 , int r = n)
    {
        if (l == r)
        {
            seg[id] = v;
            return ;
        }

        if (ndx <= mid)
            update(v , ndx , lc , l , mid);
        else 
            update(v , ndx , rc , mid + 1 , r);

        seg[id] = seg[lc] + seg[rc];
    }

    int cnt()
    {
        return seg[1]; 
    }

    int find(int v , int id = 1 , int l = 1 , int r = n)
    {
        if (l == r)
            return l;
        
        if (seg[lc] < v)
            return find(v - seg[lc] , rc , mid + 1 , r);
        
        return find(v , lc , l , mid);
    }
};

string s;
SegTree st;
map <char , deque <int>> ndx;

void change(int i)
{
    st.update(0 , ndx[s[i]].front());
        
    ndx[s[i]].pop_front();
    
    if (!ndx[s[i]].empty())
    {
        st.update(1 , ndx[s[i]].front());
    }
}

void solve()
{
    cin >> s;
    
    n = s.size();
    s = 'a' + s;

    for (int i = 1 ; i <= n ; i ++)
    {
        if (ndx[s[i]].size() == 0)
        {    
            st.update(1 , i);           
        }
        
        ndx[s[i]].push_back(i);
    }

    int i = 1;

    string ans = "";

    while (i <= n)
    {
        int dist = st.cnt();
        
        if (s[i] - 'a' + 1 > dist)
        {
            ans.push_back(s[i]);
            
            change(i);
            
            i ++;
        }
        else if (s[i] - 'a' + 1 == dist)
        {
            if (i < n && s[i + 1] - 'a' + 1 < dist)
                goto start2;
            else 
                goto start1;
        }
        else 
        {
            if (i < n && dist < s[i + 1] - 'a' + 1 && dist <= s[i] - 'a' + 1)
            {
                start1 :

                ans.push_back(s[i]);

                change(i);

                i ++;

                continue;
            }

            start2 :

            int r = st.find(dist) + 1;

            while (r <= n && s[r] - 'a' + 1 <= dist)
            {
                r ++;
            }

            ans += string(r - i , char(dist + 'a' - 1));

            for ( ; i < r ; i ++)
            {
                change(i);
            }
        }
    }

    cout << ans << endl;
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