#include<stdio.h>
struct da
{
   int max[10],a1[10],need[10],before[10],after[10];
}p[10];
void main()
{
   int i,j,k,l,r,n,tot[10],av[10],cn=0,cz=0,temp=0,c=0;
   printf("\n ENTER THE NO. OF PROCESSES:");
   scanf("%d",&n);
   printf("\n ENTER THE NO. OF RESOURCES:");
   scanf("%d",&r);
   for(i=0;i<n;i++)
   {
     printf("PROCESS %d \n",i+1);
     for(j=0;j<r;j++)
     {  
       printf("MAXIMUM VALUE FOR RESOURCE %d:",j+1);
       scanf("%d",&p[i].max[j]);
     }
     for(j=0;j<r;j++)
     {
       printf("ALLOCATED FROM RESOURCE %d:",j+1);
       scanf("%d",&p[i].a1[j]);
       p[i].need[j]=p[i].max[j]-p[i].a1[j];
     }
   }
  for(i=0;i<r;i++)
  {
    printf("ENTER TOTAL VALUE OF RESOURCE %d:",i+1);
    scanf("%d",&tot[i]);
  }
  for(i=0;i<r;i++)
  {
    for(j=0;j<n;j++)
    {
      temp=temp+p[j].a1[i];
      av[i]=tot[i]-temp;
      temp=0;
    }
  }
  printf("\n\t RESOURCES ALLOCATED NEEDED TOTAL AVAIL");
  for(i=0;i<n;i++)
  {
    printf("\n P%d \t",i+1);
  for(j=0;j<r;j++)
    printf("%d",p[i].max[j]);
    printf("\t");
  for(j=0;j<r;j++)
    printf("%d",p[i].a1[j]);
    printf("\t");
  for(j=0;j<r;j++)
    printf("%d",p[i].need[j]);
    printf("\t");
  for(j=0;j<r;j++)
   {
     if(i==0)
       printf("%d",tot[j]);
   }
   printf("");
  for(j=0;j<r;j++)
   {
     if(i==0)
       printf("%d",av[j]);
   }
  }  
  printf("\n\n\t AVAIL BEFORE\T AVAIL AFTER ");
  for(l=0;l<n;l++)
  {
    for(i=0;i<n;i++)
     {
    for(j=0;j<r;j++)
     {
      if(p[i].need[j] >av[j])
      cn++;
      if(p[i].max[j]==0)
      cz++;
     }
     if(cn==0 && cz!=r)
     {
     for(j=0;j<r;j++)
     {
       p[i].before[j]=av[j]-p[i].need[j];
       p[i].after[j]=p[i].before[j]+p[i].max[j];
       av[j]=p[i].after[j];
       p[i].max[j]=0;
     }
     printf("\n P %d \t",i+1);
    for(j=0;j<r;j++)
       printf("%d",p[i].before[j]);
       printf("\t");
    for(j=0;j<r;j++)
       printf("%d",p[i].after[j]);
       cn=0;
       cz=0;
       c++;
    break;
    }
    else
    {
      cn=0;cz=0;
    }
    }
   }
   if(c==n)
     printf("\n THE ABOVE SEQUENCE IS A SAFE SEQUENCE");
   else
       printf("\n DEADLOCK OCCURED");
}
