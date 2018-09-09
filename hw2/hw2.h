/*compute the exclusive or of two quasi-booleans?*/
int xor(int b1, int b2);

/*Show the contents of the integer array, one item and one line at a time*/
void show_array(int *a, unsigned int len);

/*Add the value of n to each item in the array a.*/
void add_to_all(int n, int *a, unsigned int len);

/*count the number of occurences of the value n*/
int occurrences_of(int n, int *a, unsigned int len);

/*return "true" if the array contains an odd number(which does not have to br positive)*/
int any_odd(int *a, unsigned int len);

/*reverse the array without building a new array*/
void reverse(int *a, unsigned int len);

/*find the minimum number in the array; return error if the array has length 0*/
int min(int *a, unsigned int len);

/*find the maximum number in the array; return error if the array has length 0*/
int max(int *a, unsigned int len);

/*return "true" if the two arrays are the same*/
int equal(int *a1, unsigned int len1, int *a2, unsigned int len2);

/*Display the giving unsigned integer one bit at time, including leading zeros, for 32 bits altogether*/
void int_binary(unsigned int n);

/*Display the giving unsigned integer one quaternary digit at time*/
void int_quaternary(unsigned int n);

