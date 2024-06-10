#pragma region macros
#define USE_MACROS true
#define USE_INT false
#define USE_INT128 true
#define USE_DOUBLE false
#define GCC_OPTIMIZE_ENABLE false
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
lint LINTMAX = ((lint(1)<<126)-1)*2+1;
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

// 2733. Brainf*ck
// #implementation #stack #string

bool chkCmd(char c) {
    switch(c) {
        case '>':
        case '<':
        case '+':
        case '-':
        case '.':
        case '[':
        case ']':
            return true;
        default:
            return false;
    }
}

signed main() {
    fastio;
    int T = input();
    forf(pridx, 1, T) {
        cout << "PROGRAM #" << pridx << ":\n";
        v<char> cmd;
        while(true) {
            string s; getline(cin, s);
            if(s=="end") break;
             for(char c : s) {
                 if(c=='%') break;
                 if(!chkCmd(c)) continue;
                 cmd.push_back(c);
             }
        }
        stack<int> retSt;
        v<int> arr(32768, 0);
        int aptr = 0, cptr = 0, csz = (int) cmd.size();
        v<int> ret(csz, -1);
        stack<int> br;
        forn(i, csz) {
            if(cmd[i] == '[') {
                br.push(i);
            }
            else if(cmd[i] == ']') {
                if(br.empty()) {
                    cout << "COMPILE ERROR";
                    goto end;
                }
                ret[i] = br.top();
                ret[br.top()] = i;
                br.pop();
            }
        }
        if(!br.empty()) {
            cout << "COMPILE ERROR";
            goto end;
        }
        while(cptr != csz) {
            if(cmd[cptr] == '>') {
                aptr++;
                if(aptr==32768) aptr=0;
            }
            if(cmd[cptr] == '<') {
                aptr--;
                if(aptr==-1) aptr=32767;
            }
            if(cmd[cptr] == '+') {
                arr[aptr]++;
                if(arr[aptr]==256) arr[aptr]=0;
            }
            if(cmd[cptr]=='-') {
                arr[aptr]--;
                if(arr[aptr]==-1) arr[aptr]=255;
            }
            if(cmd[cptr]=='.') {
                cout << ((char)arr[aptr]);
            }
            if(cmd[cptr] == '[') {
                if(arr[aptr] == 0) {
                    assert(ret[cptr] != -1);
                    cptr = ret[cptr];
                }
            }
            if(cmd[cptr] == ']') {
                if(arr[aptr] != 0) {
                    assert(ret[cptr] != -1);
                    cptr = ret[cptr];
                }
            }
            cptr++;
        }
        end:
        cout << '\n';
    }
}
