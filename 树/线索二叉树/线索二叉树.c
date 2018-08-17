#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
typedef enum{Subtree,Threa}NodeFlag;
typedef char DATA;

typedef struct BinsortTree
{
	DATA date;
	NodeFlag lflag;
	NodeFlag rflag;
	struct BinsortTree *left;
	struct BinsortTree *right; 

}ThreaBinTree;
ThreaBinTree *Previous=NULL;

ThreaBinTree *ThreaBinTreeinit()
{
	ThreaBinTree *node;
	
		if (node=(ThreaBinTree*)malloc(sizeof(ThreaBinTree)))
		{
			printf("\n请输入根节点数据:");
			scanf("%c",&node->date);
			node->left=NULL;
			node->right=NULL;
		}
		else
		{
			printf("分配内存失败\n");
			exit(0);
		}
		return node;


}

ThreaBinTree *FindNode(ThreaBinTree *bt,char date)
{
	ThreaBinTree *p;
	if (bt==NULL)
	{
		return NULL;
	}
	else 
	{
		if (bt->date==date)
		{
			return bt;
		}
		else if (p=FindNode(bt->left,date))
		{
			return p;
		}
		else if (p=FindNode(bt->right,date))
		{
			return p;
		}
		else
			return NULL;
		
	}
}

void ThreaBinTreeAddNode(ThreaBinTree *parent,ThreaBinTree *node,char select)
{
		if (select==1)
		{
			if (parent->left)
			{
				printf("左节点不为空\n");
				free(node);
				node=NULL;
			}

			else
			{
				parent->left=node;
				printf("\n添加节点成功\n");
			}
		}
		else if (select==2)
		{
			if (parent->right)
			{
				printf("右节点不为空\n");
				free(node);
				node=NULL;
			}
			else
			{
				parent->right=node;
				printf("\n添加节点成功\n");
			}
		}
}


void AddNode(ThreaBinTree *bt)
{
	ThreaBinTree *node=NULL;
	ThreaBinTree *parent=NULL;
	DATA date;
	char select;
	if (node=(ThreaBinTree*)malloc(sizeof(ThreaBinTree)))
	{
		printf("\n请输入添加节点的数据:");
		fflush(stdin);
		scanf("%c",&node->date);
		node->left=NULL;
		node->right=NULL;

		printf("\n请输入父节点数据:");
		fflush(stdin);
		scanf("%c",&date);
		parent=FindNode(bt,date);//查找指定节点
		if (!parent)
		{
			printf("没找到父节点\n");
			free(node);
			node=NULL;
		}
		else
		{	
			do 
			{
				printf("\n请输入1加入左节点或者2加入右节点:");
				fflush(stdin);
				select=getchar();
				select-='0';
				if (select==1||select==2)
				{
					ThreaBinTreeAddNode(parent,node,select);
						
				}

			} while (select!=1&&select!=2);
		}

	}
	else
	{
		printf("分配内存失败\n");
		exit(0);
	}

}

void SCsortTree(ThreaBinTree *bt)
{
	if (bt)
	{
		SCsortTree(bt->left);
		bt->lflag=(bt->left)?Subtree:Threa;
		bt->rflag=(bt->right)?Subtree:Threa;
		if (Previous)
		{
			if (Previous->rflag==Threa)
			{
				Previous->right=bt;
			}
			if (bt->lflag==Threa)
			{
				bt->left=Previous;
			}
		}
		Previous=bt;
		SCsortTree(bt->right);
	}
}

ThreaBinTree *ThreaBinTreeNextNode(ThreaBinTree *bt)
{
	ThreaBinTree *node=NULL;
	if (bt->rflag==Threa)
	{
		return bt->right;
	}
	else
	{
		node=bt->right;
		while(node->lflag==Subtree)
			node=node->left;
		return node;
	}
	

}

void ZXsortTree(ThreaBinTree *bt)
{
	if (bt==NULL)
	{
		printf("这是一颗空树\n");
		return;
	}
	else
	{
		while(bt->lflag==Subtree)
			bt=bt->left;
		do 
		{
			printf("%c ",bt->date);
			bt=ThreaBinTreeNextNode(bt);
		} while (bt);
	}
}

void ThreaBinTreeClear(ThreaBinTree *root)
{
	if (root)
	{
		if (root->left!=NULL&&root->lflag==Subtree)
		{
			ThreaBinTreeClear(root->left);
		}
		if (root->right!=NULL&&root->rflag==Subtree)
		{
			ThreaBinTreeClear(root->right);
		}
		free(root);
	}
}

void main()
{
	char select;
	ThreaBinTree *root=NULL;
	do 
	{
		printf("1初始化线索树:   2添加节点:   \n");
		printf("3树线索化:       4中序遍历线索树:\n");
		printf("0退出:\n");
		select=getch();
		switch(select)
		{
		case '1':
			if (root==NULL)
			{
				root=ThreaBinTreeinit();
			}
			else
			{
				printf("\n已经初始化\n");
			}
			break;
		case '2':
			AddNode(root);
			break;
		case '3':
			printf("生成线索二叉树:\n");
			SCsortTree(root);
			break;
		case '4':
			printf("中序遍历线索二叉树:");
			ZXsortTree(root);
			break;
		case '0':
			break;
		default:
			printf("请输入0~5的数字:\n");
			break;

		}
		printf("\n");
	} while (select!='0');
	ThreaBinTreeClear(root);
	root=NULL;
}