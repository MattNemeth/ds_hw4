
#include <string>

// Class for Node
class Node {
private:
    int m_label;
    std::string m_value;
    Node* m_next;

public:
    Node();
    Node(std::string value);

    inline int         GetLabel(){ return m_label };
    inline Node*       GetNext (){ return m_next  };
    inline std::string GetValue(){ return m_value };

    bool               SetLabel(int label );
    bool               SetNext (Node* next);

    ~Node();
}
