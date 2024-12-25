#include <iostream>
#include <vector>
#include <queue>
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 

class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        if(root==NULL){
            return {};
        }
        vector<int> ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            priority_queue<int> a;
            int size = q.size();
            for(int i = 0;i<size;i++){
                TreeNode* temp = q.front();
                q.pop();
                a.push(temp->val);
                if(temp->left){q.push(temp->left);}
                if(temp->right){ q.push(temp->right);} 
            }
            ans.push_back(a.top());   
        }
        return ans;
    }
};

int main(){
    Solution s;
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->right = new TreeNode(2);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(4);
    vector<int> ans = s.largestValues(root);
    for(auto i:ans){
        std::cout<<i<<" ";
    }
    return 0;
}