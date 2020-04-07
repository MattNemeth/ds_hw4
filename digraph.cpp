#include "digraph.h"

Digraph::Digraph()
{

}
bool Digraph::CheckBounds(int v1, int v2)
{
    if (v1 > m_headers.size() - 1 || v2 > m_headers.size() -1)
    {
        return false;
    }
    return true;
}
bool Digraph::AddEdge(int v1, int v2)
{
    if (CheckBounds(v1,v2))
    {
        // Construct a new node with all of the info.
        std::string v2ValueStr = m_headers[v2]->GetValue();
        Node* newNode = new Node(v2ValueStr);

        // Get the last node in the linked list.
        Node* lastNode = m_headers[v1];
        while (lastNode->GetNext() != nullptr)
        {
            lastNode = lastNode->GetNext();
        }

        // Add the node to the end of the linked list.
        lastNode->SetNext(newNode);

        return true;
    }
    else
    {
        return false;
    }
}

bool Digraph::HasEdge(int v1, int v2)
{
    if (CheckBounds(v1,v2))
    {
        return true;
    }
    return false;
}

bool Digraph::RemoveEdge(int v1, int v2)
{
    if (CheckBounds(v1,v2))
    {
        // Get the header node
        Node* currNode = m_headers[v1];
        Node* prevNode = currNode;

        // the value for the target node
        std::string targetValue = m_headers[v1]->GetValue();

        if (currNode->GetNext() == nullptr)
        {
            // Return False if the node has no edges.
            return false;
        }
        else
        {
            // Loop through the edges to find an edge.
            while (currNode->GetNext() != nullptr)
            {
                Node* nextNode = currNode->GetNext();

                prevNode = currNode;
                currNode = nextNode;

                // Match Found! Break out of the while loop.
                if (currNode->GetValue() == targetValue)
                {
                    break;
                }
            }

            // Delete the node and update the pointers.
            prevNode->SetNext(currNode->GetNext());
            currNode->SetNext(nullptr);

            delete currNode;
        }
        return true;
    }
    else
    {
        // if CheckBounds returns false, the v1 or v2 is out of bounds.
        // return false for this function.
        return false;
    }
}
bool Digraph::AddVertex(std::string value)
{
    Node* vertex = new Node(value);
    m_headers.push_back(vertex);
    return true;
}
bool  Digraph::SortUtil(std::map<std::string, int>*  overallVisits,
                        std::map<std::string, bool>* cycleVisits,
                        Node**                  head,
                        Node*                   v1
                       )
{
    (*overallVisits)[v1->GetValue()] = 1;
    (*cycleVisits  )[v1->GetValue()] = true;

    Node* nextEdge;
    Node* edge = v1;

    while (edge != nullptr)
    {
        nextEdge = edge->GetNext();

        if (nextEdge != nullptr && (*cycleVisits)[nextEdge->GetValue()])
        {
            m_hasCycle = true;
            return false;
        }

        if (nextEdge != nullptr && (*overallVisits)[nextEdge->GetValue()] == 0)
        {
            for (int i = 0; i < m_headers.size(); i++)
            {
                if (m_headers[i]->GetValue() == nextEdge->GetValue())
                {
                    SortUtil(overallVisits, cycleVisits, head, m_headers[i]);
                }
            }
        }
        edge = nextEdge;
    }

    // Remove v1 from the cycle visited map stack
    (*cycleVisits)[v1->GetValue()] = false;

    // Add v1 to the sorted linked list
    if (*head == nullptr)
    {
        // Creating new header node if one did not already exist
        *head = new Node(v1->GetValue());
    }
    else
    {
        Node* prevNode = new Node(v1->GetValue());
        prevNode->SetNext(*head);
        *head = prevNode;
    }
}
Node* Digraph::Sort()
{
    std::map<std::string, int>  overallVisits;
    std::map<std::string, bool> cycleVisits  ;

    Node* m_head = nullptr;

    for (int i = 0; i < m_headers.size(); i++)
    {
       overallVisits[m_headers[i]->GetValue()] = 0;
       //overallVisits[m_headers.size()] = 0;
    }

    for (int i = 0; i < m_headers.size(); i++)
    {
        std::string value = m_headers[i]->GetValue();
        if (overallVisits[value] == 0)
        {
            cycleVisits.clear();
            SortUtil(&overallVisits, &cycleVisits, &m_head, m_headers[i]);
        }
    }
    return m_head;
}

bool Digraph::Cycles(){
	return m_hasCycle;
}

Digraph::~Digraph()
{
    Node* currNode;
    Node* nextNode = currNode;

    for (int i = 0; i < m_headers.size(); i++)
    {
        currNode = m_headers[i];

        while (currNode != nullptr)
        {
            nextNode = currNode->GetNext();
            currNode->SetNext(nullptr);

            delete currNode;

            currNode = nextNode;
        }
        m_headers[i] = nullptr;
    }
}
