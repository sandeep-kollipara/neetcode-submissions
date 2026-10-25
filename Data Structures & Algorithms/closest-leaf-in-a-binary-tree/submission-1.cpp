class Solution {
    struct trio{
        int kdist;
        int leafdist;
        int leafval;
    };
public:
    int findClosestLeaf(TreeNode* root,int k){
        trio closest = {INT_MAX/2,INT_MAX/2,-1};
        auto dfs=[&](auto&& self, TreeNode* node)->trio{
            // base case or termination
            if (not node) return {INT_MAX/2,INT_MAX/2,-1};
            // post-order traversal
            trio left_depth = self(self, node->left);
            if (left_depth.kdist!=INT_MAX/2) left_depth.kdist++;
            if (left_depth.leafdist!=INT_MAX/2) left_depth.leafdist++;
            trio right_depth = self(self, node->right);
            if (right_depth.kdist!=INT_MAX/2) right_depth.kdist++;
            if (right_depth.leafdist!=INT_MAX/2) right_depth.leafdist++;
            // calc k distance, minimize the leaf distance
            trio center = {INT_MAX/2,INT_MAX/2,-1};
            if (node->val==k) center.kdist = 0;
            if (not node->left and not node->right){
                center.leafdist = 0;
                center.leafval = node->val;
            }
            if (center.leafdist > left_depth.leafdist) {
                center.leafdist = left_depth.leafdist;
                center.leafval = left_depth.leafval;
            }
            if (center.leafdist > right_depth.leafdist) {
                center.leafdist = right_depth.leafdist;
                center.leafval = right_depth.leafval;
            }
            center.kdist = min(center.kdist, left_depth.kdist);
            center.kdist = min(center.kdist, right_depth.kdist);
            if (center.kdist+center.leafdist < closest.kdist+closest.leafdist) {
                closest = center;
            }
            return center;
        };
        dfs(dfs, root).leafval;
        return closest.leafval;
    }
};
