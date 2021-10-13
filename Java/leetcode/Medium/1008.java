/*
[LeetCode] 1008. Construct Binary Search Tree from Preorder Traversal
https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/
*/

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    int idx;
    public TreeNode bstFromPreorder(int[] preorder) {
        return makeTree(preorder, Integer.MAX_VALUE);
    }
    
    private TreeNode makeTree(int[] preorder, int bound) {
        if (idx >= preorder.length || preorder[idx] > bound) 
            return null;
        TreeNode root = new TreeNode(preorder[idx]);
        root.left = makeTree(preorder, preorder[idx++]);
        root.right = makeTree(preorder, bound);
        return root;
    }
}
