#include <iostream>
#include <deque>
#include <queue>

using namespace std;
deque<int> deq;
queue<int> q;

int main() {
    int n, m;
    cin >> n >> m;
    
    for(int i=1; i <= n; i++){
        deq.push_back(i);
    }
    
    int count = 0;
    while (m--) {
        int findNumber;
        cin >> findNumber;
        int index = 0;
        
        for(int i= 0; i < deq.size(); i++){
            if(deq[i] == findNumber){
                index = i;
            }
        }
        if(index < deq.size()-index){
            while (1) {
                if (deq.front() == findNumber) {
                    deq.pop_front();
                    break;
                }
                ++count;
                deq.push_back(deq.front());
                deq.pop_front();
            }
        } else {
            while (1) {
                if (deq.front() == findNumber) {
                    deq.pop_front();
                    break;
                }
                ++count;
                deq.push_front(deq.back());
                deq.pop_back();
            }
        }
    }
    cout << count << "\n";
    return 0;
}
