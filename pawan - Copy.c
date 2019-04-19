#include<stdio.h>
#include<string.h>
#include<unistd.h>
void main()
{
    int burst[20],ar_t[10],n,i,j,temp,st[10],ft[10],wt[10],turn_a[10];
    int tot_wt=0,tot_ta=0;
    float avg_wt,avg_ta;   //average waiting time and average turnaround time
    char pn[10][10],t[10];    //process name
    //clrscr();
    write(1,"Enter the number of Process:",28);
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        write(1,"Enter Process name, Arrival time and Burst time:",49);
        //flushall();
        scanf("%s%d%d",pn[i],&ar_t[i],&burst[i]);
        if(ar_t[i]==0){
            write(1,"Something went wrong because of arrival time (Arrival time should not be zero).",45);
            exit(1);
        }
    }
    for(i=0; i<n; i++){
        for(j=0; j<n; j++)
        {
            if(burst[i]<burst[j])
            {
                temp=ar_t[i];
                ar_t[i]=ar_t[j];
                ar_t[j]=temp;
                temp=burst[i];
                burst[i]=burst[j];
                burst[j]=temp;
                strcpy(t,pn[i]);
                strcpy(pn[i],pn[j]);
                strcpy(pn[j],t);
            }
        }
    for(i=0; i<n; i++)
    {
        if(i==0)
            st[i]=ar_t[i];
        else
            st[i]=ft[i-1];
        wt[i]=st[i]-ar_t[i];
        ft[i]=st[i]+burst[i];
        turn_a[i]=ft[i]-ar_t[i];
        tot_wt+=wt[i];
        tot_ta+=ta[i];
    }
    avg_wt=(float)tot_wt/n;
    avg_ta=(float)tot_ta/n;
    printf("\nPname\tarrivaltime\texecutiontime\twaitingtime\ttatime");
    for(i=0; i<n; i++){
        printf("\n%s\t%5d\t\t%5d\t\t%5d\t\t%5d",pn[i],ar_t[i],burst[i],wt[i],turn_a[i]);
       }
    }
    printf("\n");
    write(1,"Average waiting time is:",24);printf("%f\n",avg_wt);
    write(1,"Average turnaround time is:",27);printf("%f\n",avg_ta);

}
