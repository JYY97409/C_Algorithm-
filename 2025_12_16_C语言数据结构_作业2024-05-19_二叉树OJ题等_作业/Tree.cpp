#include"Tree.h"
#include"Queue.h"

// 通过前序遍历的数组"ABD##E#H##CF##G##"构建二叉树


BTNode* BinaryTreeCreate(BTDataType* arr, int* pi)
{
	BTDataType val = (arr[(*pi)++]);
	if (val == '\0')
		return nullptr;
	if (val == '#')
		return nullptr;
	BTNode* root = (BTNode*)malloc(sizeof(BTNode));
	assert(root);
	root->val = val;
	root->left = BinaryTreeCreate(arr, pi);
	root->right = BinaryTreeCreate(arr, pi);
	return root;
}
// 二叉树销毁
void BinaryTreeDestory(BTNode** root)
{
	if (nullptr == *root)
		return;
	BinaryTreeDestory(&(*root)->left);
	BinaryTreeDestory(&(*root)->right);
	free(*root);

}
// 二叉树节点个数
int BinaryTreeSize(BTNode* root)
{
	if (nullptr == root)
		return 0;
	return BinaryTreeSize(root->left) 
		+ BinaryTreeSize(root->right) + 1;
}
// 二叉树叶子节点个数
int BinaryTreeLeafSize(BTNode* root)
{
	if (nullptr == root)
		return 0;
	if (nullptr == root->left && nullptr == root->right)
		return 1;
	return BinaryTreeLeafSize(root->left) 
		+ BinaryTreeLeafSize(root->right);
}
// 二叉树第k层节点个数
int BinaryTreeLevelKSize(BTNode* root, int k)
{
	if (nullptr == root)
		return 0;
	if (nullptr != root && 1 == k)
		return 1;
	return BinaryTreeLevelKSize(root->left, k - 1) 
		+ BinaryTreeLevelKSize(root->right, k - 1);
}
// 二叉树查找值为x的节点
BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	if (nullptr == root)
		return nullptr;
	if (root && x == root->val)
		return root;

	BTNode* ret1 = BinaryTreeFind(root->left, x); 
	if (ret1 != nullptr)
		return ret1;
	BTNode* ret2 = BinaryTreeFind(root->right, x);
	if (ret2 != nullptr)
		return ret2;
	
	return nullptr;//漏掉的点-------------------------------------------------
	
}
// 二叉树前序遍历 
void BinaryTreePrevOrder(BTNode* root)
{
	if (nullptr == root)
	{
		printf("N ");
		return;
	}
	printf("%d ", root->val);
	BinaryTreePrevOrder(root->left);
	BinaryTreePrevOrder(root->right);
}
// 二叉树中序遍历
void BinaryTreeInOrder(BTNode* root)
{
	if (nullptr == root)
	{
		printf("N ");
		return;
	}
	BinaryTreeInOrder(root->left);
	printf("%d ", root->val);
	BinaryTreeInOrder(root->right);
}
// 二叉树后序遍历
void BinaryTreePostOrder(BTNode* root)
{
	if (nullptr == root)
	{
		printf("N ");
		return;
	}
	BinaryTreePostOrder(root->left);
	BinaryTreePostOrder(root->right);
	printf("%d ", root->val);
}
// 层序遍历
void BinaryTreeLevelOrder(BTNode* root)
{
	if (nullptr == root)
		return;
	Queue* qt = QueueInit();
	QueueAdd(qt,root);//不用加if判空，不然就逻辑冗余了--------------------
	while (!isEmpty(qt))
	{
		NodeType front = QueuePop(qt);
		if (nullptr != front)
		{
			printf("%d ", front->val);
			if (front->left)
				QueueAdd(qt, front->left);
			if (front->right)
				QueueAdd(qt, front->right);
		}
	}
	QueueDestory(qt);
}

// 判断二叉树是否是完全二叉树
bool BinaryTreeComplete(BTNode* root)
{
	if (nullptr == root)
		return false;
	Queue* qt = QueueInit();
	QueueAdd(qt, root);//之前加了if，出现逻辑冗余---------------------------------
	while (!isEmpty(qt))
	{
		NodeType front = QueuePop(qt);
		if (nullptr == front)
			break;
		QueueAdd(qt, front->left);
		QueueAdd(qt, front->right);
	}
	while (!isEmpty(qt))
	{
		BTNode* ret = QueuePop(qt);
		if (nullptr != ret)
		{
			QueueDestory(qt);
			return false;
		}
	}
	QueueDestory(qt);
	return true;
}