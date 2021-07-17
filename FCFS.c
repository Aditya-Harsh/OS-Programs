#include<stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void main(){
    int i, j, number, finish=0;
    double aTAT=0, aWT=0;
    printf("Enter number of processes: ");
    scanf("%d",&number);

    int matrix[number][6];
    for(i=0; i<number; i++){
        printf("\nEnter Process name, Arrival time and Burst time: ");
        //scanf("%d%d%d",&matrix[i][0], &matrix[i][1], &matrix[i][2]);
        scanf("%d",&matrix[i][0]);
        scanf("%d",&matrix[i][1]);
        scanf("%d",&matrix[i][2]);
    }

    for(i=0; i<number-1; i++){
        for(j=0; j<number-i-1; j++){
            if(matrix[j][1]>matrix[j+1][1]){
                swap(&matrix[j][0], &matrix[j+1][0]);
                swap(&matrix[j][1], &matrix[j+1][1]);
                swap(&matrix[j][2], &matrix[j+1][2]);
            }
        }
    }


    for(i=0; i<number;i++){

        if(finish>matrix[i][1]){
            matrix[i][3]=finish-matrix[i][1];
        }
        else
            matrix[i][3]=0;

        aWT+=matrix[i][3];

        matrix[i][4]=matrix[i][2]+matrix[i][3];
        aTAT+=matrix[i][4];

        if(finish<matrix[i][1])
            finish=matrix[i][1]+matrix[i][2];
        else
            finish+=matrix[i][2];
        matrix[i][5]=finish;

    }


    printf("\n\nProcess name\tArrival time\tBurst time\tWaiting time\tTurn Around time\tFinish time");
    for(i=0; i<number;i++)
        printf("\n     %d\t\t     %d\t\t     %d\t\t     %d\t\t       %d\t\t     %d",matrix[i][0], matrix[i][1], matrix[i][2], matrix[i][3], matrix[i][4], matrix[i][5]);

    aWT=(aWT*1.0)/number;
    aTAT=(aTAT*1.0)/number;
    printf("\n\nAverage Waiting Time= %.2f", aWT);
    printf("\nAverage Turn Around time Time= %.2f\n", aTAT);
}

