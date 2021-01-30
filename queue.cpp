#include <iostream>
using namespace std;

struct node{
    int data;
    node *next;
};

template<typename T>
class myQueue
{
    public:
    myQueue();
    ~myQueue();
    void enqueue(T x);
    void dequeue();
    T peek();
    bool isEmpty() const; 
    private:
    node *head;
    node *tail;

};
template<typename T>
myQueue::myQueue(){
    head = nullptr;
    tail = nullptr;
};
template<typename T>
T myQueue::peek()
{
    return head->data;
}
template<typename T>
myQueue::~myQueue(){};
void myQueue::enqueue(T x)
{
    node *temp = new node();
    temp->data =x;
    if (isEmpty()){
        head = temp;
        tail = temp;        
    }
    else{
        tail->next = temp;
        tail = temp; 
        //tail->next = temp;
        //temp = tail; 
    }
}
template<typename T>
void myQueue::dequeue()
{
    if (isEmpty()){
        cout << "Cannot remove from empty queue!";
    }
    else{
        node *temp;
        head = head->next;
        temp = head;
        delete(temp);
    }
}

bool myQueue::isEmpty() const
{
    return head == nullptr;
}


int main()
{
    myQueue queue;
    queue.enqueue(9);
    cout << queue.peek();
    queue.enqueue(8);
    cout << queue.peek();
    queue.enqueue(7);
    cout << queue.peek();
    cout << "\nDequeue the halls\n";
    queue.dequeue();
    cout << queue.peek() << endl;
    return 0;
}