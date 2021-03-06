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
int dx4[] = { 0 , 0 , -1 , 1 } ;
int dy4[] = { -1 , 1 , 0 , 0 } ;
bool valid( int r , int c , int x , int y ){
    if( x >= 1 && x <= r && y >= 1 && y <= c ) return 1 ; return 0 ;}

using namespace std;
vi graph[1000];
vi cost[1000];
int dis[1000000];
int previous[1000000];
pp ppp;
int Dijkstra(int n)
{
    priority_queue<pp,vector<pp> , greater<pp> >pq;
    for(int i=0;i<1000000;i++)
    {
        dis[i]=MAX;
        previous[i] = -1;
    }
    pq.push(mp(0,1));
    dis[1]=0;
    while(!pq.empty())
    {
         ppp=pq.top();
        int u= ppp.S;
        pq.pop();
        if(u==n)
            return dis[n];
        for(int i=0;i<graph[u].size();i++)
        {
            int v=graph[u][i];
            if(dis[u]+cost[u][i]<dis[v])
            {
                dis[v]=dis[u]+cost[u][i];
                previous[v]=u;
                pq.push(mp(dis[v],v));
            }
        }
    }
    return -1;
}
int main ()
{
    int node,edge;
    cin >> node >> edge;
    int u,v,w;
    for(int i=1;i<=edge;i++)
    {
        cin >> u >> v>> w;
        graph[u].pb(v);
        graph[v].pb(u);
        cost[u].pb(w);
        cost[v].pb(w);
    }
    int n_node_distance;
    cin >> n_node_distance;
    int ans= Dijkstra(n_node_distance);
    if(ans== -1)
        cout << "No way to go source to n node "<<endl;
    else
    {
        cout << ans <<endl;
        vi v;
        int p=n_node_distance;
        while(p!= -1)
        {
            v.pb(p);
            p= previous[p];
        }
        reverse(v.begin(),v.end());
        for(int i=0;i<v.size();i++)
            cout << v[i]<< " ";
        cout <<endl;
    }
    return 0;
}
