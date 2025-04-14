#include <bits/stdc++.h>
using namespace std;

class Graph {
private:
    int V; // Số đỉnh
    vector<vector<int>> adj; // Danh sách kề
public:
    Graph(int vertices) : V(vertices) {
        adj.resize(V);
    }

    // Thêm cạnh
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u); // Đồ thị vô hướng
    }

    // DFS sử dụng stack
    void DFS(int start) {
        vector<bool> visited(V, false);
        stack<int> s;
        s.push(start);

        while (!s.empty()) {
            int vertex = s.top();
            s.pop();

            if (!visited[vertex]) {
                cout << vertex << " ";
                visited[vertex] = true;

                // Thêm các đỉnh kề chưa thăm vào stack
                for (int neighbor : adj[vertex]) {
                    if (!visited[neighbor]) {
                        s.push(neighbor);
                    }
                }
            }
        }
        cout << endl;
    }
};

int main() {
    int num, vertice;
    cout << "CẢM ƠN BẠN ĐÃ SỬ DỤNG SẢN PHẨM CỦA TÔI ^^\n";
    cout << "Nhập số đỉnh của đồ thị: ";
    cin >> vertice;
    Graph g(vertice);
    
    cout << "Nhấn phím để lựa chọn hoạt động:\n";
    cout << "1: Thêm cạnh\n";
    cout << "2: Hiển thị\n";
    cout << "3: Ngưng sử dụng\n";

       cin >> num;
        if(num == 1){
            int u, v;
            cout << "Nhập hai đỉnh(cách nhau bởi dấu cách): ";
            cin >> u >> v;
            g.addEdge(u, v);
        }
        if(num == 2){
            int temp;
            cout << "Nhập stack bắt đầu: ";
            cin >> temp;
            g.DFS(temp);
        }
        if(num == 3) return 0;
    }
}  while(true){
        cout << "Vui lòng nhập số để sử dụng: ";
   