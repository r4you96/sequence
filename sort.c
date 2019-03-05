#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define length 5
void swap(int *a, int *b);
void selection_sort(int list[]);
void real_selection_sort(int list[]);
void bubble_sort(int list[]);
void insertion_sort(int list[]);
int main(void) {
	srand(time(NULL));
	int list[length];

	for (int i = 0; i < length; i++)
		list[i] = rand() % 100;

	for (int i = 0; i < length; i++)
		printf("리스트 %d 번째 수 : %d\n",i, list[i]);
	
	real_selection_sort(list);
	//bubble_sort(list);
	//insertion_sort(list);

	for (int i = 0; i < length; i++)
		printf("\n리스트 %d 번째 수 : %d\n", i, list[i]);
	return 0;
}
void swap(int *a, int *b) {
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
void selection_sort(int list[]) {
	int tmp, min, min_index, i, j;
	for (i = 0; i < length; i++) {
		min = list[i];
		min_index = i;
		for (j = i; j < length; j++) {
			if (min < list[j]) {
				min_index = j;
				min = list[j];
			}
			printf("%d -> %d \n", j, list[j]);
		}
		tmp = list[i];
		list[i] = list[min_index];
		list[min_index] = tmp;
	}
}
void real_selection_sort(int list[]) {
	int min = 0, i, j;
	for (i = 0; i < length; i++) {
		min = i;
		for (j = i; j < length; j++) {
			if (list[min] > list[j]) {
				min = j;
			}
		}
		swap(&list[i], &list[min]);
	}
}

void bubble_sort(int list[]) {
	int tmp, i, j;
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < length-1; j++) {
			if (list[j] > list[j+1])
				swap(&list[j], &list[j+1]);
		}
	}
}
void insertion_sort(int list[]) {
	int tmp, i, j;
	for (int i = 1; i < length; i++) {
		for (int j = 0; j < i; j++) {
			if (list[i]<list[j]) {
				tmp = list[i];
				for (int k = i-1; k > j-1; k--)
					list[k + 1] = list[k];
				list[j] = tmp;
				break;
			}
		}
		/*
		for (int s = 0; s < length; s++)
			printf(" %d번째 순환/ 리스트 %d 번째 수 : %d\n",i, s, list[s]);
		*/
	}
}