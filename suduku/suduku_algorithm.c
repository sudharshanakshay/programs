#include<stdio.h>
#include<stdlib.h>
#define M 6
#define N 6
#define SUM 30
#define MAX 9
#define region_no(i, j) i/3==0 && j/3==0 ? 0 : i/3==0 && j/3==1 ? 1 : i/3==1 && j/3==0 ? 2 : i/3==1 && j/3==1 ? 3 : 0

void updateMatrix();
void computePosibleValues(int, int);
void fillColumn();
void checkRow(int, int, int ,int);
void displayPosibleValues();

struct possibleValues{
    int values[4];
}B[4];


static int edit1 = 1;
static int edit2 = 1;
int unique = 1;

int Matrix[M][N] = {
{ 2,  3,  9,  4,  0,  7},
{ 0,  8,  0,  0,  3,  0},
{ 1,  6,  4,  2,  8,  9},
{ 6,  0,  3,  8,  0,  2},
{ 9,  4,  0,  0,  1,  0},
{ 5,  0,  1,  7,  9,  6}
};

int x, y;

void main(){
    printf("The Matrix : \n");
    for(int i=0; i<M; i++){
        for(int j=0; j<N; j++){
            printf("%d\t", Matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    
    
    for(int i=0; i<M; i+=3){
        for(int j=0; j<N; j+=3){
            computePosibleValues(i,j); // computing possible values.
        }
    }
    
    printf("Computed posible values (region wise) :\n");
    for(int i=0;i<4; i++){
        for(int j=0; j<4;j++){
            printf("%d\t",B[i].values[j]);
        }
        printf("\n");
    }


    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(Matrix[i][j] == 0){
                edit1 = 1;
                edit2 = 1;
                x=i;
                y=j;
                //printf("%d %d %d\n",Matrix[i][j], i, j);
                fillColumn(0, j, 0);
            }
            //printf("\n");
        }
    }
    
    
    printf("\n");
    printf("The Final Matrix :\n");
    for(int i=0; i<M; i++){
        for(int j=0; j<N; j++){
            printf("%d\t", Matrix[i][j]);
        }
        printf("\n");
    }

}


void checkUnique(int i, int j, int row){
unique = 1;
if(row){
    for(int k=0; k<M; k++){
        if(k == j) continue;
        if(Matrix[i][j] == Matrix[i][k]){
            edit2 = 0;
            unique = 0;
            return;
        }
}

}else{
    for(int k=0; k<M; k++){
        if(k == i) continue;
        if(Matrix[i][j] == Matrix[k][j]){
            edit1 = 0;
            unique = 0;
            return;
        }
}
    
}

}

void checkRow(int i, int j, int sum1, int sum2){
    int field_val;
    int k;
    if(j>=6){

        if(j==6 && sum1 == sum2) {
            //printf("succes -2-\n"); 
            checkUnique(x, y, 1);

            if(unique){
                edit2=1;
                edit1=0;
            } 
            
        }
        return;
    }else{

        if(Matrix[i][j] == 0){
            k = 0;
            while(k<4){
                field_val = B[region_no(i,j)].values[k];
                
                if(edit2){

                    Matrix[i][j] = field_val;
                    B[region_no(i,j)].values[k] = 0;
                    checkRow(i, j+1,sum1, sum2+field_val);
                }
                if(edit2) B[region_no(i,j)].values[k] = field_val;
                k++;
                
            }
            }
        else{
            checkRow(i, j+1,sum1, sum2+Matrix[i][j]);
        }
    }
}

// this is recuring fuction & strictly executed only after "computePosibleValues" function is called.
void fillColumn(int i, int j, int sum){

    int k=0;
    int field_val;
    if(i >= 6){
        if(i==6 && sum == 30) {
            //printf("succes -1-\n");
            
            checkUnique(x, y, 0);
            if(unique) checkRow(x, 0 ,sum,0);

        }
        
        return;
    }
    else {
        if(Matrix[i][j] == 0)
            while(k<4){
                field_val = B[region_no(i,j)].values[k];
                
                if(edit1){
                    
                    Matrix[i][j] = field_val;
                    B[region_no(i,j)].values[k] = 0;
                    
                    //displayPosibleValues();
                    
                    fillColumn(i+1, j, sum+field_val);
                    
                    
                }
                if(edit1) B[region_no(i,j)].values[k] = field_val;
                k++;
                
            }
        else {
            fillColumn(i+1, j, sum+Matrix[i][j]);
        }   
    }
}



//here it computes the posible values in the region.
void computePosibleValues(int k, int l){

    int flag = 0;
    int struct_V_count  = 0;
    for(int number=1; number<=9; number++){
        flag = 0;
        for(int i=k; i<k+3; i++){
            for(int j=l; j<l+3; j++){
                if(Matrix[i][j] == number){
                    flag = 1;
                    break;
                }
            }
            if(flag) break;
        }
        if(!flag){ 
            B[region_no(k,l)].values[(struct_V_count++)%4] = number;
        }
    }
}


// debugging print posibleValues computed.
void displayPosibleValues(){
    for(int m=0; m<4; m++){
        for(int n=0; n<4;n++){
            printf("%d\t",B[m].values[n]);
        }
        printf("\n");
    }
    printf("\n");
}
