#include <iostream>
#include <list>
#include <cstring>

using namespace std;

class hashTable
{
    private:
    static const int mySize = 5;
    list<pair<int, string> > table[mySize]; 
    public:
    hashTable();
    ~hashTable();
    int hashFunction(int key);
    void print();
    void put(int key, string value);
    void remove(int key);
};
hashTable::hashTable()
{
   // table[mySize];
}
hashTable::~hashTable(){};
int hashTable::hashFunction(int key)
{
    return (key % mySize);
}
void hashTable::put(int key, string value)
{
    int index = hashFunction(key);
   //list<pair<int, string> > cell = table[index];
    auto & cell = table[index];
    auto bItr = begin(cell);
    bool keyExists = false;
    for(; bItr != end(cell); bItr++)
    {
        if(bItr->first == key)
        {
            keyExists = true;
             bItr->second = value; 
             cout << "[WARNING] Value is being replaced.";
              //cout << "\nKey:   " << key << " ";
              //cout << "Value: " << value << endl;
             break;
        }
    }
    if(!keyExists)
    {
         //cell.emplace_back(std::make_pair(key, value));
         cell.push_back(std::make_pair(key, value));
       //  cout << "\nKey:   " << key << " ";
       //  cout << "Value: " << value << endl;
         
    }
    return;
}
void hashTable::print() 
{
    for (int i = 0; i < mySize; i++){
        int index = i;
        auto & cell = table[index];
        auto bItr = begin(cell);
        for(; bItr != end(cell); bItr++)
        {
            cout << "Key: " << bItr->first << " ";
            cout << "Value: " << bItr->second << endl;
        }
    }
}
void hashTable::remove(int key)
{
     int index = hashFunction(key);
     auto & cell = table[index];
     auto bItr = begin(cell);
     bool keyExists = false;
     for(; bItr != end(cell); bItr++)
     {
        if(bItr->first == key)
        {
            keyExists = true;
        //    cout << "\nKey:   " << key << " ";
            bItr = cell.erase(bItr);
  
        }
     }
     if (!keyExists){
         cout << "Key not found, nothing removed" << endl;
     }
}

int main()
{
     hashTable hash;
     hash.put(10, "Teddy Bear");
     hash.put(20, "Shovel");
     hash.put(7, "Socks");

     hash.remove(20);
     hash.print();

    return 0; 
}