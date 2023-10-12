#ifndef NODE_H
#define NODE_H

/**
 * @brief represents a node of a doubly linked list
 * 
 * @author Boris Zugic
 */
template <typename T> class Node{
    
    public:
        Node(T d) : data(d), next(NULL), prev(NULL){};
        T data;
        Node<T>* next;
        Node<T>* prev;
};

#endif