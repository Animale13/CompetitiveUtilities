#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Graph{
private:
    int v;
    vector < vector <int> > adjList;
public:
    Graph(int numV){
        v = numV;
        adjList.resize(v);
    }
    void addEdge(int from, int to, bool direct = true){
        if(from!=to){
            adjList[from].push_back(to);
            if(!direct) adjList[to].push_back(from);
        }
        
    }
    void bfs(int s, bool print = false){
        vector <int> distances(v, -1);
        queue <int> q;
        int level = 0;
        q.push(s);
        distances[s] = 0;
        while(!q.empty()){
            int currNode = q.front();
            q.pop();
            if(level != distances[currNode] && print){
                cout<<endl;
                level = distances[currNode];
            }
            if(print) cout<<currNode<<" ";
            for(int i=0; i < adjList[currNode].size(); i++){
                if(distances[adjList[currNode][i]] == -1){
                    distances[adjList[currNode][i]] = distances[currNode]+1;
                    q.push(adjList[currNode][i]);
                }
            }

        }

    }

    void dfs(int s, bool print = false){
        vector <int> distances(v, -1);
        distances[s] = 0;
        dfs(s, distances, print);
    }

    void dfs(int s, vector <int> &distances, bool print = false){
        if(print) cout<<s<<" ";
        if(adjList[s].size()==0 && print)cout<<endl;
        for(int i=0; i < adjList[s].size(); i++){
            if(distances[adjList[s][i]] == -1){
                distances[adjList[s][i]] = distances[s]+1;
                this->dfs(adjList[s][i], distances, true);
            }
        }
        
    }

    

};

int main(){
    Graph g(5); 
    g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(1, 2); 
    g.addEdge(2, 0); 
    g.addEdge(2, 3); 
    g.addEdge(3, 3); 
    g.addEdge(2, 4); 
    g.bfs(0, true);
    cout<<endl;
    g.dfs(0, true);
}