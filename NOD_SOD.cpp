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
int nod=1;
int sod=1;
int pow(int p,int q)
{
    int ans=1;
    for(int i=1;i<=q;i++)
        ans*=p;
    return ans;
}
int SOD(int p,int q)
{
    int ans = ((pow(p,q+1))); /// ((p^q+1) -1) / (p-1)
    ans=ans-1;
    int tot=(ans)/(p-1);
    sod*=tot;
}
int primefactor(int n)
{
    for(int i=2;i*i<=n;i++)
    {
        int power=0;
        while(n%i==0) n/=i,power++;
        if(power>0){
                nod*=(power+1);
                SOD(i,power);
           // cout << i << " is "<< power << " times "<<endl;
        }
    }
    if(n>1){
            nod*=2;
            SOD(n,1);
        //cout << n << " is "<< 1 <<" time"<<endl;
    }
}
int main ()
{
    int n;
    cin >> n;
    primefactor(n);
    cout << nod << " "<< sod <<endl;
    return 0;
}
