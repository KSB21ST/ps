/*
first attempt - 배열의 인덱스가 사실은 사람의 인덱스를 의미하는 식으로
(예를 들어 첫 번째 사람이 신뢰 받으면 trusted의 인덱스1 의 값을 +1 해준다.)
*/
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        int trusting[1001] {};
        int trusted[1001] = {};
        for (auto c : trust){
            trusting[c[0]]++;
            trusted[c[1]]++;
        }
        for(int i=1;i<n+1;i++){
            if(trusting[i] == 0 && trusted[i] >= n-1){
                return i;
            }
        }
        return -1;
    }
};