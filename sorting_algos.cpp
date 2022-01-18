#include <bits/stdc++.h>
using namespace std;

vector<int> selection_sort(vector<int> arr){
    vector<int> temp_arr = arr;
    int index = 0, min_i;
    for(int i=0; i<arr.size(); i++){
        min_i = INT_MAX;
        for(int j=0; j<arr.size(); j++){
            if(arr[j] < min_i){
                min_i = arr[j];
                index = j;
            }
        }
        arr[index] = INT_MAX;
        temp_arr[i] = min_i;
    }
    return temp_arr;
}

void selection_sort_inplace(vector<int> &arr){
    int index, min_i;
    for(int i=0; i<arr.size()-1; i++){
        min_i = arr[i];
        for(int j=i+1; j<arr.size(); j++){
            if(arr[j] < min_i){
                min_i = arr[j];
                index = j;
            }
        }
        swap(arr[i], arr[index]);
    }
}

void bubble_sort(vector<int> &arr){
    for(int k=1; k<arr.size(); k++){
        int flag = 0;
        for(int i=0; i<arr.size() - k ; i++){
            if(arr[i] > arr[i+1]){
                swap(arr[i], arr[i+1]);
                flag = 1;
            }
        }
        if(flag == 0){
            break;
        }
    }
}

void insertion_sort(vector<int> &arr){
    // int value, hole;
    for(int i=1; i<arr.size(); i++){
        // value = arr[i];
        // hole = i;
        // while(hole>0 && arr[hole-1]>value){
        //     arr[hole] = arr[hole-1];
        //     hole = hole - 1;
        // }
        // arr[hole] = value;
        for(int j=i; j>0; j--){
            if(arr[j]<arr[j-1]){
                swap(arr[j], arr[j-1]);
            }
        }
    }
}

void merge(vector<int> &left, vector<int> &right, vector<int> &arr){
    int i=0, j=0, k=0;
    while(i<left.size() && j<right.size()){
        if(left[i]<right[j]){
            arr[k] = left[i];
            i++;
            k++;
        }
        else{
            arr[k] = right[j];
            j++;
            k++;
        }
    }
    while(i<left.size()){
        arr[k] = left[i];
        i++;
        k++;
    }
    while(j<right.size()){
        arr[k] = right[j];
        j++;
        k++;
    }
}

void merge_sort(vector<int> &arr){
    if(arr.size()<2){
        return;
    }
    int mid = arr.size() / 2;
    vector<int> left(mid), right(arr.size()-mid);
    for(int i=0; i<mid; i++){
        left[i] = arr[i];
    }
    for(int i=mid; i<arr.size(); i++){
        right[i-mid] = arr[i];
    }
    merge_sort(left);
    merge_sort(right);
    merge(left, right, arr);
}

int partition(vector<int> &arr, int start, int end){
    int pivot = arr[end];
    int pivotIndex = start;
    for(int i=start; i<end; i++){
        if(arr[i] <= pivot){
            swap(arr[i], arr[pivotIndex]);
            pivotIndex++;
        }
    }
    swap(arr[pivotIndex], arr[end]);
    return pivotIndex;
}

int randamize_partition(vector<int> &arr, int start, int end){
    int pivotIndex = start + (rand()%(end-start+1));
    swap(arr[end], arr[pivotIndex]);
    return partition(arr, start, end);
}

void quick_sort(vector<int> &arr, int start, int end){
    if(start>=end){
        return;
    }
    int pivotIndex = randamize_partition(arr, start, end);
    quick_sort(arr, start, pivotIndex-1);
    quick_sort(arr, pivotIndex+1, end);
}

int main()
{
    vector<int> arr = {7, 2, 1, 6, 8, 5, 3, 4};
    vector<int> temp_arr;
    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    // sorting function to call

    // arr = selection_sort(arr); //- stable, O(n^2)
    // selection_sort_inplace(arr); //- stable, O(n^2)
    // bubble_sort(arr); //- stable, O(n^2)
    // insertion_sort(arr); //- stable, O(n^2), better_than_selection_&_bubble
    // merge_sort(arr); //- stable, time-theta(n log n), space-theta(n)
    quick_sort(arr, 0, arr.size()-1); //- unstable, time_avg-O(n log n), time_worst-O(n^2), inplace

    //
    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}