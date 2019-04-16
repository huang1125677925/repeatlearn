class Solution {
public:
    vector<vector<int>> result;
    int N;
    void dfs(int count,vector<int>& res,int k){
        if(!count) result.push_back(res);
            if(N-k<count-1) return;
            for(int i=k;i<=N;i++){
                res.push_back(i);
                dfs(count-1,res,i+1);
                res.pop_back();
            }
    }
    vector<vector<int>> combine(int n, int k) {
        N=n;
        vector<int> res;
        dfs(k,res,1);
        return result;
    }
};