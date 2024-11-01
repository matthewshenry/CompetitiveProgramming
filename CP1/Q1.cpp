#include <iostream>
#include <string>
#include <set>
#include <unordered_map>
using namespace std;

int main() {
    int n;
    cin >> n;
    string name;
    set<string> list;
    unordered_map<string, int> name_count;
    while (n--) {
        cin >> name;
        if (list.insert(name).second){
            cout << "OK" << endl;
            name_count[name] = 0;
        }else{
            int count = ++name_count[name];
            string answer = name + to_string(count);
            while(!list.insert(answer).second){
                count = ++name_count[name];
                answer = name + to_string(count);
            }
            cout << answer << endl;
        }
    }
    return 0;
}

