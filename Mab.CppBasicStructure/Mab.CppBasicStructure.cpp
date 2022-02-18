// Mab.CppBasicStructure.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Heap.h"
#include "Vector.h"
void TestHeap();
void TestVector();

int main()
{
   
    TestHeap();
    TestVector();
}

void TestVector() {
    
    Vector<int> list;
    list.Add(4); //add item to list
    list.Add(8);
    list.Add(9);
    
    int vectorCount = list.GetCount(); //get item count

    cout << "Test List:" << endl;

    for (auto& i : list)
    {
        cout << "list item:" << i << endl;
    }
    std::cin.get();

}

void TestHeap() {

    Heap<int> heap; // make a heap of integer

    heap.Compare = [](const int& p1, const int& p2) //set lambda experssion to compare inserted item
    {
        return p1 < p2;
    };

    heap.Insert(15);
    heap.Insert(14);
    heap.Insert(7);
    heap.Insert(10);
    heap.Insert(8);

    cout << "Test Heap:" << endl;


    while (!heap.IsEmpty()) //pop all node from heap and print them 
    {
        int result = heap.Pop();

        std::cout << "value: " << result <<endl;
    }

    std::cin.get();
}


