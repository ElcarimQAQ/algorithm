#include <bits/stdc++.h>
using namespace std;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode *father;
     TreeNode(int x) : val(x), left(NULL), right(NULL), father(NULL) {}
};

class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* p) {
        if(p->father == NULL){
            if(p->right != NULL)
                return p->right;
            else
                return NULL; 
        }
        else{
            if(p->right == NULL && p->father == NULL)
            return NULL;
            if(p->right == NULL)
                return p->father;
            if(p->father == NULL)
                return p->right;
        }
    }
};
int main()
{
    Solution s;
    int x;
    cin>>x;
    TreeNode(x);
    s.inorderSuccessor(n);
    return 0;
}