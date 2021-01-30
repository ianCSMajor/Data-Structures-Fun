#include <iostream>
using namespace std;
struct node{
    int data;
    node *next;
}

class priority_queue
{
    private:
    node *head;

    public: 
    priority_queue();
    ~priority_queue();
    void insert(const int x);
    int min() const;
    void removeMin();
};
priority_queue::priority_queue(){
    head = nullptr;
};
priority_queue::~priority_queue(){};
void priority_queue::insert(const int x)
{
    node *current = new node()
    current->data = x;
    node *index = head;
    //check from the start (index value)
    bool inserted = false;  
    while (!inserted){
        if (x < index->data || index == nullptr)
            //insert 
            if (index == nullptr){
                index 
            }
            
            inserted = true;
        else{
            //go to next value 
        }
    }
}


int main()
{

    return 0; 
}