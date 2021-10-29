/**
* This code is contributed by Guddu.
 */

package graph;

import java.util.ArrayList;

public class DirectedCycleDetection {

	public static void main(String[] args) {
		
		
		
		int V = 4; 
		ArrayList<ArrayList<Integer> > adj = new ArrayList<ArrayList<Integer>>(V); 
		
		for (int i = 0; i < V; i++) 
			adj.add(new ArrayList<Integer>()); 

			addEdge(adj, 0, 1);
			addEdge(adj, 1, 2);
			addEdge(adj, 2, 3);
			addEdge(adj, 3, 1);
        	
        	System.out.println(DFS(adj, V));

	}
	
	static void addEdge(ArrayList<ArrayList<Integer>> adj, int u, int v) 
	{ 
		adj.get(u).add(v); 
		 
	} 

	static boolean DFSRec(ArrayList<ArrayList<Integer>> adj,int s, boolean[] visited, boolean[] recSt) 
	{ 
    	visited[s]=true;
    	recSt[s]=true;		// recursion stack
        
        for(int u:adj.get(s)){
            if(visited[u]==false && DFSRec(adj,u,visited,recSt)==true)
                    {return true;}
            else if(recSt[u]==true)
                {return true;}
        }
        recSt[s]=false;
        return false;
	} 
	
	static boolean DFS(ArrayList<ArrayList<Integer>> adj, int V){
	    boolean[] visited=new boolean[V]; 
    	
    		
    	boolean[] recSt=new boolean[V]; // extra boolean array to store recursion stack.
    	
        for(int i=0;i<V;i++){
            if(visited[i]==false)
                if(DFSRec(adj,i,visited,recSt)==true)
                    return true;
        }
        return false;
	}
}
