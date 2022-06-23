// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minpq;
        
        vector<int> dist(V,INT_MAX);
        dist[S]=0;
        
        minpq.push({0,S});
        
        while(minpq.size()>0)
        {
            pair<int,int> Node=minpq.top();
            minpq.pop();
            int tonode=Node.first;
            int node=Node.second;
            
            
            for(auto it:adj[node])
            {
                if((tonode+it[1])<dist[it[0]])
                {
                    dist[it[0]]=tonode+it[1];
                    minpq.push({dist[it[0]],it[0]});
                }
            }
        }
        
        return dist;
        
    }
};


// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}

  // } Driver Code Ends