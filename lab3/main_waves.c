* Zihao Wang
* cmsc152 Lab3
* 1/25/2018 */

#include<stdio.h>
#include<math.h>
#include <stdlib.h>
#include <string.h>
#include "waves.h"

/*the main function that generates the insquare*/
main(int argc, char *argv[])
{
        int c = 0;
        int n = 200;
        int dx, dy = 0;
        double r = 1.0;
        double g = 1.0;
        double b = 1.0;
        for (; argc > 1; ){
                ++argv;
                if ((*argv)[0]=='-'){
                        c = (*argv)[1];
                        argv ++;
                        switch(c){
                        case 's':
                                n = atoi(*argv);
                                break;
                        case 'x':
                                dx = atoi(*argv);
                                break;
                        case 'y':
                                dy = atoi(*argv);
                                break;
                        case 'r':
                                r = atof(*argv);
                                break;
                        case 'g':
                                g = atof(*argv);
                                break;
                        case 'b':
                                b = atof(*argv);
                                break;
                        }
                        argc = argc-2;
                }
        }
        draw_waves_gen(n,dx,dy,r,g,b);
}

