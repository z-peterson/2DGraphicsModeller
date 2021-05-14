#ifndef VECTOR_H
#define VECTOR_H

using namespace std;
#include <algorithm>
#include "QDebug"

/**
 * @brief vector()
 * custom vector class
 * Resembles the stl vector
 * This class is templated, and therefor
 * can handle custom objects such as shape
 */

namespace myVec{
    template<class T>
    class vector
    {
        int size_v;
        T *elem;
        int space;
    public:

        /**
         * @brief vector()
         * constructor
         */
        vector() : size_v{0}, elem{nullptr}, space{0} {}


        /**
         * @brief vector()
         * explicit constructor
         */
        explicit vector(int s) : size_v{s}, elem{new T[s]}, space{s}
        {
            for (int i = 0; i< size_v; ++i)
                elem[i] = 0;
        }


        /**
         * @brief vector()
         * paramaterized constructor
         */
        vector(const vector &src) : size_v{src.size_v}, elem{new T[src.size_v]}, space{src.space}
        {
            copy(src.elem, src.elem + size_v, elem);
        }


        /**
         * @brief &operator=()
         * overloaded equality
         * operator
         */
        vector &operator=(const vector &src)
        {
            T *p = new T[src.size_v];
            copy(src.elem, src.elem + size_v, elem);
            delete[] elem;
            elem = p;
            size_v = src.size_v;
            return *this;
        }


        /**
         * @brief ~vector()
         * destructor
         */
        ~vector()
        {
            delete[] elem;
        }


        /**
         * @brief operator[]()
         * overloaded [] index operator
         */
        T &operator[](int n)
        {
            return elem[n];
        }


        /**
         * @brief size()
         * return the size of the
         * vector
         */
        int size() const
        {
            return size_v;
        }


        /**
         * @brief capacity()
         * return the capacity
         * of the vector
         */
        int capacity() const {
            return space;
        }


        /**
         * @brief resize()
         * resize the vector
         */
        void resize(int newsize) {
            reserve(newsize);
            for(int i = size_v; i< newsize; ++i)
                elem[i] =0;
            size_v = newsize;
        }


        /**
         * @brief push_back()
         * add an element to the back
         * of the vector
         */
        void push_back(T d)
        {
            if(space == 0)
                reserve(8);
            else if(size_v == space)
                reserve(2 * space);

            elem[size_v] = d;
            ++size_v;
        }


        /**
         * @brief reserve()
         * reserve new space for the vector
         */
        void reserve(int newalloc)
        {
            if ( newalloc <= space) return;
            T* p = new T[newalloc];
            for ( int i = 0; i < size_v; ++i)
                p[i] = elem[i];
            delete[] elem;
            elem = p;
            space = newalloc;
        }

        using iterator = T*;
        using const_iterator = const T*;


        /**
         * @brief begin()
         * iterator begin
         */
        iterator begin()
        {
            if (size_v ==0)
                return nullptr;
            return &elem[0];
        }


        /**
         * @brief begin()
         * iterator begin
         */
        const_iterator begin() const
        {
            if (size_v == 0)
                return nullptr;
            return &elem[size_v];
        }


        /**
         * @brief end()
         * iterator end
         */
        iterator end()
        {
            if (size_v == 0)
                return nullptr;
            return &elem[size_v];
        }


        /**
         * @brief end()
         * iterator end
         */
        const_iterator end() const
        {
            if (size_v ==0)
                return nullptr;
            return &elem[size_v];
        }


        /**
         * @brief insert()
         * interator insert
         */
        iterator insert(iterator p, const T &val)
        {
            int index = p - begin();
            if (size() == capacity())
                reserve(size()==0 ? 8 : 2*size());
            ++size_v;
            iterator pp = begin() + index;
        }


        /**
         * @brief erase()
         * iterator erase
         */
        iterator erase(iterator p)
        {
            iterator returnIt = p;
            for(; p < end(); ++p)
            {
                * p = *(p + 1);

            }
            --size_v;
            return returnIt;
        }
    };
}



#endif // VECTOR_H
