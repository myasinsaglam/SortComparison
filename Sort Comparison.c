/**
@file

A program that calculate runtimes of three sorting algorithms which are Bubble Sort, Selection Sort and Merge Sort.
It has two modes: Manual and Auto.
In manuel mode you can choose any algorithm that you want to calculate runtime or randomize array again or create new sized random array.
It based on user selection.
In auto mode you can enter iteration number and try all algorithms based on iteration. 
After trying all algorithms, array size stay same and new random array values will assign.
Then you can see on the screen average runtime for each algorithm.

@author

Name 			 :		Muhammed Yasin SAĞLAM	
Student No		 :	 	15011804	
Date 			 :		30/10/2016
E-Mail			 :		myasinsaglam1907@gmail.com
Compiler Used	 	 :		GCC
IDE			 :		DEV-C++(Version 5.11)
Operating System 	 :		Windows Embedded 8.1 Industry Pro
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//Function procedures that used in this program
void printArray(int *, int ); 
void Sel_sort(int *,int );
void Bubble_sort(int *,int );
void arr_Copy(int *,int *,int);
void merge(int *,int ,int ,int );
void Merge_sort(int *,int, int );
int* Allocator(int);
void Randomizer(int *,int);
/**
Main function, Reads array size from the user and controls it(Size have to be 10 between 1.000.000.000 ).
Allocates (2 times-first array and temp array) memory for arrays that will be sorted. Because we need two array to not lose same randomized array.
Then it seperates program two mode : MANUAL and AUTO.
-In MANUAL MODE- 
It reads order of any algorithm from the user to calculate runtime or randomize array again or create new sized random array.
Then it prints runtime of chosen algorithm on the screen
-In AUTO MODE-
It reads iteration number from the user and apply all algorithms based on iteration. After applying all algorithms, array size stay same and new random array values will assign.
Then you can see on the screen average runtimes for all algorithms.
*/
int main(){
system("COLOR a");	
srand(time(NULL));
int size,choice,i,iter; 					//variables for get size(size), user selection(choice), iteration number in auto mode(iter)
float bubbletime,selectime,mergetime; 				//variables to calculate average runtimes of each algorithm
clock_t start,end;						//variables for calculating runtimes of one algorithm
int *array1,*tmp_arr;						//array declarations (array1 is main array, tmp_arr is the array that will be sorted array in sorting algorithms)

	printf("\n\nPlease enter the size of array (between 10-1.000.000.000) : "); 
	scanf("%d",&size);						//Reading Size
	while(size<10 || size>1000000000){				//Size control for determined scale
			system("CLS");
			system("COLOR c");	
			printf("ERROR!!!\nPlease enter size between 10-1.000.000.000 : ");
			scanf("%d",&size);				//Reading Size until entering values of given scale
	}
	system("COLOR a");		
	system("CLS");		
	array1=Allocator(size); 				//It allocates memory for array1 with calling by function
	Randomizer(array1,size);				//It assigns random values into array1 with calling by function
	printf("ARRAY CREATED...\n");
	/*printf("Main Array : ");
	printArray(array1,size); 				//print to control with calling by function	*/

	printf("\tMANUAL MODE\n1.Bubble Sort\n2.Selection Sort\n3.Merge Sort\n4.Change Array Size\n5.Randomize Array(size stay same)\n6.SWITCH AUTO MODE \n\nPlease enter the order of algorithm for sorting array (0 for exit): ");
	scanf("%d",&choice);					//Reading choice from the user
	system("CLS");	
	
	while(choice!=0){
		tmp_arr=Allocator(size);				//It allocates temp array with calling by function.It written in while loop because the size can be change based user selection in while.
		arr_Copy(tmp_arr,array1,size); 				//It copies main array to temp array with calling by function
	//	printArray(tmp_arr,size);				//print to control
		printf("WORKING... PLEASE WAIT...\n");
		if(choice==1){ 						//This choice calculates bubble sort runtime
			start=clock();
			Bubble_sort(tmp_arr,size); 			//Bubble sorting with calling by function
			end=clock();
			system("CLS");	
			printf("Array Size : %d\nRuntime of Bubble Sort Algorithm: %f second\n",size,((float)(end-start))/1000);
		//	printArray(tmp_arr,size);			//print to control
		}
		if(choice==2){						//This choice calculates selection sort runtime
			start=clock();
			Sel_sort(tmp_arr,size);				//Selection sorting with calling by function
			end=clock();
			system("CLS");
			printf("Array Size : %d\nRuntime of Selection Sort Algorithm: %f second\n",size,((float)(end-start))/1000);
			//printArray(tmp_arr,size);			//print to control
		}
		if(choice==3){						//This choice calculates selection sort runtime
			start=clock();
			Merge_sort(tmp_arr,0,size-1);			//Merge sorting with calling by function
			end=clock();
			system("CLS");			
			printf("Array Size : %d\nRuntime of Merge Sort Algorithm: %f second\n",size,((float)(end-start))/1000);	
			//printArray(tmp_arr,size);			//print to control
		}
		if(choice==4){						//This choice changes array size
			system("CLS");
			printf("Enter New size : ");
			scanf("%d",&size);				//Reading new size
				while(size<10 || size>1000000000){	//Size control for determined scale
					system("CLS");
					system("COLOR c");
					printf("ERROR!!!\nPlease enter size between 10-1.000.000.000 : ");
					scanf("%d",&size);		//Reading Size until entering values of given scale
					system("CLS");
					system("COLOR a");
			}
			system("CLS");
			array1=(int*)realloc(array1,(sizeof(int)*size));   //Main array Re-Allocation for New Size
				if(!array1){				//Allocation Control
					system("COLOR c");
					printf("RE-ALLOCATION FAILED!!!... Quitting..."); 
					return 0;
				}
			Randomizer(array1,size);			//Randomizing New sized main array with calling by function
			printf("New sized random array created... \nNew Array Size : %d\n\n",size);
		//	printArray(array1,size);			//print to control			
		}
		if(choice==5){						//This choice assign new randomized values to main array(size stay same)
			Randomizer(array1,size);			//Randomizing main array with calling by function
			system("CLS");
			printf("New random values assigned to array...\nArray Size : %d\n\n",size);
		//	printArray(array1,size);			//print to control
		//	system("PAUSE");	
		}
		if(choice==6){						//This choice for passing AUTO mode
			system("CLS");
			printf("Size : %d\n",size);
			printf("\tAUTO MODE\nPlease enter iteration number M ( M>9 is suggested ) :");
			scanf("%d",&iter);				//Reading iteration number
			system("CLS");
			printf("--------RESULTS--------\nSize : %d \n\n",size);
			printf("Iteration\tBUBBLE\t\tSELECTION\tMERGE\n");
			printf("---------\t--------\t--------\t--------\n\n");
			bubbletime=0; selectime=0; mergetime=0;
			for(i=0;i<iter;i++){
				printf("%d.\t\t",i+1);
		
				arr_Copy(tmp_arr,array1,size);		//temp array values are turn into main array values with calling by function
				
				start=clock();
				Bubble_sort(tmp_arr,size);		//Bubble sorting with calling by function
				end=clock();				
				printf("%f\t",((float)(end-start))/1000);	//Output the runtime
				bubbletime+=((float)(end-start))/1000;		//Calculating all of bubble sort runtimes
				
				arr_Copy(tmp_arr,array1,size);		//temp array values are turn into main array values with calling by function  
				
				start=clock();
				Sel_sort(tmp_arr,size);			//Selection sorting with calling by function
				end=clock();				
				printf("%f\t",((float)(end-start))/1000);	//Output the runtime
				selectime+=((float)(end-start))/1000;		//Calculating all of selection sort runtimes
				
				arr_Copy(tmp_arr,array1,size);			//temp array values are turn into main array values with calling by function
				
				start=clock();
				Merge_sort(tmp_arr,0,size-1);			//Merge sorting with calling by function
				end=clock();				
				printf("%f\n",((float)(end-start))/1000);	//Output the runtime
				mergetime+=((float)(end-start))/1000;		//Calculating all of merge sort runtimes
				
				Randomizer(array1,size);			//Randomizing main array with calling by function
			}
			printf("\n\n---------\t--------\t--------\t--------\n");
			printf("Averages :\t%f\t%f\t%f\n",(bubbletime/iter),(selectime/iter),(mergetime/iter));	//Output the avereage runtimes of algorithms
			printf("---------\t--------\t--------\t--------\n\n");
		}
	//printArray(tmp_arr,size); 						//print to control
	free(tmp_arr); 								// Free temp array until new choice
	//printArray(array1,size);						//print to control
	printf("\tMANUAL MODE\n1.Bubble Sort\n2.Selection Sort\n3.Merge Sort\n4.Change Array Size\n5.Randomize Array(size stay same)\n6.SWITCH AUTO MODE \n\nPlease enter the order of algorithm for sorting array (0 for exit): ");
	scanf("%d",&choice);							//Reading choice from the user
	system("CLS");
	}								

														
	free(array1);								//Free main array
	system("PAUSE");
	return 0;	
}
/**
	@param *A			array that will be printed on screen
	@param size			size of array
*/
void printArray(int *A, int size){
	int i;
	for (i=0; i < size; i++)
		printf(" %d ", A[i]);
	printf("\n");
}

/**
	@param *arr2		destination array of copying
	@param *arr1		source array of copying
	@param size		size of array
*/
void arr_Copy(int *arr2,int *arr1,int size){
	int i;
	for(i=0;i<size;i++)
		arr2[i]=arr1[i];
}
/**
	@param arr		array that will be selection sorted 
	@param size		size of array
*/
void Sel_sort(int *arr,int size){
	int i,j,temp,Mindex;
		for(i=0;i<size;i++){
			Mindex=i;
			for(j=i+1;j<size;j++){
				if(arr[Mindex]>arr[j])
					Mindex=j;
				}
			temp=arr[Mindex];
			arr[Mindex]=arr[i];
			arr[i]=temp;	
		}		
}
/**
	@param *arr		array that will be bubble sorted 
	@param size		size of array
*/
void Bubble_sort(int *arr,int size){
	int i,j,temp;
		for(i=1;i<size;i++){
			for(j=0;j<size-i;j++){
				if(arr[j]>arr[j+1]){
					temp=arr[j];
					arr[j]=arr[j+1];
					arr[j+1]=temp;	
				}
			}
		}
}
/**
	@param *arr		array that will be merged
	@param l_index		left index of array
	@param mid		middle index of array
	@param r_index		right index of array
*/
void merge(int *arr, int l_index, int mid, int r_index){
	int *temp;
		temp=(int*)malloc(sizeof(int)*(r_index-l_index+1));
			if(!temp){
				system("COLOR c");
				printf("Not enough space for merge sort!!! Quitting...");
				exit(0);
			}
	int i,j,k;
	i=l_index; 
	j=mid+1; 
	k=0;
	while(i<=mid && j<=r_index){
		if(arr[i]<=arr[j])
			temp[k++]=arr[i++];
		else
			temp[k++]=arr[j++];	
	}
	while(i<=mid)
		temp[k++]=arr[i++];
	while(j<=r_index)
		temp[k++]=arr[j++];
	k--;	
	while(k>=0){
		arr[l_index+k]=temp[k];
		k--;				
	}


free(temp);
}
/**
	@param *arr		array that will be merge sorted
	@param	left		start index of array
	@param right		end index of array
*/
void Merge_sort(int *arr,int left,int right){
    if(left<right){
        int mid =(left+right)/2;
        Merge_sort(arr,left,mid);
        Merge_sort(arr,mid+1,right);
        merge(arr,left,mid,right);
    }
}
/**
	@param size 		size of array that will be allocated
	@return array		allocated array using malloc
*/

int *Allocator(int size){
	int *array;
	array=(int*)malloc(sizeof(int)*size);
		if(!array){
			system("COLOR c");
			printf("Array Not Allocated !!! Quitting...");
			return 0;
		}
	return array;	
}
/**
	@param *arr		array that will be randomized
	@param size 		size of array
*/
void Randomizer(int *arr,int size){
	int i;
	for(i=0;i<size;i++)
		arr[i]=rand();	
}

