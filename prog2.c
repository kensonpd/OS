#include<stdio.h>
typedef struct{
    int processId;
    int burstTime;
    int priority;
}Process;
void fcfs(Process processes[],int n){
    int waitingTime=0;
    float totalWaitingTime=0;
    float averageWaitingTime;
    printf("\nFCFS Scheduling Algorithm:\n");
    for(int i=0;i<n;i++)
    {
        printf("process%d is running \n",processes[i].processId);
        waitingTime+=processes[i].burstTime;
        printf("Process %d finished waiting Time:%d\n",processes[i].processId,waitingTime);
    }
    averageWaitingTime=totalWaitingTime/n;
    printf("Average Waiting Time:%2f\n",averageWaitingTime);
}
void sjn(Process processes[],int n){
    int totalTime=0;
    int waitingTime=0;
    float totalWaitingTime=0;
    float averageWaitingTime;
    printf("\nSJN Scheduling Algorithm:\n");
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(processes[j].burstTime);
            Process temp=processes[j];
            processes[j]=processes[j+1];
            processes[j+1]=temp;
        }
    }
}
for(int i=0;i<n;i++)
{
    printf("Process %d is running\n",processes[i].processId);
    waitingTime+=totalTime;
    totalTime+=processes[i].burstTime;
    printf("Process%d finished.waiting time:%d\n",processes[i].processId,waitingTime);
    totalWaitingTime+=waitingTime;
    averageWaitingTime=totalWaitingTime/n;
    printf("Average Waiting Time:%2f\n",averageWaitingtime);
}
void priorityScheduling(Process processes[],int n)
{
    int waitingTime=0;
    float totalWaitingTime=0;
    float averageWaitingTime=0;
    printf("\nPriority Scheduling Algorithm:\n");
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(processes[j].priority>processes[j+1].priority)
            {
                 Process temp=processes[j];
            processes[j]=processes[j+1];
            processes[j+1]=temp;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        printf("process%d is running \n",processes[i].processId);
        waitingTime+=processes[i].burstTime;
        printf("Process %d finished waiting Time:%d\n",processes[i].processId,waitingTime);
         totalWaitingTime+=waitingTime;
    }
    averageWaitingTime=totalWaitingTime/n;
    printf("Average Waiting Time:%2f\n",averageWaitingTime);
}
int main()
{
    int n;
    printf("Enter the number of processes:");
    scanf("%d",&n);
    Process process[n];
    for(int i=0;i<n;i++)
    {
        printf("\nEnter details for process%d\n",i+1);
        process[i].processId=i+1;
        printf("Enter burstTime:");
        scanf("%d",&process[i].burstTime);
        printf("Enter priority:");
        scanf("%d",&processes[i].priority);
    }
    fcfs(processes,n);
    sjn(processes,n);
    priorityScheduling(processes,n);
    return 0;
}