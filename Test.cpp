#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> create_matrix(int n,int m){
    vector<vector<int>> v(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            v[i][j]=(rand()%100);
        }
    }
    return v;
}

void Merge(vector<vector<int>> &vec,int start,int mid,int end, int col){
    auto const subArrayOne = mid - start + 1;
    auto const subArrayTwo = end - mid;
 
    vector<int> arr1(subArrayOne), arr2(subArrayTwo);
    
    for (auto i = 0; i < subArrayOne; i++)
        arr1[i] = vec[start + i][col];
    for (auto j = 0; j < subArrayTwo; j++)
        arr2[j] = vec[mid + 1 + j][col];
 
    auto ptr1 = 0, ptr2 = 0; 
    int ptr3 = start; 

    while (ptr1 < subArrayOne && ptr2 < subArrayTwo) {
        if (arr1[ptr1] <= arr2[ptr2]) { 
                vec[ptr3][col] = arr1[ptr1];
            ptr1 += 1;
        }
        else {
            vec[ptr3][col] = arr2[ptr2];
            ptr2 += 1;
        }
        ptr3 += 1;
    }
    
    
    while (ptr1 < subArrayOne) {
        vec[ptr3][col] = arr1[ptr1];
        ptr1 += 1;
        ptr3 += 1;
    }
    
    
    while (ptr2 < subArrayTwo) {
        vec[ptr3][col] = arr2[ptr2];
        ptr2 += 1;
        ptr3 += 1;
    }
}

void MergeSort(vector<vector<int>> &v,int start,int end, int col){
    if(start>=end) return;
    int mid=start+(end-start)/2;
    MergeSort(v,start,mid,col);
    MergeSort(v,mid+1,end,col);
    Merge(v,start,mid, end,col);
}

void display(vector<vector<int>> &matrix) {
    for(int i = 0; i < matrix.size(); i++) {
        for(int j = 0; j < matrix[0].size(); j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{   
    vector<vector<int>> matrix;
    int n, m;
    cin >> n >> m;
    matrix = create_matrix(n,m);
    cout << "Before" << endl;
    display(matrix);
    int col; 
    cout << "Enter col to sort: ";
    cin >> col; 
    MergeSort(matrix, 0, n - 1, col);
    cout << "After sorting col: " << col << endl;
    display(matrix);
    return 0;
}
