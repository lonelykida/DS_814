#include "test.hpp"

int main(){
    int arr[5] = {3,1,2,5,4};
    // BTree*root = CreateBTree(arr,5);
    BTree*root = CreateBST(arr,5);
    PreOrderTree(root);    //测试传统非递归后续遍历
    return 0;
}