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
    
    public void connectNode(TreeNode root, Map<TreeNode, TreeNode> backNode) {
        if(root == null) return ;
        if(root.left != null) backNode.put(root.left, root);
        if(root.right != null) backNode.put(root.right, root);
        connectNode(root.left, backNode);
        connectNode(root.right, backNode);
    }
    
    public List<Integer> distanceK(TreeNode root, TreeNode target, int k) {
        Map<TreeNode, TreeNode> backNode = new HashMap<>();
        connectNode(root, backNode);
        Queue<TreeNode> q = new LinkedList<>();
        
        q.add(target);
        Set<TreeNode> vis = new HashSet<>();
        List<Integer> ans = new ArrayList<>();
        while(!q.isEmpty()) {
            int sz = q.size();
            while(sz-- > 0) {
                TreeNode node = q.poll();
                if(vis.contains(node)) continue;
                vis.add(node);
                if(k == 0)
                  ans.add(node.val);
                if(node.left != null) q.add(node.left);
                if(node.right != null) q.add(node.right);
                if(backNode.containsKey(node)) q.add(backNode.get(node));
            }
            if(k == 0) return ans;
            k -= 1;
        }
        return ans;
    }
}