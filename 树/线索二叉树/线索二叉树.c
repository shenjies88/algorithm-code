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
			printf("\n��������ڵ�����:");
			scanf("%c",&node->date);
			node->left=NULL;
			node->right=NULL;
		}
		else
		{
			printf("�����ڴ�ʧ��\n");
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
				printf("��ڵ㲻Ϊ��\n");
				free(node);
				node=NULL;
			}

			else
			{
				parent->left=node;
				printf("\n��ӽڵ�ɹ�\n");
			}
		}
		else if (select==2)
		{
			if (parent->right)
			{
				printf("�ҽڵ㲻Ϊ��\n");
				free(node);
				node=NULL;
			}
			else
			{
				parent->right=node;
				printf("\n��ӽڵ�ɹ�\n");
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
		printf("\n��������ӽڵ������:");
		fflush(stdin);
		scanf("%c",&node->date);
		node->left=NULL;
		node->right=NULL;

		printf("\n�����븸�ڵ�����:");
		fflush(stdin);
		scanf("%c",&date);
		parent=FindNode(bt,date);//����ָ���ڵ�
		if (!parent)
		{
			printf("û�ҵ����ڵ�\n");
			free(node);
			node=NULL;
		}
		else
		{	
			do 
			{
				printf("\n������1������ڵ����2�����ҽڵ�:");
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
		printf("�����ڴ�ʧ��\n");
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
		printf("����һ�ſ���\n");
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
		printf("1��ʼ��������:   2��ӽڵ�:   \n");
		printf("3��������:       4�������������:\n");
		printf("0�˳�:\n");
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
				printf("\n�Ѿ���ʼ��\n");
			}
			break;
		case '2':
			AddNode(root);
			break;
		case '3':
			printf("��������������:\n");
			SCsortTree(root);
			break;
		case '4':
			printf("�����������������:");
			ZXsortTree(root);
			break;
		case '0':
			break;
		default:
			printf("������0~5������:\n");
			break;

		}
		printf("\n");
	} while (select!='0');
	ThreaBinTreeClear(root);
	root=NULL;
}