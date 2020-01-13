#pragma once

//store the table_pointers, which maintain the information of the optimal solution
struct LCS_sol {
	int** C;
	int** B;
};
typedef LCS_sol* LCS_solptr;