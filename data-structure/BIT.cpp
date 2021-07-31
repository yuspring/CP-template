int bit[N];

void update(int pos, int val){
    while (pos < N){
        bit[pos] += val;
        pos += pos & -pos;
    }
}

int query(int pos){
    int res = 0;
    while (pos){
        res += bit[pos];
        pos -= pos & -pos;
    }
    return res;
}