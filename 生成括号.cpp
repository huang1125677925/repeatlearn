class Solution {
    vector<string> ans;
public:
    void helper(string tmp, int n, int left, int right){
        if(right==n){
            ans.push_back(tmp);
            return;
        }
        if(left<n){//加左括号
            helper(tmp+"(", n, left+1, right);
        }
        if(right<left){//加右括号
            helper(tmp+")", n, left, right+1);
        }
        // 实际上这个也是一个典型的深度优先搜索的模版，关键是，这个是怎么生成所有可能结果的？？
        // 关于这个递归深度以及回去的过程
    }
public:
    vector<string> generateParenthesis(int n) {
        helper("",n,0,0);
        return ans;
    }
};