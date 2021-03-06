#include<algorithm>
#include<sstream>
#include<iostream>
#include<iomanip>
#include<climits>
#include<cstring>
#include<cassert>
#include<utility>
#include<limits>
#include<cstdio>
#include<string>
#include<vector>
#include<bitset>
#include<stack>
#include<ctime>
#include<queue>
#include<cmath>
#include<map>
#include<set>
using namespace std;
typedef long long ll;
typedef unsigned long long  ull;
#define     mem(a,b)        memset(a,b,sizeof(a))
#define     mp              make_pair
#define     pli             pair<ll,int>
#define     fs              first
#define     sc              second
#define     VI              vector<int>
#define     clr(a)          a.clear()
#define     pob             pop_back
#define     pub             push_back
#define     eps             1E-6
#define     sf              scanf
#define     pf              printf
#define     all(a)          a.begin(),a.end()
#define     allr(a)         a.rbegin(),a.rend()
#define     full(a,l)       a,a+l
#define     fread(name)     freopen(name,"r",stdin)
#define     fwrite(name)    freopen(name,"w",stdout)
#define     sz(a)           (int)a.size()
#define     count_one       __builtin_popcount
#define     count_onell     __builtin_popcountll
#define     fastIO          ios_base::sync_with_stdio(false)
#define     PI              (acos(-1.0))
#define     linf            (1LL<<62)//>4e18
#define     inf             (0x7f7f7f7f)//>2e9
#define     fore(x,i)       for(typeof((x).begin()) i=(x.begin()); i!=(x).end(); ++i)
#define     rfore(x,i)      for(typeof((x).rbegin()) i=(x.rbegin()); i!=(x).rend(); ++i)
#define     For(i,a,b)      for(int i=a;i<=b;++i)
#define     rFor(i,a,b)     for(int i=a;i>=b;--i)
///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//int X[]={1,1,2,2,-1,-1,-2,-2},Y[]={2,-2,1,-1,2,-2,1,-1};
//int X[]={0,-1,-1,-1,0,1,1,1},Y[]={-1,-1,0,1,1,1,0,-1};
//int X[]={-1,0,1,0},Y[]={0,1,0,-1};
///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
ll bigMod(ll a, ll x, ll p) {ll r = 1; while (x > 0) {if (x % 2 != 0) {r = (r * a) % p;} a = (a * a) % p; x = (x >> 1);} return r;}
//ll modInverse(ll a, ll p){return bigMod(a,p-2,p);}
//ll extGcd(ll a,ll b,ll& x,ll& y){if(b==0){x=1;y=0;return a;}else{int g=extGcd(b,a%b,y,x);y-=a/b*x;return g;}}
template<class T> T pwr(T b, T p) {T r = 1, x = b; while (p) {if (p & 1)r *= x; x *= x; p = (p >> 1);} return r;}
template<class T> T lcm(T a, T b) {return (a / __gcd(a, b)) * b;}
template<class T> T sqr(T a) {return a * a;}
template<class T> void xswap (T &x, T &y) {if (x != y) {x ^= y; y ^= x; x ^= y;}}
///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//struct tuple{double f,s,t;tuple(){}tuple(double a,double b,double c){f=a,s=b,t=c;}};
//int cross_product(tuple a,tuple b){int v=a.f*(b.s-b.t)-a.s*(b.f-b.t)+a.t*(b.f-b.s);return (v==0?0:(v>0?+1:-1));}
//tuple make_vector(tuple s,tuple e){tuple a;a.f=e.f-s.f;a.s=e.s-s.s;a.t=e.t-s.t;return a;}
///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
template<typename T> inline bool is_set(T &mask, int pos) {return ((mask) & (1LL << pos));}
template<typename T> inline T setf(T mask, int pos) {return mask = ((mask) & (~(1LL << pos)));}
template<typename T> inline T sett(T mask, int pos) {return mask = ((mask)(1LL << pos));}
template<typename T> inline T flip(T mask, int pos) {return mask = ((mask) ^ (1LL << pos));}
///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//double dtor(double x){return x*PI/180.0;}
//double rtod(double x){return x*180.0/PI;}
//double pdis(pdd a,pdd b){return sqrt((double)sqr(a.fs-b.fs)+sqr(a.sc-b.sc));}
//template<class T> double rAng(T a,T b,T c){double d=(sqr(a)+sqr(b)-sqr(c))/(a*b*2);d=(d<-1?-1:(d>1?1:d));return acos(d);}
///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//template<class T> string to_string(T n){ostringstream oss;oss<<n;oss.flush();return oss.str();}
//int to_int(string s){int r=0;istringstream sin(s);sin>>r;return r;}
///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
template<class T1> void put(T1 e) {cout << e << endl;}
template<class T1, class T2> void put(T1 e1, T2 e2) {cout << e1 << " " << e2 << endl;}
template<class T1, class T2, class T3> void put(T1 e1, T2 e2, T3 e3) {cout << e1 << " " << e2 << " " << e3 << endl;}
template<class T1, class T2, class T3, class T4> void put(T1 e1, T2 e2, T3 e3, T4 e4) {cout << e1 << " " << e2 << " " << e3 << " " << e4 << endl;}
template<class T1, class T2, class T3, class T4, class T5> void put(T1 e1, T2 e2, T3 e3, T4 e4, T5 e5) {cout << e1 << " " << e2 << " " << e3 << " " << e4 << " " << e5 << endl;}
template<class T1> void putv(vector<T1>e1) {for (int i = 0; i < sz(e1); i++)(!i ? cout << e1[i] : cout << " " << e1[i]); cout << endl;}
template<class T1> void puta(T1 arr[], int l) {for (int i = 0; i < l; i++)(!i ? cout << arr[i] : cout << " " << arr[i]); cout << endl;}
///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
template<class T1> bool tk(T1 &e1) {return (cin >> e1 ? true : false);}
template<class T1, class T2> bool tk(T1 &e1, T2 &e2) {return (cin >> e1 >> e2 ? true : false);}
template<class T1, class T2, class T3> bool tk(T1 &e1, T2 &e2, T3 &e3) {return (cin >> e1 >> e2 >> e3 ? true : false);}
template<class T1, class T2, class T3, class T4> bool tk(T1 &e1, T2 &e2, T3 &e3, T4 &e4) {return (cin >> e1 >> e2 >> e3 >> e4 ? true : false);}
///HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
#define LM 1006
#define mod 1000000007
vector<int>G[LM];
int T, N, indeg[LM], root;
ll dp[LM][LM];

ll ncr(ll n, ll r)
{
    if (r == 0 or n == r)return 1;
    ll &ans = dp[n][r];
    if (~ans)return ans;
    return ans = (ncr(n - 1, r - 1) % mod + ncr(n - 1, r) % mod) % mod;
}
/// return pair<number_of_valid_solution,no_of_node> in u rooted subtree.
pair<ll, int> sol(int u)
{
    ll ans = 1, node = 0;
    For(i, 0, sz(G[u]) - 1)
    {
        pli temp = sol(G[u][i]);
        /**
            ekhon porjonto 'ans' ta solution ase 'node' ta Vertex niye notun 'temp.sc' vertex
            ar ager 'node' ta vertex mot (node+temp.sc) ta pos theke 'node' ta pos choose kore
            ager sob gula solution likhlam ('ans' vabe lekha somvob) ekhon baki jaygay 'temp.sc'
            Ta node 'temp.fs' vabe bosate pari.

            (node+temp.sc) ta jayga theke node ta jayga (node+temp.sc)C(node) vabe choose korte
            pari. ei jayga gulay (node) ta people ke (ans) vabe sajayte pari. ar baki position gula
            (teamp.fs) vabe sajate pari.

        */
        ans = ((((temp.fs % mod) * (ans % mod)) % mod) * (ncr(node + temp.sc, node) % mod)) % mod;
        node += temp.sc;
    }
    return mp(ans, node + 1);
}

int main()
{
    mem(dp, -1);
    int u, v, t = 1;
    sf("%d", &T);
    while (T--)
    {
        sf("%d", &N);
        For(i, 0, N)clr(G[i]);
        mem(indeg, 0);
        For(i, 1, N - 1)
        {
            sf("%d %d", &u, &v);
            G[u].pub(v);
            indeg[v]++;
        }
        For(i, 1, N)
        {
            if (indeg[i] == 0)
            {
                root = i;
                break;
            }
        }
        pf("Case %d: %lld\n", t++, sol(root));
    }
    return 0;
}

