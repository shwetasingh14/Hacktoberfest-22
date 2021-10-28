/**
* This code is contributed by Guddu.
 */

package graph;

import java.util.ArrayList;

public class DfsOfGraph {
	
	public static void main(String[] args) {
		

		int V = 7; 
		ArrayList<ArrayList<Integer> > adj = new ArrayList<ArrayList<Integer>>(V); 
		
		for (int i = 0; i < V; i++) 
			adj.add(new ArrayList<Integer>()); 

			addEdge(adj,0,1); 
        	addEdge(adj,0,2); 
        	addEdge(adj,2,3); 
        	addEdge(adj,1,3); 
        	addEdge(adj,4,5);
        	addEdge(adj,5,6);
        	addEdge(adj,4,6);
        	
        	DFS(adj, V, 0);
	}
	
	static void addEdge(ArrayList<ArrayList<Integer>> adj, int u, int v) 
	{ 
		adj.get(u).add(v); 
		adj.get(v).add(u); 
	} 
	
	static void DFSRec(ArrayList<ArrayList<Integer>> adj,int s, boolean[] visited) 
	{ 
    	visited[s]=true;
        System.out.print(s +" ");
        
        for(int u:adj.get(s)){
            if(visited[u]==false)
                DFSRec(adj,u,visited);
        } 
	} 
	
	
	
	static void DFS(ArrayList<ArrayList<Integer>> adj, int V, int s){
	    boolean[] visited=new boolean[V]; 
    		
	    for(int i=0; i<V; i++) {
	    	if(visited[i] == false) {
	    		DFSRec(adj,s,visited);
	    	}
	    }
        
	}
	
	

	// count the number of component of disconnected graph
	static int DFScount(ArrayList<ArrayList<Integer>> adj, int V, int s) {
		boolean[] visited = new boolean[V];
		int count = 0;
		
		for(int i=0; i<V; i++) {
			if(visited[i] == false) {
				DFSRec(adj, s, visited);
				count++;
			}
		}
		return count;
	}
	


}
