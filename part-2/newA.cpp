#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 

using namespace std ;
using namespace __gnu_pbds ; 

#define F first
#define S second
#define pb push_back
#define ll long long 
#define ld long double
#define rev greater < int >()
#define all(x) (x).begin () , (x).end ()
#define RF(F) freopen(F , "r" , stdin ) 
#define WF(F) freopen(F , "w" , stdout) 
#define IOS ios::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ;
#define ordered_set tree < int , null_type , less < int > , rb_tree_tag , tree_order_statistics_node_update > 


typedef pair < int , int > pii ;
typedef pair < long long , long long > pll ;
typedef map  < int , int > mii ; 
typedef map  < long long , long long > mll ;
typedef vector < int > vi ;
typedef vector < long long > vl ;


const ld  pi  = 3.14159265359 ;
const ld  eps = 1e-9 ;
const ll  INF = 1e9 ;
const int MAX_N = 3162280 ;

int n;

struct ST {

    #define lc (id << 1)
    #define rc (lc | 1)
    #define mid ((l + r) >> 1)

    vector <int> seg;

    ST()
    {
        seg.resize((n << 2) + 7 , INT_MAX);
    }

    void update(int ndx , int val , int id = 1 , int l = 1 , int r = (n << 1))
    {
        if (l == r)
        {
            seg[id] = val;
            return ;
        }

        if (ndx <= mid)
            update(ndx , val , lc , l , mid);
        else 
            update(ndx , val , rc , mid + 1 , r);

        seg[id] = seg[lc] & seg[rc];
    }

    int query(int L , int R , int id = 1 , int l = 1 , int r = (n << 1))
    {
        if (L <= l && r <= R)
            return seg[id];

        if (l > R || L > r)
            return -1;

        return query(L , R , lc , l , mid) & query(L , R , rc , mid + 1 , r);
    }
};

void solve2 ()
{
    cin >> n;

    ST st;

    vector <int> a(n);
    for (int i = 0 ; i < n ; i ++)
    {
        cin >> a[i];

        st.update(i + 1 , a[i]);
        //cout << st.query(i + 1 , i + 1) << endl;
    }

    int q;
    cin >> q;

    for (int i = 0 ; i < q ; i ++)
    {
        int l , r;
        cin >> l >> r;

        string ans = "NO";

        if (l == 1 && r == n)
        {
            if (st.query(l , r) == 0)
                ans = "YES";
        }
        else if (l == 1)
        {
            if (st.query(l , r) == st.query(r + 1 , n))
                ans = "YES";
        }
        else if (r == n)
        {
            if (st.query(l , r) == st.query(1 , l - 1))
                ans = "YES";
        }
        else if ((st.query(1 , l - 1) & st.query(r + 1 , n)) == st.query(l , r))
            ans = "YES" ;

        cout << ans << endl;
    }
}

int main() {

    int testCase = 1 ;
    //cin >> testCase;

    for(int T = 1 ; T <= testCase ; T ++){
        solve2() ;
    }

    return 0 ;
}
