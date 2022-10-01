#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

int main(){
	printf("Enter The Number Of nodes : ");
	int number_of_nodes;
	scanf("%d",&number_of_nodes);
	int edges;
	printf("Enter Number Of Edges : ");
	scanf("%d",&edges);
	int adjacency_matrix[edges+1][3];
	for(int i=0;i<edges;i++){
		int node_a,node_b,weight;
		printf("Enter node_a , node_b and weight between them : ");
		scanf("%d%d%d",&node_a,&node_b,&weight);
		adjacency_matrix[i][0] = node_a;
		adjacency_matrix[i][1] = node_b;
		adjacency_matrix[i][2] = weight;
	}
	int dist[number_of_nodes+1];
	for(int i=0;i<=number_of_nodes;i++)
		dist[i] = INT_MAX;


	// bellman_ford algo starts here
	dist[1] = 0;
	for (int i = 0; i < number_of_nodes - 1; i++) {
        for (int j = 0; j < edges; j++) {
            if (dist[adjacency_matrix[j][0]] != INT_MAX && dist[adjacency_matrix[j][0]] + adjacency_matrix[j][2] < dist[adjacency_matrix[j][1]])
                dist[adjacency_matrix[j][1]] = dist[adjacency_matrix[j][0]] + adjacency_matrix[j][2];
        }
    }
    for (int i = 0; i < edges; i++) {
        int x = adjacency_matrix[i][0];
        int y = adjacency_matrix[i][1];
        int weight = adjacency_matrix[i][2];
        if (dist[x] != INT_MAX && dist[x] + weight < dist[y]){
        	printf("The graph contains negative cycle !");
        	return 0;
        }
    }
	for(int i=1;i<=number_of_nodes;i++){
		printf("Distance Between 1 and %d : %d\n",i,dist[i]);
	}
	return 0;
}