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
#define SIZE 10000007
vector<int> prime;
bool mark[SIZE];

lli bigMod(lli a,lli b,lli m)
{
    if(b==0)
        return 1;
    lli x=bigMod(a,b>>1,m);
    x=((x%m)*(x%m))%m;
    if(b&1)
        x=(x*(a%m))%m;
    return x;
}

void primeee ( int n ) {
    mark[0] = mark[1] = 1;

    prime.pb(2);
    for ( int i = 4; i <= n; i += 2 )
        mark[i] = 1;

    int sqrtn = sqrt ( n );
    for ( int i = 3; i <= sqrtn; i += 2 ) {
        if ( mark[i] == 0 ) {
            for ( int j = i * i; j <= n; j += 2 * i ) mark[j] = 1;
        }
    }

    for ( int i = 3; i <= n; i += 2 )
        if ( mark[i] == 0 ) prime.pb(i);
}

int factors[100005];
void factorize1( int n ) {
    int sqrtn = sqrt ( n );
    for ( int i = 0; i < prime.size() && prime[i] <= sqrtn; i++ ) {
    if ( mark[n] == 0 )
        break;
        if ( n % prime[i] == 0 ) {
            while ( n % prime[i] == 0 ) {
                n /= prime[i];
                factors[prime[i]]++;
            }
            sqrtn = sqrt ( n );
        }
    }
    if ( n != 1 ) {
        factors[n]++;
    }
}

void factorize2( int n ) {
    int sqrtn = sqrt ( n );
    for ( int i = 0; i < prime.size() && prime[i] <= sqrtn; i++ ) {
    if ( mark[n] == 0 )
        break;
        if ( n % prime[i] == 0 ) {
            while ( n % prime[i] == 0 ) {
                n /= prime[i];
                factors[prime[i]]--;
            }
            sqrtn = sqrt ( n );
        }
    }
    if ( n != 1 ) {
        factors[n]--;
    }
}

int main()
{
    primeee(SIZE);
    int t;
    cin >>t;
    while(t--)
    {
        mem(factors,0);
        lli n,nn,r,M;
        scanf("%lld %lld %lld", &n,&r,&M);
        if(n<r) {
            pf("0\n");
            continue;
        }
        int mn = min(r,n-r);
        nn = n;
        for(int i=1;i<=mn;i++,n--)
        {
            factorize1(n);
            factorize2(i);
        }
        lli ans =1;

        for(int i=2;i<=nn;i++)
        {
            if(factors[i])
            ans =((ans%M)*(bigMod(i,factors[i],M)%M)%M);
        }
        printf("%lld\n",ans);
    }
    return 0;
}

