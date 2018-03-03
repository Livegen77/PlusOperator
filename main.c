#include <stdio.h>


unsigned int plusoperator(const unsigned int first, const unsigned int second){

	unsigned int length_unsigned_int = 32;
	unsigned int bit_index = 0;
	unsigned int result = 0;
	unsigned int carry = 0;

	/* Go through each byte of the two numbers */
	for(bit_index = 0; bit_index < length_unsigned_int; bit_index++){
		unsigned int value_bit = (1 << bit_index);

		/* Bit in both value match */
		if((first & value_bit) && (second &value_bit)){
			if(carry){
				result |= value_bit;
				carry = 1;
			} else {
				carry = 1;
			}
		}
		/* Bit only active on the first number */	
		else if(first & value_bit){
			if(carry == 0){
				result |= value_bit;
			}
		}
		/* Bit only active on the second number */
		else if(second & value_bit){
			if(carry == 0){
				result |= value_bit;
			}
		}
		/* Bit not used by any numbers */ 
		else{
			if(carry){
				result |= value_bit;
				carry = 0;
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

	puts("number 1 ?");
	scanf("%i", &first);

	puts("number 2 ?");
	scanf("%i", &second);

	expectedresult = first + second;
	calculatedresult = plusoperator(first, second);

	printf("expected result = %u \n", expectedresult);
	printf("calculated result = %u \n", calculatedresult);


	if(expectedresult != calculatedresult){
		printf("expected result doesn't not match the calculated result \n");
			
		printf("expected result : %08x \n", expectedresult);
		printf("calculated result : %08x \n", calculatedresult);
	}
 
}
