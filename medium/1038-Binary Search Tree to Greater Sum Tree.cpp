// Given the root of a binary search tree with distinct values, modify it so
// that every node has a new value equal to the sum of the values of the
// original tree that are greater than or equal to node.val.
// 
// As a reminder, a binary search tree is a tree that satisfies these
// constraints:
// 
// The left subtree of a node contains only nodes with keys less than the
// node's key.  The right subtree of a node contains only nodes with keys
// greater than the node's key.  Both the left and right subtrees must also be
// binary search trees.

class Solution {
public:
    TreeNode* bstToGst(TreeNode* root) {
	vector<TreeNode*> s(100), ts(100);
	s.clear(), ts.clear();
	auto p = root;
	while (p || !ts.empty()) {
	    while (p) {
	    	ts.push_back(p);
	    	p = p->left;
	    }
	    p = ts.back(), ts.pop_back();
	    s.push_back(p);
	    p = p->right;
	}
	int record = 0;
	for (auto node = s.rbegin(); node != s.rend(); ++node) {
	    (*node)->val += record;
	    record = (*node)->val;
	}
        return root;
    }
};
