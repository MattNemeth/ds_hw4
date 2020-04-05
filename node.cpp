
#include "node.cpp"

Node::Node()
{
    // Default Constructor
    m_value = "tmp";
    m_next  = nullptr;
}

Node::Node(std::string value)
{
    m_value = value;
    m_next  = nullptr;
}

Node::bool SetNext (Node* next)
{
    m_next = next;
    return true;
}

Node::~Node()
{

}
