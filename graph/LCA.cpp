const int MAXN = 2e5 + 5;
const int lgN = 20;

int dep[MAXN], dp[MAXN][lgN];
vector<int> adj[MAXN];

void dfs(int u, int p, int d){
	dep[u] = d, dp[u][0] = p;
	for (auto v : adj[u]){
		if (v == p) continue;
		dfs(v, u, d + 1);
	}
}

int jump(int u, int d){
	for (int i = 0; i < lgN - 1; i++){
		if ((d >> i) & 1) u = dp[u][i];
	}
	return u;
}

void init_lca(){
	for (int j = 0; j < lgN - 1; j++)
		for (int i = 1; i <= N; i++){
			if (dp[i][j] == -1) dp[i][j + 1] = -1;
			else dp[i][j + 1] = dp[dp[i][j]][j];
		}
}

int lca(int u, int v){
	if (dep[u] > dep[v]) swap(u, v);
	v = jump(v, dep[v] - dep[u]);
	if (u == v) return u;
	for (int i = lgN - 1; i >= 0; i--){
		if (dp[u][i] != dp[v][i]){
			u = dp[u][i], v = dp[v][i];
		}
	}
	return dp[u][0];
}