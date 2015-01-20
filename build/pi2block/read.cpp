#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>
#define UInt unsigned int
using namespace std;

// ---------------------------------------------------------------------
// node struct
// ---------------------------------------------------------------------
struct node{
	UInt* pixId;//0-x,1-y
	UInt w;
	UInt h;
	struct node *next;
};
typedef struct node NODE;
bool Pic2Block(node *ptr,UInt lx,UInt ly);

void enNode(node *prev,UInt* pixId,UInt w,UInt h){
	node *idx;
	idx = (node *)malloc(sizeof(node));
	idx->pixId = pixId;
	idx->w=w;
	idx->h=h;
	idx->next = NULL;
	prev->next = idx;
	return;
}
int main(){
	
	vector<node*> myqueue;
	int T;
	int m,n;
	int startNode,endNode;
	int setsize=0;
	char f[20];
	UInt x,y,w,h; 

	FILE *inf;
	inf=fopen("test.txt","r");

	while(fscanf(inf,"%s",&f)>0){


		fscanf(inf,"%d",&n);
		NODE *pix,*prev;
		for (int i=0;i<n;i++){
			fscanf(inf,"%u",&x);
			fscanf(inf,"%u",&y);
			fscanf(inf,"%u",&w);
			fscanf(inf,"%u",&h);
			if(i==0){				
				pix=new NODE[1];
				pix->pixId=new UInt[2];
				pix->pixId[0]=x;
				pix->pixId[1]=y;
				pix->w=w;
				pix->h=h;
				pix->next=NULL;
				prev = pix;
			}
			else{
				UInt *pixId;
				pixId = (UInt*)malloc(2*sizeof(UInt));
				pixId[0]=x; 
				pixId[1]=y;
				enNode(prev,pixId,w,h);
				prev=prev->next;
			}
		}
		//printf("%u,%u,%u,%u\n",x,y,w,h);
		
		myqueue.push_back(pix);

	}
	/*for(int i = 0; i < myqueue.size(); i++){
		NODE *temp = myqueue[i];
		while(temp!=NULL){
			printf("x=%u,y=%u,w=%u,h=%u\n",temp->pixId[0],temp->pixId[1],temp->w,temp->h);
			temp=temp->next;
		}
	}*/
	
	/*NODE *temp=myqueue.front();
	bool t;
	t=Pic2Block(temp,417,176);*/
	return 0;
}


bool Pic2Block(node *ptr,UInt lx,UInt ly){
	UInt BLK_w=16;
	UInt BLK_h=BLK_w;
	NODE *temp = ptr;
	int L,R,T,B;
	while(temp!=NULL){

		L=temp->pixId[0];
		R=L+temp->w;
		T=temp->pixId[1];
		B=T+temp->h;
		if(lx>=((L/BLK_w)*BLK_w) && lx<=((R/BLK_w)*BLK_w) && ly>=((T/BLK_h)*BLK_h) && ly<=((B/BLK_h)*BLK_h) ) 
			return true;
		temp = temp->next;
	}
	return false;
}