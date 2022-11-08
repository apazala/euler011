#include <cstdio>
#include <cinttypes>
#include <cmath>

#define N 20
#define CONSEC 4

int load_data(int grid[N][N])
{
	FILE *pf = fopen("/home/alberto/Documents/projecteuler/euler011/data.txt", "r");
	if(!pf) return -1;
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			fscanf(pf, "%d", &grid[i][j]);
		}
	}
	
	fclose(pf);
	
	return 0;
}


int main(int argc, char **argv)
{	
	int grid[N][N];
	
	if(load_data(grid) < 0)
		return 1;
	
	int64_t max_prod = 0;
	int64_t prod;
	
	//East
	for(int i = 0; i < N; i ++){
		for(int j = 0, limj = N-CONSEC; j < limj; j++){
			prod = 1;
			for(int k = 0; k < CONSEC; k++){
				prod*=grid[i][j+k];
			}
			if(prod>max_prod)
				max_prod = prod;
		}
	}
	
	//South
	for(int i = 0, limi = N-CONSEC; i < limi; i++){
		for(int j = 0; j < N; j++){
			prod = 1;
			for(int k = 0; k < CONSEC; k++){
				prod*=grid[i+k][j];
			}
			if(prod>max_prod)
				max_prod = prod;
		}
	}
	
	//South East
	for(int i = 0, limi = N-CONSEC; i < limi; i++){
		for(int j = 0, limj = N-CONSEC; j < limj; j++){
			prod = 1;
			for(int k = 0; k < CONSEC; k++){
				prod*=grid[i+k][j+k];
			}
			if(prod>max_prod)
				max_prod = prod;
		}
	}
	
	//South West
	for(int i = 0, limi = N-CONSEC; i < limi; i++){
		for(int j = CONSEC-1, limj = N-1; j < limj; j++){
			prod = 1;
			for(int k = 0; k < CONSEC; k++){
				prod*=grid[i+k][j-k];
			}
			if(prod>max_prod)
				max_prod = prod;
		}
	}
	
	printf("%" PRId64 "\n", max_prod);
	
    return 0;
}
