#include <vector>
#include <map>

#include "node.h"

// Class for digraph
class Digraph {
private:
    std::vector<Node*> m_headers;
    bool m_hasCycle;

public:
    Digraph();

    // v1 is the vertex the edge starts at & v2 is the vertex it goes to.

    // Utility Functions  - - - - - - - //
    bool  CheckBounds(int v1, int v2);
    bool  SortUtil(std::map<std::string, int>* overallVisits,
        std::map<std::string, bool>* cycleVisits,
        Node** head,
        Node* v1
    );

    // Main Functions - - - - - - - - - //
    bool  AddEdge(int v1, int v2);
    bool  HasEdge(int v1, int v2);
    bool  RemoveEdge(int v1, int v2);
    bool  AddVertex(std::string value);
    bool  Cycles();
    Node* Sort();

    ~Digraph();
};
