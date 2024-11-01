#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int greedy_lawn(int l, vector<pair<double, double>> sprinklers){
    // (starting position, interval length)
    double current = 0.0;
    int i = 0;
    int count = 0;
    double max = 0.0;
    while(current < l) {
        double prev_max = max;
        while (i < sprinklers.size() && sprinklers[i].first <= current) {
            if (sprinklers[i].first + sprinklers[i].second > max) {
                max = sprinklers[i].first + sprinklers[i].second;
            }
            i++;
        }
        if(prev_max==max){
            return -1;
        }
        current = max;
        count++;
    }
    return count;

}

int main(){
    int n, l, w, radius, pos;
    while(cin >> n >> l >> w){
        vector<pair<double, double>> sprinklers;
        for(int i=0; i<n; i++){
            cin >> pos;
            cin >> radius;
            if(radius > w / 2.0){
                double x = sqrt(pow(radius, 2) - pow(w / 2.0, 2));
                sprinklers.push_back({pos - x, 2 * x});
            }
        }
        sort(sprinklers.begin(), sprinklers.end(), [](const pair<double, double>& a, const pair<double, double>& b) {
            return a.first < b.first;
        });
        cout << greedy_lawn(l, sprinklers) << endl;
    }
    return 0;
}