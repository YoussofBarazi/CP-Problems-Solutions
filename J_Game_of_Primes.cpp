#include <bits/stdc++.h>
using namespace std;
const int N =1e6;
int a[N];
const int sz =1e6;
bool composite[sz];
void seive()
{
    composite[0]=true;
    for(long long i =2 ; i*i<sz ; i++)
    {
        if(!composite[i])
        {
            for(long long j=i+i ; j<sz ; j+=i)
            {
                composite[j]=true;
            }
        }
    }
}
int main()
{
    int t;
    cin>>t;
    seive();
    while(t--)
    {
        int ans=0;
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            if(i%2==0)
                ans++;
            else
            {
                int ma = -1;
                 if(composite[a[i]])
               {

                for(int j=2;j*j<=a[i];j++)
                {
                    if(a[i]%j==0)
                    ma=max({j,ma,a[i]/j});
                }
                if(ma > 0 && !composite[ma])
                    ans++;

            }
            else
                ans++;
        }
        }
        printf("%d\n",ans);
    }
}