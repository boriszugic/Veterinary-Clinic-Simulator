#include <iostream>
using namespace std;

#include "Node.h"

template <typename T> Node<T>::Node(T d) : data(d), next(NULL), prev(NULL){}
