#define USE_MACROS true
#define USE_INT false
#define USE_INT128 true
#define USE_DOUBLE false
#define GCC_OPTIMIZE_ENABLE true
#pragma region macros
#if USE_MACROS
#include <bits/stdc++.h>
#if GCC_OPTIMIZE_ENABLE
// #pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#endif
#if !USE_INT
#define int long long // set USE_INT to true to disable
#endif
#if !USE_DOUBLE
#define double long double // set USE_DOUBLE to true to disable
#endif
#define llmax 9223372036854775807 // 2^63-1
#if USE_INT
#define intmax 2147483647
#else
#define intmax llmax
#endif
#define INF 1000000000000000000 // INF * INF > 2^63
#define inf 3000000000 // inf > 2^31, inf * inf < 2^63
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr) // enables fast input/output
#define filein freopen("C:/Users/ryans/Desktop/Coding/Baekjoon/input.txt", "r", stdin) // stdin <- Coding/Baekjoon/input.txt
#define fileout freopen("C:/Users/ryans/Desktop/Coding/Baekjoon/output.txt", "w", stdout) // stdout <- Coding/Baekjoon/output.txt
#define all(vec) (vec).begin(), (vec).end()
#define forn(name, val) for(int name = 0; name < val; name++)
#define forf(name, start, end) for(int name = start; name <= end; name++)
#define pass print("") // do nothing

using namespace std;
template <typename T> using v = vector<T>;
template <typename T> using v2 = v<v<T>>;
template <typename T> using pq = priority_queue<T>;
using ii = array<int, 2>;
using iii = array<int, 3>;

#if USE_INT128
#define lint __int128 // to disable lint, set USE_INT128 to false
#define ll long long
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winteger-overflow"
lint LINTMAX = (lint(1)<<127)-1;
#pragma clang diagnostic pop
string lint2str(const lint &i) {string ret,bs;if(i==-LINTMAX-1)return lint2str(i/10)+"8";if(!i)return "0";if(i<0)return "-"+lint2str(-i);
	lint t=1; forn(as, 18)t*=10;lint a=i/(t*t);if(a){ret += to_string((ll) a);bs = to_string((ll) (i / t % (t * 10) + t));
		forn(j, 18) ret += bs[j + 1];bs = to_string((ll) ((i % t) + t));forn(j, 18) ret += bs[j + 1];
	} else {lint b = i / t % (t * 10);if (b) {ret += to_string((ll) b);bs = to_string((ll) ((i % t) + t));
			forn(j, 18) ret += bs[j + 1];} else { ret += to_string((ll) (i % t)); }}return ret;}
istream &operator>>(istream &in, lint &l) {string s;in>>s;lint t=l=0,size=s.size(),k=1;if(s[0]=='-')t=1;
	for(lint i=size-1;i>=t;i--){if(!t)l+=(s[i]-'0')*k;else l-=(s[i]-'0')*k;k*=10;}return in;}
ostream &operator<<(ostream &out,const lint &i){ out << lint2str(i); return out; }
#endif

template <typename T> void compress(v<T> &v, const bool &autosort=true) { if(autosort) sort(all(v)); v.erase(unique(all(v)), v.end()); }
template <typename T> T idx(const T &val, const v<T> &compressed) { return lower_bound(all(compressed), val) - compressed.begin(); }
template <typename T> T input() {T t; cin >> t; return t;} // explicit type, input<TYPE>()
int input() { int t; cin >> t; return t;} // default type : int
template <typename T> void print(const T &i, const string& end="") { cout << i << end; }
template <typename T> T pow_(T a, T b) { return pow_(a, b, intmax); }
template <typename T> T pow_(T a, T b, T mod) { a%=mod;T ans=1;while(b){if(b&1)ans=ans*a%mod;b>>=1;a=a*a%mod;} return ans; }
template <typename T> T gcd_(T a, T b) { if(a<b) swap(a, b); while(b) { T r = a % b; a = b; b = r; } return a; }
#endif
#pragma endregion

// 8462. 배열의 힘
// #mo

struct query {
    ll i, j, order;
    query()=default;
    query(ll a, ll b, ll c) {
        i = a; j = b; order = c;
    }
};

ll sqrtsize; //sqrt(쿼리의 개수)

bool cmp(query a, query b) {
    if(a.i/sqrtsize == b.i/sqrtsize) {
        return a.j < b.j;
    } else return a.i/sqrtsize < b.i/sqrtsize;
}

signed main() {
    fastio;
    int n, t; cin >> n >> t;
    sqrtsize = (int) sqrt(n);

    vector<int> a(1,1);
    int maxa = -1;
    for(int i=0; i<n; i++) {
        int asdf; cin >> asdf; a.push_back(asdf);
        maxa = max(maxa, asdf);
    }
    vector<query> queries;
    for(int i=0; i<t; i++) {
        int b, c;
        cin >> b >> c;
        queries.emplace_back(b, c, i);
    }
    sort(queries.begin(), queries.end(), cmp);
    vector<int> cnt(maxa+1, 0);
    int ansnow = 0;
    vector<int> ans(t);
    int l = queries[0].i, r = queries[0].j;
    for(int i=l; i<=r; i++) {
        ansnow -= cnt[a[i]] * cnt[a[i]] * a[i];
        cnt[a[i]]++;
        ansnow += cnt[a[i]] * cnt[a[i]] * a[i];
    }
    ans[queries[0].order] = ansnow;
    for(int i=1; i<t; i++) {
        int nl = queries[i].i;
        int nr = queries[i].j;
        while(l < nl) {
            ansnow -= cnt[a[l]] * cnt[a[l]] * a[l];
            cnt[a[l]]--;
            ansnow += cnt[a[l]] * cnt[a[l]] * a[l];
            l++;
        }
        while(nl < l) {
            l--;
            ansnow -= cnt[a[l]] * cnt[a[l]] * a[l];
            cnt[a[l]]++;
            ansnow += cnt[a[l]] * cnt[a[l]] * a[l];
        }
        while(r < nr) {
            r++;
            ansnow -= cnt[a[r]] * cnt[a[r]] * a[r];
            cnt[a[r]]++;
            ansnow += cnt[a[r]] * cnt[a[r]] * a[r];
        }
        while(nr < r) {
            ansnow -= cnt[a[r]] * cnt[a[r]] * a[r];
            cnt[a[r]]--;
            ansnow += cnt[a[r]] * cnt[a[r]] * a[r];
            r--;
        }
        ans[queries[i].order] = ansnow;
    }
    for(int i : ans) cout << i << "\n";
}
