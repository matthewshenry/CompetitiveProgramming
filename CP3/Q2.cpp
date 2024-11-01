#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
    int n, m, time_passed = 0, count = 0;
    cin >> n;
    priority_queue<int, vector<int>, greater<int>> waitable_time;
    for(int i=0; i<n; i++){
        cin >> m;
        waitable_time.push(m);
    }
    while(n > 0){
        if(time_passed <= waitable_time.top()){
            time_passed += waitable_time.top();
            count++;
        }
        waitable_time.pop();
        n--;
    }
    cout << count;
}
