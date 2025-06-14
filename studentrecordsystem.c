
#include <stdio.h>
#include <stdlib.h>

struct Student {
    char name[50];
    int roll;
    float marks;
};

int main() {
    struct Student s;
    FILE *fptr;
    fptr = fopen("student.txt", "wb");

    printf("Enter name: ");
    scanf("%s", s.name);
    printf("Enter roll number: ");
    scanf("%d", &s.roll);
    printf("Enter marks: ");
    scanf("%f", &s.marks);

    fwrite(&s, sizeof(struct Student), 1, fptr);
    fclose(fptr);

    fptr = fopen("student.txt", "rb");
    fread(&s, sizeof(struct Student), 1, fptr);
    printf("\nStored Data:\nName: %s\nRoll: %d\nMarks: %.2f\n", s.name, s.roll, s.marks);
    fclose(fptr);
    return 0;
}
