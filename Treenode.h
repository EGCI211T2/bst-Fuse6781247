class TreeNode {   
                                        
   TreeNode *leftPtr; // pointer to left subtree 
   int data; // node value                               
   TreeNode *rightPtr; // pointer to right subtree
public:
        TreeNode(int); 
        ~TreeNode();
        void set_left(TreeNode* t);
        void set_right(TreeNode* t){rightPtr=t;}
        int get_value(){return data;}
        TreeNode* move_right(){ return rightPtr; }
        TreeNode* move_left(){ return leftPtr; }
    //void search_tree(TreeNode * crn ,int x );
       

}; // end structure treeNode 
        

typedef TreeNode * TreeNodePtr; 
// synonym for TreeNode*
void TreeNode::set_left(TreeNode *t){
  leftPtr=t;
}

TreeNode::TreeNode(int x){
   data =x;
   leftPtr=NULL;
   rightPtr=NULL;

}
TreeNode::~TreeNode(){
  cout<<"Deleting "<< data<<endl;
  
}
