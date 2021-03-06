
vector<int> G[MAX],child;
int sum=0;
int dfs(int u,int par)
{	
	child[u] = 1;
	for(auto x : G[u])
	{
		if(x == par)continue;
		dfs(x,u);
		child[u] += child[x]; 
	}
	return 0;
}
int32_t main() {
    IOS;
    int n,m,u,v;
    cin >> n >> m;
    rep(i,0,m)
    {
    	cin >> u >> v;
    	G[u].pb(v);G[v].pb(u);
    }
    child.resize(n+1);
    dfs(1,0);
    rep(i,1,n+1)cout << child[i] << ' ';
    return 0;
}

//INPUT
//	  	    1
//	 	   / \
//		  2   3
//		 / \ 
//		4   5

//OUTPUT
// 5 3 1 1 1
