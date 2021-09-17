#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int main()
{
FILE *f;
int y,num,noOfRecords,sizeOfFile;
f=fopen("data2.d","wb");
noOfRecords=1;
srand(time(0));
while(1)
{
if(noOfRecords==217) break;
num=rand();
fwrite(&num,sizeof(int),1,f);
noOfRecords++;
}
fseek(f,0,SEEK_END);
sizeOfFile=ftell(f);
fseek(f,0,SEEK_SET);
fclose(f);
noOfRecords=(sizeOfFile/sizeof(int));
printf("No of records %d\n",noOfRecords);
return 0;
}