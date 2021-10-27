template<typename T>
void Queue::print(Node *&node) {
    Node *iter = node;
    while (iter and iter->value) {
        // print and iterate
        cout << *(T*)iter->value << ' '; // *(T*)iter->value, because iter->value is void pointer, it needs casting
        iter = iter->next;
    }
    cout << endl;
}

template<typename T>
void Queue::add(T x, Node *&node) {
    if (!node->value) {
        // if queue is empty
        node->value = new T(x);
        return;
    }
    Node *iter = node;
    while (iter->next) iter = iter->next; // go to the end
    iter->next = new Node; // create new Node
    iter->next->value = new T(x); // set new value and append it
}

template<typename T>
void Queue::pop(Node *&node) {
    if (!node->value) return; // if queue is empty - do nothing
    if (!node->next and node->value) {
        // if queue contains only one element
        delete (T*)node->value;
        node->value = nullptr;
        return;
    }
    // delete the first node
    Node *next_node = node->next; // create pointer, which points to the next node after the first
    delete (T*)node->value; // delete the first node value
    delete node; // delete the first node
    node = next_node; // set the first node
}

int Queue::size(Node *&node) {
    if (!node->value) return 0;
    int counter = 1; // because the first node doesn't count in while-cycle
    Node *iter = node;
    while (iter->next) {
        counter++;
        iter = iter->next;
    }
    return counter;
}