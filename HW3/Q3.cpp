#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int t, quality, price;
    vector<pair<int, int>> computers;
    cin >> t;
    for(int i=0; i<t; i++) {
        cin >> quality;
        cin >> price;
        computers.push_back({price, quality});
    }
    sort(computers.begin(), computers.end());
    for(int i=1; i<t; i++) {
        if(computers[i].second < computers[i-1].second){
            if(computers[i].first > computers[i-1].first){
                cout << "Happy Alex";
            }
            return 0;
        }
    }
    cout << "Poor Alex";
    return 0;
}
