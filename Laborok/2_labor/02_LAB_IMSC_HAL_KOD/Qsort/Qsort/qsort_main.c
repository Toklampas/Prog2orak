#include <stdio.h>
#include <stdlib.h>


// Az összehasonlító függvény:
// a tömb két elemét hasonlítja össze.
// Ezt nekünk kell megírnunk, hiszen bármilyen típusú
// tömböt átadhatunk volna a qsortnak, és
// ő nem tud a típusról.
// Miért void pointerek a paraméterei?
int compare(const void* a, const void *b)
{	
	// 1. FELADAT - ide kell egy break point (töréspont)
	double* da = (double*)a, *db = (double*)b;

	// Visszatérés: <0, ha a a<b; 0, ha a=b;	>0, ha a>b.
	if (*da<*db)return-1;
	else if (*da == *db) return 0;
	else return 1;
}

// 5. FELADAT: qsort paraméterlistájával megegyező függvény, amely rendező algoritmust valósít meg

main()
{
	// 2. FELADAT: tömbméret bekérés a felhasználótól. Használj dinamikus memóriakezelést!
	int array_size;
	int i;

	printf("Add meg a tomb meretet: ");
	scanf("%d", &array_size);

	double* d = (double*)malloc(array_size * sizeof(double));
	if (d == NULL)
		return 1;

	// 4. FELADAT: biztonságos szövegbevitel. Tipp: scanf_s
	// miért kell scanf_s: ha olyan területre írunk, amit nem foglaltunk le (akár csak kis részben is) => segmentation fault hiba
	// hacker/óvatlan felhasználó leállíthatja a programunk: buffer overflow attack
	// Warning kikapcsolás: C/C++ -> Preprocessor -> Preprocessor definitions: _CRT_SECURE_NO_WARNINGS
	for (i = 0; i<array_size; i++)
	{
		printf("Enter a number:");
		// 3. FELADAT: scanf háromféleképpen
		//scanf("%lf", &d[i]); // 1. mód
		//scanf("%lf", d + i); // 2. mód
		//scanf("%lf", &*(d + i)); // 3. mód

		// 4. FELADAT
		scanf_s("%lf", &d[i], sizeof(double));

	}

	qsort(d, array_size, sizeof(double), compare);

	for (i = 0; i<array_size; i++)
	{
		printf("%lf ", d[i]);
	}

	// 2. FELADAT: a korábban lefoglalt dinamikus területet ne felejtsd el felszabadítani!
	free(d);

	return 0;
}