int N, block[MAXN];
//build
for (int i = 0;i < N;i++){
    block[i / k] = 1; //val
}

//query
for (int i = l;i <= r;i++){
    if (i / k != l / k) break;
    //query left
}
for (int i = r;i >= l;i--){
    if (i / k != r / k) break;
    //query right
}
for (int i = l / k + 1;i < r / k;i++){
    //query all
}
//單點修改
void modify(int i, int x){
    arr[i] += x;
    block[i / k] += x;
}
//區間修改
void modify(int l, int r, int x){
    for (int i = l / k + 1;i < r / k;i++){
        block[i] += k * x, lz_tag[i] += x;
    }
    for (int i = l;i <= r;i++){
        if (i / k != l / k) break;
        a[i] += x;
    }
    if (l / k == r / k) return;
    for (int i = r;i >= l;i--){
        if (i / k != r / k) break;
        a[i] += x;
    }
}

int query(int l, int r){
    int ans = INT_MAX;
    if (lz_tag[l / k]){
        for (int i = (l / k) * k; i < (l / k + 1) * k;i++){
            a[i] += lz_tag[l / k];
        }
        lz_tag[l / k] = 0;
    }
    if (lz_tag[r / k]){
        for (int i = (r / k) * k; i < (r / k + 1) * k;i++){
            a[i] += lz_tag[r / k];
        }
        lz_tag[r / k] = 0;
    }
    for (int i = l;i <= r;i++){
        if (i / k != l / k) break;
        ans = min(ans, a[i]);
    }
    for (int i = r;i >= l;i--){
        if (i / k != r / k) break;
        ans = min(ans, a[i]);
    }
    for (int i = l / k + 1;i < r / k;i++) ans = min(ans, block[i]);
    return ans;
}