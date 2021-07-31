#include <bits/stdc++.h>
//#include <bits/extc++.h>

/*
by: yuspring
bobotou is cute!!
target: AC
*/

//#define int long long
#define bobotou ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pb push_back
#define eb emplace_back
#define pf push_front
#define pob pop_back
#define pof pop_front
#define sz(x) ((int)x.size())
#define iter(x) x.begin(), x.end()
#define niter(a,n) a, a+n
#define riter(x) x.rbegin(), x.rend()
#define mp(a,b) make_pair(a,b)
#define uni(a) a.resize(unique(iter(a)) - a.begin())
#define F first
#define S second
#define L idx<<1
#define R idx<<1|1
#define out(x) cout << x << '\n';
#define outs(x) cout << x << ' ';

using namespace std;
//using namespace __gnu_pbds;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<double, double>;

const ll INF = 0x3f3f3f3f;
const ll LINF = (ll)1 << 60;
const int mod = 1e9 + 7;

template<typename A, typename B>
ostream& operator<<(ostream& os, pair<A, B> p){
    return os << '(' << p.F << ',' << p.S << ')';
}

template<typename A>
ostream& operator<<(ostream& os, vector<A> p){
    for (auto it = p.begin(); it != p.end(); it++) os << *it << " \n"[it == p.end() - 1];
    return os;
}

template<typename A>
void printv(A arr, size_t N, size_t M){
    for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) cerr << *(*(arr + i) + j) << " \n"[j == M - 1];
}

/*------------------------------------------------------------------------*/


signed main(){
	bobotou;
	
	return 0;
}