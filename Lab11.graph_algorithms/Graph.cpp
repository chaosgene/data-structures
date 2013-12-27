#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <limits>
#include "Graph.h"
#include <queue>
#include <stack>
#include <algorithm>
#include <limits>
using namespace std;

// Constructor
Graph::Graph() {
	numVertices = 0;
	numEdges = 0;
}

// Destructor
Graph:: ~Graph() {
	for (list<EdgeNode *>::iterator it = edges.begin();
         it != end(edges);
         ++it) {
		delete *it;
	}	
    for (vector<Vertex *>::iterator it = vertices.begin();
            it != end(vertices);
            ++it) {
        delete *it;
    }
}

// Clear
void Graph::clear() {
    for (list<EdgeNode *>::iterator it = edges.begin();
         it != end(edges);
         ++it) {
		delete *it;
	}	
    for (vector<Vertex *>::iterator it = vertices.begin();
            it != end(vertices);
            ++it) {
        delete *it;
    }
    edges.clear();
    vertices.clear();
    numVertices = 0;
    numEdges = 0;
}

// Check if string is valid as first line of file
bool Graph::isValidFirstLine(const string &line) {
    // Check first line is an unsigned integer
    for (string::const_iterator it = line.begin();
            it != end(line);
            ++it) { 
        // To be valid, each digit is an unsigned integer 0-9
        if (!isdigit(*it)) {
            return false;
        }
    } 
    return true;
}

// Check if string is valid as a line representing a vertex in file
bool Graph::isValidVertexLine(const string &line) {
    // Check that there is a , inside the string
    string::size_type n = line.find(",");
    if (n == string::npos)
        return false;
    // Check that there are no other commas in the string
    n = line.find(",", n + 1);
    if (n != string::npos)
        return false;
    // After splitting the string based on commas, evaluate
    istringstream ss(line);
    string name;
    getline(ss, name, ',');
    string val;
    getline(ss, val, ',');
    // Whether the first half contains at least one character
    if (name.empty())
        return false;
    // Whether what follows the comma-space can be an unsigned int
    istringstream iss(val);
    float f;
    iss >> f;
    if (!(iss.eof() && !iss.fail()))
        return false;
    // The value must be > 0
    if (f < 0)
        return false;
    return true;
}

// Check if string is valid as line of an edge in file 
bool Graph::isValidEdgeLine(const string &line) {
    // Check if there are two commas and no more
    string::size_type n = line.find(",");
    if (n == string::npos)
        return false; // No first comma
    // Check that there are no other commas in the string
    n = line.find(",", n + 1);
    if (n == string::npos)
        return false; // No second comma
    n = line.find(",", n + 1);
    if (n != string::npos)
        return false; // Has more than two commas
    // After splitting the string based on commas, evaluate
    istringstream ss(line);
    string v1;
    getline(ss, v1, ',');
    string v2;
    getline(ss, v2, ',');
    string weight;
    getline(ss, weight, ',');
    // Whether what follows weight can be an unsigned int
    istringstream iss(weight);
    float f;
    iss >> f;
    if (!(iss.eof() && !iss.fail()))
        return false;
    // The value must be > 0
    if (f < 0)
        return false;
    // The addEdge(...) method will check if the v1 and v2 are valid
    return true;
}

// Remove trailing and leading whitespace
void Graph::trim(string &vertexName) {
    // Trim whitespace off the vertex names
    size_t endpos = vertexName.find_last_not_of(" ");
    if (string::npos != endpos)
        vertexName = vertexName.substr(0, endpos+1);
    size_t startpos = vertexName.find_first_not_of(" ");
    if (string::npos != startpos)
        vertexName = vertexName.substr(startpos);
}

// Clear current graph and read in data from a file
void Graph::readFromFile(string file) {
    clear(); // Comment out to have file contents added to existing graph
    string line;
    ifstream graphFile(file);
    if (graphFile.is_open()) {
        // Check the file isn't empty
        if (!getline(graphFile, line)) {
            cout << "The file is empty." << endl;
            return;
        }    
        // Check the first line's validity
        if (!isValidFirstLine(line)) {
            cout << "FIRST LINE INVALID" << endl;
            cout << line << " is not an unsigned integer. Aborted." << endl;
            return;
        }
        // Get the next lines and add them as vertices
        int numLinesWVerts = stoi(line); // Since line is valid, can convert
        for (int i = 0; i < numLinesWVerts; ++i)
        {
            getline(graphFile, line);
            if (!isValidVertexLine(line)) {
                cout << "VERTEX LINE INVALID" << endl;
                cout << line << " is not a valid format for a vertex. Skipped."
                    << endl;
                continue; // Go to the next line
            }
            // Use the validated two halves to construct and add the vertex
            istringstream ss(line);
            string name;
            getline(ss, name, ',');
            trim(name);
            string val;
            getline (ss, val, ',');
            // Convert token into a float
            float numVal = ::atof(val.c_str());
            // Construct and add the vertex
            addVertex(name, numVal);
        } 
        // Get all remaining lines and add them as edges
        while (getline(graphFile, line)) {
            if (!isValidEdgeLine(line)) {
                cout << "EDGE LINE INVALID" << endl;
                cout << line << " is not a valid format for an edge. Skipped."
                    << endl;
                continue;
            }
            // Split the string
            istringstream ss(line);
            string v1;
            getline(ss, v1, ',');
            string v2;
            getline(ss, v2, ',');
            string weight;
            getline(ss, weight, ',');
            float weightVal = ::atof(weight.c_str());
            trim(v1);
            trim(v2);
            // Add the edge
            addEdge(v1, v2, weightVal);
        }
    } else
        cout << "File " << file << " can't be opened." << endl;
}

// Create and write to a given file
void Graph::writeToFile(string file) {
    ofstream blankFile(file);
    if (blankFile.is_open()) {
        blankFile << numVertices << endl;
        for (auto it = begin(vertices); it != end(vertices); ++it)
            blankFile << (*it)->name << ", " << (*it)->value << endl;
        for (auto it = begin(edges); it != end(edges); ++it)
            blankFile << ((*it)->leftVertex)->name << ", "
                << ((*it)->rightVertex)->name << ", " 
                << ((*it)->weight) << endl;
    } else {
        cout << "Unable to open file." << endl;
    }
}

// Tells whether graph is empty
bool Graph::empty() const {
	return ( (numVertices == 0) &&
		 (numEdges == 0) &&
		 vertices.empty() );
}

// Bind two vertices
void Graph::connect(vector<Vertex *>::iterator it,
                    vector<Vertex *>::iterator it2,
                       float weight) {
	// Access the vector pointed to by it 
	// Temporarily store edge pointer next1, even if nullptr
	EdgeNode * next1; 
	next1 = (*it)->edge;
	// When the possible edge already exists, update value to the lesser
	bool exists = false;
	// To check, start at one endpoint and find its entire edge list
	EdgeNode * next =(*it)->edge;
	while (next) {
		Vertex * leftVertexPtr = next->leftVertex;
		Vertex * rightVertexPtr = next->rightVertex;
		if (leftVertexPtr == &(**it)) {
			if (rightVertexPtr->name == (*it2)->name) {
				exists = true;
				// next contains pointer to an edgenode in edges 
				break;
			}
			next = next->nextLeft;			
		}
		else if (rightVertexPtr == &(**it)) {
			if (leftVertexPtr->name == (*it2)->name) {
				exists = true;
				break;
			}
			next = next->nextRight;
		}
	}
	// If trying to add a duplicate
	if (exists) {
		if (next->weight > weight) 
			next->weight = weight; // Update its value
		return;
	}
	else {
		// Set the edge pointer of the vector at it  to a new edgenode 
		(*it)->edge = new EdgeNode(&(**it), &(**it2), weight);
		edges.push_back((*it)->edge);
	}
	// Access the vector pointed to by it2
	// Temporarily store edge pointer in EdgeNode * next2, even if nullptr
	EdgeNode * next2;
	next2 = (*it2)->edge;
	// Set the edge pointer of the vector at it2 to the new edgenode
	(*it2)->edge = (*it)->edge;			
	((*it)->edge)->nextLeft = next1;
	((*it)->edge)->nextRight = next2;
    ++numEdges;
}

// Wrapper method for vertex binding, checks validity
void Graph::addEdge(string v1, string v2, int weight) {
	if (v1 == v2) {
		cout << "No loop edges to self allowed." << endl;
		return;
	}
	// Find vertex with v1 OR v2 as the name
	bool found = 0;
	bool firstMatches = false;
	bool secondMatches = false;
	for (auto it = begin(vertices); (!found) && (it != end(vertices));
		 ++it) {
		firstMatches = ((*it)->name == v1);
		secondMatches = ((*it)->name == v2);
		if ( firstMatches || secondMatches ) {
			found = true;
			// It now points to a vertex with an endpoint from input
			// Find where the other endpoint vertex lies
			if (firstMatches) {
				bool secondExists = false;
				for (auto it2 = it; it2 != end(vertices);
					++it2) {
					if ((*it2)->name == v2) {
						secondExists = true;
						// Add edge-node
						connect(it, it2, weight);
					}
				}
				// If the second vertex was never found
				if (!secondExists)
					cout << "Error. Endpoint " <<
						(*it)->name
                        << " was found but " << v2
                        << " was never added. Aborted." << endl;
			}
			else if (secondMatches) {
				bool firstExists = false;
				for (auto it2 = it; it2 != end(vertices);
					++it2) {
					if ((*it2)->name == v1) {
						firstExists = true;
						// Add edge-node
						connect(it, it2, weight);
					}
				}
				// If the first vertex was never found
				if (!firstExists)
					cout << "Error. Endpoint " <<
						(*it)->name
                        << " was found but " << v1
                        << " was never added. Aborted." << endl;
			}
		}
	}
	if (!found)
		cout << "Error. Neither endpoint " << v1 << " or " << v2
            << " have been added into the graph. Aborted." << endl;
}

// Construct and add a vertex with specified fields
void Graph::addVertex(string name, float val) {
    // Vertices are unique by name
    // In the case that vertices contains name, it needs to be replaced with
    //  the more recent vertex.
    bool hasDup = false;
    for (auto it = begin(vertices); it != end(vertices); ++it) {
        if ((*it)->name == name) {
            hasDup = true;
            (*it)->value = val;
            break;
        }
    }
    if (!hasDup) {
	    vertices.push_back(new Vertex(name, val, numVertices));
        numVertices++; 
    }
}

// Find how many disjoint sets of vertices there are
int Graph::numConnectedComponents() {
    if (empty())
        return 0;
    int numClusters = 0; // Store a counter for the result
    vector<bool> visited (numVertices, false);
    Vertex * seed;
    vector<Vertex *>::iterator it = begin(vertices);
    for (;;) {
        // Reset the seed
        seed = nullptr;
        // Find a vertex that is unvisited
        for ( ; it != end(vertices); ++it) {
            if (!visited[(*it)->id]) {
                seed = *it;
                numClusters++; // Have found the beginning of a new cluster
                break;
            }
        }    
        // If not found, every node's been visited so end execution 
        if (!seed)
            return numClusters;
        // Perform a depth-first traversal from seed
        // Mark each node as found
        // Create a stack of vertex references
        stack<Vertex *> stVertexPtrs;
        stVertexPtrs.push(seed);
        while (!stVertexPtrs.empty()) {
            seed = stVertexPtrs.top();
            stVertexPtrs.pop();
            if (!visited[seed->id]) {
                visited[seed->id] = true;
                // DEBUG_VERSION cout << srcVertex->name << ".";
                // For all edges from vertex to unvisited vertices, push on the
                // unvisited vertex
                EdgeNode * newEL = seed->edge;
		        while (newEL) {
                    Vertex * leftVertexPtr = newEL->leftVertex;
                    Vertex * rightVertexPtr = newEL->rightVertex;
                    if ((leftVertexPtr) &&
                        (!visited[leftVertexPtr->id])) {
                        stVertexPtrs.push(leftVertexPtr);
                    } else if ((rightVertexPtr) &&
                    (!visited[rightVertexPtr->id])) {
                        stVertexPtrs.push(rightVertexPtr);
                    } 
                    newEL = (seed == leftVertexPtr ? newEL->nextLeft :
                        newEL->nextRight); 
                }
            }
        }
    }
    return -1;
}

// Tell whether the graph is entirely connected, from any vertex to any other
bool Graph::isConnected() {
        vector<bool> visited (numVertices, false);
        Vertex * seed = vertices.front();
        stack<Vertex *> stVertexPtrs;
        stVertexPtrs.push(seed);
        while (!stVertexPtrs.empty()) {
            seed = stVertexPtrs.top();
            stVertexPtrs.pop();
            if (!visited[seed->id]) {
                visited[seed->id] = true;
                // DEBUG_VERSION cout << srcVertex->name << ".";
                // For all edges from vertex to unvisited vertices, push on the
                // unvisited vertex
                EdgeNode * newEL = seed->edge;
		        while (newEL) {
                    Vertex * leftVertexPtr = newEL->leftVertex;
                    Vertex * rightVertexPtr = newEL->rightVertex;
                    if ((leftVertexPtr) &&
                        (!visited[leftVertexPtr->id])) {
                        stVertexPtrs.push(leftVertexPtr);
                    } else if ((rightVertexPtr) &&
                    (!visited[rightVertexPtr->id])) {
                        stVertexPtrs.push(rightVertexPtr);
                    } 
                    newEL = (seed == leftVertexPtr ? newEL->nextLeft :
                        newEL->nextRight);     
                }
            }
        }
        // Traversal marked all connected parts as visited
        // If any remain, the graph is not connected
        for (int i = 0; i < numVertices; i++) {
            if (!visited[i])
                return false;
        }
    return true;
}

// Tell if a graph is a tree
bool Graph::tree() {
    if (empty())
        return true; // Empty graphs will be considered trees
    // A graph is a tree if it has V - 1 edges and is connected
    if ((vertices.size() - 1) != edges.size())
        return false;
    if (!isConnected())
        return false; 
    return true;
}

// Print the minimum spanning tree given a vertex that must be included
void Graph::minWeightComponent(std::string src) {
	/**
		Prim's algorithm is efficient for edge-heavy graphs.
	*/
	// Find the vertex in the vertices vector with the same name as src
	bool found = false;
	Vertex * sourceVertex = nullptr;
	for (auto it = begin(vertices); (!found) &&  (it != end(vertices));
		 ++it) {
		if ((*it)->name == src) {
			found = true;
			sourceVertex = &(**it);
		}
	}
	if (!sourceVertex) {
		cout << "No source vertex of name " << src
            << " is in the graph. Aborted." << endl;
		return;
	}
	// No guarantee of connectedness - store all that are encountered
	list<Vertex *> connectedVertices;
	connectedVertices.push_back(sourceVertex);
	// Create a collection of pointers to edge nodes called ens
	list<EdgeNode *> ens;
	// Create an array of bools where position will be the id of the vertex
	// Since numVertices is not known at run-time,  
 	vector<bool> visited (numVertices, false); // set all to unvisited
	// Create an array of bools where position will be the id of the vertex
	// Since numVertices is not known at run-time,
	vector<bool> touchable (numVertices, false); // set all to untouched
	// Mark this src vertex as visited
	visited[sourceVertex->id] = true;
	// Mark this src vertex as touched
	touchable[sourceVertex->id] = true;
	// From the edge pointer of the vertex, add edgenodes to the collection	
	// Go to the next edgenode (left/right)  based on whether the value of
	//  the vertex at src is equal to  leftVertex or rightVertex
	EdgeNode * next = sourceVertex->edge;
	while (next)	{
		Vertex * leftVertexPtr = next->leftVertex;
		Vertex * rightVertexPtr = next->rightVertex;
		// Add the vertices only if they have not been visited yet
		if (!touchable[leftVertexPtr->id]) {
			connectedVertices.push_back(leftVertexPtr);
			touchable[leftVertexPtr->id] = true;
		}
		else if (!touchable[rightVertexPtr->id]) {
			connectedVertices.push_back(rightVertexPtr);
			touchable[rightVertexPtr->id] = true;
		}
		ens.push_back(next); // Add each edgenode to ens
		if (leftVertexPtr == sourceVertex)
			next = next->nextLeft;			
		else if (rightVertexPtr == sourceVertex)
			next = next->nextRight;
	}
	// Collection of edges will be stored in a list
	list<EdgeNode *> edgeAnswers;	
	while (!ens.empty()) {
		// Find the currMinWeight edgenode and remove any unneeded edges
		list<EdgeNode *>::iterator currMinWeight = begin(ens);
		list<EdgeNode *>::iterator itr = begin(ens);
		while ((itr != end(ens))) {
			// Remove if both vertices have been visited
			if (visited[((*itr)->leftVertex)->id] &&
                    visited[((*itr)->rightVertex)->id]) {
				itr = ens.erase(itr);
				currMinWeight = begin(ens);
				for (auto it = begin(ens); it != itr; it++) {
					if ( ((*it)->weight) <
					   ((*currMinWeight)->weight) )
						currMinWeight = it;
				}
			} else {
				if ( itr != end(ens)) {
					if ( ((*itr)->weight) <
				           ((*currMinWeight)->weight) ) {
						currMinWeight = itr;
					}
					++itr;
				}
			}	
		}
		if (!ens.empty()) {
			// Find the endpoint that is not visited
			bool leftVisited = visited[((*currMinWeight)->
							leftVertex)->id];
		//	bool rightVisited = visited[((*currMinWeight)
		//					->rightVertex)->id];
			Vertex * unvisitedV;
			if (leftVisited) {
				unvisitedV = ((*currMinWeight)->rightVertex);
			} else {
				unvisitedV = ((*currMinWeight)->leftVertex);
			}
			// Remove from ens and store it in the answer array
			edgeAnswers.push_back(*currMinWeight);
			ens.erase(currMinWeight);
			// Mark this endpoint vertex as visited
			visited[unvisitedV->id] = true;
			touchable[unvisitedV->id] = true;
			// Look at the edge list from this endpoint vertex
			// Add the edge nodes to the collection 
			EdgeNode * newEL = unvisitedV->edge;
			while (newEL) {
				bool hasOneUnvisitedNeighb =
                    !( (visited[(newEL->leftVertex)->id]) &&
                    ( visited[(newEL->rightVertex)->id]));
				if (hasOneUnvisitedNeighb) {
					ens.push_back(newEL);
			    }
				Vertex * leftVertexPtr = newEL->leftVertex;
				Vertex * rightVertexPtr = newEL->rightVertex;
				if (!touchable[leftVertexPtr->id]) {
					connectedVertices.push_back
						(leftVertexPtr);
					touchable[leftVertexPtr->id] = true;
				} else if (!touchable[rightVertexPtr->id]) {	
					connectedVertices.push_back
						(rightVertexPtr);	
					touchable[rightVertexPtr->id] = true;
				}
                newEL = (unvisitedV == leftVertexPtr ? newEL->nextLeft :
                    newEL->nextRight); 
			}
		}
	}
	cout << "{{";
	list<Vertex *>::iterator itVerts = begin(connectedVertices);
	if (itVerts != end(connectedVertices)) {
		cout << (*itVerts)->name;
		++itVerts;
	}
	for ( ; itVerts != end(connectedVertices); ++itVerts) {
		cout << ", ";
		cout << (*itVerts)->name;
	}
	cout << "}, {";
	list<EdgeNode *>::iterator itEdges = begin(edgeAnswers);
	if (itEdges != end(edgeAnswers)) {
		cout << "(" << ((*itEdges)->leftVertex)->name << ", "
            << ((*itEdges)->rightVertex)->name << ")";
		++itEdges;
	}
	for ( ; itEdges != end(edgeAnswers); ++itEdges) {
		cout << ", ";
		cout << "(" << ((*itEdges)->leftVertex)->name << ", "
            << ((*itEdges)->rightVertex)->name << ")";
	}
	cout << "}}" << endl;
}

// Depth-first traversal that returns true if input is found
bool Graph::DFS(string source, string val) {
    // Create a stack of vertex references
    stack<Vertex *> stVertexPtrs;
    // Create a set V
    vector<bool> visited (numVertices, false);
    Vertex * srcVertex = nullptr;
    // Find the vertex with the string source
    for (auto it = begin(vertices); it != end(vertices); it++) {
        if ((*it)->name == source) {
		    srcVertex = &(**it);
		    break;
	    }
    }
    // Check to see that the source was found
    if (!srcVertex) {
        cout << "The root for the DFS was not in the graph. Aborted." << endl;
        return false;
    } 
    stVertexPtrs.push(srcVertex);
    while (!stVertexPtrs.empty()) {
        srcVertex = stVertexPtrs.top();
        stVertexPtrs.pop();
        if (!visited[srcVertex->id]) {
            visited[srcVertex->id] = true;
            if (srcVertex->name == val)
                return true;
            // For all edges from vertex to unvisited vertices, push on the
            // unvisited vertex
            EdgeNode * newEL = srcVertex->edge;
		    while (newEL) {
                Vertex * leftVertexPtr = newEL->leftVertex;
                Vertex * rightVertexPtr = newEL->rightVertex;
                if ((leftVertexPtr) &&
                        (!visited[leftVertexPtr->id])) {
                    stVertexPtrs.push(leftVertexPtr);
                } else if ((rightVertexPtr) &&
                    (!visited[rightVertexPtr->id])) {
                    stVertexPtrs.push(rightVertexPtr);
                } 
                newEL = (srcVertex == leftVertexPtr ? newEL->nextLeft :
                    newEL->nextRight); 
            }
        }
    }
   return false;
}

// Breadth-first traversal that returns true if input is found
bool Graph::BFS(string source, string val) {
    // Create a queue
    queue<Vertex *> qVertexPtrs;
    // Create a set V
    vector<bool> visited (numVertices, false);
    Vertex * srcVertex = nullptr;
    // Find the vertex with the string source
    for (auto it = begin(vertices); it != end(vertices); it++) {
        if ((*it)->name == source) {
		    visited[(*it)->id] = true;
		    srcVertex = &(**it);
		    break;
	    }
    }
    // Check to see that the source was found
    if (!srcVertex) {
        cout << "The root for the BFS was not in the graph. Aborted." << endl;
        return false;
    } 
    // Enqueue source
    qVertexPtrs.push(srcVertex);
    while (!qVertexPtrs.empty()) {
	    Vertex * current = qVertexPtrs.front();
        // DEBUG_VERSION cout << current->name;
	    qVertexPtrs.pop();
	    if (current->name == val) 
		    return true;
	    EdgeNode * newEL = current->edge;
		while (newEL) {
            Vertex * leftVertexPtr = newEL->leftVertex;
            Vertex * rightVertexPtr = newEL->rightVertex;
            visited[current->id] = true;
            if ((leftVertexPtr) && (!visited[leftVertexPtr->id])) {
                visited[leftVertexPtr->id] = true;
                qVertexPtrs.push(leftVertexPtr);
            } else if ((rightVertexPtr) &&
                (!visited[rightVertexPtr->id])) {
                visited[rightVertexPtr->id] = true;
                qVertexPtrs.push(rightVertexPtr);
            } 
            newEL = (current == leftVertexPtr ? newEL->nextLeft :
                newEL->nextRight); 
        }
    }
    return false;
}

// Get the shortest number of edges between two nodes (using BFS)
int Graph::closeness(string v1, string v2) {
    // Create a queue
    queue<Vertex *> qVertexPtrs;
    // Create a set distances, -1 will represent infinity
    vector<int> distances (numVertices, -1);
    Vertex * srcVertex = nullptr;
    // Find the vertex with the string source
    for (auto it = begin(vertices); it != end(vertices); it++) {
        if ((*it)->name == v1) {
		    distances[(*it)->id] = 0;
		    srcVertex = &(**it);
		    break;
	    }
    }
    // Check to see that the source was found
    if (!srcVertex) {
        cout << "The root " << v1 << " was not in the graph. Aborted." << endl;
        return -1;
    } 
    if (v1 == v2)
        return 0;
    // Enqueue source
    qVertexPtrs.push(srcVertex);
    while (!qVertexPtrs.empty()) {
	    Vertex * current = qVertexPtrs.front();
	    if (current->name == v2) {
            return distances[current->id];
        }
	    qVertexPtrs.pop();
	    EdgeNode * newEL = current->edge;
		while (newEL) {
            Vertex * leftVertexPtr = newEL->leftVertex;
            Vertex * rightVertexPtr = newEL->rightVertex;
			if (leftVertexPtr == current) {
                if (distances[rightVertexPtr->id] == -1) {
                    distances[rightVertexPtr->id] = distances[current->id] + 1;
                    qVertexPtrs.push(rightVertexPtr);
                }
				newEL = newEL->nextLeft;
            } else if (rightVertexPtr == current) {
                if (distances[leftVertexPtr->id] == -1) {
                    distances[leftVertexPtr->id] = distances[current->id] + 1;
                    qVertexPtrs.push(leftVertexPtr);
                }
				newEL = newEL->nextRight;
            }
        }
    }
    cout << "Could not find a path from " << v1 << " to " << v2 << endl;
    return -1;
}

// Find whether the graph is bipartite
bool Graph::partitionable() {
    if (empty())
        return true; // An empty set may be partitioned into two empty subsets
    // By the definition of a bigraph, any graph with no edges is bipartite
    else if (edges.empty()) { // Has vertices, no edges
       return true; 
    }
    // Use colors to designate two sets, and an un-colored state
    int BLACK = 1;
    int UNCOLORED = -1;
    vector<int> colors (numVertices, UNCOLORED);
    // Iteration needed since graph is not guaranteed to be connected
    // A graph is bipartite if all its components, even disjoint, are bipartite
    int i = 0;
    for (;;) {
        Vertex * src = nullptr;
        // Find the first uncolored source node
        for ( ; i < numVertices; i++) {
            if (colors.at(i) == UNCOLORED) {
                src = vertices.at(i);
            }
        }
        if (!src)
            return true; // Have went through all the components and not broken
        // Assign BLACK color to source
        colors[src->id] = BLACK;
        // DEBUG_VERSION cout << src->name << " got colored " << BLACK <<  endl;
         // Create a queue
        queue<Vertex *> qVertexPtrs;
        // Enqueue source
        qVertexPtrs.push(src);
        while (!qVertexPtrs.empty()) {
	        Vertex * current = qVertexPtrs.front();
            // DEBUG_VERSION cout << current->name;
	        qVertexPtrs.pop();
            // Find adjacent vertices
	        EdgeNode * newEL = current->edge;
		    while (newEL) {
                Vertex * leftVertexPtr = newEL->leftVertex;
                Vertex * rightVertexPtr = newEL->rightVertex;
                Vertex * adjacentVertexPtr = nullptr;
			    if (leftVertexPtr == current) {
				    newEL = newEL->nextLeft;
                    adjacentVertexPtr = rightVertexPtr;
                }		
			    else if (rightVertexPtr == current) {
				    newEL = newEL->nextRight;
                    adjacentVertexPtr = leftVertexPtr;
                }
                // If the adjacent vertex is un-colored, assign alternate color
                if (colors[adjacentVertexPtr->id] == -1) {
                    colors[adjacentVertexPtr->id] = 1 - colors[current->id];
                    // DEBUG_VERSION cout << adjacentVertexPtr->name
                    // << " got colored " << 1 - colors[current->id] << endl;
                    qVertexPtrs.push(adjacentVertexPtr);
                }
                else if (colors[adjacentVertexPtr->id] == colors[current->id]) {
                    return false;
                }
            }
        }
    }
    return true;
}

// A comparator for Vertex pointers
bool vertexPtrComp(Graph::Vertex * a, Graph::Vertex * b) {
    return (a->value < b->value);
}

// A comparator for EdgeNode pointers
bool edgePtrComp(Graph::EdgeNode * a, Graph::EdgeNode * b) {
    return (a->weight < b->weight);
}

bool Graph::EdgeNode::operator==(const EdgeNode & other) const {
    if (leftVertex->name == (other.leftVertex)->name) 
        return (rightVertex->name == (other.rightVertex)->name);
    else if (leftVertex->name == (other.rightVertex)->name) 
        return (rightVertex->name == (other.leftVertex)->name);
    return false;
} 

// Find whether an input graph is a subset of this graph
bool Graph::isSubGraph(const Graph &g) {
    if (&g == this) 
        return true;
    // Check the graph does not have more vertices or edges than this graph
    if (numVertices < g.numVertices || numEdges < g.numEdges) {
       return false;
    }
    // Confirmed g has <= # of edges and vertices (trichotomy)
    if (empty()) // So if this graph is empty, g must be as well
        return true; // Empty set is the subset of an empty set
    if (g.empty())
        return true; // Empty set is the subset of every set
    // Sort the vector of vertices in linearithmic time
    std::sort(begin(vertices), end(vertices), vertexPtrComp);
    // Do a linear look-up for each vertex in g, stopping at a higher value
    for (auto i = begin(g.vertices); i != end(g.vertices); ++i)
    {
        // Check if the current vertex pointer's data is in vertices
        // Iterate through vertices
        for (auto a = begin(vertices); a != end(vertices); ++a) {
            // If a bigger number is found, stop execution
            if ((*a)->name == (*i)->name) {
                break; // Move on to the next vertex in the subgraph
            } else if ((*a)->value > (*i)->value)
                return false;
        } 
    }
    // Have confirmed every vertex in g exists by name
    cout << "Set of vertices is a subset." << endl;
    // Now check edges
    edges.sort(edgePtrComp);
    for (auto j = begin(g.edges); j != end(g.edges); ++j) {
       for (auto b = begin(edges); b != end(edges); ++b) {
            if ((**b) == (**j)) {
                break; // Move on to the next edge in the subgraph
            } else if ((*b)->weight > (*j)->weight) {
                return false;
            }
        }
    } 
    return true;
}

// A private method to do a DFS given a particular node
// Adds to a list of paths whose total deviance will not exceed leastDeviance
// Deepening from one vertex might have ties for example 0.5 -> 0.5 -> 0.5 and 
// 1.0 -> 0.5 should both be included in the answers
// Because of this, leastDeviance cannot be mutated
void Graph::deepen(Vertex * v, float & deviance, const float TARGET,
                    float & devianceThreshold, list<list<Vertex *>> & paths) {
    vector<bool> visited (numVertices, false);
    list<Vertex *> currentPath;
    currentPath.push_back(v);
    float newDeviance = deviance;
    float currentSum = -1;
    deepenAux(paths, visited, v, newDeviance, deviance, currentSum, currentPath,
                TARGET, devianceThreshold);
    // Set the leastDeviance to the newDeviance found by deepening
    deviance = newDeviance;
}

// Recursive function that returns whether it's call is at the end of a path
bool Graph::deepenAux(list<list<Vertex *>> & paths,
                        vector<bool> & visited,
                        Vertex * v,
                        float & newDeviance,
                        const float & oldDeviance, // Needed for condition
                        float currentSum,
                        list<Vertex *> & currentPath,
                        const float & TARGET,
                        float & devianceThreshold) {
    // Mark v as visited
    visited[v->id] = true;
    bool isStartVertex = (currentSum == -1);
    if (isStartVertex) { 
        currentSum = v->value;
    }
    // Deal with each neighbor
    EdgeNode * newEL = v->edge;
    bool hasUnvisitedNeighbors = false;
    while (newEL) {
        Vertex * leftVertexPtr = newEL->leftVertex;
        Vertex * rightVertexPtr = newEL->rightVertex;
        Vertex * adjacentVertex = nullptr;
   	    if (leftVertexPtr == v) {
            adjacentVertex = rightVertexPtr;
		    newEL = newEL->nextLeft;
        }		
		else if (rightVertexPtr == v) {
            adjacentVertex = leftVertexPtr;
		    newEL = newEL->nextRight;
        }
        // If unvisited
        if (!visited[adjacentVertex->id]) {
            float currentSumSend = currentSum + adjacentVertex->value;
            // If adding neighbor decreases oldDeviance
            if (fabs(TARGET - currentSumSend) < oldDeviance) {
                hasUnvisitedNeighbors = true;
                // Re-set newDeviance
                newDeviance = fabs(TARGET - currentSumSend);
                // Store neighbor into currentPath
                currentPath.push_back(adjacentVertex);
                // Deepen on that neighbor
                bool endin = deepenAux(paths, visited, adjacentVertex,
                                        newDeviance, oldDeviance,
                                        currentSumSend, currentPath, TARGET,
                                        devianceThreshold);    
                if (!endin) { 
                    if (newDeviance < devianceThreshold)
                        paths.clear();
                    if (newDeviance <= devianceThreshold) {
                        paths.push_back(currentPath);
                        devianceThreshold = newDeviance;
                    }
                }
                if (!currentPath.empty()) // Exception guard
                    currentPath.pop_back();
                
            }
        }        
    }
    return hasUnvisitedNeighbors;
}

// Find the path that's sum is most close to the target input
void Graph::printPathCloseVal(float value) {
    // Declare a container for the answers
    list<list<Vertex *>> paths;
    // Initialize least-deviance to infinity
    float devianceTreshold = numeric_limits<float>::max(); 
    // For each vertex (covers connected-ness cases)
    float deviance;
    for (auto it = begin(vertices); it != end(vertices); ++it) {
        deviance = fabs(value - (*it)->value);
        deepen(*it, deviance, value, devianceTreshold, paths);
    }
    for (auto it0 = begin(paths); it0 != end(paths); ++it0) {
        // For every path
        // Print the first item
        auto it1 = begin(*it0);
        cout << (*it1)->name;
        ++it1;
        for ( ; it1 != end(*it0); ++it1) {                
            cout << "->" <<  (*it1)->name;
        }
        cout << endl;
    }
}

// Print the graph to the screen
void Graph::printGraph() {
    bool DEBUG_MODE = 1;
    cout << "# Vertices: " << numVertices << " # Edges: " << numEdges << endl;
	cout << "{{";
	vector<Vertex *>::iterator it = begin(vertices);
	if (it != end(vertices)) {
        if (DEBUG_MODE)
            cout << (*it)->name << ": " << (*it)->value; 
		++it;
	}
	for ( ; it != end(vertices); ++it) {
		cout << ", ";
        if (DEBUG_MODE)
		    cout << (*it)->name << ": " << (*it)->value;
	}
	cout << "}, {";
	
    list<EdgeNode *>::iterator itEdges = begin(edges);
	if (itEdges != end(edges)) {
		if (DEBUG_MODE) {
            cout << "(" << ((*itEdges)->leftVertex)->name << ", "
                << ((*itEdges)->rightVertex)->name << " Cost: "
                << ((*itEdges)->weight) << ")";
        }
		++itEdges;
	}
	for ( ; itEdges != end(edges); ++itEdges) {
		cout << ", ";
		if (DEBUG_MODE) {
            cout << "(" << ((*itEdges)->leftVertex)->name << ", "
                << ((*itEdges)->rightVertex)->name << " Cost: "
                << ((*itEdges)->weight) << ")";
        }
	}
	cout << "}}" << endl;
}
