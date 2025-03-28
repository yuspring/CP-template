const MAXN = 1e5+5;
int tmp[MAXN];

void merge_sort(int arr[ ], int l, int r){
    if (l == r) return;
    int m = (l + r) >> 1;
    merge_sort(arr, l, m);
    merge_sort(arr, m + 1, r);
    int rid = m + 1, idx = 0;
    for (int lid = l; lid <= m; lid++){
        while (rid <= r && arr[rid] < arr[lid]){
            tmp[idx++] = arr[rid++];
        }
        tmp[idx++] = arr[lid];
    }
    for (int i = l; i < rid; i++){
        arr[i] = tmp[i - l];
    } 
}
