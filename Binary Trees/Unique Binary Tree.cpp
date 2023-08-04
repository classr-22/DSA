int uniqueBinaryTree(int a, int b){
    // Write your code here.
    if(a==b)
        return false;
    else if(a==1 && b==3 || a==3 && b==1)
        return false;
    else
        return true;

}
