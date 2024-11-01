#include <iostream>
#include <string>
#include <set>
using namespace std;

string distracted(string tasks) {
    char current_task = tasks[0];
    set<char> started;
    for(char s : tasks){
        if(s != current_task){
            if(started.count(s)){
                return "NO";
            }
            started.insert(current_task);
            current_task =s;
        }
    }
    return "YES";
}

int main() {
    int num_inputs;
    cin >> num_inputs;
    while (num_inputs--) {
        int n;
        string tasks;
        cin >> n;
        cin >> tasks;
        cout << distracted(tasks) << endl;
    }
    return 0;
}
