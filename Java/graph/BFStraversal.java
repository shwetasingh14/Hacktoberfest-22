/**
* This code is contributed by Guddu.
 */

package graph;

import java.util.ArrayList;
import java.util.*;

public class BFStraversal {

	public static void main(String[] args) {
		
		int V = 5; 
		ArrayList<ArrayList<Integer> > adj = new ArrayList<ArrayList<Integer>>(V); 
		
		for (int i = 0; i < V; i++) 
			adj.add(new ArrayList<Integer>()); 
	
		addEdge(adj,0,1); 
    	addEdge(adj,0,2); 
    	addEdge(adj,1,2); 
    	addEdge(adj,2,3); 
    	addEdge(adj,1,3);
    	addEdge(adj,3,4);
    	addEdge(adj,2,4);
		
		System.out.println("Following is Breadth First Traversal: "); 
	    ArrayList<Integer> f = BFS(adj,V,4);

	    for(Object it: f) {
	    	System.out.print(it+ " ");
	    }
	}
	
	
	// create graph data structure.
	static void addEdge(ArrayList<ArrayList<Integer>> adj, int u, int v) {
		adj.get(u).add(v);
		adj.get(v).add(u);
	}
	
	// bfs -- breadth first search this is valid only for single component graph/continuous graph
	static ArrayList<Integer> BFS(ArrayList<ArrayList<Integer>> adj,int V,int s) 
	{ 
		boolean[] visited=new boolean[V]; // create boolean array for each vertex.
    	ArrayList<Integer> bfsTraversalList = new ArrayList<Integer>();
    	
    
		
    
    	Queue<Integer> q=new LinkedList<>();	// to store the visited vertex
    	
    	visited[s] = true; 
    	q.add(s); 
    
    	while(q.isEmpty()==false) 
    	{ 
    		int u = q.poll(); 		// take the first input in queue.
//    		System.out.print(u + " "); 
    		bfsTraversalList.add(u);
    		 
    		for(int v:adj.get(u)){		//for each loop 
    		    if(visited[v]==false){
    		        visited[v]=true;
    		        q.add(v);
    		    }
    		} 
    	} 
    	
    	return bfsTraversalList;
	} 
	
	
	

		

}
