/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */

class Solution {
    
    public TreeNode func(TreeNode root, TreeNode p, TreeNode q) {
        if(root == null) return null;
        if((root == p || root == q)) return root;
        boolean a = root.val < p.val;
        boolean b = root.val < q.val;
        if(a ^ b) return root;
        if(a) return func(root.right, p, q);
        return func(root.left, p, q);
    }
    
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        return func(root, p, q);
    }
}