#include <iostream>

using namespace std;

int main()
{
    //n=8 s=3 -->4 -1 2 3 5 0 2 7
    //4 -1 2  min:-1
    //3 5 0   min: 0
    //2 7     min: 2

    int n, s, mn=1e9, c=0 ;
    cin>>n>>s;
    for(int i=1; i<=n; i++)
    {
        int v;
        cin>>v;

        if(v<mn)
        {
            mn=v;
        }
        c++;
        if (c==s ||i==n)
        {
            cout <<mn<<" ";

            c=0;
            mn=1e9;
        }
    }
    return 0;
}