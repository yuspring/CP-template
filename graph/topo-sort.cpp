queue<int> q;
for (int i=0; i<n; i++){
    //找出「入邊」(in-degree)為零的頂點
    if (in[i] == 0) q.push(i);
}

vector<int> ans;
while (!q.empty()){
    int now = q.front();
    q.pop();
    ans.push_back(now);
 
    //遍歷子任務
    for (auto nxt: g[now]){
        in[nxt]--;
        if (in[nxt] == 0) q.push(nxt);
    }
}