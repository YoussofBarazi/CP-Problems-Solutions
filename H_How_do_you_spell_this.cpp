#include <bits/stdc++.h>
#define vi vector<int>
#define ll long long
#define vl vector<ll>
#define pi pair<int, int>
#define pl pair<ll, ll>
#define oo INT_MAX
#define OO LONG_MAX
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

struct TrieNode
{
    TrieNode *childNode[26];
    int min_remain = 1e9;

    TrieNode()
    {
        for (int i = 0; i < 26; i++)
            childNode[i] = NULL;
    }
};

void insert_key(TrieNode *root, string &key)
{
    TrieNode *currentNode = root;

    for (int i = 0; i < key.size(); i++)
    {
        if (currentNode->childNode[key[i] - 'a'] == NULL)
        {
            TrieNode *newNode = new TrieNode();

            currentNode->childNode[key[i] - 'a'] = newNode;
        }

        currentNode = currentNode->childNode[key[i] - 'a'];
        currentNode->min_remain = min((int)key.size() - i - 1, currentNode->min_remain);
    }
}

int isPrefixExist(TrieNode *root, string &key)
{
    TrieNode *currentNode = root;

    for (auto c : key)
    {

        if (currentNode->childNode[c - 'a'] == NULL)
            return -1;

        currentNode = currentNode->childNode[c - 'a'];
    }

    return currentNode->min_remain;
}

void solve()
{
    int n, q;
    cin >> n >> q;

    TrieNode *root = new TrieNode();
    string key;

    while (n--)
    {
        cin >> key;

        insert_key(root, key);
    }

    while (q--)
    {
        cin >> key;

        int ans = isPrefixExist(root, key);

        cout << ans << endl;
    }
}

int main()
{
    IOS;

    int t = 1;
    // cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}