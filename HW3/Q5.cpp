class Solution {
public:
    int hIndex(vector<int>& citations) {
        int papers = citations.size();
        vector<int> count(papers + 1, 0);
        for (int c : citations){
            if (c >= papers) {
                count[papers]++;
            } else {
                count[c]++;
            }
        }
        int total = 0;
        for (int i = papers; i >= 0; i--){
            total += count[i];
            if (total >= i) {
                return i;
            }
        }
        return 0;
    }
};