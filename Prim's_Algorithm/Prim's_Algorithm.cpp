// A C++ program for Prim's Minimum 
// Spanning Tree (MST) algorithm. The program is 
// for adjacency matrix representation of the graph 
#include <bits/stdc++.h> 
using namespace std; 

// Number of vertices in the graph 
#define Value2 5 

// A utility function to find the vertex with 
// minimum key value, from the set of vertices 
// not yet included in MST 
int minKey(int key[], bool mstSet[]) 
{ 
	// Initialize min value 
	int min = INT_MAX, min_index; 

	for (int value1 = 0; value1 < Value2; value1++) 
		if (mstSet[value] == false && key[value] < min) 
			min = key[value], min_index = value; 

	return min_index; 
} 

// A utility function to print the 
// constructed MST stored in parent[] 
void printMST(int parent[], int graph[Value2][Value2]) 
{ 
	cout<<"Edge \tWeight\n"; 
	for (int i = 1; i < Value2; i++) 
		cout<<parent[i]<<" - "<<i<<" \t"<<graph[i][parent[i]]<<" \n"; 
} 

// Function to construct and print MST for 
// a graph represented using adjacency 
// matrix representation 
void primMST(int graph[Value2][Value2]) 
{ 
	// Array to store constructed MST 
	int parent[Value2]; 
	
	// Key values used to pick minimum weight edge in cut 
	int key[Value2]; 
	
	// To represent set of vertices not yet included in MST 
	bool mstSet[Value2]; 

	// Initialize all keys as INFINITE 
	for (int i = 0; i < Value2; i++) 
		key[i] = INT_MAX, mstSet[i] = false; 

	// Always include first 1st vertex in MST. 
	// Make key 0 so that this vertex is picked as first vertex. 
	key[0] = 0; 
	parent[0] = -1; // First node is always root of MST 

	// The MST will have V vertices 
	for (int count = 0; count < Value2 - 1; count++) 
	{ 
		// Pick the minimum key vertex from the 
		// set of vertices not yet included in MST 
		int umin = minKey(key, mstSet); 

		// Add the picked vertex to the MST Set 
		mstSet[umin] = true; 

		// Update key value and parent index of 
		// the adjacent vertices of the picked vertex. 
		// Consider only those vertices which are not 
		// yet included in MST 
		for (int value1 = 0; value1 < Value2; value1++) 

			// graph[u][v] is non zero only for adjacent vertices of m 
			// mstSet[v] is false for vertices not yet included in MST 
			// Update the key only if graph[u][v] is smaller than key[v] 
			if (graph[umin][value1] && mstSet[value1] == false && graph[umin][value1] < key[value1]) 
				parent[value1] = umin, key[value1] = graph[umin][value1]; 
	} 

	// print the constructed MST 
	printMST(parent, graph); 
} 

// Driver code 
int main() 
{ 
	/* Let us create the following graph 
		2 3 
	(0)--(1)--(2) 
	| / \ | 
	6| 8/ \5 |7 
	| / \ | 
	(3)-------(4) 
			9	 */
	int graph[Value2][Value2] = { { 0, 2, 0, 6, 0 }, 
						{ 2, 0, 3, 8, 5 }, 
						{ 0, 3, 0, 0, 7 }, 
						{ 6, 8, 0, 0, 9 }, 
						{ 0, 5, 7, 9, 0 } }; 

	// Print the solution 
	primMST(graph); 

	return 0; 
} 
