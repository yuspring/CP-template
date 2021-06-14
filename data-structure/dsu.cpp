const int MAXN = 1e6 + 5;
int boss[MAXN], rk[MAXN];
int N;

void initDSU(){
    for(int i = 0; i < N; i++) boss[i] = i, rk[i] = 1;
}

int find(int x){
	return (x == boss[x] ? x : boss[x] = find(boss[x]));
}

void unite(int x, int y){
	x = find(x), y = find(y);
	if (x == y) return;
	if (rk[x] > rk[y]) swap(x, y);
	boss[x] = y, rk[y] += rk[x];
}
