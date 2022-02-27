#include<stdio.h>
int lastmodified(int input1, int input2[]){
    if(input1 == 0) return 0;
    if (input2[input1-1]+1 > 9){
        input2[input1-1] = 0;                   // not neccesary to update
        printf("\n");
        printf("pointing to %d",input1);
        --input1;                               // input = input - 1;
        lastmodified(input1, input2);
        
    }else if(input2[input1-1]+1 < 9) {
        input2[input1-1]++;                   // not neccesary to update
        printf("\npointing to %d\n", input1);
        return input1;
    }
}

void visualize(int example, int len, int list[]){ // just for visualization, not logic here 
    printf("example %d : ", example);
    for(int i=0;i<len;i++) printf("%d", list[i]);
}

void main(){
    int a[5] = {1,2,9,9,9};
    int x = 5;
    
    visualize(1, 5, a);
    
    int ans = lastmodified(x,a);
    visualize(1, 5, a);
    printf("\nans = %d\n",ans);
    
    printf("\n");
    
    int b[2] = {9,9};
    int y = 2;
    
    visualize(2, 2, b);
    
    ans = lastmodified(y,b);
    visualize(2, 2, b);
    printf("\nans = %d\n",ans);
    
}
