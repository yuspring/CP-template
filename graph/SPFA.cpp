const ll INF = 1 << 31 - 1;
int N;
vector<pii> adj[MAXN];

int SPFA(int s, int e){
    vector<int> dis(N, INF), cnt(N);
    vector<bool> inq(N);
    dis[s] = 0;
    queue<int> q;
    q.push(s);
    inq[s] = 1;
    
    while(!q.empty()){
        int v = q.front();
        q.pop();
        inq[v] = 0;
        for(pii p : adj[v]){
            if(dis[p.F] != INF || dis[v] + p.S > dis[p.F]) continue;
            cnt[p.F]++;
            if(cnt[p.F] >= N) return INF;
            d[p.F] = d[v] + p.S;
            if(!inq[p.F]){
                inq[p.F] = 1;
                q.push(p.F);
            }
        }        
    }
    return dis[e];
}