#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
using namespace std;

int keyword(vector<string>& words){
    set<string> unique_keywords;
    for (string word : words){
        for (int i = 0; i < word.length(); ++i){
            word[i] = tolower(word[i]);
        }
        replace(word.begin(), word.end(), '-', ' ');
        unique_keywords.insert(word);
    }
    return unique_keywords.size();
}

int main(){
    int n;
    cin >> n;
    vector<string> words;
    string word;
    for (int i = 0; i < n; ++i){
        cin >> ws;
        getline(cin, word);
        words.push_back(word);
    }
    cout << keyword(words) << endl;
    return 0;
}
