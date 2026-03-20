template <typename T> class Node {
public:
  T value;
  Node *next;

  Node(T val) : value(val), next(nullptr) {}

  Node(T val, Node *node) : value(val), next(node) {}
};
