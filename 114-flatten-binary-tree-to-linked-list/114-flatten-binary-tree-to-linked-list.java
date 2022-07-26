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
    public void flatten(TreeNode root) {

        if(root == null){

            return;

        }

        

        TreeNode left = root.left;

         TreeNode right = root.right;

        

        flatten(left);

        if(left != null){

            root.right = left;

            root.left = null;

            

            

            TreeNode curr = root;

            while(curr.right != null){

                curr = curr.right;

            }

            curr.right = right;

            

        }

        

        flatten(root.right);

        

    }
}