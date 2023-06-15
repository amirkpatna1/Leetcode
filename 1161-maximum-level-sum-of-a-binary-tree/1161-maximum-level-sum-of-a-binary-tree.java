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
    public int maxLevelSum(TreeNode root) {
        Queue<TreeNode> q = new LinkedList<TreeNode>();
        q.offer(root);
        int level = 1, maxLevel = 1, maxSum = -1000000000;
        while(q.size() > 0) {
            int n = q.size(), currSum = 0;
            while(n-- > 0) {
                TreeNode currNode = q.poll();
                currSum += currNode.val;
                if(currNode.left != null) q.offer(currNode.left);
                if(currNode.right != null) q.offer(currNode.right);
            }
            if(currSum > maxSum) {
                maxSum = currSum;
                maxLevel = level;
            }
            level += 1;
        }
        return maxLevel;
    }
}