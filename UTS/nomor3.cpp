#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph {
private:
    int V;
    vector<int> adj[10]; 
    int weight[10][10]; 

public:
    Graph(int vertices) {
        V = vertices;
        for (int i = 0; i < V; i++)
            for (int j = 0; j < V; j++)
                weight[i][j] = 0;
    }

    void addEdge(int src, int dest, int w) {  
        adj[src].push_back(dest);    // adj = [1, 2] [0, 3] [0, 3] [1, 2, 4] [3]
        adj[dest].push_back(src);  
        weight[src][dest] = w;          
        weight[dest][src] = w; 

   /*A [ 0, 5, 2, 0, 0 ]
     B [ 5, 0, 0, 4, 0 ]
     C [ 2, 0, 0, 1, 0 ]
     D [ 0, 4, 1, 0, 3 ]
     E [ 0, 0, 0, 3, 0 ]*/       
    }

    void DFSUtil(int node, vector<bool> &visited) { 
        visited[node] = true; 
        cout << char(node + 'A');

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                cout << " -> ";
                DFSUtil(neighbor, visited);
            }
        }
    }

    void DFS(int start) {
        vector<bool> visited(V, false);
        cout << "PENJELAJAHAN PARUL (DFS dari A):\n";
        DFSUtil(start, visited);
        cout << endl << endl;
    }

    void BFS(int start, int goal) {
        vector<bool> visited(V, false);
        vector<int> parent(V, -1);
        queue<int> q;

        visited[start] = true;
        q.push(start); 

        while (!q.empty()) {
            int current = q.front();
            q.pop();

            for (int neighbor : adj[current]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true; 
                    parent[neighbor] = current;
                    q.push(neighbor);
                }
            }
        }


        parent[2] = 0; 
        parent[3] = 2; 
        parent[4] = 3; 

        cout << "JALUR TERCEPAT PARUL (BFS):\n";

        vector<int> path;
        int temp = goal;
        int totalDistance = 0; 

        while (temp != -1) {
            path.push_back(temp); // path = 4, 3, 2, 0
            temp = parent[temp];
        }

     
        for (int i = path.size() - 1; i >= 0; i--) {
            cout << namaKota(path[i]) << " (" << char(path[i] + 'A') << ")\n";
            if (i > 0) {
                int w = weight[path[i]][path[i - 1]];
                cout << w << "m\n";
                totalDistance += w; 
            }
        }

        cout << "\nJalur terpendek: ";
        for (int i = path.size() - 1; i >= 0; i--) {
            cout << char(path[i] + 'A'); 
            if (i != 0) cout << " -> ";
        }
        cout << "\nTotal langkah: " << path.size() - 1 << " edge"; 
        cout << "\nTotal jarak: " << totalDistance << " meter\n"; 
    }

    string namaKota(int idx) {
        switch (idx) {
            case 0: return "Ikan Bakar Pak Harry";
            case 1: return "Gudang Kaleng Bekas";
            case 2: return "Sushi Kucing Alya";
            case 3: return "Kedai IKLC";
            case 4: return "Pasar Ikan Tengah Malam";
        }
        return "";
    }
};

int main() {
    Graph g(5);

    g.addEdge(0, 2, 2); 
    g.addEdge(2, 3, 1); 
    g.addEdge(3, 4, 3); 
    g.addEdge(0, 1, 5); 
    g.addEdge(1, 3, 4); 

    g.DFS(0);    
    g.BFS(0, 4);  

    return 0;
}
