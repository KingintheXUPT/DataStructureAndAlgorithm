#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
	char data;
	struct Node *Lchild;
	struct Node *Rchild;
}BiTNode,*BiTree ;

BiTree CreatBiTree(){//先序建立二叉树 
	BiTree s;
	char ch;
	ch=getchar();
	if(ch=='#') return NULL;//叶子结点的左右孩为空，记录为# 
	else{
		s=(BiTree)malloc(sizeof(BiTNode));//给每个节点申请内存 
		s->data=ch;
		s->Lchild=CreatBiTree();
		s->Rchild=CreatBiTree();
		return s;
	}
}

void PreOrder(BiTree root){//先序遍历二叉树 
	if(root){
		printf("%c",root->data);
		PreOrder(root->Lchild);
		PreOrder(root->Rchild);
	}
}

void InOrder(BiTree root){//中序遍历二叉树 
	if(root){
		InOrder(root->Lchild);
		printf("%c",root->data);
		InOrder(root->Rchild);
	}
}

void PostOrder(BiTree root){//后序遍历二叉树 
	if(root){
		PostOrder(root->Lchild);
		PostOrder(root->Rchild);
		printf("%c",root->data); 
	}
}

int PostCountleaf(BiTree root){//统计叶子节点数 
	int m,n;
	if(root==NULL) return 0;
	if(root->Lchild==NULL&&root->Rchild==NULL) return 1;
	m=PostCountleaf(root->Lchild);
	n=PostCountleaf(root->Rchild);
	return (m+n);
}

int PostOneleaf(BiTree root){//统计度数为1的节点数 
	int m=0;
	if(root==NULL) return 0;
	if((root->Lchild==NULL&&root->Rchild!=NULL)||(root->Lchild!=NULL&&root->Rchild==NULL)) m++;
	m+=PostOneleaf(root->Lchild);
	m+=PostOneleaf(root->Rchild);
	return m;
}

int PostTowleaf(BiTree root){//统计度数为二的节点数 
	int m=0;
	if(root==NULL) return 0;
	if(root->Lchild!=NULL&&root->Rchild!=NULL) m++;
	m+=PostTowleaf(root->Lchild);
	m+=PostTowleaf(root->Rchild);
	return m;
}

void InpreOrder(BiTree root){//输出叶子节点 
	if(root){
		InpreOrder(root->Lchild);
		if(root->Lchild==NULL&&root->Rchild==NULL){
			printf("%c",root->data);
		}
		InpreOrder(root->Rchild);	
	}
}

void ChangelOrder(BiTree root){//交换左右子树 
	BiTree p;
	if(root){
		if(root->Lchild!=NULL||root->Rchild!=NULL){
			p=root->Lchild;
			root->Lchild=root->Rchild;
			root->Rchild=p;		 
		}
		ChangelOrder(root->Lchild);
		ChangelOrder(root->Rchild);
	}	
}

void RouteToleaf(BiTree root,char arr[],int i){//统计根节点到叶子节点的路径
	int x=PostCountleaf(root);
	if(root){//判断root是否存在 	 
		arr[i]=root->data;//将root的值赋予数组中
		if(root->Lchild==NULL&&root->Rchild==NULL){
			printf("%c:",arr[i]);
			for(int j=0;j<i;j++){
				printf("%c",arr[j]);
			}
			printf("\n");
		}		
		RouteToleaf(root->Lchild,arr,i+1);
		RouteToleaf(root->Rchild,arr,i+1);
	}	 
}

void TreeText(BiTree root){//关于root存在问题的小测试 
	if(root){//root是否存在，而NULL与"不存在" 不一样. 
		printf("hehe");
		TreeText(root->Lchild);
		TreeText(root->Rchild);
	}
	if(root->Lchild!=NULL&&root->Rchild!=NULL){
		printf("leaf");
	} 
}

int PostTreeDepth(BiTree root){//判断树的深度 
	int h1,h2,h;
	if(root==NULL) return 0;
	else{
		h1=PostTreeDepth(root->Lchild);
		h2=PostTreeDepth(root->Rchild);
		h=(h1>h2? h1:h2)+1;
		return h;
	}
}

int TreeOutputRm(BiTree root,int x,int i){
	int h1,h2;
	if(root){
			if(root->Lchild==NULL&&root->Rchild==NULL&&i==x) return 1;
	h1=TreeOutputRm(root->Lchild,x,i+1);
	h2=TreeOutputRm(root->Rchild,x,i+1);
	return h1+h2;
	}
}

main(){
	BiTree root;
	root=CreatBiTree();
//	char arr[10];
//	RouteToleaf(root,arr,0);
	int x;
	scanf("%d",&x);
	int h=TreeOutputRm(root,x,1);
	printf("%d",h);	
} 
