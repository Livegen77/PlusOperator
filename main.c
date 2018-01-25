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
			} else {
				retenu = 1;
			}
		}	
		else if(first & value_bit){
			result |= value_bit;
		}	
		else if(second & value_bit){
			result |= value_bit;
		}	
	}

	return result;
}

void main(int argc){

	unsigned int first = 4;
	unsigned int second = 2;

	unsigned int expectedresult = first + second;
	unsigned int calculatedresult = plusoperator(first, second);

	printf("expected result = %i \n", expectedresult);
	printf("calculated result = %u \n", calculatedresult); 
}
