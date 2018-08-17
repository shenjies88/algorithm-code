#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
	int parent;
	int weight;
	int left;
	int right;
}Huffman;
typedef char* HuffmanCode;

void SelectNode(Huffman *ht,int n,int *bt1,int *bt2)
{
	int i;
	Huffman *h1,*h2,*t;
	h1=NULL;
	h2=NULL;
	for (i=1;i<=n;i++)
	{
		if (!ht[i].parent)
		{
			if (h1==NULL)
			{
				h1=ht+i;
				continue;
			}
			if (h2==NULL)
			{
				h2=ht+i;
				if (h1->weight>h2->weight)//使h1是小值
				{
					t=h1;
					h1=h2;
					h2=t;
				}
				continue;
			}
			if (ht[i].weight<=h1->weight)
			{
				h2=h1;
				h1=ht+i;
			}
			else if(ht[i].weight<h2->weight)
			{
				h2=ht+i;
			}

		}
	}
	if (h1>h2)//使bt1是下标小的，下标小的再左节点
	{
		*bt1=h2-ht;
		*bt2=h1-ht;
	}
	else
	{
		*bt1=h1-ht;
		*bt2=h2-ht;
	}
}



void CreateTree(Huffman *ht,int n,int *w)
{
	int m=n*2-1;
	int i,bt1,bt2;
	for (i=1;i<=n;i++)
	{
		ht[i].weight=w[i-1];
		ht[i].left=0;
		ht[i].right=0;
		ht[i].parent=0;
	}
	for (i=n+1;i<=m;i++)
	{
		ht[i].weight=0;
		ht[i].parent=0;
		ht[i].left=0;
		ht[i].right=0;
	}
	for (i=n+1;i<=m;i++)
	{
		SelectNode(ht,i-1,&bt1,&bt2);
		ht[bt1].parent=i;
		ht[bt2].parent=i;
		ht[i].left=bt1;
		ht[i].right=bt2;
		ht[i].weight=ht[bt1].weight+ht[bt2].weight;
	}
}


void HuffmanBM(Huffman *ht,int n,HuffmanCode *hc)
{
	int i,curren,start,parent;
	char *code;
	code=(char*)malloc(n*sizeof(char));
	code[n-1]='\0';
	for (i=1;i<=n;i++)
	{
		start=n-1;
		curren=i;
		parent=ht[i].parent;
		while(parent)
		{
			if (curren==ht[parent].left)
			{
				code[--start]='0';
			}
			else if (curren==ht[parent].right)
			{
				code[--start]='1';
			}
			curren=ht[curren].parent;
			parent=ht[curren].parent;
		}
		hc[i-1]=(HuffmanCode)malloc((n-start)*sizeof(char));
		strcpy(hc[i-1],&code[start]);
	}
}

void EhuffmanCode(HuffmanCode *hc,char *test,char *alphabet,char *code)
{
	int i=0,len=0,j;
	code[0]='\0';
	while(test[i])
	{
		for (j=0;j<4;j++)
		{
			if (alphabet[j]==test[i])
				break;	
			else
				continue;
		}
		strcpy(code+len,hc[j]);
		len=len+strlen(hc[j]);
		i++;
	}
	code[len]='\0';
}

void DhuffmanCode(Huffman *ht,char *alphabet,char *code1,char *code,int m)
{
	int i,position=0,j=0;
	
	while(code[position])
	{
		
		for (i=m;ht[i].left&&ht[i].right;position++)
		{
			if(code[position]=='0')
				i=ht[i].left;
			else if (code[position]=='1')
			{
				i=ht[i].right;
			}
		}
		code1[j]=alphabet[i-1];
		j++;
	}
		code1[j]='\0';
}



void main()
{
	int i,n=4,m;
	char test[]="DBDBDADBDCDADBDADBDADACDBDBD";
	char code[100],code1[100];
	char alphabet[]={'A','B','C','D'};
	int w[]={5,7,2,13};
	Huffman *ht;
	HuffmanCode *hc;
	m=2*n-1;
	if (!(ht=(Huffman*)malloc((m+1)*sizeof(Huffman))))
	{
		printf("分配内存失败\n");
		exit(0);
	}
	if (!(hc=(HuffmanCode*)malloc(n*sizeof(char*))))
	{
		printf("分配内存失败\n");
		exit(0);
	}
	CreateTree(ht,n,w);//创建Huffman 给ht赋值完毕
	for (i=1;i<=m;i++)
	{
		printf("%d ",ht[i].weight);
	}
	printf("\n");
    HuffmanBM(ht,n,hc);
	for (i=0;i<n;i++)
	{
		printf("编码后:%d=%s=%c\n",w[i],hc[i],alphabet[i]);
	}
	printf("\n");
	EhuffmanCode(hc,test,alphabet,code);
	printf("字符串:%s\n",test);
	printf("翻译后%s\n",code);
	printf("\n");
		
	DhuffmanCode(ht,alphabet,code1,code,m);
	printf("字符串:%s\n",code);
	printf("翻译后""%s\n",code1);
	printf("\n");

	printf("%c",hc[0][0]);
	printf("%c",hc[0][1]);
	printf("%c\n",hc[0][2]);

}