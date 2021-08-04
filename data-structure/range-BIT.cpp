const int N = 5e5 + 5;
int bit1[N], bit2[N];

// [l,r] 
void modify2(int l, int r, int val){
    modify(bit1, l, val * (-l));
    modify(bit2, l, val);
    modify(bit1, r + 1, val * (r + 1));
    modify(bit2, r + 1, val * (-1));
    return;
}

// [l,r]
int query2(int l, int r){
    int res = 0;
    res += query(bit1, r + 1) + query(bit2, r + 1) * (r + 1);
    res += -query(bit1, l) - query(bit2, l) * (l);
    return res;
}