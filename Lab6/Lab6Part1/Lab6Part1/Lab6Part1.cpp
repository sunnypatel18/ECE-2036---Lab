// Lab6Part1.cpp : Defines the entry point for the console application.
#include "stdafx.h"
#include "Windows.h"
#include "LIMITS.h"
//////////////////////change call of function////////////////////
static HANDLE Thread_semaphore;
void Mandelbrot();
DWORD WINAPI Mandelbrot_Thread(LPVOID lpArg);


int _tmain(int argc, _TCHAR* argv[])
{
	HANDLE hThread1;
	DWORD dwThread1ID = 0;
	HANDLE hThread2;
	DWORD dwThread2ID = 0;
	HANDLE hThread3;
	DWORD dwThread3ID = 0;
	HANDLE hThread4;
	DWORD dwThread4ID = 0;
	INT nParameter = 1;
	//DWORD WINAPI PerfectThread(LPVOID lpArg);
	DWORD time_count;
	//unsigned long i, j, sum;
	printf("\n");
	time_count = GetTickCount();
	Mandelbrot();
	/////////////////////////////////////////////comment out section///////////////////////
	// count primes using only one thread
	//for (j = 2; j <= 100000; j++)
	//{
	//	sum = 0;
	//	for (i = 1; i<j; i++)
	//	{
	//		if ((j % i) == 0) sum = sum + i;
	//	}
	//	if (sum == j) printf("%d is a perfect number\n", j);
	//}
	time_count = GetTickCount() - time_count;
	printf("\n\n %d milliseconds elapsed time\n\n\r", time_count);
	// now do it with four threads
	// setup a semaphore for synchronization of threads with an initial value of 0 (waits on 0)
	Thread_semaphore = CreateSemaphore(NULL, 0, 4, TEXT("Thread_Done"));
	time_count = GetTickCount();
	/////////////////change name of Madelbrot_Thread//////////////////////////////////
	hThread1 = CreateThread(NULL, 0, Mandelbrot_Thread, (LPVOID)nParameter, 0, &dwThread1ID);
	nParameter++;
	hThread2 = CreateThread(NULL, 0, Mandelbrot_Thread, (LPVOID)nParameter, 0, &dwThread2ID);
	nParameter++;
	hThread3 = CreateThread(NULL, 0, Mandelbrot_Thread, (LPVOID)nParameter, 0, &dwThread3ID);
	nParameter++;
	hThread4 = CreateThread(NULL, 0, Mandelbrot_Thread, (LPVOID)nParameter, 0, &dwThread4ID);
	// waits for all four threads to signal done with release semaphore
	WaitForSingleObject(Thread_semaphore, INFINITE);
	WaitForSingleObject(Thread_semaphore, INFINITE);
	WaitForSingleObject(Thread_semaphore, INFINITE);
	WaitForSingleObject(Thread_semaphore, INFINITE);
	time_count = GetTickCount() - time_count;
	printf("\n\n %d milliseconds elapsed time\n\r", time_count);
	CloseHandle(hThread1);
	CloseHandle(hThread2);
	CloseHandle(hThread3);
	CloseHandle(hThread4);
	return 0;
}
// code for each of the threads to execute
//image size in pixels and array setup
const unsigned ImageHeight = 480;
const unsigned ImageWidth = 600;
int Image[ImageWidth][ImageHeight];
////////////////copy from lab sheet/////////////////
void Mandelbrot(){
	double MinRe = -2.0;
	double MaxRe = 1.0;
	double MinIm = -1.2;
	double MaxIm = MinIm + (MaxRe - MinRe)*ImageHeight / ImageWidth;
	double Re_factor = (MaxRe - MinRe) / (ImageWidth - 1);
	double Im_factor = (MaxIm - MinIm) / (ImageHeight - 1);
	unsigned MaxIterations = 4096;

	for (unsigned y = 0; y<ImageHeight; ++y)
	{
		double c_im = MaxIm - y*Im_factor;
		for (unsigned x = 0; x<ImageWidth; ++x)
		{
			double c_re = MinRe + x*Re_factor;
			double Z_re = c_re, Z_im = c_im;
			bool isInside = true;
			int niterations = 0;
			for (unsigned n = 0; n<MaxIterations; ++n)
			{
				double Z_re2 = Z_re*Z_re, Z_im2 = Z_im*Z_im;
				if (Z_re2 + Z_im2 > 4)
				{
					isInside = false;
					niterations = n;
					break;
				}
				Z_im = 2 * Z_re*Z_im + c_im;
				Z_re = Z_re2 - Z_im2 + c_re;
			}
			Image[x][y] = niterations;
		}
	}
}

///////////////// copy from lab sheet but change the header///////////////
DWORD WINAPI Mandelbrot_Thread(LPVOID lpArg) {
	INT threadnumber = (INT)lpArg;
	double MinRe = -2.0;
	double MaxRe = 1.0;
	double MinIm = -1.2;
	double MaxIm = MinIm + (MaxRe - MinRe)*ImageHeight / ImageWidth;
	double Re_factor = (MaxRe - MinRe) / (ImageWidth - 1);
	double Im_factor = (MaxIm - MinIm) / (ImageHeight - 1);
	unsigned MaxIterations = 4096;
	////////////change for loop condition//////////////////
	for (unsigned y = ImageHeight*(threadnumber - 1) / 4; y<ImageHeight*(threadnumber - 1) / 4 + (ImageHeight / 4); ++y)
	{
		double c_im = MaxIm - y*Im_factor;
		for (unsigned x = 0; x<ImageWidth; ++x)
		{
			double c_re = MinRe + x*Re_factor;
			double Z_re = c_re, Z_im = c_im;
			bool isInside = true;
			int niterations = 0;
			for (unsigned n = 0; n<MaxIterations; ++n)
			{
				double Z_re2 = Z_re*Z_re, Z_im2 = Z_im*Z_im;
				if (Z_re2 + Z_im2 > 4)
				{
					isInside = false;
					niterations = n;
					break;
				}
				Z_im = 2 * Z_re*Z_im + c_im;
				Z_re = Z_re2 - Z_im2 + c_re;
			}
			Image[x][y] = niterations;
		}
	}
	///////////////////////have the following two statements////////////////
	ReleaseSemaphore(Thread_semaphore, 1, NULL);
	return(0);
}