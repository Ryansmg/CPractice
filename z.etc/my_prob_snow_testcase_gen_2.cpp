#include <bits/stdc++.h>
#define int long long
#define INF 1000000000000000000 // INF * INF > 2^63
#define inf 3000000000 // inf > 2^31, inf * inf < 2^63
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define filein freopen("C:/Users/ryans/Desktop/Coding/Baekjoon/input.txt", "r", stdin)
#define fileout freopen("C:/Users/ryans/Desktop/Coding/Baekjoon/output.txt", "w", stdout)
#define all(vec) (vec).begin(), (vec).end()
#define forn(name, val) for(int name = 0; name < val; name++)
using namespace std;
template <typename T> using v = vector<T>;
template <typename T> using v2 = v<v<T>>;
signed main() {
    random_device rd;
    mt19937 gen(rd());
    fastio; fileout;
    int L, n, m; cin >> L >> n >> m;
    cout << L << ' ' << n << ' ' << m << '\n';
    uniform_int_distribution dis(0LL, 100000LL),
    dis2(1LL, 100000LL), dis3(1LL, n);
    for(int i=0; i<n; i++) {
        int a = 1+dis(gen), b = L-dis(gen), t = dis2(gen);
        // a=1; b=L; t=100000; // 엣지케이스를 위한 세팅
        if(a>b) swap(a, b);
        cout << a << ' ' << b << ' ' << t << '\n';
    }
    for(int i=0; i<m; i++) {
        int a = 1+dis(gen), b = L-dis(gen);
        if(a>b) swap(a, b);
        cout << dis3(gen) << ' ' << a << ' ' << b << '\n';
    }
}
