//序列化二叉树

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res;
        queue<TreeNode*> que;  //队列
        que.push(root);
        while(!que.empty()){
            TreeNode* p=que.front();
            que.pop();
            if(p==NULL){
                res+="null,";  //string型
            }
            else{
                res+=to_string(p->val)+",";
                que.push(p->left);
                que.push(p->right);
            }
        }
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode* r=NULL;
        vector<string> arr;
        string tmp;
        for(int i=0;i<data.size();i++){
            if(data[i]==','){   //用”#”表示一个字符串的首地址！！所以要用单引号！！
                arr.push_back(tmp);
                tmp="";
            }
            else{
                tmp+=data[i];
            }
        }
        if(arr[0]=="null"){
            return r;
        }
        queue<TreeNode*> que;
        TreeNode* root=new TreeNode(stoi(arr[0]));
        que.push(root);
        int i=1;
        TreeNode *q;
        while(!que.empty() && i<arr.size()){
            q=que.front();
            que.pop();
            if(arr[i]!="null"){
                q->left=new TreeNode(stoi(arr[i]));
                que.push(q->left);
            }
            i++;
            if(i>data.size()){
                break;
            }
            if(arr[i]!="null"){
                q->right=new TreeNode(stoi(arr[i]));
                que.push(q->right);
            }
            i++;
        }
        return root;
    }
};