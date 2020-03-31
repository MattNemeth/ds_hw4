
#include <vector>

#include "node.h"

// Class for digraph
class Digraph {
private:
    vector<Node*> m_headers;

public:
    Digraph           ();

    // v1 is the vertex the edge starts at and v2 is the vertex it goes to.

    bool  AddEdge     (int v1, int v2   );
    bool  AddVertex   (std::string value);
    bool  HasEdge     (int v1, int v2   );
    bool  RemoveEdge  (int v1, int v2   );
    bool  RemoveVertex(std::string value);
    Node* Sort        ();

    ~Digraph          ();
}
