#### 二叉树遍历

```java
struct TreeNode {
    int val;
    TreeNode left, right;
}

void traverse(TreeNode root) {
    // 前序遍历代码位置
    traverse(root.left);
    // 中序遍历代码位置
    traverse(root.right);
    // 后序遍历代码位置
}

// 层级遍历
void traverse(TreeNode root) {
    if (root == null) return;
    // 初始化队列，将root加入队列
    Queue<TreeNode> q = new LinkedList<>();
    q.offer(root);
    
    while (q.isEmpty()) {
        TreeNode cur = q.poll();
        
        /* 层级遍历代码位置*/
        System.out.println(root.val);
        /**********/
        
        if (cur.left != null) {
            q.offer(cur.left);
        }
        
        if (cur.right != null) {
            q.offer(cur.right);
        }
    }

}
```

#### N叉树遍历

```java
class TreeNode {
    int val;
    TreeNode[] children;
}

void traverse(TreeNode root) {
    for (TreeNode child : root.children) {
        traverse(child);
    }
}
```



