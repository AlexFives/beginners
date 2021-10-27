template<typename T>
void Stack::print(Node *&node) {
    Node *iter = node;
    while (iter and iter->value) {
        // print and iterate
        cout << *(T*)iter->value << ' '; // *(T*)iter->value, because iter->value is void pointer, it needs casting
        iter = iter->next;
    }
    cout << endl;
}

template<typename T>
void Stack::add(T x, Node *&node) {
    if (!node->value) {
        // if stack is empty
        node->value = new T(x);
        return;
    }
    Node *iter = node;
    while (iter->next) iter = iter->next; // go to the end
    iter->next = new Node; // create new Node
    iter->next->value = new T(x); // set new value and append it
}

template<typename T>
void Stack::pop(Node *&node) {
    if (!node->value) return; // if stack is empty - do nothing
    if (!node->next and node->value) {
        // if stack contains only one element
        delete (T*)node->value;
        node->value = nullptr;
        return;
    }
    Node *iter = node;
    while (iter->next->next) iter = iter->next; // go to the end
    delete (T*)iter->next->value; // delete last node value
    delete iter->next; // delete last node
    iter->next = nullptr; // set last node to nullptr
}

int Stack::size(Node *&node) {
    if (!node->value) return 0;
    int counter = 1; // because the first node doesn't count in while-cycle
    Node *iter = node;
    while (iter->next) {
        counter++;
        iter = iter->next;
    }
    return counter;
}