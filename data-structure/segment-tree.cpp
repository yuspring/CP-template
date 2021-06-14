const int MAXN = 1e5 + 5;

int arr[MAXN], tr[MAXN << 2], tag[MAXN << 2];

#define L idx<<1
#define R idx<<1|1

int pull(int a, int b){
	return max(a, b);
}

void build(int idx, int l, int r){
	if (l == r) tr[idx] = arr[l];
	else{
		int m = (l + r) >> 1;
		build(L, l, m);
		build(R, m + 1, r);
		tr[idx] = pull(tr[L], tr[R]);
	}
}

void push(int idx){
	if (tag[idx]){
		tr[L] = max(tr[L], tag[idx]);
		tr[R] = max(tr[R], tag[idx]);
		tag[L] = max(tag[L], tag[idx]);
		tag[R] = max(tag[R], tag[idx]);
		tag[idx] = 0;
	}
}

void modify(int idx, int val, int ql, int qr, int l, int r){
	if (l != r) push(idx);
	if (ql <= l && r <= qr){
		tr[idx] = max(tr[idx], val);
		tag[idx] = max(tag[idx], val);
		return;
	}
	int m = (l + r) >> 1;
	if (qr > m) modify(R, val, ql, qr, m + 1, r);
	if (ql <= m) modify(L, val, ql, qr, l, m);
	tr[idx] = pull(tr[L], tr[R]);
}

int query(int idx, int ql, int qr, int l, int r){
	if (l != r) push(idx);
	if (ql <= l && r <= qr) return tr[idx];
	int m = (l + r) >> 1;
	if (ql > m)  return query(R, ql, qr, m + 1, r);
	if (qr <= m) return query(L, ql, qr, l, m);
	return pull(query(L, ql, qr, l, m), query(R, ql, qr, m + 1, r));
}
