#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <syslog.h>
#include <string.h>
#include <X11/Xlib.h>
/*
#define Button1Mask     (1<<8)
#define Button2Mask     (1<<9)
#define Button3Mask     (1<<10)
#define Button4Mask     (1<<11)
#define Button5Mask     (1<<12)
*/

int main (int argc, char **argv) {
			
        /* Our process ID and Session ID */
        pid_t pid, sid;

        /* Fork off the parent process */
        pid = fork();
        if (pid < 0) {
                exit(EXIT_FAILURE);
        }
        /* If we got a good PID, then
                we can exit the parent process. */
        if (pid > 0) {
                printf( "Daemon started with PID %d\n", pid );
                exit(EXIT_SUCCESS);
        }

        /* Change the file mode mask */
        umask(0);
                
        /* Open any logs here */        
                
        /* Create a new SID for the child process */
        sid = setsid();
        if (sid < 0) {
                /* Log the failure */
                exit(EXIT_FAILURE);
        }



        /* Change the current working directory */
        if ((chdir("/")) < 0) {
                /* Log the failure */
                exit(EXIT_FAILURE);
        }

        /* Close out the standard file descriptors */
        close(STDIN_FILENO);
        close(STDOUT_FILENO);
        close(STDERR_FILENO);

                
        /* The Big Loop */
        while (1) {
                /* Do some task here ... */
                sleep(1); /* wait 1 second */
                        
        }

        exit(EXIT_SUCCESS);

}
