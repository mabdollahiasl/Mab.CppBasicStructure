#include <queue>
#include <iostream>

using std::cout;
using std::endl;
using std::queue;

template <typename T>
class HeapNode
{
private:
public:
    HeapNode<T>* Parent = NULL;
    HeapNode<T>* Left = NULL;
    HeapNode<T>* Right = NULL;
    T Value;
    HeapNode(T Value)
    {
        this->Value = Value;

    }
};

template <typename T>
class Heap
{
private:
    HeapNode<T>* findLastNode()
    {
        queue<HeapNode<T>*> tree;
        tree.push(this->Root);
        HeapNode<T>* last=nullptr;
        while (!tree.empty())
        {
            last = tree.front();
            tree.pop();
            if (last->Left != NULL)
            {
                tree.push(last->Left);
            }
            if (last->Right != NULL)
            {
                tree.push(last->Right);
            }
        }
        return last;
    }
    void resolveNode(HeapNode<T>* cur)
    {
        if (cur->Parent == NULL)
        {
            return;
        }
        HeapNode<T>* parent = cur->Parent;
        HeapNode<T>* current = cur;

        while ((parent != NULL) && (!Compare(parent->Value, current->Value)))
        {
            T temp = parent->Value;
            parent->Value = current->Value;
            current->Value = temp;
            current = parent;
            parent = current->Parent;
        }
    }
    void SwapValue(HeapNode<T>* p1, HeapNode<T>* p2)
    {
        T temp = p1->Value;
        p1->Value = p2->Value;
        p2->Value = temp;
    }
    void resolveRemove(HeapNode<T>* root)
    {
        bool nLeft = true;
        bool nRight = true;

        if (root->Left != NULL)
        {
            nLeft = Compare(root->Value, root->Left->Value);
        }
        if (root->Right != NULL)
        {
            nRight = Compare(root->Value, root->Right->Value);
        }
        if (nLeft && nRight)
        {
            return;
        }
        else if (nLeft == false && nRight == false)
        {
            if (Compare(root->Left->Value, root->Right->Value))
            {
                SwapValue(root, root->Left);
                resolveRemove(root->Left);
            }
            else
            {
                SwapValue(root, root->Right);
                resolveRemove(root->Right);
            }
        }
        else if (nLeft == false)
        {
            SwapValue(root, root->Left);
            resolveRemove(root->Left);
        }
        else if (nRight == false)
        {
            SwapValue(root, root->Right);
            resolveRemove(root->Right);
        }
    }

public:
    HeapNode<T>* Root = NULL;

    bool (*Compare)(const T&, const T&)=nullptr;

    Heap()
    {
    }

    ~Heap()
    {
    }
    bool IsEmpty()
    {
        return this->Root == NULL;
    }
    T Pop()
    {
        if (Compare == nullptr) {
            throw "compare is not set!";
        }
        T rootvalue = this->Root->Value;
        HeapNode<T>* lastNode = findLastNode();
        if (lastNode != this->Root)
        {
            if (lastNode->Parent->Left == lastNode) //remove the connection between last parent node and last node
            {
                lastNode->Parent->Left = NULL;
            }
            else
            {
                lastNode->Parent->Right = NULL;
            }
            this->Root->Value = lastNode->Value;
            delete lastNode;
            lastNode = NULL;

            resolveRemove(this->Root);
        }
        else
        {
            delete this->Root;
            this->Root = NULL;
        }

        return rootvalue;
    }

    void Insert(T Value)
    {
        if (Compare == nullptr) {
            throw "compare is not set!";
        }

        HeapNode<T>* newNode = new HeapNode<T>(Value);
        newNode->Value = Value;

        if (this->Root == NULL)
        {
            this->Root = newNode;
            return;
        }
        queue<HeapNode<T>*> tree;
        tree.push(this->Root);
        while (!tree.empty())
        {
            HeapNode<T>* cur = tree.front();
            tree.pop();
            if (cur->Left == NULL)
            {
                cur->Left = newNode;
                newNode->Parent = cur;
                resolveNode(newNode);
                return;
            }
            else if (cur->Right == NULL)
            {
                cur->Right = newNode;
                newNode->Parent = cur;
                resolveNode(newNode);
                return;
            }
            else
            {
                tree.push(cur->Left);
                tree.push(cur->Right);
            }
        }
    }
};
