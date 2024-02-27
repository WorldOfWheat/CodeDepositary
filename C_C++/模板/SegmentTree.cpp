namespace SegmentTree 
{
    class NodeData
    {
    public:
        static NodeData combine(NodeData a, NodeData b)
        {
            NodeData combined;
            combined.value = a.value + b.value;
            return combined;
        }
        int value = 0;
        int lazy_tag = 0;
    };

    class TreeNode
    {
    public:
        TreeNode()
        {
            left = NULL;
            right = NULL;
        }

        TreeNode* left;
        TreeNode* right;
        NodeData data;
    };

    class Tree
    {
    public:
        void build(vector<int> &arr)
        {
            size = arr.size();
            build(arr, root, 0, size);
        }
        NodeData query(int index)
        {
            return query(root, index, index + 1, 0, size);
        }
        NodeData query(int index_left, int index_right)
        {
            return query(root, index_left, index_right, 0, size);
        }
        void update(int value, int index)
        {
            update(root, value, index, index + 1, 0, size);
        }
        void update(int value, int index_left, int index_right)
        {
            update(root, value, index_left, index_right, 0, size);
        }

    private:
        int size;
        TreeNode* root = new TreeNode();
        NodeData build(V arr, TreeNode* node, int left, int right)
        {
            if (left + 1 == right)
            {
                node->data.value = arr[left];
                return node->data;
            }
            int mid = (left + right) >> 1;
            node->left = new TreeNode();
            node->right = new TreeNode();
            NodeData left_data = build(arr, node->left, left, mid);
            NodeData right_data = build(arr, node->right, mid, right);
            NodeData combined = NodeData::combine(left_data, right_data);
            node->data = combined;
            return combined;
        }
        NodeData query(TreeNode* node, int index_left, int index_right, int left, int right)
        {
            if (index_left == left && index_right == right)
            {
                return node->data;
            }

            push_lazy_tag(node, left, right);

            int mid = (left + right) >> 1;
            if (index_right <= mid)
            {
                return query(node->left, index_left, index_right, left, mid);
            }
            if (index_left >= mid)
            {
                return query(node->right, index_left, index_right, mid, right);
            }

            NodeData left_data = query(node->left, index_left, mid, left, mid);
            NodeData right_data = query(node->right, mid, index_right, mid, right);
            return NodeData::combine(left_data, right_data);
        }
        void update(TreeNode* node, int value, int index_left, int index_right, int left, int right)
        {
            if (index_left == left && index_right == right)
            {
                node->data.lazy_tag += value;
                return;
            }

            push_lazy_tag(node, left, right);

            int mid = (left + right) >> 1;
            if (index_right <= mid)
            {
                update(node->left, value, index_left, index_right, left, mid);
                return;
            }
            if (index_left >= mid)
            {
                update(node->right, value, index_left, index_right, mid, right);
                return;
            }

            update(node->left, value, index_left, mid, left, mid);
            update(node->right, value, mid, index_right, mid, right);
        }
        void push_lazy_tag(TreeNode* node, int left, int right)
        {
            node->data.value += node->data.lazy_tag * (right - left);
            int mid = (left + right >> 1);
            node->left->data.value += node->data.lazy_tag * (mid - left);
            node->right->data.value += node->data.lazy_tag * (right - mid);
            node->left->data.lazy_tag += node->data.lazy_tag;
            node->right->data.lazy_tag += node->data.lazy_tag;
            node->data.lazy_tag = 0;
        }
    };
};
