#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

void swap(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

bool letters_in_order(char a, char b) {
    return tolower(a) <= tolower(b);
}

bool numbers_in_ascending_order(char a, char b) {
    return a <= b;
}

void bubble_sort(char arr[], int n, bool (*pair_is_in_order)(char, char)) {
    bool swapped;
    do {
        swapped = false;
        for (int i = 1; i < n; i++) {
            if (!pair_is_in_order(arr[i - 1], arr[i])) {
                swap(&arr[i - 1], &arr[i]);
                swapped = true;
            }
        }
    } while (swapped);
}

int main() {
    char letters[] = {'z', 'S', 's', 'a'};
    int n1 = sizeof(letters) / sizeof(letters[0]);

    printf("Before letters: ");
    for (int i = 0; i < n1; i++) printf("%c ", letters[i]);

    bubble_sort(letters, n1, letters_in_order);

    printf("\nAfter letters:  ");
    for (int i = 0; i < n1; i++) printf("%c ", letters[i]);

    char numbers[] = {4, -1, 2, 9};
    int n2 = sizeof(numbers) / sizeof(numbers[0]);

    printf("\n\nBefore numbers: ");
    for (int i = 0; i < n2; i++) printf("%d ", numbers[i]);

    bubble_sort(numbers, n2, numbers_in_ascending_order);

    printf("\nAfter numbers:  ");
    for (int i = 0; i < n2; i++) printf("%d ", numbers[i]);

    printf("\n");
    return 0;
}
