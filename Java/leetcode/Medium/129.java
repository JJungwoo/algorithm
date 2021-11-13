/*
[LeetCode] 129. Sum Root to Leaf Numbers
https://leetcode.com/problems/sum-root-to-leaf-numbers/
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
    List<Integer> visitNumberList = new ArrayList<>();
    public int sumNumbers(TreeNode root) {
        int sum = 0;
        visitNumberList.add(root.val);
        if (root.left == null && root.right == null) {
            for (int i=0;i<visitNumberList.size();i++) {
                sum += visitNumberList.get(i) * (Math.pow(10, visitNumberList.size() - i - 1));
            }
            return sum;
        }
        
        if (root.left != null) {
            sum += sumNumbers(root.left);
            visitNumberList.remove(visitNumberList.size() - 1);
        }
        if (root.right != null) {
            sum += sumNumbers(root.right);
            visitNumberList.remove(visitNumberList.size() - 1);
        }
        return sum;
    }
}
