#include <stdio.h>
#include <stdlib.h>
#include "pearson.h"
int main(int argc, char** argv){

	if(argc < 2)
	{
		printf("Specify an argument\n");
		return 1;
	}

	unsigned char *hash = generate_hash(argv[1]);
	int i;
	for(i = 0; i < 8; i++)
		printf("%02x",hash[i]);
	printf("\n");

	free(hash);
	return 0;
}

unsigned char *generate_hash(char* data){
	int i,j;
	unsigned char current_char;
	unsigned char *result = (unsigned char *) malloc(8);

	for(j = 0; j < 8; j++){
		current_char = m_lookup_table[data[0] + j  % 256];

		for(i = 0; i < 8; i++)
			current_char = m_lookup_table[current_char ^ data[i]];
		result[j] = current_char;
	}
	return result;
}
