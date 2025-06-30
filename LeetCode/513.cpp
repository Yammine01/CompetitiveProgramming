#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


int findBottomLeftValue(TreeNode* root) {
    queue<TreeNode*> queue;
    int answer;

    queue.push(root);

    while (!queue.empty())
    {
        int size = queue.size();
        for(int i = 0; i < size; ++i) {
            TreeNode* front = queue.front();
            queue.pop();

            if(i == 0) answer = front->val;

            if(front->left) queue.push(front->left);
            if(front->right) queue.push(front->right);
        }
    }
    return answer;
}


int main(int argc, char const *argv[])
{

    return 0;
}
