#include<bits/stdc++.h>

using namespace std;

const int N=1e3+5;


map<int,int>mp;

int main(){

    int t;

    scanf("%d",&t);

    while(t--){
        int count=0;
        int n,m;

        scanf("%d%d",&n,&m);
        int a[n][m];

        int res=0;

        for(int i=0;i<n;i++){

            for(int j=0;j<m;j++){

                scanf("%d",&a[i][j]);
            }
        }

        for(int j=0;j<m;j++)
            mp[a[0][j]]++;


        for(int i=1;i<n;i++){

            for(int j=0;j<m;j++){
                if(mp[a[i][j]]>0)
                {

                   count++;
                   mp[a[i][j]] --;
                }
            }
            mp.clear();
        for(int j=0;j<m;j++)
            mp[a[i][j]]++;

        }
        printf("%d\n",count);
        mp.clear();
    }
}
