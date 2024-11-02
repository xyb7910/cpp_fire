#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int val;
    int nxt;
};

int main() {
    int n, M;
    cin >> n;
    
    vector<Node> l(n + 1); 
    int head = 1; 
    

    for (int i = 1; i <= n; ++i) {
        cin >> l[i].val >> l[i].nxt;
    }
    
    cin >> M;
    while (M--) {
        int id;
        cin >> id;
     
        if (id == head) {
           
            head = l[id].nxt;
        } else {
           
            for (int i = head; i != -1; i = l[i].nxt) {
                if (l[i].nxt == id) {
                    l[i].nxt = l[id].nxt; 
                    break;
                }
            }
        }
    }
    

    for (int i = head; i != -1; i = l[i].nxt) {
        cout << l[i].val << " ";
    }
    cout << endl;
    
    return 0;
}