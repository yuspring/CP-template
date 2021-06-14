const int lgN = 17 + 1, MAXN = 1e5;
int arr[MAXN];
int dp[lgN][MAXN];
int N;

void initST(){
    for (int i = 0; i < N; i++) dp[0][i] = arr[i];
    for (int i = 1; i < lgN; i++)
        for (int j = 0; j + (1 << i) <= N; j++)
            dp[i][j] = max(dp[i - 1][j], dp[i - 1][i + (1 << (j - 1))]);
}

int query(int l, int r){
    int k = __lg(r - l + 1);
    return max(dp[k][l], dp[k][r - (1 << k) + 1]);
}
