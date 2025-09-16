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

int n , q;

struct SegmentTree {

    #define lc (id << 1)
    #define rc (lc | 1)
    #define mid ((l + r) >> 1)

    vector <pii> seg;

    SegmentTree ()
    {
        seg.resize((n << 2) + 100 , {0 , 0});
    }

    void set(int ndx , int val , int id = 1 , int l = 1 , int r = n)
    {
        if (l == r)
        {
            seg[id] = {val , 0};
            return ;
        }

        if (ndx <= mid)
            set(ndx , val , lc , l , mid);
        else 
            set(ndx , val , rc , mid + 1 , r);
    }

    void update(int L , int R , int id = 1 , int l = 1 , int r = n)
    {
        if (L <= l && r <= R)
        {
            seg[id].S ++;
            return ;
        }

        if (l > R || L > r)
            return ;

        update(L , R , lc , l , mid);
        update(L , R , rc , mid + 1 , r);
    }

    ll query(int ndx , int id = 1 , int l = 1 , int r = n)
    {
        if (l == r)
        {
            int cnt = seg[id].S;
            int x = seg[id].F;

            while (cnt > 0)
            {
                int tmp = x , sum = 0;

                while (tmp > 0)
                {
                    sum += tmp % 10;
                    tmp /= 10;
                }

                if (sum == x)
                    cnt = 0;
                
                x = sum;
                cnt --;
            }

            seg[id] = {x , cnt};

            return x;
        }

        seg[lc].S += seg[id].S;
        seg[rc].S += seg[id].S;
        seg[id].S = 0;

        if (ndx <= mid)
            return query(ndx , lc , l , mid);
        else 
            return query(ndx , rc , mid + 1 , r);
    }
};


void solve()
{
    cin >> n >> q;

    SegmentTree st;
    
    for (int i = 1 ; i <= n ; i ++)
    {
        int x;
        cin >> x;

        st.set(i , x);    
    }

    while (q --)
    {
        int t;
        cin >> t;

        if (t == 1)
        {
            int l , r ;
            cin >> l >> r;

            st.update(l , r);
        }
        else 
        {
            int x;
            cin >> x;

            cout << st.query(x) << endl;
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