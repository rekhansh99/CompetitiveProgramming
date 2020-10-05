#include<stdio.h>
#include<stdlib.h>
#define max 100
void push(int stack[], int data, int *top){
    if((*top) < max-1){
        stack[++(*top)] = data;
    }
}
int pop(int stack[], int *top){
    if((*top) >= 0){
        return stack[(*top)--];
    }
    return -404040;
}
int main(){
    printf("Enter number of units you want to enter: ");
    int num;
    scanf("%d",&num);
    int arr[num];
    int top = -1;
    int temp;
    for(int i=0; i<num; i++){
        scanf("%d",&temp);
        push(arr, temp, &top);
    }   
    int i = 0;
    int array[num];
    int data = pop(arr, &top); 
    while(data != -404040){
        array[i] = data*1;
        data = pop(arr, &top);
        i++;
    }
    i = num-1;
    while(i >= 0){
        if(array[i] < 0){
            push(arr, array[i], &top);
            array[i] = -1;
        }
        i--;
    }
    i = num-1;
    while(i >= 0){
        if(array[i] != -1){
            push(arr, array[i], &top);
        }
        i--;
    }
    printf("So, your stack be : \n");
    for(int i=0; i<num; i++){
        data = pop(arr, &top);
        printf("%d\n",data);
    }
       
}