#include<bits/stdc++.h>

#define  pf                  printf
#define  sc                  scanf
#define  PI                  2*acos(0.0)
#define  fast                ios_base::sync_with_stdio(false);cin.tie(0); cout.tie(0)
#define  mem(a,b)            memset(a, b, sizeof(a) )
#define  gcd(a,b)            __gcd(a,b)
#define  lcm(a,b)            (a*(b/gcd(a,b)))
#define  MAX                 1234567899
#define  mod                 1000000007
#define  all(v)              (v).begin(),(v).end()
#define  vSort(v)            sort(all(v))
#define  maxSort(v)          sort(all(v),greater<int>())
#define  Unique(v)           v.erase(unique(all(v)),v.end())
#define  sqr(x)              ((x)*(x))
#define  qube(x)             ((x)*(x)*(x))
#define  deci(n)             cout<<fixed<<setprecision(n)
#define  sci(n)              sc("%d",&(n))
#define  scii(x,y)           sc("%d %d",&(x),&(y))
#define  scl(x)              sc("%lld",&(x))
#define  scll(x,y)           sc("%lld %lld",&(x),&(y))
#define  vi                  vector<int>
#define  hi                  pf(" HI \n")
#define  pp                  pair<int,int>
#define  pb(x)               push_back(x)
#define  mp(x,y)             make_pair(x,y)
#define  F                   first
#define  S                   second
#define  check(n,pos)        (n & (1<<(pos)))
#define  biton(n,pos)        (n  (1<<(pos)))
#define  bitoff(n,pos)       (n & ~(1<<(pos)))
typedef  long long int       lli;
typedef  unsigned long long int ulli;
int dx4[] = { 0, 0, -1, 1 } ;
int dy4[] = { -1, 1, 0, 0 } ;
bool valid( int r, int c, int x, int y )
{
    if( x >= 1 && x <= r && y >= 1 && y <= c ) return 1 ;
    return 0 ;
}

using namespace std;

struct node
{
    bool endmark;
    node* next[26+1];
    node()
    {
        endmark= false;
        for(int i=0; i<26; i++)
            next[i]= NULL;
    }
} * root;

void Insert(char *str,int len)
{
    node* cur= root;
    for(int i=0; i<len; i++)
    {
        int id= str[i]-'a';
        if(cur->next[id]==NULL)
            cur->next[id] = new node();
        cur = cur->next[id];
    }
    cur->endmark= true;
}
bool Search(char *str,int len)
{
    node* cur = root;
    for(int i=0;i<len;i++){
            int id= str[i]-'a';
        if(cur->next[id]==NULL)
        {
            return false;
        }
        cur= cur->next[id];

    }
    return cur->endmark;
}
void del(node *cur)
{
    for(int i=0; i<26; i++)
    {
        if(cur->next[i])
        {
            del(cur->next[i]);
        }
    }
    delete(cur);
}
int main ()
{
     root = new node();
    pf("Enter number of words: ");
    int word;
    sci(word);
    for(int i=1;i<=word;i++)
    {
        char str[50];
        sc("%s",str);
        Insert(str,strlen(str));
    }
    pf("Enter number of query: ");
    int query;
    sci(query);
    for(int i=1;i<=query;i++)
    {
        char str[50];
        sc("%s",str);
        if(Search(str,strlen(str)))
            pf("FOUND\n");
        else
            pf("NOT FOUND\n");
    }
    del(root);

    return 0;
}

