#include "list.h"

#define FILENAME_MAX_LEN 100
#define ERROR_CANNOT_OPEN_FILE "ERROR: File cannot be opened, try again. \n"
#define ERROR_INVALID_FILE_CONTENT "ERROR: File content invalid, try again. \n"

int main(void){

    /* test cases for DeleteNodes */
    double a[4] = {2, 6, 5, 6};
    double b[1] = {0};
    double c[3] = {6, 6, 6};
    Node *heada = 0;
    Node *headb = 0;
    Node *headc = 0;

    //create 3 linklists.
    for (int i = 0; i < sizeof(a) / sizeof(double); i++){
        InsertNode(&heada, i, a[i]);
    }
    for (int i = 0; i < sizeof(b) / sizeof(double); i++){
        InsertNode(&headb, i, b[i]);
    }
    for (int i = 0; i < sizeof(c) / sizeof(double); i++){
        InsertNode(&headc, i, c[i]);
    }

    DisplayList(heada);
    int resa = DeleteNodes(&heada, 6);
    printf("Returned value:%d\n", resa);
    DisplayList(heada);

    DisplayList(headb);
    int resb = DeleteNodes(&headb, 6);
    printf("Returned value:%d\n", resb);
    DisplayList(headb);

    DisplayList(headc);
    int resc = DeleteNodes(&headc, 6);
    printf("Returned value:%d\n", resc);
    DisplayList(headc);

    /* test cases for RemoveDuplicates*/

    double ba[6] = {1, 2, 2, 4, 6, 6};
    double bb[2] = {1, 2};
    double bc[5] = {6, 6, 6, 7, 7};
    Node *headba = 0;
    Node *headbb = 0;
    Node *headbc = 0;

    for (int i = 0; i < sizeof(ba) / sizeof(double); i++){
        InsertNode(&headba, i, ba[i]);
    }

    for (int i = 0; i < sizeof(bb) / sizeof(double); i++){
        InsertNode(&headbb, i, bb[i]);
    }

    for (int i = 0; i < sizeof(bc) / sizeof(double); i++){
        InsertNode(&headbc, i, bc[i]);
    }

    DisplayList(headba);
    RemoveDuplicates(&headba);
    DisplayList(headba);

    DisplayList(headbb);
    RemoveDuplicates(&headbb);
    DisplayList(headbb);

    DisplayList(headbc);
    RemoveDuplicates(&headbc);
    DisplayList(headbc);

    /* test cases for ReverseList*/

    double ca[5] = {1, 2, 3, 4, 5};
    double cb[1] = {0};
    double cc[1] = {1};
    Node *headca = 0;
    Node *headcb = 0;
    Node *headcc = 0;

    for (int i = 0; i < sizeof(ca) / sizeof(double); i++)
    {
        InsertNode(&headca, i, ca[i]);
    }

    for (int i = 0; i < sizeof(cb) / sizeof(double); i++)
    {
        InsertNode(&headcb, i, cb[i]);
    }

    for (int i = 0; i < sizeof(cc) / sizeof(double); i++)
    {
        InsertNode(&headcc, i, cc[i]);
    }

    DisplayList(headca);
    ReverseList(&headca);
    DisplayList(headca);

    DisplayList(headcb);
    ReverseList(&headcb);
    DisplayList(headcb);

    DisplayList(headcc);
    ReverseList(&headcc);
    DisplayList(headcc);
}

/****************** sample output
2->6->5->6
Returned value:2
2->5
0
Returned value:0
0
6->6->6
Returned value:3
NULL
1->2->2->4->6->6
1->4
1->2
1->2
6->6->6->7->7
NULL
1->2->3->4->5
5->4->3->2->1
0
0
1
1
***************************************/