#include<iostream>
#include<vector>
#include<unordered_set>
#include<queue>

using namespace std;

class Graph
{
    private:
        int vertex_count;
        vector<vector<bool> > graph;

    public:

        Graph(int n)
        {
            this->vertex_count = n;
            for(int i=0;i<vertex_count;i++)
            {
                vector<bool> temp;
                for(int j=0;j<vertex_count;j++)
                {
                    temp.push_back(false);
                }
                graph.push_back(temp);
            }
        }

        void create_graph()
        {
            for(int i=0; i<vertex_count; i++)
            {
                for(int j=i+1; j<vertex_count; j++)
                {   
                    bool ans;
                    cout<<"Vertex "<<i<<" and Vertex "<<j<<" is connected?"<<endl;
                    cin>>ans;
                    graph[i][j] = ans;
                    graph[j][i] = ans;
                }
            }
        }

        void print_graph()
        {
            for(int i=0; i<vertex_count; i++)
            {
                cout<<"Vertex "<<i<<" : ";
                for(int j=0; j<vertex_count; j++)
                {
                    if(graph[i][j] == true)
                        cout<<j<<" ";
                }
                cout<<endl;
            }
        }

        void bfs(int source)
        {
            unordered_set<int> visited;
            queue<int> q;
            q.push(source);
            visited.insert(source);

            while(!q.empty())
            {
                int current_vertex = q.front();
                cout<<current_vertex<<" ";

                for(int i=0; i<vertex_count; i++)
                {
                    if(current_vertex != i && graph[current_vertex][i] == true && visited.find(i) == visited.end())
                    {
                        q.push(i);
                        visited.insert(i);
                    }
                }
                q.pop();
            }
            cout<<endl;
        }
};

int main()
{
    Graph gr(5);
    gr.create_graph();
    gr.print_graph();
    while(1)
    {
        int source;
        cout<<"Enter the source vertex : ";
        cin>>source;
        gr.bfs(source);
        cout<<endl;
    }
    
}
