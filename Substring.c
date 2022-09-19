#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static inline char * sub_str(char *dest, char *src, int s_idx, int edix){
	if(s_idx >= edix){
		return("Wrong input");
	}
	for (int i = s_idx; i < edix + 1; i++){
		dest[i - s_idx] = src[i];
	}
	return dest;
}

static inline char * asm_sub_str(char *dest, char *src, int s_idx, int edix){
		asm volatile ("cld\n\t"
		              "rep\n\t"
		              "movsb"
		              :
		              :"S"(src + s_idx), "D"(dest), "c"(edix - s_idx + 1)
		             );
					
	return dest;
}

int main(int argc, char **argv){
	char * source_str, * dest, *dest2, *d1, *d2;
	int start_idx, end_idx;

	if(argc < 4){
		fprintf(stderr, "String, starting, ending\n");
		return 1;
	}
	source_str = argv[1];
	start_idx = atoi(argv[2]);
	end_idx = atoi(argv[3]);
//Vital step to malloc dest size in order to assign member value to it.
	dest = (char *)malloc(end_idx -start_idx + 2);
    dest2 = (char *)malloc(end_idx -start_idx + 2);
	d1 = sub_str(dest, source_str, start_idx, end_idx);
	d2 = asm_sub_str(dest2, source_str, start_idx, end_idx);
	printf("d1 string is: %s\n", d1);
	printf("d2 string is: %s\n", d2);
	printf("strcmp return is %d\n",strcmp(d1, d2));
	
	free(dest);
	return 0;
}
