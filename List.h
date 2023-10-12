#ifndef LIST_H
#define LIST_H

#include <iostream>
using namespace std;

template <typename T> class List;
template <typename T> ostream& operator<<(ostream&, List<T>&);

#include "Node.h"
#include "CompareBehaviour.h"

/**
 * @brief manages a collection of parameterized data
 * 
 * @author Boris Zugic
 */
template <typename T> class List{

    friend ostream& operator<< <T>(ostream&, List<T>&);

public:
    List() : head(nullptr), comparison(nullptr) {}
    virtual ~List(){
        while (head) {
            Node<T>* next = head->next;
            delete head;
            head = next;
        }
        delete comparison;
    }

    bool add(T obj){
        
        Node<T>* currNode;
        Node<T>* prevNode;
        Node<T>* tmpNode = new Node<T>(obj);

        currNode = head;
        prevNode = NULL;

        while (currNode != NULL) {

            if ((!comparison->compare(currNode->data, obj)))
                break;
            
            prevNode = currNode;
            currNode = currNode->next;
        }

        if (prevNode == NULL) 
            head = tmpNode;
        else {
            prevNode->next = tmpNode;
        }

        tmpNode->next = currNode;
        tmpNode->prev = prevNode;

        return true;
        }

    virtual bool find(int id, T* foundObj){
        
        Node<T>* currNode = head;
        Node<T>* nextNode;
        while (currNode != NULL) {
            nextNode = currNode->next;
            if (currNode->data->getId() == id){
                *foundObj = currNode->data;
                return true;
            }
            currNode = nextNode;
        }
        return false;
    }

    void convertToArray(T* arr, int& size){
        
        Node<T>* currNode = head;
        size = 0;
        while(currNode != NULL){
            arr[size++] = currNode->data;
            currNode = currNode->next;
        }
    }

    void cleanupData(){
        
        Node<T>* currNode = head;
        Node<T>* nextNode;
        while (currNode != NULL) {
            nextNode = currNode->next;
            if (currNode->data != NULL){
                delete currNode->data;
                currNode->data = NULL;
            }
            currNode = nextNode;
        }
    }

    void setComparison(CompareBehaviour<T> *c){comparison = c;}

private:
    Node<T>* head;
    CompareBehaviour<T>* comparison;

};

template <typename T>
ostream& operator<<(ostream& output, List<T>& l){
    
    int size;
    T* apptsArray = new T[MAX_ARR];
    l.convertToArray(apptsArray, size);

    output << "--- FORWARD:" << endl;
    for (int i = 0; i < size; i++)
        output << *(apptsArray[i]);

    output << "--- BACKWARD:" << endl;
    for (int i = size - 1; i >= 0; i--)
        output << *(apptsArray[i]);

    delete[] apptsArray;

    return output;
}

#endif
