// gcc mousemeter.c -o mousemeter -lm && sudo ./mousemeter

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <math.h>

const char *device = "/dev/input/mice";
const int  pps = 600; // pixels per cm

int fd, bytes;
unsigned char data[3];
int left, middle, right;
signed char x, y;
double dist;
    
int main(int argc, char** argv)
{
	
	// disable terminal buffering
	setbuf(stdout, NULL); 
	
	// open stram
	fd = open(device, O_RDWR);
	if(fd == -1)
	{
		printf("Cannot read %s, try running with sudo\n", device);
		return -1;
	}

	printf("You can move your mouse ...");
	
	while(1)
	{
		// Read Mouse     
		bytes = read(fd, data, sizeof(data));

		if(bytes > 0)
		{
			// position +-1 or 0
			x = data[1];
			y = data[2];
			
			// button
			left = data[0] & 0x1;
			right = data[0] & 0x2;
			middle = data[0] & 0x4;

			if (x != 0 || y != 0)
			{
				dist += sqrt(x*x + y*y);
				printf("\rDistance is %.0f px, approx %.2f cm     ", dist, dist/pps);
			}

			// printf("x=%d, y=%d, left=%d, middle=%d, right=%d, dist = %f\n", x, y, left, middle, right, dist);
		    
		}   
	}
	
	return 0; 
}
