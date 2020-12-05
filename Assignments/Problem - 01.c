/*
                        -- Course Name  : Structure Programming Language   --
                        -- Course No    : SWE121, SWE122                   --
                        -- Problem No   : 001                              --
                        -- Submitted By : Ariful Islam Shanto - 2019831029 --


Problem Statement:
Write a code to sort the elements firstly according to num of problems solved. If number of
problems solved is equal then according to cgpa, if cgpa is equal then according to their
registration number.
Input:
The number in the first line means number of students. Then each line of input has 3 numbers. The first
number represents the registration number, the second number represents the number of solved
problems and the third number represents the cgpa of the students.

Sample Input:
4
1 200 3.99
4 400 3.77
2 1000 3.55
33 1000 3.62

Sample Output:
33 1000 3.62
2 1000 3.55
4 400 3.77
1 200 3.99

*/

#include <stdio.h>

typedef struct {
	int regNo;
	int pSolved;
	double cgpa;
} Student;

int main()
{
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
