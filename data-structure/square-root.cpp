int N, block[MAXN], tag[MAXN], arr[MAXN];
int k = sqrt(N);

void build(){
    for (int i = 0;i < N;i++){
        block[i / k] = 1;
    }
}

void modify(int i, int x){
    arr[i] += x;
    block[i / k] += x;
}

int query(int l, int r){
    int ans = INF;
    for (int i = l;i <= r;i++){
        if (i / k != l / k) break;
        ans = min(ans, arr[i]);
    }
    for (int i = r;i >= l;i--){
        if (i / k != r / k) break;
        ans = min(ans, arr[i]);
    }
    for (int i = l / k + 1;i < r / k;i++) ans = min(ans, block[i]);
    return ans;
}

void range_modify(int l, int r, int x){
    for (int i = l / k + 1;i < r / k;i++){
        block[i] += k * x, tag[i] += x;
    }
    for (int i = l;i <= r;i++){
        if (i / k != l / k) break;
        arr[i] += x;
    }
    if (l / k == r / k) return;
    for (int i = r;i >= l;i--){
        if (i / k != r / k) break;
        arr[i] += x;
    }
}

int range_query(int l, int r){
    int ans = INF;
    if (tag[l / k]){
        for (int i = (l / k) * k; i < (l / k + 1) * k;i++){
            arr[i] += tag[l / k];
        }
        tag[l / k] = 0;
    }
    if (tag[r / k]){
        for (int i = (r / k) * k; i < (r / k + 1) * k;i++){
            arr[i] += tag[r / k];
        }
        tag[r / k] = 0;
    }
    for (int i = l;i <= r;i++){
        if (i / k != l / k) break;
        ans = min(ans, arr[i]);
    }
    for (int i = r;i >= l;i--){
        if (i / k != r / k) break;
        ans = min(ans, arr[i]);
    }
    for (int i = l / k + 1;i < r / k;i++) ans = min(ans, block[i]);
    return ans;
}