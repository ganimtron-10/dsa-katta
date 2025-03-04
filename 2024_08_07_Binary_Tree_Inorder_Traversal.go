// https://leetcode.com/problems/binary-tree-inorder-traversal/ 

/** * Definition for a binary tree node. 
    * type TreeNode struct { 
	* Val int 
	* Left *TreeNode 
	* Right *TreeNode 
	* } 
*/ 

func inorder(root * TreeNode, valueList * [] int) {
    if root == nil {
        return
    }
    inorder(root.Left, valueList) 
	*valueList = append( * valueList, root.Val)
    inorder(root.Right, valueList)
}
func inorderTraversal(root * TreeNode)[] int {
    var valueList[] int
    inorder(root, & valueList)
	return valueList
}