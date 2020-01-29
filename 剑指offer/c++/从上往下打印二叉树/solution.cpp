/*从上往下打印出二叉树的每个节点，同层节点从左至右打印。*/

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
    vector<int> PrintFromTopToBottom(TreeNode* root) {
    	vector<int> result;
    	if(root == nullptr)	return result;

    	queue<TreeNode*> q;//使用模板------队列数据结构
    	q.push(root);

    	while(!q.empty()){
    		node = q.front();
    		result.push_back(node->val);
    		if(node->left!=NULL)	q.push(node->left);
    		if(node->right!=NULL)	q.push(node->right);
    		q.pop();
    	}

    	return result;
    }
};