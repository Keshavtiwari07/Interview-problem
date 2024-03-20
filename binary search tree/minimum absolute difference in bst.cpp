class Solution {
public:
    int getMinimumDifference(TreeNode *root) {
        // support variables
        int res = INT_MAX, pos = 1;
        TreeNode *st[25], *curr = root, *prev = NULL;
        // DFS!
        while (pos) {
            // going left as long as possible
            while (curr != NULL) {
                st[pos++] = curr;
                curr = curr -> left;
            }
            // extracting the current top of the stack
            curr = st[--pos];
            // updating values and moving right if we are not done
            if (pos) {
                // updating res and prev
                if (prev) res = min(res, curr->val - prev->val);
                prev = curr;
                curr = curr -> right;
            }
        }
        return res;
    }
};