// A C++ program to implement greedy algorithm for graph coloring
#include <iostream>
#include <list>
using namespace std;

// A class that represents an undirected graph
class Graph
{
	int V; // No. of vertices
	list<int> *adj; // A dynamic array of adjacency lists
public:
	// Constructor and destructor
	Graph(int V) { this->V = V; adj = new list<int>[V]; }
	~Graph()	 { delete [] adj; }

	// function to add an edge to graph
	void addEdge(int v, int w);

	// Prints greedy coloring of the vertices
	void greedyColoring();
};

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w);
	adj[w].push_back(v); // Note: the graph is undirected
}

// Assigns colors (starting from 0) to all vertices and prints
// the assignment of colors
void Graph::greedyColoring()
{
	int result[V];

	// Assign the first color to first vertex
	result[0] = 0;

	// Initialize remaining V-1 vertices as unassigned
	for (int u = 1; u < V; u++)
		result[u] = -1; // no color is assigned to u

	// A temporary array to store the available colors. True
	// value of available[cr] would mean that the color cr is
	// assigned to one of its adjacent vertices
	bool available[V];
	for (int cr = 1; cr < V; cr++)
		available[cr] = false;

	// Assign colors to remaining V-1 vertices
	for (int u = 1; u < V; u++)
	{
		// Process all adjacent vertices and flag their colors
		// as unavailable
		list<int>::iterator i;
		for (i = adj[u].begin(); i != adj[u].end(); ++i)
			if (result[*i] != -1)
				available[result[*i]] = true;

		// Find the first available color
		int cr;
		for (cr = 1; cr < V; cr++)
			if (available[cr] == false)
				break;

		result[u] = cr; // Assign the found color

		// Reset the values back to false for the next iteration
		for (i = adj[u].begin(); i != adj[u].end(); ++i)
			if (result[*i] != -1)
				available[result[*i]] = false;
	}

	// print the result
	for (int u = 1; u < V; u++)
		cout << "Vertex " << u << " ---> Color "
			<< result[u] << endl;
}

// Driver program to test above function
int main()
{
    //1=A , 2=B .... 20=T
    Graph g1(21);
    g1.addEdge(5, 6);
	g1.addEdge(5, 7);
	g1.addEdge(5, 15);
	
	g1.addEdge(2, 3);
	g1.addEdge(2, 4);
	g1.addEdge(2, 7);
	g1.addEdge(2, 13);
	g1.addEdge(2, 19);
	
	g1.addEdge(3, 8);
	g1.addEdge(3, 12);
	g1.addEdge(3, 18);
	g1.addEdge(3, 20);
	
	g1.addEdge(7, 9);
    

	g1.addEdge(1, 4);
	g1.addEdge(1, 5);
	g1.addEdge(1, 8);
	g1.addEdge(1, 11);
	g1.addEdge(1, 17);
	
	g1.addEdge(4, 13);
	g1.addEdge(4, 19);
	
	g1.addEdge(6, 7);
	g1.addEdge(6, 10);
	g1.addEdge(6, 17);
	g1.addEdge(6, 20);
	
	g1.addEdge(9, 11);
	g1.addEdge(9, 19);
	
	g1.addEdge(10, 14);
	g1.addEdge(10, 15);
	
	
	g1.addEdge(11, 10);
	
	g1.addEdge(8, 12);
	g1.addEdge(8, 17);
	g1.addEdge(8, 18);
	
	g1.addEdge(12, 16);
	g1.addEdge(12, 18);
	
	g1.addEdge(12, 15);
	
	g1.addEdge(14, 20);
	
	g1.addEdge(16, 19);
	g1.addEdge(16, 20);
	
	cout << "Coloring of graph  \n";
	g1.greedyColoring();


	return 0;
}
