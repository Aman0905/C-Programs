#include <stdio.h>

#define MAX 100
typedef struct Job {
  char id[6];
  int deadline;
  int profit;
} Job;

void jobOptimal(Job jobs[], int n);

int min(int a, int b) {
  if(a < b) return a;
  return b;
}

int main(void) {
  int i, j;
  Job jobs[6] = {
    {"j1", 5, 200},
    {"j2", 3, 180},
    {"j3", 3, 190},
    {"j4", 2, 300},
    {"j5", 4, 120},
    {"j6", 2, 100},
  };

  Job temp;

  int n = 6;

  //descending order
  for(i = 1; i < n; i++) {
    for(j = 0; j < n - i; j++) {
      if(jobs[j+1].profit > jobs[j].profit) {
        temp = jobs[j+1];
        jobs[j+1] = jobs[j];
        jobs[j] = temp;
      }
    }
  }

  printf("%10s %10s %10s\n", "Job", "Deadline", "Profit");
  for(i = 0; i < n; i++) {
    printf("%10s %10i %10i\n", jobs[i].id, jobs[i].deadline, jobs[i].profit);
  }

  jobOptimal(jobs, n);

  return 0;
}

void jobOptimal(Job jobs[], int n) {
	
  int i, j, k, maxprofit;


  int timeslot[MAX];

  // time slots
  int filledTimeSlot = 0;

  //max deadline
  int dmax = 0;
  for(i = 0; i < n; i++) {
    if(jobs[i].deadline > dmax) {
      dmax = jobs[i].deadline;
    }
  }

  for(i = 1; i <= dmax; i++) {
    timeslot[i] = -1;
  }

  printf("deadline max: %d\n", dmax);
  
  
  for(i = 1; i <n; i++) {
    k = min(dmax, jobs[i - 1].deadline);
    while(k >= 1) {
      if(timeslot[k] == -1) {
        timeslot[k] = i-1;
        filledTimeSlot++;
        break;
      }
      k--;
    }
    
    if(filledTimeSlot == dmax) {
	  printf("Job %s could not be completed",jobs[i].id);
	}
  }

  //required jobs
  printf("\nRequired Jobs: ");
  for(i = 1; i <= dmax; i++) {
    printf("%s", jobs[timeslot[i]].id);
      printf(" --> ");
  }

  //required profit
  maxprofit = 0;
  for(i = 1; i <= dmax; i++) {
    maxprofit += jobs[timeslot[i]].profit;
  }
  printf("\nMax Profit: %d\n", maxprofit);
}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      
