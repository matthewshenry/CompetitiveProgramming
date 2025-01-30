class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper){
        long long sum = 0;
        vector<long long> prefixSums ={0};
        for(int num : nums){
            sum += num;
            prefixSums.push_back(sum);
        }
        return countAndMergeSort(prefixSums, 0, prefixSums.size(), lower, upper);
    }

private:
    int countAndMergeSort(vector<long long>& sums, int start, int end, int lower, int upper){
        if(end - start <= 1) return 0;
        int mid = start + (end - start) / 2;
        int count = countAndMergeSort(sums, start, mid, lower, upper) +
                    countAndMergeSort(sums, mid, end, lower, upper);

        int j = mid, k = mid, t = mid;
        vector<long long> cache;
        for(int i = start; i < mid; ++i){
            while(k < end && sums[k] - sums[i] < lower) ++k;
            while(j < end && sums[j] - sums[i] <= upper) ++j;
            while(t < end && sums[t] < sums[i]) cache.push_back(sums[t++]);
            cache.push_back(sums[i]);
            count += j - k;
        }
        for(int i = 0; i < t - start; ++i) sums[start + i] = cache[i];
        return count;
    }
};
