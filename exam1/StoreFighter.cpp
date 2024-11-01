//#include <iostream>
//#include <vector>
//#include <queue>
//using namespace std;
//
//int main() {
//    int n, j, t;
//    cin >> n >> j >> t;
//    vector<queue<int>> queues(n);
//    for(int i=0; i<n; i++){
//        for(int l=0; l<j; l++){
//            int move;
//            cin >> move;
//            queues[i].emplace(move);
//        }
//    }
//    int total=0;
//    while(t--){
//        priority_queue<int> pq;
//        int max_val=0;
//        int max_line=0;
//        for(int i=0; i<n; i++){
//            pq.push(queues[i].front());
//            if(queues[i].front() == pq.top()){
//                max_line = i;
//            }
//            queues[i].pop();
//        }
//        total += pq.top();
//        pq.pop();
//        pq.push(queues[max_line].front());
//        if(queues[max_line].empty()){
//            queues[max_line].emplace(0);
//        }
//
//    }
//    cout << total;
//}

//#include <iostream>
//#include <vector>
//#include <queue>
//using namespace std;
//
//int main() {
//    int n, j, t;
//    cin >> n >> j >> t;
//    vector<queue<int>> queues(n);
//    for(int i=0; i<n; i++){
//        for(int l=0; l<j; l++){
//            int move;
//            cin >> move;
//            queues[i].emplace(move);
//        }
//    }
//    int total=0;
//    while(t--){
//        int max_val=0;
//        int max_line=0;
//        for(int i=0; i<n; i++){
//            if(queues[i].front() > max_val){
//                max_val = queues[i].front();
//                max_line = i;
//            }
//        }
//        total += queues[max_line].front();
//        queues[max_line].pop();
//        if(queues[max_line].empty()){
//            queues[max_line].emplace(0);
//        }
//
//    }
//    cout << total;
//}

//#include <iostream>
//#include <vector>
//#include <queue>
//using namespace std;
//
//int main() {
//    int n, j, t;
//    int total = 0;
//    cin >> n >> j >> t;
//    int tot = n*j;
//    int v;
//    priority_queue<int> pq;
//    for(int i=0; i<tot; i++){
//        cin >> v;
//        pq.push(v);
//    }
//    if(t > tot){
//        t = tot;
//    }
//    while(t--){
//        total += pq.top();
//        pq.pop();
//    }
//    cout << total;
//}