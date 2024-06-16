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
    
    static class Pair {
        int idx = 0;
        TreeNode node;
        Pair(int idx, TreeNode node) {
            this.idx = idx;
            this.node = node;
        }
    }
    
    public int widthOfBinaryTree(TreeNode root) {
        LinkedList<Pair> q = new LinkedList<>();
        
        q.add(new Pair(0, root));
        int ans = 0;
        while(!q.isEmpty()) {
            int val = q.getLast().idx - q.getFirst().idx + 1;
            ans = Math.max(ans, val);
            int sz = q.size();
            int mn = q.getFirst().idx;
            while(sz-- > 0) {
                Pair p = q.poll();
                TreeNode node = p.node;
                int index = p.idx - mn;
                if(node.left != null) q.add(new Pair(2 * index + 1, node.left));
                if(node.right != null) q.add(new Pair(2 * index + 2, node.right));
                
            }
        }
        
        return ans;
    }
}