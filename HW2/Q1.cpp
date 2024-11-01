#include <iostream>
#include <vector>
#include <queue>
using namespace std;

long long annoy(vector<pair<long long,long long>> coworkers,long long num_help){
  long long most_annoyance = 0;
    priority_queue<pair<long long,long long>, vector<pair<long long,long long>>, greater<pair<long long,long long>>> minheap;
    for (auto &coworker : coworkers){
        minheap.push({coworker.first+coworker.second, coworker.second});
    }
    while(num_help--){
        auto least_annoyed = minheap.top();
        minheap.pop();
      long long current_annoyance = least_annoyed.first;
      long long a_increase = least_annoyed.second;
      current_annoyance += a_increase;
      minheap.push({current_annoyance, a_increase});
    }
    while (!minheap.empty()){
        most_annoyance = max(most_annoyance, minheap.top().first-minheap.top().second);
        minheap.pop();
    }
    return most_annoyance;
}

int main(){
  long long num_help;
    cin >> num_help;
  long long num_coworkers;
    cin >> num_coworkers;
  long long annoyance;
  long long a_increase;
    vector<pair<long long,long long>> coworkers;
    for(int i=0; i<num_coworkers; i++){
        cin >> annoyance;
        cin >> a_increase;
        coworkers.push_back(make_pair(annoyance, a_increase));
    }
    cout << annoy(coworkers, num_help) << endl;
    return 0;
}
//VJudge Name: henrymatthews
//I don't know why it won't let me name Q1 "Q1.cpp" and instead keeps adding suffixes to all of them. Apologies.
