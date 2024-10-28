#include<iostream>
#include<cmath>

using namespace std;

int jumpSearch(int arr[],int size,int target){
    int step = sqrt(size);
    int prev = 0;

    while(arr[min(step,size) - 1] < target){
        prev= step;
        step += sqrt(size);
        if(prev >= size){
            return -1;
        }
    }

    for(int i = prev; i < min(step,size); i++){
        if(arr[i] == target){
            return i;
        }
    }
    return -1;
}

int main(){
    int arr[] = {2, 4, 6, 8, 10, 12, 14, 16, 18};
    int size = sizeof(arr) /sizeof(arr[0]);
    int target;

    cout<< "Enter the number to search: ";
    cin >> target;
    int result = jumpSearch(arr,size,target);
    if(result != -1){
        cout << "Element found at index: " << result << endl;

    }else{
        cout << "Element not found" << endl;
    }
    return 0;
}
