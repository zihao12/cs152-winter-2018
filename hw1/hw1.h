/*valid_room: see if the given number corresponds to a room number*/
int valid_room(unsigned int num);

/*rotary_pulses_r:using recusrion to compute the number of rotations required for a given phone number*/

unsigned int rotary_pulses_r(unsigned long long int phone_num);

/*rotary_pulses_i: *using iteration to compute the number of rotations required for a given phone number*/
unsigned int rotary_pulses_i(unsigned long long int phone_num);

/* nth_harmonic: compute the nth_harmonic*/
double nth_harmonic(unsigned int n);

/*least_ge_harmonic: find the smallest: finds the least value of n such that the nth harmonic number is at least x*/
unsigned int least_ge_harmonic(double x);

/*checkerboard: print n*n checkerboard using ASCII*/
void checkerboard(unsigned int side, unsigned int sq, char light, char dark);
