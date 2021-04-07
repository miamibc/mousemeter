/** gcc mousemeter.c -o mousemeter -lX11 -lm **/
#include <X11/Xlib.h>
#include <stdio.h>
#include <unistd.h>
#include <math.h>

int main (int argc, char **argv) {

	setbuf(stdout, NULL); // disable terminal buffering

	Window root_window; 
	float distance = 0, old_distance = -1,  delta;
	unsigned int buttons, old_buttons;
	unsigned int root_x, root_y, old_x, old_y, mask; 
	int accel_numerator_return, accel_denominator_return, threshold_return;
	Display *display = XOpenDisplay(NULL);

	/*
	Bool XQueryPointer(display, w, root_return, child_return, root_x_return, root_y_return,
		         win_x_return, win_y_return, mask_return)
		Display *display;
		Window w;
		Window *root_return, *child_return;
		int *root_x_return, *root_y_return;
		int *win_x_return, *win_y_return;
		unsigned int *mask_return;
	*/
	XGetPointerControl(display, &accel_numerator_return, &accel_denominator_return, &threshold_return);
	printf( "accel_numerator_return %d\naccel_denominator_return: %d\nthreshold_return: %d\n", 
		accel_numerator_return, 
		accel_denominator_return, 
		threshold_return
	);
		
	XQueryPointer(display, DefaultRootWindow(display), &root_window, &root_window, &old_x, &old_y, &old_x, &old_y, &mask);

	while (1) {
		
		XQueryPointer(display, DefaultRootWindow(display), &root_window, &root_window, &root_x, &root_y, &root_x, &root_y, &mask);		
		delta = sqrt(
			(root_x-old_x)*(root_x-old_x)*0.95 +
			(root_y-old_y)*(root_y-old_y)*1.10
		); 
		distance += delta;
		buttons = (mask & (Button1Mask|Button2Mask|Button3Mask)) > 0;	
		
		if ( distance > old_distance || buttons != old_buttons )  {
			
			old_x = root_x;
			old_y = root_y;
			old_buttons = buttons;
			old_distance = distance;
			
			printf( "Mouse (X: %d, Y: %d, buttons: %d, distance %f cm)    \r", 
				root_x, 
				root_y, 
				buttons,
				distance / 500
			);
			
			
		}
		
		usleep( 100000 );
		
	}
	XCloseDisplay(display);
	return 0;
}
