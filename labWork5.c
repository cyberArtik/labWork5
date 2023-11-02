#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void options();
void memory_start(int ***array, int n, int m);
void manually_input(int **array, int n, int m);
void random_input(int **array, int n, int m);
void odd_rows_sort(int **array, int n, int m);
void output_array(int **array, int n, int m);
void memory_stop(int **array, int n);

void options() {
    printf("\n Options:\n");
    printf("1. Allocate memory for the 2D array\n");
    printf("2. Manual input of elements from the keyboard\n");
    printf("3. Fill the array with random elements\n");
    printf("4. Sort odd rows using Insertion Sort \n");
    printf("5. Display elements\n");
    printf("6. Deallocate memory\n");
    printf("0. Exit program\n");
}

// options(1)
void memory_start(int ***array, int n, int m) {

    *array = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        (*array)[i] = (int *)malloc(m * sizeof(int));
    }
    printf("Memory allocated successfully.\n");
}
// options(2)
void manually_input(int **array, int n, int m) {
    int i, j;
    printf("Enter the elements for the %d x %d array:\n", n, m);
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%d", &array[i][j]);
        }
    }
}
// options(3)
void random_input(int **array, int n, int m) {
    int i, j;
    srand(time(NULL));
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            array[i][j] = rand() % 100;
        }
    }
    printf("Array was filled with random elements.\n");
}
// options(4) basetask
void baseTask(int **array, int n, int m) {
    for (int i = 1; i < n; i += 2) {
        for (int j = 1; j < m; j++) {
            int key = array[i][j];
            int k = j - 1;
            while (k >= 0 && array[i][k] > key) {
                array[i][k + 1] = array[i][k];
                k--;
            }
            array[i][k + 1] = key;
        }
    }
    printf("Odd rows were sorted using Insertion Sort.\n");
}
// options(5)
void output_array(int **array, int n, int m) {
    printf("The 2D Array elements:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }
}
// options(6)
void memory_stop(int **array, int n) {
    for (int i = 0; i < n; i++) {
        free(array[i]);
    }
    free(array);
    array = NULL;
    printf("Memory deallocated successfully.\n");
}

// index medium (1)

void index_occurrence(int *array_1D, int k){

    int index = 0;
    int target;
    int first = 0;
    printf("Enter a target value from the 1D array, whose index will be found: ");
    scanf("%d", &target);

    for(int i = 0; i<k; i++){


        if(target == *(array_1D + i)){
            index--;
            first++;
            if (first == 1){
                    printf("\n");
                printf("The index is: %d", i);
            }

        }

        index++;
        if(index == k){
        printf("\n");
        printf("The index occurrence was not found.");
        }


    }
    printf("\n");

}


void transponse_matrix(int **array_2D, int m, int n) {
    int **temp;


    temp = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        temp[i] = (int *)malloc(m * sizeof(int));
    }


    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            temp[j][i] = array_2D[i][j];
        }
    }
    for(int i = 0; i<n;i++){
    for(int j = 0; j<m; j++){
        printf("%d ", temp[i][j]);
    }
    printf("\n");
}
    free(temp);
}


void neg_sum(int *array_1D, int k){
    int negative_sum = 0;
    for(int i = 0; i<k; i++){
        if(*(array_1D + i)<0){
            negative_sum += *(array_1D+i);
        }
    }
    printf("Sum of negative elements of the 1D array is %d", negative_sum);
    printf("\n");
}

void reverse_array(int arr[], int size) {
    int *start = arr;
    int *end = arr + size - 1;

    while (start < end) {
        int temp = *start;
        *start = *end;
        *end = temp;

        start++;
        end--;
    }

    printf("Reversed Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int k;
    int n, m;
    int **array = NULL;
    int option;
    printf("Odd rows were odd_rows_sorted using Insertion odd_rows_sort\n");
    printf("Enter the number of rows (n): ");
    scanf("%d", &n);
    printf("Enter the number of columns (m): ");
    scanf("%d", &m);



    do {
        options();
        printf("Enter your option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                memory_start(&array, n, m);
                break;
            case 2:
                manually_input(array, n, m);
                break;
            case 3:
                random_input(array, n, m);
                break;
            case 4:
                baseTask(array, n, m);
                break;
            case 5:
                output_array(array, n, m);
                break;
            case 6:
                memory_stop(array, n);
                break;
            case 0: printf("\n");
            default:
                printf("\n");
                break;
        }
    } while (option != 0);


printf("Enter the length of the 1D array: ");
scanf("%d", &k);

  int* array_1D = (int*)malloc(k * sizeof(int));

    printf("Enter the elements of the 1D array: ");
    for (int i = 0; i < k; i++) {
        scanf("%d", &array_1D[i]);
    }
index_occurrence(array_1D, k);
    free(array_1D);
     printf("\n----------------------------------------------------------\n\n");

    printf("Enter the size of the array: ");
    scanf("%d", &k);

    int *array_r = (int *)malloc(k * sizeof(int));

    printf("Enter %d integers to reverse:\n", k);
    for (int i = 0; i < k; i++) {
        scanf("%d", &array_r[i]);
    }

    reverse_array(array_r, k);

    printf("\n");
    free(array_r);


    printf("\n----------------------------------------------------------\n\n");
    printf("Enter the length of the 1D array: ");
    scanf("%d", &k);

    array_1D = (int*)malloc(k * sizeof(int));

    printf("Enter the elements of the 1D array: ");
    for (int i = 0; i < k; i++) {
        scanf("%d", &array_1D[i]);
    }

    neg_sum(array_1D, k);
    free(array_1D);


int** array_2D;

printf("\n----------------------------------------------------------\n");
printf("Enter the number of rows of the 2D array: ");
scanf("%d", &n);
printf("Enter the number of columns of the 2D array: ");
scanf("%d", &m);

array_2D = (int**) malloc(n * sizeof(int));
printf("\n");
printf("Enter the elements of the array: \n");
for(int i = 0; i<n;i++){
    array_2D[i] = (int *)malloc(m * sizeof(int));
    for(int j = 0; j<m; j++){
        scanf("%d", &array_2D[i][j]);
    }
}
printf("\n");

if(n != m){
    printf("Number of rows must be equal to the number of columns");
}
else{
    printf("The matrix have been transposed: \n");
    transponse_matrix(array_2D, m, n);
}

free(array_2D);
printf("\n--------------------------------------------------\n");


    return 0;
}
