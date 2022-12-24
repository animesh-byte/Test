#include <bits/stdc++.h>
using namespace std;


void display(vector<vector<int>>&arr){
    for(int i=0;i<arr.size();i++){
        for(int j=0;j<arr[0].size();j++){
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
}
vector<vector<int>> create_matrix(int n,int m){
    vector<vector<int>> v(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            v[i][j]=(rand()%100);
        }
    }
    return v;
}
void swap_row(vector<int>&v1, vector<int> &v2){
    for(int i=0;i<v1.size();i++){
        v1[i] ^= v2[i] ^= v1[i] ^= v2[i];
    }
}
void cycle_sort(vector<vector<int>>&v,vector<pair<int,int>>&p, vector<vector<int>> temp){
    for(int i = 0; i < p.size(); i++) {
        if(p[i].second == i) continue;
        for(int j = 0; j < v[i].size(); j++) {
            v[i][j] = temp[p[i].second][j];
        }
    }
}
void _sort(vector<vector<int>>&v,int col){
    vector<pair<int,int>> arr(v.size());
    for(int i=0;i<v.size();i++){
        arr[i].first=v[i][col];
        arr[i].second=i;
    }
    sort(arr.begin(),arr.end());
    cycle_sort(v,arr, v);
}
int main()
{   
    vector<vector<int>> matrix;
    int n,m;
    srand(time(0));
    cout << "enter dimensions -\n";
    cin >> n >> m;
    matrix=create_matrix(n,m);
    cout << "before -\n";
    display(matrix);
    cout << " enter col to sort -\n";
    int col;
    cin >> col;
    _sort(matrix,col);
    cout << "after sorting \n";
    display(matrix);
}
