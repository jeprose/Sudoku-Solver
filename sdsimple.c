#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int board[9][9];    /*stores board*/

int isValid(int row, int column, int num);
int recursive(int n);
int isValid(register int row, register int column, register int num);
void printBoard();

int main(int argc, char* argv[]){  
    FILE *fp;
	register int i=0,j;						/*i for row, j for column*/		
	char buf[110];                          
    unsigned long int buff;					
	if(argc==2){                            /*if command line, writes text from file into board*/
        if((fp=fopen(argv[1],"r"))==NULL){			
		    return 1;
	    }
        while(!feof(fp)){
            while(fgets(buf,100,fp)!=NULL){				
                for(j=0;j<9;j++){
                    board[i][j]=((int)(buf[j]-'0'));
                }
                i++;
            }
        }
    fclose(fp);
    }   
    else{                               /*if no command line, writes text from input into board*/
        for(i=0;i<9;++i){
            scanf("%lu",&buff);
            for(int j=0;j<9;j++){
                board[i][j]=buff%10;
                buff=buff/10;
            }
        }
    }
    recursive(0);                   /*calls recursive function*/
    printBoard();
    return 0;
}
int recursive(register int n){
    register int i;
    if(n==81){          /*success if reaches end of board*/
        return 1;
    }
    if(board[n/9][n%9]==0){             /*if space is so-far unsolved*/
        for(i=1;i<10;++i){              /*runs through possible sudoku values*/ 
            if(isValid(n/9,n%9,i)){
                board[n/9][n%9]=i;          /*sets it to random value if works*/
                if(recursive(n+1)==1){      /*calls recursive*/
                    return 1;
                }
            }
        }
        board[n/9][n%9]=0;                 /*if none of values worked, bad branch, resets and goes down level*/
        return 0;
    }
    else{
        return recursive(n+1);          /*skips to find unsolved number*/
    }
}
int isValid(register int row, register int column, register int num){
    register int i;             /*checks in row, column, and box of location for duplicates*/
    for(i=0;i<9;++i){
        if((i!=column && board[row][i]==num) || (i!=row && board[i][column]==num)){   
            return 0;
        }
        if(i!=row%3*3+column%3 && board[row/3*3+i/3][column/3*3+i%3]==num){
            return 0;
        }
    }
    return 1;
}
void printBoard(){
    int i,j; 
    for(i=0;i<9;i++){
        for(j=0;j<9;j++){
            printf("%d",board[i][j]);
        }
        printf("\n");
    }
}
