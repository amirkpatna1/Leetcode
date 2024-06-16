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
    
    public boolean func(TreeNode root, long mx, long mn) {
        if(root == null) return true;
        boolean left = func(root.left, root.val, mn);
        boolean right = func(root.right, mx, root.val);
        boolean flag = root.val < mx && root.val > mn;
        return flag && left && right;
    }
    
    public boolean isValidBST(TreeNode root) {
        return func(root, (long)1e12, (long)-1e12);
    }
}