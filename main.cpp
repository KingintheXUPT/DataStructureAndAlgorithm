#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
	char data;
	struct Node *Lchild;
	struct Node *Rchild;
}BiTNode,*BiTree ;

BiTree CreatBiTree(){
	BiTree s;
	char ch;
	ch=getchar();
	if(ch=='#') return NULL;
	else{
		s=(BiTree)malloc(sizeof(BiTNode));
		s->data=ch;
		s->Lchild=CreatBiTree();
		s->Rchild=CreatBiTree();
		return s;
	}
}

void PreOrder(BiTree root){
	if(root){
		printf("%c",root->data);
		PreOrder(root->Lchild);
		PreOrder(root->Rchild);
	}
}

void InOrder(BiTree root){
	if(root){
		InOrder(root->Lchild);
		printf("%c",root->data);
		InOrder(root->Rchild);
	}
}

void PostOrder(BiTree root){
	if(root){
		PostOrder(root->Lchild);
		PostOrder(root->Rchild);
		printf("%c",root->data); 
	}
}

int PostCountleaf(BiTree root){
	int m,n;
	if(root==NULL) return 0;
	if(root->Lchild==NULL&&root->Rchild==NULL) return 1;
	m=PostCountleaf(root->Lchild);
	n=PostCountleaf(root->Rchild);
	return (m+n);
}

int PostOneleaf(BiTree root){
	int m=0;
	if(root==NULL) return 0;
	if((root->Lchild==NULL&&root->Rchild!=NULL)||(root->Lchild!=NULL&&root->Rchild==NULL)) m++;
	m+=PostOneleaf(root->Lchild);
	m+=PostOneleaf(root->Rchild);
	return m;
}

int PostTowleaf(BiTree root){
	int m=0;
	if(root==NULL) return 0;
	if(root->Lchild!=NULL&&root->Rchild!=NULL) m++;
	m+=PostTowleaf(root->Lchild);
	m+=PostTowleaf(root->Rchild);
	return m;
}

void InpreOrder(BiTree root){
	if(root){
		InpreOrder(root->Lchild);
		if(root->Lchild==NULL&&root->Rchild==NULL){
			printf("%c",root->data);
		}
		InpreOrder(root->Rchild);	
	}
}

void ChangelOrder(BiTree root){
	BiTree p;
	if(root){
		if(root->Lchild!=NULL&&root->Rchild){
			p=root->Lchild;
			root->Lchild=root->Rchild;
			root->Rchild=p;
		}
		ChangelOrder(root->Lchild);
		ChangelOrder(root->Rchild);
	}	
}

main(){
	BiTree root;
	root=CreatBiTree();
	ChangelOrder(root);
	PreOrder(root);
	printf("\n");
	InOrder(root);
	printf("\n");
	PostOrder(root);
} 
