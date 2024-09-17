#include<stdio.h>

typedef struct{
    int row, col;
    int value;
} entry;

int CONVERT_TO_TUPLE(int A[][3], int r, int c, entry tuple1[]){
    tuple1[0].row = r;
    tuple1[0].col = c;
    tuple1[0].value = 0; // update to no. of non-zero values 
    int ind1 = 0; // zeroth position is already occupied for the details of the tuple
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if(A[i][j] != 0){
                ind1++;
                tuple1[ind1].row = i;
                tuple1[ind1].col = j;
                tuple1[ind1].value = A[i][j];
                tuple1[0].value++;
            }
        }
    }
    printf("The value of ind is : %d\n", ind1);
    return ind1;
}

void print_tuple(entry tuple1[], int ind1){
    ind1 = tuple1[0].value;
    for(int i = 1; i <= ind1; i++){
        printf("(%d,%d,%d)\n", tuple1[i].row, tuple1[i].col, tuple1[i].value);
    }
}

int add_tuple_matrix(entry tuple1[], entry tuple2[], entry result[]){
    int ind1 = tuple1[0].value;
    int ind2 = tuple2[0].value;
    int i = 1, j = 1; 
    int res_index = 0;

    while(i <= ind1 && j <= ind2){
        if(tuple1[i].row == tuple2[j].row && tuple1[i].col == tuple2[j].col){
            result[res_index].row = tuple1[i].row;
            result[res_index].col = tuple1[i].col;
            result[res_index].value = tuple1[i].value + tuple2[j].value;
            res_index++;
            i++; j++;
        }
        else if((tuple1[i].row < tuple2[j].row) || (tuple1[i].row == tuple2[j].row && tuple1[i].col < tuple2[j].col)){
            result[res_index++] = tuple1[i++];
        }
        else{
            result[res_index++] = tuple2[j++];
        }
    }

    while(i <= ind1)
        result[res_index++] = tuple1[i++];
    while(j <= ind2)
        result[res_index++] = tuple2[j++];

    return res_index;
}

int TRANSPOSE_TUPLE(entry tuple[], entry transpose[]){
    int n = tuple[0].value;
    int r = tuple[0].col;
    int c = tuple[0].row;

    transpose[0].row = r;
    transpose[0].col = c;
    transpose[0].value = n;

    int k = 1;
    for(int i = 0; i < c; i++){
        for(int j = 1; j <= n; j++){
            if(tuple[j].col == i){
                transpose[k].row = tuple[j].col;
                transpose[k].col = tuple[j].row;
                transpose[k].value = tuple[j].value;
                k++;
            }
        }
    }

    return k - 1;
}

int main(){
    int r1 = 3, c1 = 3, r2 = 3, c2 = 3;
    int A[][3] = {{0,0,3}, {4,2,0}, {0,5,6}};
    int B[][3] = {{0,9,1}, {0,0,0}, {7,0,0}};

    entry tuple1[20];
    entry tuple2[20];
    entry result[20];
    entry transpose[20];

    int ind1 = CONVERT_TO_TUPLE(A, r1, c1, tuple1);
    int ind2 = CONVERT_TO_TUPLE(B, r2, c2, tuple2);

    printf("Tuple1: \n");
    print_tuple(tuple1, ind1);

    int result_size = add_tuple_matrix(tuple1, tuple2, result);
    printf("THE RESULT IS : \n");
    for(int i = 0; i < result_size; i++){
        printf("(%d,%d,%d)\n", result[i].row, result[i].col, result[i].value);
    }

    int transpose_size = TRANSPOSE_TUPLE(tuple1, transpose);
    printf("Transpose of Tuple1: \n");
    print_tuple(transpose, transpose_size);

    return 0;
}
