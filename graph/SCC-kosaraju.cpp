const int N = 1e6 + 5;
vector<int> adj[N], adj2[N];
int vis[N], scc[N], id;
stack<int,vector<int>> st;

void dfs1(int u){
    vis[u] = true;
    for (auto v : adj[u]){
        if (!vis[v]) dfs1(v);
    }
    st.push(u);
}

void dfs2(int u){
    scc[u] = id;
    for (auto v : adj2[u]){
        if (!scc[v]) dfs2(v);
    }
}

