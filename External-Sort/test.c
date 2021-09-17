#include<stdio.h> 
#include<stdlib.h> 
 
int findPartitionPoint(int *x, int lb,int  ub) 
{ 
int e,f,g; 
e=lb; 
f=ub; 
while(e<f) 
{ 
while(e<ub && x[e]<=x[lb]) 
{ 
e++; 
} 
while(x[f]>x[lb]) 
{ 
f--; 
} 
if(e<f) 
{ 
g=x[e]; 
x[e]=x[f]; 
x[f]=g; 
} 
else 
{ 
g=x[lb]; 
x[lb]=x[f]; 
x[f]=g; 
} 
} 
return f; 
} 
 
void quickSort(int *x, int lb,int ub) 
{ 
int pp; 
if(ub<=lb) return ; 
pp=findPartitionPoint(x,lb,ub); 
quickSort(x,lb,pp-1); 
quickSort(x,pp+1,ub); 
} 
 
int main() 
{
FILE *f0,*f1,*f2,*f3,*f4,*f5,*f6,*f7,*f8,*f9,*f,*files[10],*file; 
int smallest,num,sizeOfFile,noOfRecords,fileOf,howMany,totalWritten,i,z0,z1,z2,z3,z4,z5,z6,z7,z8,z9; 
char fileName[4];
int *x; 
totalWritten=0; 
f=fopen("data.d","rb"); 
fseek(f,0,SEEK_END); 
sizeOfFile=ftell(f); 
fseek(f,0,SEEK_SET); 
noOfRecords=(sizeOfFile/sizeof(int)); 
howMany=(noOfRecords/10); 
for(fileOf=0;fileOf<=9;fileOf++) 
{ 
x=(int*)malloc(sizeof(int)*howMany); 
for(i=0;i<howMany;i++) 
{ 
fread(&num,sizeof(int),1,f); 
x[i]=num; 
} 
quickSort(x,0,howMany-1); 
sprintf(fileName,"f%d.d",fileOf); 
files[fileOf] = fopen(fileName, "wb"); 
for(i=0;i<howMany;i++) 
{ 
fwrite(&x[i],sizeof(int),1,files[fileOf]); 
} 
fclose(files[fileOf]); 
totalWritten=totalWritten+howMany; 
if(fileOf==8)
{
howMany=noOfRecords-totalWritten; 
} 
free(x); 
} 
fclose(f); 
// 10 sorted files are created and now we have to apply merge logic to them 
file=fopen("data2.d","wb");
f0=fopen("f0.d","rb");
f1=fopen("f1.d","rb");
f2=fopen("f2.d","rb");
f3=fopen("f3.d","rb");
f4=fopen("f4.d","rb");
f5=fopen("f5.d","rb");
f6=fopen("f6.d","rb");
f7=fopen("f7.d","rb");
f8=fopen("f8.d","rb");
f9=fopen("f9.d","rb");
fread(&z0,sizeof(int),1,f0);
fread(&z1,sizeof(int),1,f1);
fread(&z2,sizeof(int),1,f2);
fread(&z3,sizeof(int),1,f3);
fread(&z4,sizeof(int),1,f4);
fread(&z5,sizeof(int),1,f5);
fread(&z6,sizeof(int),1,f6);
fread(&z7,sizeof(int),1,f7);
fread(&z8,sizeof(int),1,f8);
fread(&z9,sizeof(int),1,f9);
while(1)
{
if(!feof(f0))
{
smallest=z0;
}
if(!feof(f1))
{
if(feof(f0)) 
{
smallest=z1;
}
if(z1<smallest) 
{
smallest=z1;
}
}
if(!feof(f2))
{
if(feof(f0) && feof(f1))
{
smallest=z2;
}
if(z2<smallest) 
{
smallest=z2;
}
}
if(!feof(f3))
{
if(feof(f0) && feof(f1) && feof(f2))
{
smallest=z3;
}
if(z3<smallest)
{
smallest=z3;
}
}
if(!feof(f4))
{
if(feof(f0) && feof(f1) && feof(f2) && feof(f3))
{
smallest=z4;
}
if(z4<smallest) 
{
smallest=z4;
}
}
if(!feof(f5))
{
if(feof(f0) && feof(f1) && feof(f2) && feof(f3) && feof(f4))
{
smallest=z5;
}
if(z5<smallest)
{
smallest=z5;
}
}
if(!feof(f6))
{
if(feof(f0) && feof(f1) && feof(f2) && feof(f3) && feof(f4) && feof(f5))
{
smallest=z6;
}
if(z6<smallest)
{
smallest=z6;
}
}
if(!feof(f7))
{
if(feof(f0) && feof(f1) && feof(f2) && feof(f3) && feof(f4) && feof(f5) && feof(f6) )
{
smallest=z7;
}
if(z7<smallest)
{
smallest=z7;
}
}
if(!feof(f8))
{
if(feof(f0) && feof(f1) && feof(f2) && feof(f3) && feof(f4) && feof(f5) && feof(f6) && feof(f7) )
{
smallest=z8;
}
if(z8<smallest)
{
smallest=z8;
}
}
if(!feof(f9))
{
if(feof(f0) && feof(f1) && feof(f2) && feof(f3) && feof(f4) && feof(f5) && feof(f6) && feof(f7) && feof(f8) )
{
smallest=z9;
}
if(z9<smallest)
{
smallest=z9;
}
}
if(feof(f0) && feof(f1) && feof(f2) && feof(f3) && feof(f4) && feof(f5) && feof(f6) && feof(f7) && feof(f8) && feof(f9)) 
{
break; 
}
if(smallest==z0)
{
fwrite(&z0,sizeof(int),1,file);
fread(&z0,sizeof(int),1,f0);
}
if(smallest==z1)
{
fwrite(&z1,sizeof(int),1,file);
fread(&z1,sizeof(int),1,f1);
}
if(smallest==z2)
{
fwrite(&z2,sizeof(int),1,file);
fread(&z2,sizeof(int),1,f2);
}
if(smallest==z3)
{
fwrite(&z3,sizeof(int),1,file);
fread(&z3,sizeof(int),1,f3);
}
if(smallest==z4)
{
fwrite(&z4,sizeof(int),1,file);
fread(&z4,sizeof(int),1,f4);
}
if(smallest==z5)
{
fwrite(&z5,sizeof(int),1,file);
fread(&z5,sizeof(int),1,f5);
}
if(smallest==z6)
{
fwrite(&z6,sizeof(int),1,file);
fread(&z6,sizeof(int),1,f6);
}
if(smallest==z7)
{
fwrite(&z7,sizeof(int),1,file);
fread(&z7,sizeof(int),1,f7);
}
if(smallest==z8)
{
fwrite(&z8,sizeof(int),1,file);
fread(&z8,sizeof(int),1,f8);
}
if(smallest==z9)
{
fwrite(&z9,sizeof(int),1,file);
fread(&z9,sizeof(int),1,f9);
}
}
fclose(f0);
fclose(f1);
fclose(f2);
fclose(f3);
fclose(f4);
fclose(f5);
fclose(f6);
fclose(f7);
fclose(f8);
fclose(f9);
fclose(file);
printf("Data of file data.d is sorted,for sorted data check data2.d\n");
return 0; 
}