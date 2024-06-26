#pragma region macros
#define GCC_OPTIMIZE_ENABLE true

#include <bits/stdc++.h>
using namespace std;

#if GCC_OPTIMIZE_ENABLE
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#endif

#define int long long
#define double long double
#define cint const int &

#define llmax 9223372036854775807 // 2^63-1
#define INF 1000000000000000000 // INF * INF > 2^63
#define inf 3000000000 // inf > 2^31, inf * inf < 2^63
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define forn(name, val) for(int name = 0; name < val; name++)
#define forf(name, start, end) for(int name = start; name <= end; name++)

#define pass {cout << "";} // do nothing
#define filein freopen("C:/Users/ryans/Desktop/Coding/Baekjoon/input.txt", "r", stdin)
#define fileout freopen("C:/Users/ryans/Desktop/Coding/Baekjoon/output.txt", "w", stdout)

template <typename T> using v = vector<T>;
template <typename T> using v2 = v<v<T>>;
template <typename T> using pq = priority_queue<T>;
using ii = array<int, 2>;
using iii = array<int, 3>;

#ifndef int
#define intmax 2147483647
#else
#define intmax llmax
#endif

#pragma region lint
#define lint __int128
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
#pragma endregion

template <typename T = int> T input() {T t; cin >> t; return t;}

#define all(vec) (vec).begin(), (vec).end()
template <typename T> void compress(v<T> &v, const bool &autosort=true) { if(autosort) sort(all(v)); v.erase(unique(all(v)), v.end()); }
template <typename T> T idx(const T &val, const v<T> &compressed) { return lower_bound(all(compressed), val) - compressed.begin(); }

template <typename T> T pow_(T a, T b) { return pow_(a, b, intmax); }
template <typename T> T pow_(T a, T b, T mod) { a%=mod;T ans=1;while(b){if(b&1)ans=ans*a%mod;b>>=1;a=a*a%mod;} return ans; }
template <typename T> T gcd_(T a, T b) { if(a<b) swap(a, b); while(b) { T r = a % b; a = b; b = r; } return a; }
#pragma endregion

// 18246. 색종이와 쿼리
// #multi_segtree #prefix_sum

class segtree {
public:
    vector<int> tree;
    int n;
    explicit segtree(int treeSize) {
        tree = v<int>(4*treeSize, 0);
        n = treeSize;
    }
    explicit segtree(const v<int> &a) : segtree((int) a.size()) {
        init(a, 1, 1, n);
    }
    segtree(const v<int> &a, int treeSize) : segtree(treeSize) {
        init(a, 1, 1, n);
        assert(a.size() == treeSize);
    }
    void update(int tar, int diff) { update(tar, tar, diff); }
    static int findNode(int start, int end, cint tar, int node) {
        if(start==end) { return node; }
        if(tar<=(start+end)/2) return findNode(start, (start+end)/2, tar, node*2);
        return findNode((start+end)/2+1, end, tar, node*2+1);
    }
    int query(int tar) { return query(tar, tar); }
    int query(int left, int right) { return query(1, left, right, 1, n); }
protected:
    void update(int left, int right, int diff) { update(1, left, right, 1, n, diff); }
    void init(const v<int> &a, int node, int start, int end) {
        if(start==end) {
            tree[node] = a[start-1];
        } else {
            init(a, node*2, start, (start+end)/2);
            init(a, node*2+1, (start+end)/2+1, end);
            tree[node] = max(tree[node*2],  tree[node*2+1]);
        }
    }
    void update(int node, int left, int right, int start, int end, int diff) {
        if(end<left || right < start) return;
        if(left <= start && end <= right) {
            tree[node] = diff;
            return;
        }
        update(node*2, left, right, start, (start+end)/2, diff);
        update(node*2+1, left, right, (start+end)/2+1, end, diff);
        tree[node] = max(tree[node*2],  tree[node*2+1]);
    }
    int query(int node, int left, int right, int start, int end) {
        if(right < start || end < left) return {};
        if(left <= start && end <= right) return tree[node];
        return max(query(node*2, left, right, start, (start+end)/2),
               query(node*2+1, left, right, (start+end)/2+1, end));
    }
};
// [y][x]
class seg2d {
public:
    v<segtree> trees; int yn, xn;
    //Cnt : y, Size : x
    seg2d(cint treeCnt, cint treeSize) {
        trees = v<segtree>(treeCnt*4, segtree(treeSize));
        yn = treeCnt, xn = treeSize;
    }
    seg2d(cint treeCnt, cint treeSize, const v2<int> &arr) {
        trees = v<segtree>(treeCnt*4, segtree(treeSize));
        yn = treeCnt, xn = treeSize;
        init(1, 1, yn, arr, (int) arr[0].size());
    }
    /// 1<=x1<=treeSize, 1<=y1<=treeCnt
    void update(cint x, cint y, cint val) {
        update(1, 1, yn, x, y, val, segtree::findNode(1, xn, x, 1));
    }
    /// 1<=x1<=treeSize, 1<=y1<=treeCnt
    int query(cint x1, cint x2, cint y1, cint y2) {
        return query(1, 1, yn, x1, x2, y1, y2);
    }
    segtree* query_tree(int y) {
        return query_tree(1, 1, yn, y);
    }
private:
    segtree* query_tree(int node, int start, int end, cint y) {
        if(start==end) return &trees[node];
        if(y<=(start+end)/2) return query_tree(node*2, start, (start+end)/2, y);
        else return query_tree(node*2+1, (start+end)/2+1, end, y);
    }
    void init(int node, int start, int end, const v2<int> &arr, cint sz) {
        if(start==end) {
            trees[node] = segtree(arr[start-1], sz);
            return;
        }
        init(node*2, start, (start+end)/2, arr, sz);
        init(node*2+1, (start+end)/2+1, end, arr, sz);
        int ts = (int) trees[node].tree.size();
        forn(i, ts) trees[node].tree[i] = max(trees[node*2].tree[i], trees[node*2+1].tree[i]);
    }
    void update(int node, int start, int end, cint x, cint y, cint val, cint t) {
        if(y < start || end < y) return;
        if(start==end) {
            trees[node].update(x, val);
            return;
        }
        update(node*2, start, (start+end)/2, x, y, val, t);
        update(node*2+1, (start+end)/2+1, end, x, y, val, t);
        trees[node].update(x, max(trees[node*2].tree[t], trees[node*2+1].tree[t]));
    }
    int query(int node, cint start, cint end, cint x1, cint x2, cint y1, cint y2) {
        if(end<y1 || y2<start) return 0;
        if(y1 <= start && end <= y2) return trees[node].query(x1, x2);
        return max(query(node*2, start, (start+end)/2, x1, x2, y1, y2),
            query(node*2+1, (start+end)/2+1, end, x1, x2, y1, y2));
    }
};

signed main() {
    fastio;
    int n, m; cin >> n >> m;
    v2<int> arr(1510, v<int>(1510, 0));
    forn(i, n) {
        int y1, x1, y2, x2;
        cin >> y1 >> x1 >> y2 >> x2;
        y2--; x2--;
        arr[y1][x1]++;
        arr[y1][x2+1]--;
        arr[y2+1][x1]--;
        arr[y2+1][x2+1]++;
    }
    forf(i, 0, 1509) forf(j, 1, 1509)
        arr[i][j] += arr[i][j-1];
    forf(i, 0, 1509) forf(j, 1, 1509)
        arr[j][i] += arr[j-1][i];
    pass

    seg2d seg(1510, 1510, arr);
    forn(i, m) {
        int y1, x1, y2, x2;
        cin >> y1 >> x1 >> y2 >> x2;
        cout << seg.query(x1+1, x2, y1+1, y2) << '\n';
    }
}
