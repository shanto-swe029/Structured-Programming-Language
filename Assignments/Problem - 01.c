/*
                        -- Course Name  : Structure Programming Language   --
                        -- Course No    : SWE121, SWE122                   --
                        -- Problem No   : 001                              --
                        -- Submitted By : Ariful Islam Shanto - 2019831029 --
*/

#include <stdio.h>

typedef struct {
	int regNo;
	int pSolved;
	double cgpa;
} Student;

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n;		// number of students
	scanf("%d", &n);

	Student info[n];
	Student temp;

	for( int i = 0; i < n; i++ ) {
		scanf("%d %d %lf", &info[i].regNo, &info[i].pSolved, &info[i].cgpa);
	}

	// sorting according to the number of problems solved
	for( int i = 0; i < n; i++ ) {
		for( int j = i + 1; j < n; j++ ) {
			if( info[i].pSolved < info[j].pSolved ) {
				temp    = info[i];
				info[i] = info[j];
				info[j] = temp;
			}
		}
	}

	// sorting according to the CGPA
	int l = 0, r;	// for indexing

	for( int i = 0; i < n; i++ ) {
		if( i == n - 1 ) {
			r = n;
			// segment sort from index l to r
			for( int j = l; j < r; j++ ) {
				for( int k = j + 1; k < r; k++ ) {
					if( info[j].cgpa < info[k].cgpa ) {
						temp    = info[j];
						info[j] = info[k];
						info[k] = temp;
					}
				}
			}
			l = r;
		}
		else if( info[i].pSolved != info[l].pSolved ) {
			r = i;
			// segment sort from index l to r
			for( int j = l; j < r; j++ ) {
				for( int k = j + 1; k < r; k++ ) {
					if( info[j].cgpa < info[k].cgpa ) {
						temp    = info[j];
						info[j] = info[k];
						info[k] = temp;
					}
				}
			}
			l = r;
		}
	}


	// sorting according to the registration number
	l = 0;
	for( int i = 0; i < n; i++ ) {
		if( i == n - 1 ) {
			r = n;
			// segment sort from index l to r
			for( int j = l; j < r; j++ ) {
				for( int k = j + 1; k < r; k++ ) {
					if( info[j].regNo > info[k].regNo ) {
						temp    = info[j];
						info[j] = info[k];
						info[k] = temp;
					}
				}
			}
			l = r;
		}
		else if( ( info[i].pSolved != info[l].pSolved ) || ( info[i].cgpa != info[l].cgpa ) ) {
			r = i;
			// segment sort from index l to r
			for( int j = l; j < r; j++ ) {
				for( int k = j + 1; k < r; k++ ) {
					if( info[j].regNo > info[k].regNo ) {
						temp    = info[j];
						info[j] = info[k];
						info[k] = temp;
					}
				}
			}
			l = r;
		}
	}

	//printing the sorted list
	for( int i = 0; i < n; i++ ) {
		printf("%d %d %0.2lf\n", info[i].regNo, info[i].pSolved, info[i].cgpa);
	}

    return 0;
}
