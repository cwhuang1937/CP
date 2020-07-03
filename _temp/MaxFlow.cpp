struct MaxFlow{
	struct edge{
		int to, cap, flow, rev;
	};
	vector<edge> v[MAXN];
	int s, t, dis[MAXN], cur[MAXN];
	int dfs(int u, int cap){
		if(u == t || !cap)
			return cap;
		for(int &i = cur[u]; i < v[u].size(); i++){
			edge &e = v[u][i];
			if(dis[e.to] == dis[u] + 1 && e.flow != e.cap){
				int df = dfs(e.to, min(e.cap - e.flow, cap));
				if(df){
					e.flow += df;
					v[e.to][e.rev].flow -= df;
					return df;
				}
			}
		}
		dis[u] = -1;
		return 0;
	}
	bool bfs(){
		memset(dis, -1, sizeof(dis));
		queue<int> q;
		q.push(s), dis[s] = 0;
		while(!q.empty()){
			int tmp = q.front();
			q.pop();
			for(auto &u : v[tmp]){
				if(!~dis[u.to] && u.flow != u.cap){
					q.push(u.to);
					dis[u.to] = dis[tmp] + 1;
				}
			}
		}
		return dis[t] != -1;
	}
	int maxflow(int _s, int _t){
		s = _s, t = _t;
		int flow = 0, df;
		while(bfs()){
			memset(cur, 0, sizeof(cur));
			while(df = dfs(s, INF)){
				flow += df;
			}
		}
		return flow;
	}
	void addedge(int st, int ed, int cap){
		v[st].push_back(edge{ed, cap, 0, v[ed].size()});
		v[ed].push_back(edge{st, 0, 0, v[st].size() - 1});
	}
};