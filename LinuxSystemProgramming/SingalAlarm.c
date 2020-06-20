#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void my_sig_handler(int signumber)
{
    printf("Alarm delivered signumber is %d\n", signumber);
    system("/bin/ls");
    exit(0);	
}



int main()
{
    alarm(5);
    signal(SIGALRM, my_sig_handler);


    //start executing from this line only if not exited in signal handler.
    for(;;)
    sleep(1);
	
    return 0;
}

