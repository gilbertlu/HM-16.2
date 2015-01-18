struct node{
	int pixId[2];//0-x,1-y
	int w;
	int h;
	struct node *next;
};
typedef struct node NODE;

node *fronts, *rear;
void enNode(node *prev,int *pixId,int w,int h){
	node *idx;
	idx = (node *)malloc(sizeof(node));
	idx->pixId =pixId;
	idx->w=w;
	idx->h=h;
	idx->next = NULL;
	prev->next = idx;
	return;
}


Bool Pic2Block(node *ptr,UInt lx,UInt ly){
UInt BLK_w=16;
UInt BLK_h=BLK_w;
  NODE *temp = ptr;
  int L,R,T,B;
  while(temp->next!=NULL){
        L=ptr->pixId[0];
		R=L+ptr->w;
		T=ptr->pixId[1];
		B=T+ptr->h;
		if(lx>=((L/BLK_w)*BLK_w) && lx<=((R/BLK_w)*BLK_w) && ly>=((T/BLK_h)*BLK_h) && ly<=((B/BLK_h)*BLK_h) ) 
			return true;
		ptr++;
  }
  return false;
}