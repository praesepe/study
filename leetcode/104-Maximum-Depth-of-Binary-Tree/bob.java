/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Solution {
    public int length(TreeNode root,int maxDepth) {
        if(root == null) {
            return maxDepth;
        }
        
        maxDepth += 1;
        int leftMaxDepth = root.left == null ?  maxDepth : length(root.left, maxDepth);
        int rightMaxDepth = root.right == null ?  maxDepth : length(root.right, maxDepth);
        
        return rightMaxDepth > leftMaxDepth ? rightMaxDepth : leftMaxDepth;
    }
    
    public int maxDepth(TreeNode root) {
        return length(root, 0);
    }
}
