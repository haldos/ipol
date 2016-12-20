
#include <stdio.h>
#include <stdlib.h>
	
	typedef struct
	{
		double a,b,c,d,e,f,g,h,i,j,k;
	} ObjectOrientedType;

	typedef struct
	{
		double *a,*b,*c,*d,*e,*f,*g,*h,*i,*j,*k;
	} DataOrientedType;

DataOrientedType* DataOrientedType_init(int N)
{
	DataOrientedType* data=(DataOrientedType*)malloc(sizeof(*data));
	data->a=malloc(N*sizeof(double));
	data->b=malloc(N*sizeof(double));
	data->c=malloc(N*sizeof(double));
	data->d=malloc(N*sizeof(double));
	data->e=malloc(N*sizeof(double));
	data->f=malloc(N*sizeof(double));
	data->g=malloc(N*sizeof(double));
	data->h=malloc(N*sizeof(double));
	data->i=malloc(N*sizeof(double));
	data->j=malloc(N*sizeof(double));
	data->k=malloc(N*sizeof(double));

	srand(0);
	for(int i=0;i<N;i++)
		data->a[i]=rand();

	return data;
}

ObjectOrientedType* ObjectOrientedType_init(int N)
{
	ObjectOrientedType* object=(ObjectOrientedType*)malloc(N*sizeof(*object));
	srand(0);
	for(int i=0;i<N;i++)
		object[i].a=rand();
	return object;
}

double Object_average(ObjectOrientedType* object, int N)
{
	double av=0;
	for(int i=0;i<N;i++)
		av+=object[i].a/(double)N;
	return av;
}

double Data_average(DataOrientedType* data, int N)
{
	double av=0;
	for(int i=0;i<N;i++)
		av+=data->a[i]/(double)N;
	return av;
}

int main()
{
	int N=1000;

	ObjectOrientedType* objArray	= ObjectOrientedType_init(N);
	DataOrientedType* 	dataArray 	= DataOrientedType_init(N);

	int R=100;
	for(int i=0;i<R;i++)
	{
		double d_av=Data_average(dataArray,N);
		double o_av=Object_average(objArray,N);
		printf("D average: %g\n",d_av/RAND_MAX);
		printf("O average: %g\n",o_av/RAND_MAX);
	}
}
