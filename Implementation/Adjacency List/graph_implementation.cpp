#include<iostream>
#include<vector>
#include<unordered_set>
#include<queue>
#include<unordered_map>

using namespace std;

class Graph
{
    private:
        int vertex; // Total number of vertices
        unordered_map<int, vector<int> > adj_list;  // Graph implemented using adjacency list

    public:
        Graph(int v)    // constructor
        {
            this->vertex = v;   //set vertex
        }

        void createGraph()  // creating graph
        {
            for(int i = 0; i < this->vertex; i++)
            {
                int count = 0;
                cout<<"vertex "<<i<<" is connected to how many other vertices?"<<endl;
                cin>> count;    // count of connected vertices

                for(int j = 0; j < count; j++)
                {
                    int connected_vertex;
                    cout<<"Vertex "<<i<<" is connected to ";
                    cin>>connected_vertex;
                    this->adj_list[i].push_back(connected_vertex);  // adding connected vertex to respective index list
                }
            }
        }

        void print() // printing graph
        {
            cout<<endl<<"Printing graph..."<<endl;

            for(int i = 0; i < this->vertex; i++)
            {
                cout<<"Vertex "<<i<<" is connected to ";
                for(int j = 0; j < this->adj_list[i].size(); j++)  // adj_list[i] will provide vector present at index i
                {
                    cout<<this->adj_list[i][j]<<" ";
                }
                cout<<endl;
            }
        }

        void bfs(int source)
        {
            queue<int> q;
            unordered_set<int> visited;
            q.push(source);
            visited.insert(source);

            while(!q.empty())
            {
                int element = q.front();
                for(int i=0; i<this->adj_list[element].size(); i++)
                {
                    int connected_vertex = this->adj_list[element][i];
                    if(visited.find(connected_vertex) == visited.end())
                    {
                        cout<<connected_vertex<<" ";
                        q.push(connected_vertex);
                        visited.insert(connected_vertex);
                    }
                }
            }
        }
};

int main()
{
    cout<<"Enter the number of vertices in the graph"<<endl;
    int v;
    cin>>v;
    Graph graph(v);
    graph.createGraph();
    graph.print();
    
    while(1)
    {
        int source;
        cout<<"On which vertex you want to apply bfs? : "<<endl;
        cin>>source;
        graph.bfs(source);
        cout<<endl<<endl;
    }
    
}