#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/resource.h>
#include <sys/time.h>
#define TIME 10
#define MB (1024*1024)


void print_timeval(struct timeval t) {
	printf("%ld.%06ld\n", t.tv_sec, t.tv_usec);
}

void print_rusage(struct rusage t) {
	printf("user CPU time used: ");
	print_timeval(t.ru_utime);
	printf("system CPU time used: ");
	print_timeval(t.ru_stime);
	printf("maximum resident set size: %ld\n", t.ru_maxrss);
	printf("integral shared memory size: %ld\n", t.ru_ixrss);
	printf("integral unshared data size: %ld\n", t.ru_idrss);
	printf("integral unshared stack size: %ld\n", t.ru_isrss);
	printf("page reclaims (soft page faults): %ld\n", t.ru_minflt);
	printf("page faults (hard page faults): %ld\n", t.ru_majflt);
	printf("swaps: %ld\n", t.ru_nswap);
	printf("block input operations: %ld\n", t.ru_inblock);
	printf("block output operations: %ld\n", t.ru_oublock);
	printf("IPC messages sent: %ld\n", t.ru_msgsnd);
	printf("IPC messages received: %ld\n", t.ru_msgrcv);
	printf("signals received: %ld\n", t.ru_nsignals);
	printf("voluntary context switches: %ld\n", t.ru_nvcsw);
	printf("involuntary context switches: %ld\n", t.ru_nivcsw);
}

int main(void) { 
	char** mem = (char**) malloc(TIME * sizeof (char*));
	 
	if (mem != NULL) {
		for (int i = 0; i < TIME; ++i) {
			mem[i] = (char*) malloc(10*MB * sizeof *(mem[i]));
			memset(mem[i], '\0', 10*MB);
			
			if (mem[i] != NULL) {
				sleep(1);
				struct rusage usage;
				getrusage(RUSAGE_SELF, &usage);
				printf("\n-------------SECOND #%d-------------\n", i+1);
				print_rusage(usage);
				printf("\n-------------SECOND #%d-------------\n", i+1);
			}
			else {
				printf("Allocation failure #%d\n", i+1);
				break;
			}
		}
	}
	else {
		printf("Allocation failure #0\n");
	}
	return 0;
}
