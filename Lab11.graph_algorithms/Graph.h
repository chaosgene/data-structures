#ifndef GRAPH
#define GRAPH
#include <string>
#include <iostream>
#include <vector>
#include <list>

//This class will be used to create a graph library.
/**
    Whenever paths are to be printed, they should be printed with 
	    v1 -> v2 -> v3 -> ...
    where v1, v2, and v3 are replaced with the names of the vertex.

    Whenever trees are to be printed, they should be printed with
	    {V, E} 
    where V is the set of vertices, and E is the set of edges 
    (note: V and E are sets and should be enclosed in brackets)
**/
class Graph {
	/**
		Followed an edge-list implementation.		
	*/
	public:
		/**
		Since Vertex refers to EdgeNode and EdgeNode refers to a vertex,
		forward declare EdgeNode.
		*/
		struct EdgeNode; 
		
        struct Vertex {
    		// Data members
			std::string name;
			float value; 
			// Pointer to a linked list of neighbors
			EdgeNode * edge; // List will be unordered
			unsigned int id;
			// Constructor for vertex
			Vertex(std::string name, float val, int id) {
				this->name = name;
				value = val;
				edge = nullptr;
				this->id = id;
			}
		};
        
		struct EdgeNode {
			// Vertices represented by references
			Vertex * leftVertex;
			Vertex * rightVertex;
			// Additional data member - an unsigned weight
			float weight;	
			// max two possible pointers
			EdgeNode * nextLeft;
			EdgeNode * nextRight;
			// Constructor for edgenode
			EdgeNode(Vertex * ver1, Vertex * ver2, float weight) {
				this->weight = weight;
				leftVertex = ver1;
				rightVertex = ver2;
			}
            bool operator==(const EdgeNode & other) const;
		};

	private:
		//Put your private data members here
		// count of vertices to be incremented w/ ea. addVertex()
		int numVertices;
		// count of edges to be incremented w/ ea. addEdge()
		int numEdges; // ct. of edges
		// keep a collection of vertices in a vector
		std::vector<Vertex *> vertices; // to be accessed by index	
		// keep a collection of pointers to each edge in a vector
		std::list<EdgeNode *> edges;
		//Put your private methods here
		// Connect two vertices
        	void connect(std::vector<Vertex *>::iterator it,
                	std::vector<Vertex *>::iterator it2, float weight);
        	// Check if string is valid as first line of input file
        	bool isValidFirstLine(const std::string &line);
        	// Check if string is valid as line representing a vertex of input file
        	bool isValidVertexLine(const std::string &line);
        	// Check if string is valid as line representing edge of input file
        	bool isValidEdgeLine(const std::string &line);
        	// Check if graph is connected
        	bool isConnected();
        	// Trim
        	void trim(std::string &vertexName);
        	// Deepen
        	void deepen(Vertex * v, float & deviance, const float TARGET, 
                        	float & devianceThreshold,
                        	std::list<std::list<Vertex *>> &paths);
        	// Deepen recursive 
        	bool deepenAux(std::list<std::list<Vertex *>> & paths,
                        	std::vector<bool> & visited,
                        	Vertex * v,
                        	float & newDeviance,
                        	const float & oldDeviance,
                        	float currentSum,
                        	std::list<Vertex *> & currentPath,
                        	const float & TARGET,
                        	float & devianceTreshold);
	public:
		//Construct
		Graph();
		//Delete
		~Graph();
        //Clear
        void clear();
		//Read A Graph From A File
		void readFromFile(std::string file);
		//Write A Graph To A File
		void writeToFile(std::string file);
		//Empty
		bool empty() const;
		//Add Edge
		void addEdge(std::string v1, std::string v2, int weight);
		//Add Vertex
		void addVertex(std::string name, float val);
		//Count Connected Components
		int numConnectedComponents();
		//Tree Check
		bool tree();
		//Minimum Weight Components
		void minWeightComponent(std::string src);
		//Depth First Search
		bool DFS(std::string source, std::string val);
		//Breadth First Search
		bool BFS(std::string source, std::string val);
		//Closeness
		int closeness(std::string v1, std::string v2);
		//Partition
		bool partitionable();
		// Subgraph Test
		bool isSubGraph(const Graph& g);
		//Print Valued Path
		void printPathCloseVal(float value);
		// Print the graph for debugging
		void printGraph(); 
};
#endif
