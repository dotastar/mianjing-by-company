class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> v = numbers;
        vector<int> r(2);
        int n = v.size();
        sort(v.begin(), v.end());
        int i = 0, j = n-1;
        while(i < j) {
            int sum = v[i] + v[j];
            if(sum > target) j--;
            else if(sum < target) i++;
            else {
                int k = 0;
                for(k = 0; k < n; k++) {
                    if(numbers[k] == v[i]) break;
                }
                int index1 = k+1;
                for(k = 0; k < n; k++) {
                    if(numbers[k] == v[j] && k != index1 - 1) break;
                }
                int index2 = k+1;
                r[0] = min(index1, index2);
                r[1] = max(index1, index2);
                return r;
            }
        }
        return r;
    }
};
