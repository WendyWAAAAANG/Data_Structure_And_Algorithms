#include <stdio.h>
int FindMostOne(int* M, int n);

//function declaration.
int main(){
    //declare some matrix.
    return 0;
}

int FindMostOne(int** M, int n){
    //decalre the variable to store result.
    //result is the id of row.
    int res = -1;
    //set two counters to traverse the num.
    int i = 0;
    int j = 0;
    while(i < n && j < n){
        //then we will scan the num,
        if(M[i][j] == 1){
            //which means next maybe still be 1,
            //continue scanning next at same row.
            j++;
            //update the result row index.
            res++;
        }
        else{
            //which means the current index in this row is 0.
            //already reach the end of 1.
            //so we just scan next row.
            i++;
        }
    }
    return res;
}
// int FindMostOne(int* M, int n){
//     //decalre the variable to store result.
//     int res = 0;
//     //declare a pointer to keep scan each row.
//     int p = 0;
//     int row = 0;
//     for(int i = 0; i < n; i++){
//         while(p < n){
//             if(M[row][p] == 0 && p = 0){
//                 //which means this row does not have one,
//                 //just break and check next row.
//                 break;
//             }
//             if(M[row][p] == 1 && p = (n-1)){
//                 //which means we reach the end of row.
//                 //obviously this row has most one.
//                 return p;
//             }
//             if(M[row][p] == 1 && M[row][p+1] == 0){
//                 //which means we have found the boundary between 0 and 1.
//                 if(p > row){
//                     //which means the p is larger.
//                     res = p;
//                 }
//                 //otherwise, we will do nothing.
//             }
//             //otherwise, keep check next element.
//             p++;
//         }
//     }
//     return res;
// }
