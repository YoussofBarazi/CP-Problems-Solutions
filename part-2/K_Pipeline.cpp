#include <bits/stdc++.h>

#define ll long long
#define S second
#define F first

using namespace std ;

int const N = 1e6 + 7 ;

ll n , k;
ll sum(ll s)
{
    return k * (k + 1) / 2 - (s * (s - 1) / 2) - (k - s);
}

void solve(int Testcase){

    cin >> n >> k;
/*
    if(n == 1){
        printf("0\n") ;
        return ;
    }
*/
    ll l = 2 , r = k;

    while (l < r)
    {
        ll mid = (l + r + 1) / 2;

        if (sum(mid) >= n)
            l = mid;
        else
            r = mid - 1;
    }

    //cout << sum(l) << endl;

    if(sum(l) < n)cout << "-1\n" ;
    else cout << k - l + 1 << endl;
}

int main(){

    int Testcase = 1 ;

    for(int T = 1 ; T <= Testcase ; T ++){
        solve(T) ;
    }

    return 0;
}
