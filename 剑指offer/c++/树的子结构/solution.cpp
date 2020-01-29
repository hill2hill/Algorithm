/*输入两棵二叉树A，B，判断B是不是A的子结构。
（ps：我们约定空树不是任意一个树的子结构）

pps: 个人分析应该是指数值一样，但在计算机内并不是存在重合的存储空间，

否则只需要进行根节点的遍历搜索即可。
*/

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
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
    	if(pRoot1 == nullptr || pRoot2 == nullptr)	return false;

    	bool a = false, b = false, c = false;


    	//先序遍历各个节点
    	if(pRoot1 -> val == pRoot2 -> val){
    		//发现可能,就进行check
    		a = check(pRoot1, pRoot2);
    	}
    	b = HasSubtree(pRoot1-> left, pRoot2);
    	c = HasSubtree(pRoot1-> right, pRoot2);
    	
    	return a||b||c;

    }

    bool check(TreeNode* A, TreeNode* B){

    	if(B == NULL) return true;
    	if(A == NULL)	return false;
    	if(A -> val != B -> val)	return	false;
    	return	check(A -> left, B -> left) && check(A -> right,B -> right);
    }
};