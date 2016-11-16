#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
	char data;
	struct Node *Lchild;
	struct Node *Rchild;
}BiTNode,*BiTree ;

BiTree CreatBiTree(){//������������ 
	BiTree s;
	char ch;
	ch=getchar();
	if(ch=='#') return NULL;//Ҷ�ӽ������Һ�Ϊ�գ���¼Ϊ# 
	else{
		s=(BiTree)malloc(sizeof(BiTNode));//��ÿ���ڵ������ڴ� 
		s->data=ch;
		s->Lchild=CreatBiTree();
		s->Rchild=CreatBiTree();
		return s;
	}
}

void PreOrder(BiTree root){//������������� 
	if(root){
		printf("%c",root->data);
		PreOrder(root->Lchild);
		PreOrder(root->Rchild);
	}
}

void InOrder(BiTree root){//������������� 
	if(root){
		InOrder(root->Lchild);
		printf("%c",root->data);
		InOrder(root->Rchild);
	}
}

void PostOrder(BiTree root){//������������� 
	if(root){
		PostOrder(root->Lchild);
		PostOrder(root->Rchild);
		printf("%c",root->data); 
	}
}

int PostCountleaf(BiTree root){//ͳ��Ҷ�ӽڵ��� 
	int m,n;
	if(root==NULL) return 0;
	if(root->Lchild==NULL&&root->Rchild==NULL) return 1;
	m=PostCountleaf(root->Lchild);
	n=PostCountleaf(root->Rchild);
	return (m+n);
}

int PostOneleaf(BiTree root){//ͳ�ƶ���Ϊ1�Ľڵ��� 
	int m=0;
	if(root==NULL) return 0;
	if((root->Lchild==NULL&&root->Rchild!=NULL)||(root->Lchild!=NULL&&root->Rchild==NULL)) m++;
	m+=PostOneleaf(root->Lchild);
	m+=PostOneleaf(root->Rchild);
	return m;
}

int PostTowleaf(BiTree root){//ͳ�ƶ���Ϊ���Ľڵ��� 
	int m=0;
	if(root==NULL) return 0;
	if(root->Lchild!=NULL&&root->Rchild!=NULL) m++;
	m+=PostTowleaf(root->Lchild);
	m+=PostTowleaf(root->Rchild);
	return m;
}

void InpreOrder(BiTree root){//���Ҷ�ӽڵ� 
	if(root){
		InpreOrder(root->Lchild);
		if(root->Lchild==NULL&&root->Rchild==NULL){
			printf("%c",root->data);
		}
		InpreOrder(root->Rchild);	
	}
}

void ChangelOrder(BiTree root){//������������ 
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

void RouteToleaf(BiTree root,char arr[],int i){//ͳ�Ƹ��ڵ㵽Ҷ�ӽڵ��·��
	int x=PostCountleaf(root);
	if(root){//�ж�root�Ƿ���� 	 
		arr[i]=root->data;//��root��ֵ����������
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

void TreeText(BiTree root){//����root���������С���� 
	if(root){//root�Ƿ���ڣ���NULL��"������" ��һ��. 
		printf("hehe");
		TreeText(root->Lchild);
		TreeText(root->Rchild);
	}
	if(root->Lchild!=NULL&&root->Rchild!=NULL){
		printf("leaf");
	} 
}

int PostTreeDepth(BiTree root){//�ж�������� 
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
