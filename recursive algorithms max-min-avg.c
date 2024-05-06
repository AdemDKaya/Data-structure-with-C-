#include<stdio.h>

int find_max(int a[], int i, int l) {
    int m;
    if (i >= l - 2) {
        if (a[i] > a[i + 1])
            return a[i];
        else
            return a[i + 1];
    }
    m = find_max(a, i + 1, l);
    if (a[i] > m)
        return a[i];
    else
        return m;
}

int find_sum(int a[], int n) {
    if (n <= 0)
        return 0;
    return (find_sum(a, n - 1) + a[n - 1]);
}

float find_avg(int a[], int n) {
    int sum = 0;
    float avg;
    if (n <= 0)
        return 0;
    sum = find_sum(a, n);
    avg = (float)sum / n;
    return avg; 
}

int main() {
    int a[100], n, i, max, sum;
    float avg;
    printf("Enter size of the array: ");
    scanf("%d", &n);
    printf("Enter array elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    max = find_max(a, 0, n);
    sum = find_sum(a, n);
    avg = find_avg(a, n); 
    printf("Maximum element in the array is %d\n", max);
    printf("Sum of elements of array is %d\n", sum);
    printf("Average of elements in the array is %f\n", avg);
    return 0;
}
