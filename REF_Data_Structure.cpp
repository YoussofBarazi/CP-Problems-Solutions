#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 7;

// DSU

int parent[N], Size[N];
int get(int v)
{
    if (v == parent[v])
        return v;
    return parent[v] = get(parent[v]);
}
bool join(int a, int b)
{
    a = get(a);
    b = get(b);

    if (a == b)
        return false;

    if (Size[a] < Size[b])
        swap(a, b);

    parent[b] = a;

    Size[a] += Size[b];

    return true;
}

// fenwick

struct Fenwick {
    int bit[N];
    Fenwick() {
        memset(bit,0,sizeof bit);
    }
    void add(int id ,int x){ // ATTENTION: id from 1 not 0
        for(int i = id;i < N;i += i & -i)
            bit[i] += x;
    }

    int getsum(int id){
        int sum = 0;
        for(int i = id;i;i -= i & -i)
            sum += bit[i];
        return sum;
    }
};

const int LOG = 32;
int a[N] , n;

// sparse table

struct SparseTable {
    int st[N][LOG];
    
    void build() {
        for(int j = 0;j < LOG;j++)
            for(int i = 0 ; i < n ; i++) 
                if(i + (1 << j) - 1 < n)
                    st[i][j] = (j ? min(st[i][j-1], st[i + (1 << (j-1))][j-1]): a[i]);
    }

    int query(int l,int r) {
        int x = log2(r-l+1);
        return min(st[l][x],st[r-(1<<x)+1][x]);
    }
};

// trie bit

const int CHAR = 2;
const int LOG = 32;

struct trie {
    trie* child[CHAR];
    int cnt;
    
    trie() {
        memset(child, 0, sizeof child);
        cnt = 0;
    }
    
    void insert(int x,int i = LOG-1) {
        cnt++;
        if (i == -1) return;
        
        int cur = (x&(1<<i)) > 0;
        if (child[cur] == 0) child[cur] = new trie();
        child[cur]->insert(x,i-1);
    }
    
    void erase(int x,int i = LOG-1) {
        cnt--;
        if (i == -1) return;
        
        int cur = (x&(1<<i)) > 0;
        child[cur]->erase(x,i-1);
        if (child[cur]->cnt == 0) {delete child[cur];child[cur] = 0;}
        return;
    }
    
    int cntSmallerThan(int x,int i = LOG-1) {
        if (i == -1) return 0;
        
        int cur = (x&(1<<i)) > 0;
        int ret = 0;
        if (cur) {
            ret += child[0] ? child[0]->cnt:0;
            ret += child[1] ? child[1]->cntSmallerThan(x,i-1):0;
        }
        else if (!cur) {
            ret += child[0] ? child[0]->cntSmallerThan(x,i-1):0;
        }
        return ret;
    }
    
    int kth(int k,int i = LOG-1) {
        if (k >= cnt) return -1;
        if (i == -1) return 0;

        int cnt0 = child[0] ? child[0]->cnt:0;
        
        if (k < cnt0) return child[0]->kth(k,i-1);
        return child[1]->kth(k-cnt0,i-1) + (1<<i);
    }
};

// trie string 

string str;

struct trie {
    trie* child[CHAR];
    int cnt,end;
    
    trie() {
        memset(child, 0, sizeof child);
        cnt = end = 0;
    }
    
    void insert(int i = 0) {
        cnt++;
        if (i == (int)str.size()) {
            end++;
            return;
        }
        
        int cur = str[i]-'a';
        if (child[cur] == 0) child[cur] = new trie();
        child[cur]->insert(i+1);
    }
    
    void erase(int i = 0) {
        cnt--;
        if (i == (int)str.size()) {
            end--;
            return;
        }
        
        int cur = str[i]-'a';
        child[cur]->erase(i+1);
        if (child[cur]->cnt == 0) {delete child[cur];child[cur] = 0;}
        return;
    }
    
    int cntPrefix(int i = 0) {
        if (i == (int)str.size()) return cnt;
        
        int cur = str[i]-'a';
        if (child[cur] == 0) return 0;
        return child[cur]->cntPrefix(i+1);
    }
};