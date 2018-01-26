#include <stdio.h>

int plusoperator(const unsigned int first, const unsigned int second){

	unsigned int length_unsigned_int = 32;
	unsigned int bit_index = 0;
	unsigned int result = 0;
	unsigned int retenu = 0;

	for(bit_index = 0; bit_index < length_unsigned_int; bit_index++){
		unsigned int value_bit = (1 << bit_index);

		/* Bit in both value match */
		if((first & value_bit) && (second &value_bit)){
			if(retenu){
				result |= value_bit;
				retenu = 0;
			} else {
				retenu = 1;
			}
		}	
		else if(first & value_bit){
			if(retenu){
				retenu = 0;
			}
			else {
				result |= value_bit;
			}
		}
		else if(second & value_bit){
			if(retenu){
				retenu = 0;
			}
			else {
				result |= value_bit;
			}
		}
		else{
			if(retenu){
				result |= value_bit;
				retenu = 0;
			}
		}	
	}

	return result;
}

void main(int argc, char **argv){
	unsigned int 	first = 0;
	unsigned int 	second = 0;
	unsigned int 	expectedresult = 0;
	unsigned int 	calculatedresult = 0;
	unsigned char 	operator = 0;

	while((operator != '+') && (operator != '-')){
		printf("+ or minus - ? %c \n", operator);
		scanf("%c", &operator);
	}

	puts("number 1 ?");
	scanf("%i", &first)
;
	puts("number 2 ?");
	scanf("%i", &second);


	expectedresult = first + second;
	calculatedresult = plusoperator(first, second);

	printf("expected result = %i \n", expectedresult);
	printf("calculated result = %u \n", calculatedresult); 
}
