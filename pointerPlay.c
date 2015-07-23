#import<stdio.h>
#import<string.h>

#define MAX 10

// prototypes
void readArray(int *p, int length);

int main(void)
{
	//pointer arithmatic.
	int a[MAX];
	int i;
	int *p;

	p=a;
	for (i=0; i<MAX; i++)
		a[i]=i;

	readArray(p, 10);

}

void readArray(int *p, int length) {

	for (int j = 0; j < length; j++) {
		printf("%d\n",*p++);
	}
}

// remove trailing and leading whitespace from first name and last name string
void removeSpaces(char s[]) {

}

// return the last name
char* mr(char s[]) {
	char* mr = s;
	return mr;
}
// convert to uppercase
void upper(char s[]) {

}