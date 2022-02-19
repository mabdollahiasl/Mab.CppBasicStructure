template <typename T>
class StackNode
{
private:
    /* data */
public:
    T Value;
    StackNode* Next = NULL;
    StackNode() {

    };
    ~StackNode() {

    };
};

template <typename T>
class Stack
{
private:
    StackNode<T>* Last;
public:
    Stack()
    {
        this->Last = NULL;
    }
    ~Stack()
    {
    }
    bool IsEmpty() {
        return this->Last == NULL;

    }
    void Push(T value)
    {
        StackNode<T>* p = new StackNode<T>();
        p->Value = value;
        if (this->Last == NULL)
        {
            this->Last = p;
            return;
        }
        p->Next = this->Last;
        this->Last = p;

    }
    T Pop() {
        if (this->Last == NULL)
        {
            throw "empty stack";
        }
        StackNode<T>* last = this->Last;
        this->Last = last->Next;
        T val = last->Value;
        delete last;
        return val;

    }

    T Pick() {
        if (this->Last == NULL)
        {
            throw "empty stack";
        }
        return this->Last->Value;
    }
};




