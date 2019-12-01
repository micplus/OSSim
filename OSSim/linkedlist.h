#pragma once

template <typename T>
struct Node {
    T data;
    Node* next;
    Node() :next(nullptr) {};
    Node(T item) :data(item), next(nullptr) {};
};

template <typename T>
struct LinkedList {
    int length;
    Node<T>* head;
    Node<T>* tail;

    LinkedList();
    ~LinkedList();

    bool isEmpty();

    void addFirst(T item);
    void addLast(T item);
    
    void removeFirst();
    void remove(int index);
    bool remove(T item);

    T getFirst();
    T getLast();
    T get(int index);

    int search(T item);
};



template <typename T>
LinkedList<T>::LinkedList() {
    length = 0;
    head = new Node<T>();
    tail = head;
}

template <typename T>
LinkedList<T>::~LinkedList() {
    Node<T>* p = head;
    while (p != nullptr) {
        Node<T>* q = p;
        p = q->next;
        delete q;
    }
}

template<typename T>
bool LinkedList<T>::isEmpty() {
    return length == 0;
}

template<typename T>
void LinkedList<T>::addFirst(T item) {
    Node<T>* newNode = new Node<T>(item);
    newNode->next = head->next;
    head->next = newNode;
    if (isEmpty()) {
        tail = newNode;
    }
    length++;
}

template<typename T>
void LinkedList<T>::addLast(T item) {
    Node<T>* newNode = new Node<T>(item);
    newNode->next = tail->next;
    tail->next = newNode;
    tail = newNode;
    length++;
}

template<typename T>
void LinkedList<T>::removeFirst() {
    if (!isEmpty()) {
        Node<T>* p = head->next;
        head->next = p->next;
        delete p;
        length--;
        if (isEmpty()) {
            tail = head;
        }
    }
}

template<typename T>
void LinkedList<T>::remove(int index) {
    if (!isEmpty()) {
        int i = 0;
        Node<T>* p = head;
        for (; i < index; ++i) {
            p = p->next;
        }
        Node<T>* q = p->next;
        p->next = q->next;
        delete q;
        if (index == length - 1) {
            tail = p;
        }
        length--;
        if (isEmpty()) {
            tail = head;
        }
    }
}

template<typename T>
bool LinkedList<T>::remove(T item) {
    Node<T>* pBack = head;
    Node<T>* pFront = pBack->next;
    while (pFront) {
        if (pFront->data == item) {
            pBack->next = pFront->next;
            length--;
            if (isEmpty()) {
                tail = head;
            }
            return true;
        }
        pBack = pFront;
        pFront = pFront->next;
    }
    return false;
}

template<typename T>
T LinkedList<T>::getFirst() {
    return head->next->data;
}

template<typename T>
T LinkedList<T>::getLast() {
    return tail->data;
}

template<typename T>
T LinkedList<T>::get(int index) {
    int i = 0;
    Node<T>* p = head;
    for (; i < index; ++i) {
        p = p->next;
    }
    return p->next->data;
}

template<typename T>
int LinkedList<T>::search(T item) {
    int i = 0;
    Node* p = head->next;
    while (p) {
        if (p->data == item) {
            return i;
        }
        p = p->next;
        i++;
    }
    return -1;
}
