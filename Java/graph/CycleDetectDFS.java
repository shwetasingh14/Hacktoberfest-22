/**
* This code is contributed by Guddu.
 */

package graph;

import java.util.ArrayList;

public class CycleDetectDFS {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		int V = 7; 
		ArrayList<ArrayList<Integer> > adj = new ArrayList<ArrayList<Integer>>(V); 
		
		for (int i = 0; i < V; i++) 
			adj.add(new ArrayList<Integer>()); 

			addEdge(adj,2,0); 
        	addEdge(adj,0,3); 
        	addEdge(adj,3,4); 
        	addEdge(adj,3,5); 
        	addEdge(adj,3,6);
//        	addEdge(adj,4,5);
        	addEdge(adj, 2, 1);
        	
        	System.out.println(cycleDetection(adj, V));

	}
	
	static void addEdge(ArrayList<ArrayList<Integer>> adj, int u, int v) 
	{ 
		adj.get(u).add(v); 
		adj.get(v).add(u); 
	} 
	
	
	static boolean cycleDetection(ArrayList<ArrayList<Integer>> adj, int V) {
		boolean visited[] = new boolean[V];
		
		for(int i=0; i<V; i++) {
			if(visited[i] == false) {
				if(DfsRec(adj, i, visited, -1) == true) return true;
			}
		}
		
		return false;
	}
	
	static boolean DfsRec(ArrayList<ArrayList<Integer>> adj, int s, boolean visited[], int parent) {
		visited[s] = true;
		
		for(int u: adj.get(s)) {
			if(visited[u] == false) {
				if(DfsRec(adj, u, visited, s) == true) return true;
			} else if(u != parent) {
				return true;
			}
		}
		
		return false;
	}
	

}
