
#include "node.cpp"

Node()
{
    // Default Constructor
    m_value = "tmp";
    m_next  = nullptr;
}

Node(std::string value)
{
    m_value = value;
    m_next  = nullptr;
}

bool SetLabel(int label )
{
    m_label = label;
    return true;
}
bool SetNext (Node* next)
{
    m_next = next;
    return true;
}

~Node()
{

}
