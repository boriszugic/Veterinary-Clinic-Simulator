#ifndef COMPAREBEHAVIOUR_H
#define COMPAREBEHAVIOUR_H

/**
 * @brief base class for all comparison behaviour
 *
 * @author Boris Zugic 
 */
template<typename T> class CompareBehaviour{
    
    public:
        CompareBehaviour(bool order = true){asc = order;};
        virtual ~CompareBehaviour(){};
        virtual bool compare(T, T) = 0;
            protected:
        bool asc;

    private:

};

#endif