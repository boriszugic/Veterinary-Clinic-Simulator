#ifndef COMPAREDATE_H
#define COMPAREDATE_H

#include <iostream>
using namespace std;

#include "CompareBehaviour.h"

/**
 * @brief derived class that compares date
 *
 * @author Boris Zugic 
 */
template <typename T> class CompareDate : public CompareBehaviour<T> {
    public:
        CompareDate(bool asc = true) : CompareBehaviour<T>(asc) {}
        virtual ~CompareDate() {}
        virtual bool compare(T obj1, T obj2) override {
            if (CompareBehaviour<T>::asc)
                return *(*obj1).getDate() < *(*obj2).getDate();
            else {
                return (*obj1).getDate() > (*obj2).getDate();
            }
        }
};

#endif