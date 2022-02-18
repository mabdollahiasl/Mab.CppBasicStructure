#include <iostream>
#include <iterator> // For std::forward_iterator_tag
#include <cstddef>  // For std::ptrdiff_t
template <typename T>
class Vector
{

    struct Iterator
    {
        using iterator_category = std::random_access_iterator_tag;
        using difference_type = std::ptrdiff_t;
        using value_type = T;
        using pointer = T*;   // or also value_type*
        using reference = T&; // or also value_type&
        Iterator(pointer ptr) : m_ptr(ptr)
        {
        }

        reference operator*() const { return *m_ptr; }
        pointer operator->() { return m_ptr; }

        // Prefix increment
        Iterator& operator++()
        {
            m_ptr++;
            return *this;
        }

        // Postfix increment
        Iterator operator++(int)
        {
            Iterator tmp = *this;
            ++(*this);
            return tmp;
        }

        friend bool operator==(const Iterator& a, const Iterator& b) { return a.m_ptr == b.m_ptr; };
        friend bool operator!=(const Iterator& a, const Iterator& b) { return a.m_ptr != b.m_ptr; };

    private:
        pointer m_ptr;
    };

private:
    T* buffer;
    int capacity;
    int count;
    void increaseCapacity()
    {
        T* newbuffer = new T[capacity * 2];
        for (int i = 0; i < count; i++)
        {
            newbuffer[i] = std::move(buffer[i]);
        }

        delete[] buffer;
        capacity = capacity + (capacity / 2);
        buffer = newbuffer;
    }

public:
    Iterator begin() { return Iterator(&buffer[0]); }
    Iterator end() { return Iterator(&buffer[count]); }
    Vector() : capacity(2), count(0)
    {
        buffer = new T[2];
    }
    ~Vector()
    {
        delete[] buffer;
    }
    int GetCount() const
    {
        return count;
    }
    T& operator[](int i)
    {
        if (i < count)
        {
            return buffer[i];
        }
        else
        {
            throw "out of the bound!";
        }
    }
    int Add(const T& item)
    {
        if (count >= capacity)
        {
            increaseCapacity();
        }
        buffer[count] = item;

        return count++;
    }
    int Add(const T&& item)
    {
        if (count >= capacity)
        {
            increaseCapacity();
        }
        buffer[count] = std::move(item);
        return count++;
    }
};
