/*
输入一颗二叉树的跟节点和一个整数，
打印出二叉树中结点值的和为输入整数的所有路径。
路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。
(注意: 在返回值的list中，数组长度大的数组靠前)---------------测试用例中与书中并未要求此条件*/

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
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
    	vector<vector<int> > res;
    	vector<int> path;
    	//局部变量，可以使用引用传递
    	if(root == nullptr)	return res;
    	searchPath(root, expectNumber, &res, &path);//引用传递不能在这里加'&'
    	return res;
    }

    void searchPath(TreeNode* root,int expectNumber, vector<vector<int> > &res, vector<int> &path){
    	path.push_back(root->val);
    	if(root->val == expectNumber && !root->left && !root->right){//假如当前节点已经满足条件了，但是其延伸下去的路径依然可以满足条件（对应后两个判断，给它的左右子树一个机会）
    		res.push_back(path);
    	}
    	else{
    		if(root->left){
    			searchPath(root->left,expectNumber-root->val,res,path);//引用传递不能在这里加'&'
    		}
    		if(root->right){
    			searchPath(root->right,expectNumber-root->val,res,path);//引用传递不能在这里加'&'
    		}
    	}
    	path.pop_back();//当前节点和其左右子树都访问完了
    }
};