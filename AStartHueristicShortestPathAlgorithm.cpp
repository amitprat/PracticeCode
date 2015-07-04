struct Node
{
    int u;
    int gscore;
    int hscore;

    Node(u,pos,gscore,hscore):u(u),gscore(gscore),hscore(hscore){}
};
class Minheap
{
    Node *n;
    int *pos;
    int V;
public:
    Minheap(Graph g,int src)
    {
        V = g.V;
        n = new Node[V];
        pos = new int[V];
        for(int i=0;i<V;i++) {
            n[i] = Node(i,INT_MAX,INT_MAX);
            pos[i] = i;
        }
        n[src] = Node(src,src,0, hueristic(src,dst));
        heapify(n,0)
    }
    void heapify(Node n[],int i)
    {
        int l = LEFT(i);
        int r = RIGHT(i);
        if(n[i].fscore > n[l].fscore)
            m = l;
        if(n[m].fscore > n[r].fscore)
            m = r;
        if(i != m)
        {
            swap(pos[n[i].u],pos[n[m].u]);
            swap(n[i],n[m]);
            heapify(n,m);
        }
    }
    void decreaseKey(int u,int v,int dist,int goal)
    {
        int pos = pos[v];
        int fscore = dist + hueristic(v,goal);
        n[pos].gscore = dist;
        n[pos].fscore = fscore;

        while(pos && n[parent(pos)].fscore < n[pos].fscore) {
            swap(n[parent(pos)],n[pos]);
            pos = parent(pos);
        }
    }
};
void findGoal( Graph g, int src, int dst )
{
    int dist[g.V];
    for(int i=0;i<g.V;i++)  dist[i] = INT_MAX;
    dist[src] = 0;
    Minheap h(g,src);
    unordered_map<int,int> table;
    unordered_map<int,bool> marker;

    while(h.empty())
    {
        Node n = h.extractMin();
        if(n.u == dst)
            return constructedPath(table,src,dst);
        marker[n.u] = true;
        for(auto v : g.adj[n.u])
        {
            if(marker[v.dst])   continue;

            if(dist[u] != INT_MAX && dist[v.dst] > dist[u] + v.dist ) {
                table[v] = u;
                dist[v.dst] =  dist[u] + v.dist;
                h.decreaseKey(u,v.dst,dist[v.dst],dst);
            }
        }
    }
}
