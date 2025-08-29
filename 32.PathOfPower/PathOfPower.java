class PathOfPower{

    public class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;
        @SuppressWarnings("unused")
        TreeNode() {}
        @SuppressWarnings("unused")
        TreeNode(int val) { this.val = val; }
        @SuppressWarnings("unused")
        TreeNode(int val, TreeNode left, TreeNode right) {
            this.val = val;
            this.left = left;
            this.right = right;
        }
    }

    private int maxPathValue;

    public int maxPathSum(TreeNode root) {
        maxPathValue = Integer.MIN_VALUE;
        findMaxPath(root);
        return maxPathValue;
    }

    private int findMaxPath(TreeNode node) {
        if (node == null) {
            return 0;
        }

        int leftPath = Math.max(0, findMaxPath(node.left));
        int rightPath = Math.max(0, findMaxPath(node.right));

        maxPathValue = Math.max(maxPathValue, node.val + leftPath + rightPath);

        return node.val + Math.max(leftPath, rightPath);
    }
}