template<typename T>
void Stack::print(Node *&node) {
    Node *iter = node;
    while (iter and iter->value) {
        cout << *(T*)iter->value << ' ';
        iter = iter->next;
    }
    cout << endl;
}

template<typename T>
void Stack::add(T x, Node *&node) {
    if (!node->value) {
        node->value = new T(x);
        return;
    }
    Node *iter = node;
    while (iter->next) iter = iter->next;
    iter->next = new Node;
    iter->next->value = new T(x);
}

template<typename T>
void Stack::pop(Node *&node) {
    if (!node->value) return;
    if (!node->next and node->value) {
        delete (T*)node->value;
        node->value = nullptr;
        return;
    }
    Node *iter = node;
    while (iter->next->next) iter = iter->next;
    delete (T*)iter->next->value;
    delete iter->next;
    iter->next = nullptr;
}

int Stack::size(Node *&node) {
    if (!node->value) return 0;
    int counter = 1;
    Node *iter = node;
    while (iter->next) {
        counter++;
        iter = iter->next;
    }
    return counter;
}