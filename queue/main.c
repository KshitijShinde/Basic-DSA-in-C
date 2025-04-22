#include <stdio.h>

int queue[100];
int max;
int front=0;
int end=-1;
void enq()
    {
    int x;
    printf("enter element in queue=");
    scanf("%d",&x);
    
    if(end==max-1){
        printf("queue overflow...");
    }
    else{
        end++;
        queue[end]=x;
    }
    
}

void deq(){
    if(front>end){
        printf("queue is empty");
    }
    else{
        front++;
    }
    
}

void dis(){
    for(int i=front;i<=end;i++){
        printf("|%d",queue[i]);
    }
}

int main()
{
    
    printf("enetr size of queue");
    scanf("%d",&max);
    int choice;    
    do
    {
        printf("\nEnter choice:\n1 : enter\n2 : delete\n3 : Display\n4 : Exit\n");
        scanf("%d", &choice);
        
        switch (choice)
        {
            case 1:
                enq();
                break;
            case 2:
                deq();
                break;
            case 3:
            printf("following are elements in queue\n");
                dis();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    }
    while (choice != 4);
    
    return 0;
}