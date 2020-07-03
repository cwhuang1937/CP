struct Bipartite_Graph_Matching{
	int mp[MAXN + 1], mq[MAXN + 1], n;
	bitset<MAXN + 1> vis;
	vector<int> child[MAXN + 1];
	void init(int _n){
		n = _n;
		for(int i = 1; i <= n; i++)
			child[i].clear();
	}
	void add_edge(int x, int y){
		child[x].push_back(y);
	}
	bool dfs(int x){
		vis[x] = 1;
		for(int i : child[x])
			if(!~mq[i] || !vis[mq[i]] && dfs(mq[i]))
				return mq[mp[x] = i] = x, 1;
		return 0;
	}
	int matching(){
		int ans = 0;
		memset(mp, -1, sizeof(mp)), memset(mq, -1, sizeof(mq));
		for(int i = 1; i <= n; i++)
			if(vis.reset(), dfs(i))
				ans++;
		return ans;
	} 
}; 
