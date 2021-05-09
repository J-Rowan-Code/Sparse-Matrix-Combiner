/* 
	ADD MATRICIES BUG!!!
	Where should I put the PrintLL and add_matrices functions?
	Do i link my two sets of linked lists together?
	Can we assume that the matrices will all be in sets of 4?
	Can we assume the matrices will all be the same size?
	Will the matrices always be in the same dimensions (4x4/5x5/6x6 etc)
	Bug where if the last position in the matrix is not full doesn't finish
*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node{
	int row;
	int col;
	int value;
	Node *next=NULL;
};

void read_matrix(Node *&a, char *file_name);
void add_node(int row, int col, int value, Node *&list);
void printLL(Node *list);
void add_matrices(Node *A1, Node *B1);

Node *A=NULL, *B=NULL, *current=NULL;
int rowmax, colmax, check, count=1;

int main (int argc, char** argv){
	if(argc!=3){
		printf("Needs two matrices \n");
		exit(1);
	}
	
	read_matrix(A, argv[1]);
	read_matrix(B, argv[2]);
	printf("Matrix %d: ", count);
	printLL(A);
	printf("Matrix %d: ", count);
	printLL(B);
	add_matrices(A, B);
	
}

void read_matrix(Node *&a, char *file_name){
	int col=0, row=0, value=0, indx=0, indx2=0;
	
	FILE *f;
	f = fopen(file_name, "r");
	if (f==NULL){
		printf("Cannot open file %s. Exiting", file_name);
		exit(2);
	}
	fscanf(f, "%d %d", &row, &col);
	rowmax = row;
	colmax = col;
	for(indx=0; indx<row; indx++){
		for(indx2=0; indx2<col; indx2++){
			fscanf(f, "%d", &value);
			if(value==0){
				continue;
			}
			if(value!=0){
				add_node(indx, indx2, value, a);
			}
		}
	}
	fclose(f);
}



void add_node(int row, int col, int value, Node *&list){
	Node *temp=NULL;
	if(list==NULL){
		list = new Node;
		temp = list;
	}else{
		temp = list;
		while(temp->next!=NULL){
			temp = temp->next;
		}
		temp->next = new Node;
		temp = temp->next;
	}
	temp->row = row;
	temp->col = col;
	temp->value = value;
}

void printLL(Node *list){
	int row=0, col=0;
	check=0;
	Node *temp = list;
	while(temp!=NULL){
		printf("%d ",temp->value);
		temp=temp->next;
	}
	printf("\n");
	count++;
	temp=list;
	if(list==NULL){
		for(row=0; row<rowmax; row++){
			for(col=0; col<colmax; col++){
				printf("0 ");
			}
			printf("\n");
		}
		return;
	}
	for(row=0; row<rowmax; row++){
		for(col=0; col<colmax; col++){
			if((temp->row==row)&&(temp->col==col)){
				printf("%d ", temp->value);
				if(temp->next!=NULL){
					temp=temp->next;
					check=1;
				}
				continue;
			}
			printf("0 ");
			
		}
		printf("\n");
	}
	if(check==0){
		for(row=0; row<rowmax; row++){
			for(col=0; col<colmax; col++){
				printf("0 ");
			}
		}
	}
}
	

void add_matrices(Node *A1, Node *B1){
	int row, col;
	Node *startA=A1, *startB=B1;
	
	printf("Matrix Result: ");
	if(A1==NULL){
		printLL(B1);
		return;
	}
	if(B1==NULL){
		printLL(A1);
		return;
	}
	
	if((A1==NULL)&&(B1==NULL)){
		for(row=0; row<rowmax; row++){
			for(col=0; col<colmax; col++){
				printf("0 ");
			}
			printf("\n");
		}
		return;
	}		
	
	for(row=0; row<rowmax; row++){
		for(col=0; col<colmax; col++){
			if(((A1->row==row)&&(A1->col==col))||((B1->row==row)&&(B1->col==col))){
				if(((A1->row==row)&&(A1->col==col))&&((B1->row==row)&&(B1->col==col))){
					printf("%d ", (A1->value+B1->value));
					if(A1->next!=NULL){
						A1=A1->next;
					}
					if(B1->next!=NULL){
						B1=B1->next;
					}
				}
				else if((A1->row==row)&&(A1->col==col)){
					printf("%d ", A1->value);
					if(A1->next!=NULL){
						A1=A1->next;
					}
				}
				else if((B1->row==row)&&(B1->col==col)){
					printf("%d ", B1->value);
					if(B1->next!=NULL){
						B1=B1->next;
					}
				}
			}
		}
	}
	
	A1=startA;
	B1=startB;
	
	printf("\n");
	for(row=0; row<rowmax; row++){
		for(col=0; col<colmax; col++){
			if(((A1->row==row)&&(A1->col==col))||((B1->row==row)&&(B1->col==col))){
				if(((A1->row==row)&&(A1->col==col))&&((B1->row==row)&&(B1->col==col))){
					printf("%d ", (A1->value+B1->value));
					if(A1->next!=NULL){
						A1=A1->next;
					}
					if(B1->next!=NULL){
						B1=B1->next;
					}
				}
				else if((A1->row==row)&&(A1->col==col)){
					printf("%d ", A1->value);
					if(A1->next!=NULL){
						A1=A1->next;
					}
				}
				else if((B1->row==row)&&(B1->col==col)){
					printf("%d ", B1->value);
					if(B1->next!=NULL){
						B1=B1->next;
					}
				}
			}
			else{
				printf("0 ");
			}
		}
		printf("\n");
	}
}
