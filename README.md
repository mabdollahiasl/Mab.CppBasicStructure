## Mab.CppBasicStructure
In this project I implemented some structure in C++.

## Heap Class
it's a heap data structure. it has a lambda for comparing its items, so we can use it as Min Heap or Max Heap.

**Sample code:** 

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


## Vector Class:
It's a auto increment length array. When we add item to it, it increase the size of it self automatically. 
It also support for each iteration.

**Sample code:**

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

