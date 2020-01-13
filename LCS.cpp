using namespace std;
#include<iostream>
#include "LCS_head.h"

const int LEFT = 1;
const int UPPER = 2;
const int LANDU = 3;

//input:the sequences Xi and Yj;
//C[i][j]: the length of an LCS of Xi and Yj;
//B[i][j]: corresponding to the best optimal subproblem solution;
//the index of C and B actually start from 1 corresponding to the actual length,
//because the situation of 0-length is the boundary condition;
//construct the tables C and B, which maintain all the information of LCS;
LCS_solptr LCS(string X, string Y) {
	int m = X.length();
	int n = Y.length();
	int** C = (int**)malloc(sizeof(int*) * (m + 1));
	for (int i = 0;i < (m + 1);i++)
		C[i] = (int*)malloc(sizeof(int) * (n + 1));
	int** B = (int**)malloc(sizeof(int*) * (m + 1));
	for (int i = 0;i < (m + 1);i++)
		B[i] = (int*)malloc(sizeof(int) * (n + 1));

	/*initial*/
	for (int i = 0;i < m + 1;i++) {
		C[i][0] = 0;
		B[i][0] = 0;
	}
	for (int j = 1;j < n + 1;j++) {
		C[0][j] = 0;
		B[0][j] = 0;
	}
	/*X[i](Y[j]) corresponding to the B or C[i+1][j+1]*/
	for (int i = 0;i < m;i++)
		for (int j = 0;j < n;j++) {
			if (X[i] == Y[j]) {
				C[i + 1][j + 1] = C[i][j] + 1;
				B[i + 1][j + 1] = LANDU;
			}
			else if (C[i][j + 1] >= C[i + 1][j]) {
				C[i + 1][j + 1] = C[i][j+1];
				B[i + 1][j + 1] = UPPER;
			}
			else {
				C[i + 1][j + 1] = C[i + 1][j];
				B[i + 1][j + 1] = LEFT;
			}
		}
	LCS_solptr sol = new LCS_sol;//the pointer of solution
	sol->C = C;
	sol->B = B;
	return sol;
	
}

void LCS_print(string X, int** B, int i, int j) {
	if (i == 0 || j == 0)
		return;
	if (B[i][j] == LANDU) {
		LCS_print(X, B, i - 1, j - 1);
		cout << X[i - 1];
	}
	else if (B[i][j] == UPPER)
		LCS_print(X, B, i - 1, j);
	else
		LCS_print(X, B, i, j - 1);
}



int main() {
	string X = "ACCGGGAAGCTTACCCGGCCGAGGAA";
	string Y = "AATCCAGTGGAGGGGACCA";
	int m = X.length();
	int n = Y.length();
	//LCS(X, Y);
	LCS_solptr sol = LCS(X, Y);
	int** B = sol->B;
	int** C = sol->C;
	cout << "the length of LCS:" << C[m][n]<<endl;
	LCS_print(X, B, m, n);
	for (int i = 0;i < m + 1;i++) {
		for (int j = 0;j < n + 1;j++) {
			cout << C[i][j];
		}
		cout << endl;
	}
	for (int i = 0;i < m + 1;i++) {
		for (int j = 0;j < n + 1;j++) {
			cout << B[i][j];
		}
		cout << endl;
	}
	
}