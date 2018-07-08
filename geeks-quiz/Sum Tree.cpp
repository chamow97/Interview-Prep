int giveSum(Node *temp)
{
    if(!temp)
    {
        return 0;
    }
    return temp -> data + giveSum(temp -> left) + giveSum(temp -> right);
}

bool isSumTree(Node* root)
{
    if(root == NULL)
    {
        return true;
    }
    else if(root -> left == NULL && root -> right == NULL)
    {
        return true;
    }
    else if(root -> data == giveSum(root -> left) + giveSum(root -> right))
    {
        if(isSumTree(root -> left) && isSumTree(root -> right))
        {
            return true;
        }
        return false;
    }
    else
    {
        return false;
    }    
}