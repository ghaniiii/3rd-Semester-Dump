void preOrder(node* root){
	if(root==NULL)
		return;
	else
	{	if(root==this->root){
			max=root->val;
			arr[length]=root->val;
			maxIndex=0;
			length++;
		}
		else if(length<3){
			
			arr[length]=root->val;
			
			if(max<root->val){
				max=root->val;
				maxIndex=length;
			}
			
			length++;
		}
		else{
			if(root->val<max){
				
				max=root->val;
				
				arr[maxIndex]=max;
				
				for(int i=0;i<3;i++){
					
					if(arr[i]>max){
						max=arr[i];
						maxIndex=i;
					}
			
				}
				
			}
		}
		preOrder(root->left);
		preOrder(root->right);
	}
}