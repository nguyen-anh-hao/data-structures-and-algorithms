// https://oj.vnoi.info/problem/pvhpassword

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
    virtual int evaluatePassword(string s, int x) = 0;
};

class PVHPasswordSolution : public BaseSolution {
public:
    int evaluatePassword(string s, int x) override {
        int evaluate[128] = {};
        evaluate['a'] = x;

        for (int i = 'b'; i <= 'z'; ++i) {
            if (i == 'z' - x + 1)
                continue;
            evaluate[i] = evaluate[i - 1] + 1;
        }

        int result = 0;
        for (char c : s) {
            result += evaluate[c];
        }

        return result;
    }
};

void read_input(string& s, int& x) {
    cin >> s >> x;
}

void write_output(int result) {
    cout << result << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

#ifndef ONLINE_JUDGE
    freopen("pvhpassword.inp", "r", stdin);
    freopen("pvhpassword.out", "w", stdout);
#endif

    BaseSolution* solution = new PVHPasswordSolution();

    string s;
    int x;
    read_input(s, x);

    int result = solution->evaluatePassword(s, x);
    write_output(result);

    delete solution;
    return 0;
}