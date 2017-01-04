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
#define     pdd             pair<double,double>
#define     fs              first
#define     sc              second
#define     VI              vector<int>
#define     clr(a)          a.clear()
#define     pob             pop_back
#define     pub             push_back
#define     eps             1E-5
#define     sf              scanf
#define     pf              printf
#define     all(a)          a.begin(),a.end()
#define     allr(a)         a.rbegin(),a.rend()
#define     full(a,l)       a,a+l
#define     fread(name)     freopen(name,"r",stdin);
#define     fwrite(name)    freopen(name,"w",stdout);
#define     sz(a)           a.size()
#define     count_one       __builtin_popcount;
#define     count_onell     __builtin_popcountll;
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
struct tuple{double f,s,t;tuple(){}tuple(double a,double b,double c){f=a,s=b,t=c;}};
//int cross_product(tuple a,tuple b){int v=a.f*(b.s-b.t)-a.s*(b.f-b.t)+a.t*(b.f-b.s);return (v==0?0:(v>0?+1:-1));}
//tuple make_vector(tuple s,tuple e){tuple a;a.f=e.f-s.f;a.s=e.s-s.s;a.t=e.t-s.t;return a;}
///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//template<typename T> inline bool isOn(T &mask,int pos){return((mask)&(1LL<<pos));}
//template<typename T> inline void setf(T &mask,int pos){mask=((mask)&(~(1LL<<pos)));}
//template<typename T> inline void sett(T &mask,int pos){mask=((mask)(1LL<<pos));}
//template<typename T> inline void flip(T &mask,int pos){mask=((mask)^(1LL<<pos));}
///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
double dtor(double x){return x*PI/180.0;}
double rtod(double x){return x*180.0/PI;}
template<class T> T sqr(T a){return a*a;}
double pdis(pdd a,pdd b){return sqrt((double)sqr(a.fs-b.fs)+sqr(a.sc-b.sc));}
template<class T> double rAng(T a,T b,T c){double d=(sqr(a)+sqr(b)-sqr(c))/(a*b*2);d=(d<-1?-1:(d>1?1:d));return acos(d);}
///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//template<class T> string to_string(T n){ostringstream oss;oss<<n;oss.flush();return oss.str();}
//int to_int(string s){int r=0;istringstream sin(s);sin>>r;return r;}
///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
template<class T1> void put(T1 e){cout<<e<<endl;}
template<class T1,class T2> void put(T1 e1,T2 e2){cout<<e1<<" "<<e2<<endl;}
template<class T1,class T2,class T3> void put(T1 e1,T2 e2,T3 e3){cout<<e1<<" "<<e2<<" "<<e3<<endl;}
template<class T1,class T2,class T3,class T4> void put(T1 e1,T2 e2,T3 e3,T4 e4){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<endl;}
template<class T1,class T2,class T3,class T4,class T5> void put(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<endl;}
template<class T1> void putv(vector<T1>e1){for(int i=0;i<sz(e1);i++)(!i?cout<<e1[i]:cout<<" "<<e1[i]);cout<<endl;}
template<class T1> void puta(T1 arr[],int l){for(int i=0;i<l;i++)(!i?cout<<arr[i]:cout<<" "<<arr[i]);cout<<endl;}
///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
template<class T1> bool tk(T1 &e1){return(cin>>e1?true:false);}
template<class T1,class T2> bool tk(T1 &e1,T2 &e2){return(cin>>e1>>e2?true:false);}
template<class T1,class T2,class T3> bool tk(T1 &e1,T2 &e2,T3 &e3){return(cin>>e1>>e2>>e3?true:false);}
template<class T1,class T2,class T3,class T4> bool tk(T1 &e1,T2 &e2,T3 &e3,T4 &e4){return(cin>>e1>>e2>>e3>>e4?true:false);}
///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//ll bigMod(ll a,ll x,ll p){ll r=1;while(x>0){if(x%2!=0){r=(r*a)%p;}a=(a*a)%p;x=(x>>1);}return r;}
//ll modInverse(ll a, ll p){return bigMod(a,p-2,p);}
//ll extGcd(ll a,ll b,ll& x,ll& y){if(b==0){x=1;y=0;return a;}else{int g=extGcd(b,a%b,y,x);y-=a/b*x;return g;}}
template<class T> T pwr(T b, T p){T r=1,x=b;while(p){if(p&1)r*=x;x*=x;p=(p>>1);}return r;}
template<class T> T lcm(T a,T b){return(a/__gcd(a,b))*b;}
template<class T> void xswap (T &x,T &y){if(x!=y){x^=y;y^=x;x^=y;}}
///HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
string str;
stringstream ss;
pdd a,b,c;

void input()
{
    ss.clear();ss<<str;ss>>a.fs;cin>>a.sc>>b.fs>>b.sc>>c.fs>>c.sc;
}

tuple create_equation(pdd p, pdd q)
{
    double a = (p.sc-q.sc);
    double b = -(p.fs-q.fs);
    double c = p.sc*(p.fs-q.fs)-p.fs*(p.sc-q.sc);
    return tuple(a,b,c);
}

tuple creat_straight_line_perpendicular_of(tuple e,pdd p)
{
    double a = e.s;
    double b = -e.f;
    double c =  -(a*p.fs+b*p.sc);
    return tuple(a,b,c);
}

pdd calculate_intersection(tuple e1, tuple e2)
{
    double d = (e1.f*e2.s-e2.f*e1.s);
    double x = ((-e1.t)*(e2.s)-(-e2.t)*(e1.s))/d;
    double y = ((e1.f)*(-e2.t)-(e2.f)*(-e1.t))/d;
    return mp(x,y);
}

pdd circumcenter(pdd a, pdd b,pdd c)
{
    pdd mab = mp((a.fs+b.fs)/2,(a.sc+b.sc)/2);
    pdd mbc = mp((b.fs+c.fs)/2,(b.sc+c.sc)/2);
    tuple ab = create_equation(a,b);
    tuple bc = create_equation(b,c);
    tuple pab = creat_straight_line_perpendicular_of(ab,mab);
    tuple pbc = creat_straight_line_perpendicular_of(bc,mbc);
    return calculate_intersection(pab,pbc);
}

bool isEql(double a,double b)
{
    if(abs(a-b)<eps)return true;
    return false;
}

bool chk(double a,double b, double c,double e)
{
    bool aok,bok,cok;
    aok = bok = cok = false;
    double aa = a/e;
    double bb = b/e;
    double cc = c/e;
    int fa = floor(aa);
    int sa = ceil(aa);
    int fb = floor(bb);
    int sb = ceil(bb);
    int fc = floor(cc);
    int sc = ceil(cc);
    if(isEql(fa*e,a) or isEql(sa*e,a))aok = true;
    if(isEql(fb*e,b) or isEql(sb*e,b))bok = true;
    if(isEql(fc*e,c) or isEql(sc*e,c))cok = true;
    if(aok and bok and cok)
    {
        return true;
    }
    return false;
}

int main()
{
//    fread("I.in");
//    fwrite("WA.out");
    while(cin>>str and str!="END")
    {
        input();
        pdd p = circumcenter(a,b,c);

        /**
            r1 is calculated from circumcenter of the triangle.
            r2 is calculated from equation a/sin(a)=b/sin(b)=c/sin(c)=2*r.
            you may use any of them.
        */
        double r1 = (pdis(a,p)+pdis(b,p)+pdis(c,p))/3;
        double r2 = (pdis(a,b)/sin(rAng(pdis(c,a),pdis(b,c),pdis(a,b))))*.5;

        double u = rAng(r2,r2,pdis(a,b));
        double v = rAng(r2,r2,pdis(b,c));
        double w = rAng(r2,r2,pdis(c,a));
        For(i,3,1000)
        {
            double e = (2*PI)/i;
            if(chk(u,v,w,e))
            {
                put(i);
                break;
            }
        }
    }
    return 0;
}
