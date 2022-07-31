#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int vertices;
    // pointer to an array of lists
    list<int> *l;

public:
    Graph(int v)
    {
        vertices = v;
        // l = new List<int> will create a single list
        // this creates an array of lists
        l = new list<int>[v];
    }

    void addEdge(int i, int j, bool undir = true)
    {
        l[i].push_back(j);
        if (undir)
        {
            l[j].push_back(i);
        }
    }

    void printAdjList()
    {
        // Iterate over all rows
        for (int i = 0; i < vertices; i++)
        {
            cout << i << " -> ";
            // every element of ith linked list
            for (auto node : l[i])
            {
                cout << node << ", ";
            }
            cout << endl;
        }
    }

    void printBfs(int src)
    {
        queue<int> q;
        bool *visited = new bool[vertices]{0};
        q.push(src);
        visited[src] = true;
        while (!q.empty())
        {
            int f = q.front();
            cout << f << ", ";
            q.pop();
            for (auto nbr : l[f])
            {
                if (!visited[nbr])
                {
                    q.push(nbr);
                    visited[nbr] = 1;
                }
            }
        }
    }

    void printDFSHelper(int node, bool *visited)
    {
        visited[node] = true;
        cout << node << ", ";
        for (auto nbr : l[node])
        {
            if (!visited[nbr])
            {
                printDFSHelper(nbr, visited);
            }
        }
        return;
    }

    void printDFS(int src)
    {
        bool *visited = new bool[vertices]{0};
        printDFSHelper(src, visited);
        return;
    }

    void topoDFS(int node, stack<int> &s, int visited[])
    {
        visited[node] = 1;
        for(auto nbr : l[node])
        {
            if(!visited[nbr])
                topoDFS(nbr, s, visited);
        }
        s.push(node);
    }

    void topological_sort_dfs(int n)
    {
        int visited[vertices] = {0};
        // memset(visited, 0, sizeof visited);
        stack<int> s;
        for(int i=1; i<n; i++)
        {
            if(!visited[i]) topoDFS(i, s, visited);
        }

        while(!s.empty())
        {
            cout<<s.top()<<", ";
            s.pop();
        }
    }

    void topological_sort_bfs()
    {
        vector<int> indegree(vertices, 0);

        // iterate over all the edges to find the right indegree
        for (int i = 0; i < vertices; i++)
        {
            for (auto nbr : l[i])
            {
                indegree[nbr]++;
            }
        }

        // bfs
        queue<int> q;
        // init the q with nodes having 0 indegree
        for (int i = 0; i < vertices; i++)
        {
            if (indegree[i] == 0)
                q.push(i);
        }

        while (!q.empty())
        {
            int node = q.front();
            cout << node << ", ";
            q.pop();

            for (auto nbr : l[node])
            {
                indegree[nbr]--;
                if (indegree[nbr] == 0)
                {
                    q.push(nbr);
                }
            }
        }
        return;
    }

    bool detectCycleDFS(int node, int parent, bool *visited)
    {
        visited[node] = 1;
        for (auto nbr : l[node])
        {
            if (!visited[nbr])
            {
                if (detectCycleDFS(nbr, node, visited))
                    return true;
            }
            else if (nbr != parent)
                return true;
        }
        return false;
    }

    detectCycleBFS(int node, int prev, bool *visit)
    {
        queue<pair<int, int>> q;
        q.push({node, -1});
        visit[node] = 1;
        while (!q.empty())
        {
            pair<int, int> f = q.front();
            q.pop();
            for (auto nbr : l[f.first])
            {
                if (!visit[nbr])
                {
                    q.push({nbr, f.first});
                    visit[nbr] = 1;
                }
                else if (nbr != f.second)
                    return true;
            }
        }
        return false;
    }

    bool detectCycle(int s)
    {
        bool *visited = new bool[vertices]{0};
        bool *visit = new bool[vertices]{0};
        bool ans = detectCycleDFS(s, -1, visited) && detectCycleBFS(s, -1, visit);
        delete[] visited;
        delete[] visit;
        return ans;
    }

    bool isBipartiteBFS(int node, int color[])
    {
        queue<int> q;
        q.push(node);
        color[node] = 1;
        while (!q.empty())
        {
            int f = q.front();
            q.pop();
            for (auto nbr : l[f])
            {
                if (color[nbr] == -1)
                {
                    color[nbr] = 1 - color[f];
                    q.push(nbr);
                }
                else if (color[nbr] == color[f])
                    return false;
            }
        }
        return true;
    }

    bool isBipartiteDFS(int node, int colors[])
    {
        for (auto nbr : l[node])
        {
            if (colors[nbr] == -1)
            {
                colors[nbr] = 1 - colors[node];
                if (!isBipartiteDFS(nbr, colors))
                    return false;
            }
            else if (colors[nbr] == colors[node])
                false;
        }
        return true;
    }

    bool isBipartite(int s)
    {
        int color[vertices];
        memset(color, -1, sizeof color);
        int colors[vertices];
        colors[s] = 1;
        memset(colors, -1, sizeof colors);
        // bool ans = isBipartiteBFS(s, color);
        bool ans = isBipartiteDFS(s, color) && isBipartiteBFS(s, colors);
        return ans;
    }

    bool isDirecCycleBFS()
    {
        vector<int> indegree(vertices+1, 0);

        for(int i=1; i<=vertices; i++)
        {
            for(auto nbr:l[i]) indegree[nbr]++;
        }

        queue<int> q;
        for (int i = 1; i <= vertices; i++)
        {
            if (indegree[i] == 0)
                q.push(i);
        }
        int count = 0;
        while (!q.empty())
        {
            int node = q.front();
            cout << node << ", ";
            q.pop();
            count++;
            for (auto nbr : l[node])
            {
                indegree[nbr]--;
                // if(indegree[nbr] < 0)return true;
                if (indegree[nbr] == 0)
                {
                    q.push(nbr);
                }
            }
        }
        
        return count == vertices ? true : false;
    }

    bool isDirecCycleDFS(int node, int visited[], int dfsVisited[])
    {
        visited[node] = 1;
        dfsVisited[node] = 1;
        for(auto nbr : l[node])
        {
            if(!visited[nbr])
            {
                if(isDirecCycleDFS(nbr, visited, dfsVisited)) return true;
            }
            else if(dfsVisited[node]) return true
            ;
        }
        dfsVisited[node] = 0;
        return false;
    }

    bool isDirecCycle(int s)
    {
        int visited[vertices], dfsVisited[vertices]; 
        bool ans = isDirecCycleDFS(s, visited, dfsVisited);
        return ans;
    }

    vector<int> shortestPathUndir(int src)
    {
        vector<int> distance(vertices, INT_MAX);
        queue<int> q;
        q.push(src);
        distance[src] = 0;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();

            for(auto nbr : l[node])
            {
                if(distance[node] + 1 < distance[nbr])
                {
                    distance[nbr] = distance[node] + 1;
                    q.push(nbr);
                }
            }
        }
        return distance;
    }
};

    vector<int> shortestPathDir(int src)
    {
        vector<int> distance(vertices, INT_MAX);
        queue<int> q;
        q.push(src);
        distance[src] = 0;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();

            for(auto nbr : l[node])
            {
                if(distance[node] + nbr.second < distance[nbr])
                {
                    distance[nbr] = distance[node] + 1;
                    q.push(nbr);
                }
            }
        }
        return distance;
    }
};

int main()
{
    Graph g(4);
    // g.addEdge(0, 1, false);
    g.addEdge(1, 2, false);
    g.addEdge(2, 3, false);
    g.addEdge(3, 4, false);
    g.addEdge(4, 2, false);
    // g.addEdge(3, 4, false);
    // g.addEdge(3, 6, false);
    // g.addEdge(4, 6, false);
    // g.addEdge(4, 5, false);
    // g.addEdge(5, NULL);
    // g.addEdge(1, 4);
    // g.addEdge(1, 2);
    // g.addEdge(0, 4);

    // g.printAdjList();

    // g.printDFS(1);

    // g.topological_sort();

    // cout << g.detectCycle(0);

    // cout << g.isDirecCycle(0);

    // g.topological_sort_dfs(7);

    cout << g.isDirecCycleBFS();

    return 0;
}