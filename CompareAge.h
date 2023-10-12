#ifndef COMPAREAGE_H
#define COMPAREAGE_H

#include "CompareBehaviour.h"

/**
 * @brief derived class that compares age
 *
 * @author Boris Zugic 
 */
template<typename T> class CompareAge : public CompareBehaviour<T>{
    
    public:
        CompareAge(bool asc = true) : CompareBehaviour<T>(asc) {};
        virtual ~CompareAge(){};
        virtual bool compare(T obj1, T obj2) override{
            if (CompareBehaviour<T>::asc)
                return obj1->getAge() < obj2->getAge();
            else{
                return obj1->getAge() > obj2->getAge();
            }
        }

};

#endif