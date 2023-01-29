// 1st solution - by brute force
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        for (int i=0;i<(nums.size()-1);i++){
            for (int j=i+1;j<nums.size();j++){
                if(nums[i] + nums[j] == target){
                    ans.push_back(i);
                    ans.push_back(j);
                    return ans;
                }
            }
        }
        return ans;
    }
};

/*
2nd solution - use hash map
learned:
1. unordered_map -> use map.count()
2. {a, b, ...} can make vector
3.  처음에는 (값, 인덱스) 인 튜플을 사용하려고 했었다 -> 그것 대신 key: 값 value: 인덱스 인 map 을 사용하는 게 훨씬 효율적! 
심지어 count() 까지 있어서 굳이 hash 함수를 다 만들 필요 없이 손쉽게 코드를 짤 수 있다.
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> visited;
        vector<int> ans;
        for (int i=0;i<nums.size();i++){
            int tag = target - nums[i];
            if(visited.count(tag)){
                ans.push_back(min(i, visited[tag]));
                ans.push_back(max(i, visited[tag]));
                return ans;
            }
            visited[nums[i]] = i;
        }
        return ans;
    }
};