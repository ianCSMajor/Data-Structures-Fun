#include <iostream>
#include <map>
#include <list>
using namespace std;
// struct NodeStruct
// {
//     string myLabel;
// };
class graph
{
    private:
         //Don't use the list stl because the item could be at the end of the list
            //That could result in linear time. Use a has table 
        class NodeClass
        {
       
            private:
            string label;
            public:
            NodeClass(string label)
            {
                this->label = label;
            }
        };

   map<string, NodeClass> nodes;
   map<NodeClass, list<NodeClass>> adjacencyList;
    public:
            void addNode(string label);
            void addEdge(string from, string to);

};
        void graph::addNode(string label)
        {
            NodeClass *node = new NodeClass(label);
            map<string, NodeClass>::iterator it = nodes.find(label);
            if(it != nodes.end())
            {
                //element found 
               //1.  *node = it->second;
                cout << "Element found";
                nodes.emplace(label, node);
                adjacencyList.emplace(node, nodes);
            }

        }
        void graph::addEdge(string from, string to)
        {
            NodeClass fromNode = nodes.at(from);
            if(fromNode == nullptr) 
            {
                std::out_of_range;
            }
            NodeClass toNode = nodes.at(to);
            if(toNode == nullptr)
            {
                std::out_of_range;
            }
        adjacencyList.at(fromNode).insert(toNode);
        adjacencyList.at(toNode).insert(fromNode);


        }

int main()
{

    return 0;
}