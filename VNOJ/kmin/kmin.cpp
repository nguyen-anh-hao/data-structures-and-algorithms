// https://oj.vnoi.info/problem/kmin

#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

#define MOD 1000000007
#define INF 1e9

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef unsigned int ui;
typedef unsigned short us;
typedef unsigned char uc;

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pdd;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<pdd> vpdd;
typedef vector<ld> vld;

class BaseSolution {
public:
    virtual ~BaseSolution() {}
    virtual vi findKMinSums(vi& a, vi& b, int k) = 0;
};

class NaiveKMinSolution : public BaseSolution {
public:
    vi findKMinSums(vi& a, vi& b, int k) override {
        int m = a.size(), n = b.size();
        vi c(m * n);

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                c[i * n + j] = a[i] + b[j];
            }
        }

        sort(all(c));
        return vi(c.begin(), c.begin() + k);
    }
};

class OptimizedKMinSolution : public BaseSolution {
public:
    vi findKMinSums(vi& a, vi& b, int k) override {
        int m = a.size(), n = b.size();
        vi result(k);
        priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<pair<int, pii>>> pq;  // {sum, {x, y}}
        vector<vector<bool>> visited(m, vector<bool>(n, false));                             // visited[x][y]

        sort(all(a));
        sort(all(b));

        pq.push({a[0] + b[0], {0, 0}});
        visited[0][0] = true;

        for (int i = 0; i < k; ++i) {
            auto top = pq.top();
            pq.pop();
            result[i] = top.fi;

            int x = top.se.fi, y = top.se.se;

            if (x + 1 < m && !visited[x + 1][y]) {
                pq.push({a[x + 1] + b[y], {x + 1, y}});
                visited[x + 1][y] = true;
            }

            if (y + 1 < n && !visited[x][y + 1]) {
                pq.push({a[x] + b[y + 1], {x, y + 1}});
                visited[x][y + 1] = true;
            }
        }

        return result;
    }
};

void read_input(vi& a, vi& b, int& k) {
    int m, n;
    cin >> m >> n >> k;
    a.resize(m);
    b.resize(n);
    for (int& x : a) cin >> x;
    for (int& x : b) cin >> x;
}

void write_output(const vi& result) {
    for (const int& x : result) cout << x << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifndef ONLINE_JUDGE
    freopen("kmin.inp", "r", stdin);
    freopen("kmin.out", "w", stdout);
#endif

    vi a, b;
    int k;
    read_input(a, b, k);

    BaseSolution* solution = new OptimizedKMinSolution();
    vi result = solution->findKMinSums(a, b, k);

    write_output(result);

    delete solution;
    return 0;
}
