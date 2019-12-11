#include <iostream>
using namespace std;

//This merge function will be merge the two array
void MergeArray(int input[],int start,int mid,int end){

	int size1 = mid - start + 1;
	int size2 = end - mid;
	int size = size1 + size2;

	
	int array[size];
	int L[size1];
	int R[size2];
	
	for(int i=0;i<size1;i++){
		L[i]=input[start+i];
	}
	
	for(int i=0;i<size2;i++){
		R[i]=input[mid+1+i];
	}

	//Sort the array
	int i=0;
	int j=0;
	int k=0;
	while(i<size1 && j<size2){
		if(L[i]<=R[j]){   		//this means first array have larger value do we put smaller value in the array
			array[k]=L[i];
			i++;
			k++;
		}
		else{
			array[k]=R[j];
			j++;
			k++;
		}
	}

	while(i<size1){
		array[k]=L[i];
		i++;
		k++;
	}

	while(j<size2){
		array[k]=R[j];
		j++;
		k++;
	}

	//Time to make the copy of array into the input array

	for(int index=0;index<size;index++){
		input[start+index]=array[index];
	}
	

}
void MergeSort(int input[],int start,int end){
	if(start>=end){
		return;
	}
	else{
		int mid = (start + end)/2;
		MergeSort(input,start,mid);
		MergeSort(input,mid+1,end);
		MergeArray(input,start,mid,end);

	}
}

void mergeSort(int input[],int size){
	MergeSort(input,0,size-1);
}

int main() {
  	int input[1000],length;
 	cin >> length;
  	for(int i=0; i < length; i++){
   		cin >> input[i];
   	}


	mergeSort(input, length);
  	for(int i = 0; i < length; i++) {
    	cout << input[i] << " ";
	}
	cout<<endl;
}
