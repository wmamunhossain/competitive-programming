#include<bits/stdc++.h>
using namespace std;
#define     ll                      long long
#define     ull                     unsigned long long
#define     mems(a,b)               memset(a,b,sizeof(a))
#define     mp                      make_pair
#define     pii                     pair<ll,ll>
#define     pdd                     pair<double,double>
#define     fs                      first
#define     sc                      second
#define     VI                      vector<int>
#define     clr(a)                  a.clear()
#define     pb                      push_back
#define     eps                     1E-5
#define     sf                      scanf
#define     pf                      printf
#define     For(i,a,b)              for(int i=a;i<=b;++i)
#define     all(a)                  a.begin(),a.end()
#define     fread(name)             freopen(name,"r",stdin)
#define     fwrite(name)            freopen(name,"w",stdout)
#define     sz(a)                   (int)a.size()
#define     cone                    __builtin_popcountll
#define     fastIO                  ios_base::sync_with_stdio(false)
#define     cintie                  cin.tie(NULL)
#define     endl                    "\n"
#define     PI                      (acos(-1.0))
#define     linf                    (1LL<<62)
#define     inf                     (0x7f7f7f7f)
#define     sqr(a)                  ((a)*(a))
#define     lcm(a,b)                ({(a)/__gcd(a,b)*(b);})
#define     is_set(mask,pos)        ((mask)&(1LL<<pos))
#define     rset(mask,pos)          ((mask)&(~(1LL<<pos)))
#define     sett(mask,pos)           ((mask)|(1LL<<pos))
#define     flip(mask,pos)          ((mask)^(1LL<<pos))
#define     debv(v)                 for(int i=0;i<sz(v);++i)(!i?cout<<v[i]:cout<<" "<<v[i]);cout<<endl;
#define     deba(arr,l)             for(int i=0; i<l; i++)(!i?cout<<arr[i]:cout<<" "<<arr[i]);cout<<endl;
#define     deb(a...)               {cerr<<"#line:"<<__LINE__<<" -> ";dbg,a; cerr<<endl;}
struct debugger { template<typename T> debugger& operator , (const T v) { cerr<<v<<" "; return *this; } } dbg;
///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//int X[]={1,1,2,2,-1,-1,-2,-2},Y[]={2,-2,1,-1,2,-2,1,-1};
//int X[]={0,-1,-1,-1,0,1,1,1},Y[]={-1,-1,0,1,1,1,0,-1};
int X[]={-1,0,1,0},Y[]={0,1,0,-1};
///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//int bigMod(int a,int x,int p){int r=1;while(x>0){if(x%2!=0){r=(r*a)%p;}a=(a*a)%p;x=(x>>1);}return r;}
//int modInverse(int a, int p){return bigMod(a,p-2,p);}
//int extGcd(int a,int b,ll& x,ll& y){if(b==0){x=1;y=0;return a;}else{int g=extGcd(b,a%b,y,x);y-=a/b*x;return g;}}
//template<class T> T pwr(T b, T p){T r=1,x=b;while(p){if(p&1)r*=x;x*=x;p=(p>>1);}return r;}
///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//struct triple{double f,s,t;triple() {} triple(double a,double b,double c){f=a,s=b,t=c;}};
//int cross_product(triple a,triple b){int v=a.f*(b.s-b.t)-a.s*(b.f-b.t)+a.t*(b.f-b.s);return (v==0?0:(v>0?+1:-1));}
//triple make_vector(triple s,triple e){triple a;a.f=e.f-s.f;a.s=e.s-s.s;a.t=e.t-s.t;return a;}
///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//double pdis(pdd a,pdd b){return sqrt((double)sqr(a.fs-b.fs)+sqr(a.sc-b.sc));}
//template<class T> double rAng(T a,T b,T c){double d=(sqr(a)+sqr(b)-sqr(c))/(a*b*2);d=(d<-1?-1:(d>1?1:d));return acos(d);}
///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//template<class T> string to_str(T n){ostringstream oss;oss<<n;oss.flush();return oss.str();}
//template<typename T>T str_to(const string& s){T d;istringstream(s) >> d;return d;}
//struct fast{fast(){ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);}}cincout;
///HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
#define LM 203
char g[LM][LM];

int r,c;
pii st,en;
vector<pii> tp;
int T,t=1;
int dist[LM][LM];

struct tuple
{
    int a,b,c;
    tuple(int x,int y,int z)
    {
        a = x,b = y,c = z;
    }
} ;

bool cmp(tuple a,tuple b)
{
    return a.a<b.a;
}

vector<tuple> bfs(pii u)
{
    vector <tuple>ret;
    mems(dist, 63);
    dist[u.first][u.second] = 0;
    queue <int> Q;
    Q.push(u.first), Q.push(u.second);
    int x, y;
    while(!Q.empty())
    {
        x = Q.front();
        Q.pop();
        y = Q.front();
        Q.pop();
        for(int i = 0; i < 4; i++)
        {
            int nx = X[i] + x;
            int ny = Y[i] + y;
            if(nx < 0 || nx >= r || ny < 0 || ny >= c || g[nx][ny] == '#' || dist[nx][ny] <= dist[x][y]+1)
                continue;
            dist[nx][ny] = dist[x][y]+1;
            if(g[nx][ny] == '*')
            {
                tuple tem = tuple(dist[nx][ny], nx, ny);
                if(sz(ret) < 2)
                    ret.pb(tem);
                else if(ret.back().a > tem.a)
                    ret.back() = tem;
                sort(all(ret),cmp);
                while(ret.size()>2)ret.pop_back();
            }
            else
            {
                Q.push(nx);
                Q.push(ny);
            }
        }
    }
    return ret;
}

int main()
{
    t = 1;
    sf("%d",&T);
    while(T--)
    {
        sf("%d %d",&r,&c);
        tp.clear();
        for(int i=0;i<r;++i)
        {
            for(int j=0;j<c;++j)
            {
                sf(" %c",&g[i][j]);
                if(g[i][j]=='P')
                    st = mp(i,j);
                else if(g[i][j]=='D')
                    en = mp(i,j);
                if(g[i][j]=='*')
                    tp.pb(mp(i,j));
            }
        }

        pf("Case %d: ",t++);


        vector <tuple > stNodes = bfs(st);

        vector <tuple > enNodes = bfs(en);

        int ans = 1e9;

        for(int i=0;i<sz(stNodes);++i)
        {
            tuple a = stNodes[i];
            for(int j=0;j<sz(enNodes);++j)
            {
                tuple b = enNodes[j];
                if((a.b==b.b)&&(a.c==b.c))
                {
                    if(sz(tp)>1)ans = min(ans,a.a+b.a+2);
                }
                else
                {
                    ans = min(ans,a.a+b.a+1);
                }
            }
        }

        ans = min(ans,dist[st.fs][st.sc]);

        if(ans<1e9)
        {
            pf("%d\n",ans);
        }
        else
        {
            pf("impossible\n");
        }

    }
    return 0;
}

/*
4
3 4
####
#PD#
####

*/
