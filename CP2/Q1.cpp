#include <iostream>
#include <vector>
using namespace std;

int schedule(int n, vector<pair<int, int>> times){
    vector<int> removables;
    for(int i=0; i<times.size(); i++){

    }
}

int main(){
    int n;
    cin >> n;
    vector<pair<int, int>> times;
    pair<int, int> startend;
    while(n--){
        cin >> startend.first;
        cin >> startend.second;
        times.push_back(startend);
    }
    schedule(n, times);
}
