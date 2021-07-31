int boss[N], rk[N];

int find(int x){
	return (x == boss[x] ? x : boss[x] = find(boss[x]));
}

void unite(int x, int y){
	x = find(x), y = find(y);
	if (x == y) return;
	if (rk[x] > rk[y]) swap(x, y);
	boss[x] = y, rk[y] += rk[x];
}
