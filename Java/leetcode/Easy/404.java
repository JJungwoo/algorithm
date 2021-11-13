/*
[LeetCode] 404. Sum of Left Leaves
https://leetcode.com/problems/sum-of-left-leaves/
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
    boolean isLeft;
    public int sumOfLeftLeaves(TreeNode root) {
        if (root.left == null && root.right == null) {
            if (isLeft) return root.val;
            else return 0;
        }
        
        int sum = 0;
        if (root.left != null) {
            isLeft = true;
            sum += sumOfLeftLeaves(root.left);
        } 
        if (root.right != null) {
            isLeft = false;
            sum += sumOfLeftLeaves(root.right);
        }
        return sum;
    }
}
