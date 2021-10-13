/*
[LeetCode] 543. Diameter of Binary Tree
https://leetcode.com/problems/diameter-of-binary-tree/
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
    // input: root = [1,2,3,4,5]
    // output: 3
    int answer;
    public int diameterOfBinaryTree(TreeNode root) {
        maxPathInBTree(root);
        return answer;
    }
    
    private int maxPathInBTree(TreeNode root) {
        if (root == null) {
            return 0;
        }
        
        int left = maxPathInBTree(root.left);
        int right = maxPathInBTree(root.right);
        
        answer = Math.max(answer, left + right);
        
        return Math.max(left, right) + 1;
    }
}
