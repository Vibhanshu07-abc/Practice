#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node*next;
}vertex;
typedef struct list{
    vertex*head;
}list;
void add(list*adj[],int src,int dst){
    vertex* newnode;
    newnode=(vertex*)malloc(sizeof(vertex));
    newnode->data=dst;
    newnode->next=NULL;
    if(adj[src]->head==NULL){
        adj[src]->head=newnode;
    }
     vertex*temp=adj[src]->head;
     while(temp){
        temp=temp->next;
     }
     temp->next=newnode;
}
void enqueue(int *rear,int data,int queue[]){
      queue[++(*rear)]=data;
}
int dequeue(int *front ,int queue){
    return(queue[(*front)++]);
}
void bfs(list*adj[],int start,int n){
         int visited[n];
         for(int i=0;i<n;i++){
            visited[i]=-1;
         }
         int front=0;
         int rear=0;
         int queue[n];
         visited[start]=1;//visited
         enqueue(&rear,start,queue);
         printf("starting fron : %d",start);
         while(front<rear){
            int v=dequeue(&front,queue);
            vertex*temp=adj[v]->head;
            while(temp){
                int demo=temp->data;
                if(visited[demo]==-1){
                  visited[demo]=1;
                  enqueue(&rear,demo,queue);
                }
                temp=temp->next;
            }
         }
}
int main(){
    int n,src,dst,start;
    printf("enter the number of vertex to added ");
    scanf("%d",&n);
    list*adj[n];
    for(int i=0;i<n;i++){
        list *adj[i]
        adj[i]=(list*)malloc(sizeof(list));
    }
    for(int i=0;i<n;i++){
    printf("enter the source and dst\n");
    scanf("%d",&src);
    scanf("%d",&dst);
    }
    printf("enter the position to start");
    scanf("%d",&start);
    bfs(adj,start,n);

}