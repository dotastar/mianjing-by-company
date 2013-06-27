#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

//matrix rotate

// rotate by +90 in a new matrix
void rotate1(vector<vector<int > >& old_matrix){
	int n = old_matrix.size();
	vector<vector<int > > new_matrix(old_matrix);
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < n; ++j)
			new_matrix[i][j] = old_matrix[n-1-j][i];
	old_matrix = new_matrix;
}

// rotate by +90 in place, swap twice
void rotate2(vector<vector<int > >& matrix){
	int n = matrix.size();
	// 1. transpose
	for(int i = 0; i < n; ++i)
		for(int j = i+1; j < n; ++j)
			swap(matrix[i][j], matrix[j][i]);
	// 2. reverse each row
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < n/2; ++j)
			swap(matrix[i][j], matrix[i][n-1-j]);

}

// rotate by +90 in place, layer by layer
void rotate3(vector<vector<int > >& matrix){
	int n = matrix.size();
	for(int i = 0; i < n/2; ++i)
		for(int j = i; j < n-1-i; ++j){
			int t = matrix[i][j];
			matrix[i][j] = matrix[n-1-j][i];
			matrix[n-1-j][i] = matrix[n-1-i][n-1-j];
			matrix[n-1-i][n-1-j] = matrix[j][n-1-i];
			matrix[j][n-1-i] = t;
		}
}

// rotate by -90 in place, swap twice
void rotate4(vector<vector<int > >& matrix){
	int n = matrix.size();
	// 1. transpose
	for(int i = 0; i < n; ++i)
		for(int j = i+1; j < n; ++j)
			swap(matrix[i][j], matrix[j][i]);
	// 2. reverse each column
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < n/2; ++j)
			swap(matrix[j][i], matrix[n-1-j][i]);

}

// rotate by +180 in place, swap twice
void rotate5(vector<vector<int > >& matrix){
	int n = matrix.size();
	// 1. reverse each row
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < n/2; ++j)
			swap(matrix[i][j], matrix[i][n-1-j]);
	// 2. reverse each column
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < n/2; ++j)
			swap(matrix[j][i], matrix[n-1-j][i]);

}

void print_matrix(const vector<vector<int> >& matrix){
	int n = matrix.size();
	for(int i = 0; i < n; ++i){
			for(int j = 0; j < n; ++j){
				cout<<setw(3)<<matrix[i][j]<<" ";
			}
			cout<<endl;
		}
	cout<<endl;
}
int main(){
	int n = 5;
	vector<vector<int> > matrix(n, vector<int>(n));
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			matrix[i][j]=i*n + j;
		}
	}

	print_matrix(matrix);

	vector<vector<int> > matrix1(matrix);
	rotate1(matrix1);
	print_matrix(matrix1);

	vector<vector<int> > matrix2(matrix);
	rotate2(matrix2);
	print_matrix(matrix2);

	vector<vector<int> > matrix3(matrix);
	rotate3(matrix3);
	print_matrix(matrix3);

	vector<vector<int> > matrix4(matrix);
	rotate4(matrix4);
	print_matrix(matrix4);

	vector<vector<int> > matrix5(matrix);
	rotate5(matrix5);
	print_matrix(matrix5);

}
