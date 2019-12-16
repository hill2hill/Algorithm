/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    int TreeDepth(TreeNode* pRoot)
    {
        if(pRoot == nullptr) return 0;
        int depth = 0;
        if(pRoot -> left == NULL && pRoot -> right == NULL) return 1;
        int left_depth = TreeDepth(pRoot -> left);
        int right_depth = TreeDepth(pRoot -> right);
        if (left_depth > right_depth)
        {
            depth = left_depth + 1;
        }
        else
        {
            depth = right_depth + 1;
        }
        
        //depth = 1 + TreeDepth(pRoot -> left) > TreeDepth(pRoot -> right) ? TreeDepth(pRoot -> left) : TreeDepth(pRoot -> right);
        return depth;
    }
};