/*approach 1: */

void inorderTrsl(TreeNode* root, vector<int> &inorder){
    if(root==NULL){
        return;
    }

    //LNR
    inorderTrsl(root->left, inorder);
    inorder.push_back(root->data);
    inorderTrsl(root->right, inorder);
}

vector<int> mergeArrays(vector<int> a, vector<int> b){
    vector<int> ans(a.size()+b.size());

    int i=0, j=0;
    int k = 0;

    while(i<a.size() and j<b.size()){
        if(a[i] < b[j]){
            ans[k++]=a[i];
            i++;
        }
        else{
            ans[k++]=b[j];
            j++;
        }
    }

    while(i<a.size()){
        ans[k++]=a[i];
        i++;
    }

    while(j<b.size()){
        ans[k++]=b[j];
        j++;
    }

    return ans;
}


TreeNode* inorderToBST(int st, int ed, vector<int> &inorder){
    //base case
    if(st>ed){
        return NULL;
    }

    int mid = (st+ed)/2;

    TreeNode* root = new TreeNode(inorder[mid]);

    root->left = inorderToBST(st, mid-1, inorder);
    root->right = inorderToBST(mid+1, ed, inorder);

    return root;
}


vector<int> mergeBST(TreeNode *root1, TreeNode *root2)
{
    //step1 : Convert BST into Sorted DLL in-place
    TreeNode* head1 = NULL;
    convertIntoSortedDLL(root1, head1);
    head1->left = NULL;

    TreeNode* head2 = NULL;
    convertIntoSortedDLL(root2, head2);
    head2->left = NULL;

    //step 2 : merge sorted Linked List
    TreeNode* head = mergeLL(head1, head2);

    //Step 3 : Convert SLL into BST
    return sortedLLToBST(head, countNodes(head));
    
}


/************************************************************/
/*approach 2: */

void inorderTrsl(TreeNode* root, vector<int> &inorder){
    if(root==NULL){
        return;
    }

    //LNR
    inorderTrsl(root->left, inorder);
    inorder.push_back(root->data);
    inorderTrsl(root->right, inorder);
}

vector<int> mergeArrays(vector<int> a, vector<int> b){
    vector<int> ans(a.size()+b.size());

    int i=0, j=0;
    int k = 0;

    while(i<a.size() and j<b.size()){
        if(a[i] < b[j]){
            ans[k++]=a[i];
            i++;
        }
        else{
            ans[k++]=b[j];
            j++;
        }
    }

    while(i<a.size()){
        ans[k++]=a[i];
        i++;
    }

    while(j<b.size()){
        ans[k++]=b[j];
        j++;
    }

    return ans;
}

void convertIntoSortedDLL(TreeNode* root, TreeNode* &head){
    //base case
    if(root==NULL){
        return NULL;
    }

    convertIntoSortedDLL(root->right, head);

    root->right = head;
    if(head!=NULL){
        head->left = root;
    }
    
    head = root;

    convertIntoSortedDLL(root->left, head);
}

TreeNode* mergeLL(TreeNode* head1, TreeNode* head2){
    TreeNode* head = NULL;
    TreeNode* tail = NULL;

    while(head1!=NULL and head2!=NULL){
        if(head1->data < head2->data){
            if(head==NULL){
                head = head1;
                tail = head1;
                head1 = head1->right;
            }
            else{
                //insert at end
                tail->right = head1;
                head1->left = tail;
                tail = head1;
                head1 = head1->right;
            }
        }
        else{
            if(head==NULL){
                head = head2;
                tail = head2;
                head2 = head2->right;
            }
            else{
                //insert at end
                tail->right = head2;
                head2->left = tail;
                tail = head2;
                head2 = head2->right;
            }
        }
    }

    //checking each LL individually 
    while(head1!=NULL){
        tail->right = head1;
        head1->left = tail;
        tail = head1;
        head1 = head1->right;
    }

    while(head2!=NULL){
        tail->right = head2;
        head2->left = tail;
        tail = head2;
        head2 = head2->right;
    }

    return head;
}

int countNodes(TreeNode* head){
    int cnt = 0;

    TreeNode* temp = head;
    while(temp!=NULL){
        cnt++;
        temp=temp->right;
    }

    return cnt;
}

TreeNode* sortedLLToBST(TreeNode* &head, int n){
    //base case
    if(n<=0 or head==NULL){
        return NULL;
    }

    TreeNode* left = sortedLLToBST(head, n/2);

    //create root node
    TreeNode* root = head;
    root->left = left;

    head = head->next;

    root->right = sortedLLToBST(head, n-n/2-1);

    return root;
}

vector<int> mergeBST(TreeNode *root1, TreeNode *root2)
{
    //step1 : Convert BST into Sorted DLL in-place
    TreeNode* head1 = NULL;
    convertIntoSortedDLL(root1, head1);
    head1->left = NULL;

    TreeNode* head2 = NULL;
    convertIntoSortedDLL(root2, head2);
    head2->left = NULL;

    //step 2 : merge sorted Linked List
    TreeNode* head = mergeLL(head1, head2);

    //Step 3 : Convert SLL into BST
    return sortedLLToBST(head, countNodes(head));
    
}