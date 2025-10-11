class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int count = 0;
        
        for (std::size_t i = 0; i < std::size(arr); i++) {
            for (std::size_t j = i + 1; j < std::size(arr); j++) {
                for (std::size_t k = j + 1; k < std::size(arr); k++) {
                    if (std::abs(arr[i] - arr[j]) <= a &&
                       std::abs(arr[j] - arr[k]) <= b &&
                       std::abs(arr[k] - arr[i]) <= c) {
                        count++;
                    }
                }
            }
        }
        
        return count;
    }
};