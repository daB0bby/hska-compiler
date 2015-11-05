//
// TODO: Do not split the code in seperate header and cpp file!
// template classes must have definition and implementation in a single file.
//

//
// Created by timo on 05.11.15.
//

#ifndef HSKA_COMPILER_VECTOR_H
#define HSKA_COMPILER_VECTOR_H


template <class T>
class vector
{
public:
    vector();
    vector(int initialSize);
    vector(vector<T> &copy);
    ~vector();

    void add(const T &t);
    void insert(int index, const T &t);
    void remove(const T &t);
    void remove(int position);
    T get(int position);
    T &operator [](int position);

    int size();
    int currentCapacity();


private:
    void resize();

    T *buffer;
    int index;
    int maxSize;

};


#endif //HSKA_COMPILER_VECTOR_H


//
// Created by timo on 05.11.15.
//


template <class T>
vector<T>::vector()
{
    vector(4);
}

template <class T>
vector<T>::vector(int initialSize)
{
    buffer = new T[initialSize];
    maxSize = initialSize;
}

template <class T>
vector::vector(vector<T> &copy)
{
    maxSize = copy.maxSize;
    index = copy.index;
    buffer = new T[copy.maxSize];
    for (int i = 0; i < index; i++) buffer[i] = copy.buffer[i];
}

template <class T>
vector<T>::~vector()
{
    delete[] buffer;
}

template <class T>
void vector<T>::add(const T &t)
{
    insert(index, t);
}

template <class T>
void vector<T>::insert(int position, const T &t)
{
    // position is out of range
    if (position > index) return;

    // array is full -> reallocating memory
    if (index >= maxSize) resize();

    // move all elements after 'position' one level down
    for (int i = index; i > position; i--)
    {
        buffer[i + 1] = buffer[i];
    }

    // inserting the new element and increment the index (=size())
    buffer[position] = t;
    index++;
}

template <class T>
void vector<T>::remove(const T &t)
{
    for (int i = 0; i < index; i++)
    {
        if (&(buffer[i]) == &t)
        {
            remove(i);
            break;
        }
    }
}

template <class T>
void vector<T>::remove(int position)
{
    // move all elements after 'position' one level up
    for (int i = position; i < index - 1; i++)
    {
        buffer[i] = buffer[i + 1];
    }

    index--;
}

template <class T>
int vector<T>::size()
{
    return index;
}

template <class T>
int vector<T>::currentCapacity()
{
    return maxSize;
}

template <class T>
void vector<T>::resize()
{
    T *newBuf = new T[maxSize * 2];

    for (int i = 0; i < maxSize; i++)
    {
        newBuf[i] = buffer[i];
    }

    delete[] buffer;
    buffer = newBuf;
    maxSize *= 2;
}

template <class T>
T vector<T>::get(int position)
{
    return buffer[position];
}

template <class T>
T & vector<T>::operator[](int position)
{
    return buffer[position];
}

