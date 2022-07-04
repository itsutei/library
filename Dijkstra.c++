template<typename T>
struct dijkstra{
  
  vector<vector<pair<T,int>>>G;
  
  dijkstra(int n) : G(n){}
  void add_edge(int from, int to, T v){
    G[from].push_back({v,to});
    //G[to].push_back({v,from});
  }
  vector<T> build(int s){
    const auto INF = numeric_limits< T >::max();
    priority_queue<pair<T,int>, vector<pair<T,int>>, greater<>> q;
    vector<T> d(G.size(),INF);
    q.push({0,s});
    d[s] = 0;
    while(!q.empty()){
      auto [p_cost,p_to] = q.top();
      q.pop();
      if(d[p_to]<p_cost) continue;
      for(auto [e_cost,e_to]:G[p_to]){
        if(d[e_to]<=e_cost+p_cost) continue;
        d[e_to] = e_cost+p_cost;
        q.push({d[e_to], e_to});
      }
    }
    for(auto &i:d) if(i==INF) i=-1;
    return d;
  }
};


template<typename T>auto dijkstra(vector<vector<pair<T,int>>>&G,int s){
  
  priority_queue<pair<T,int>, vector<pair<T,int>>, greater<>> q;
  const auto INF = numeric_limits< T >::max();
  vector<T> d(G.size(),INF);
  
  q.push({0,s});
  d[s] = 0;
  while(!q.empty()){
    auto [p_cost,p_to] = q.top();
    q.pop();
    if(d[p_to]<p_cost) continue;
    for(auto [e_cost,e_to]:G[p_to]){
      if(d[e_to]<=e_cost+p_cost) continue;
      d[e_to] = e_cost+p_cost;
      q.push({d[e_to], e_to});
    }
  }
  for(auto &i:d) if(i==INF) i=-1;
  return d;
}