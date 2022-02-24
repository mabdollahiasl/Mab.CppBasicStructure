template <typename QT>
class QueueNode
{
private:
    /* data */
public:
    QT Value;
    QueueNode* Next = NULL;
    QueueNode(/* args */) {

    };
    ~QueueNode() {

    };
};

template <typename QT>
class Queue
{
private:
    QueueNode<QT>* First = NULL;
    QueueNode<QT>* Last = NULL;

    /* data */
public:
    Queue(/* args */)
    {
        this->First = NULL;
    }
    ~Queue()
    {
    }
    bool IsEmpty()
    {
        return this->First == NULL;
    }
    void Push(QT value)
    {
        QueueNode<QT>* p = new QueueNode<QT>();
        p->Value = value;
        if (this->First == NULL)
        {
            this->First = p;
            this->Last = p;
            return;
        }
        this->Last->Next = p;
        this->Last = p;
    }
    QT Pop()
    {
        if (this->First == NULL)
        {
            throw "empty Queue";
        }
        QueueNode<QT>* First = this->First;
        this->First = First->Next;
        QT val = First->Value;
        delete First;
        return val;
    }
    QT Pick()
    {
        if (this->First == NULL)
        {
            throw "empty Queue";
        }
        QT val = First->Value;
        return val;
    }
};

