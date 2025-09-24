class TreeNode {
    int val;
    TreeNode left, right;
    @SuppressWarnings("unused")
    TreeNode(int x) {
        val = x;
    }
}

public class AncestralGuardian {
    public int findGuardian(TreeNode root, int id1, int id2) {
        TreeNode lca = findLCA(root, id1, id2);
        while (lca != null) {
            if (isPrime(lca.val)) return lca.val;
            lca = getParent(root, lca.val);
        }
        return -1;
    }

    private TreeNode findLCA(TreeNode root, int p, int q) {
        if (root == null) return null;
        if (root.val == p || root.val == q) return root;
        TreeNode left = findLCA(root.left, p, q);
        TreeNode right = findLCA(root.right, p, q);
        if (left != null && right != null) return root;
        return left != null ? left : right;
    }

    private TreeNode getParent(TreeNode root, int val) {
        if (root == null) return null;
        if ((root.left != null && root.left.val == val) ||
            (root.right != null && root.right.val == val)) {
            return root;
        }
        TreeNode left = getParent(root.left, val);
        if (left != null) return left;
        return getParent(root.right, val);
    }

    private boolean isPrime(int n) {
        if (n < 2) return false;
        if (n == 2) return true;
        if (n % 2 == 0) return false;
        for (int i = 3; i * i <= n; i += 2) {
            if (n % i == 0) return false;
        }
        return true;
    }
}