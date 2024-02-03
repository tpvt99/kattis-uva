#include <iostream>

int main() {
    char name[31];
    int ys, ms, ds;
    int yb, mb, db;
    int course;
    int TC = 0;
    scanf("%d", &TC);
    while (TC-- > 0) {
        scanf(" %30[^0-9]%d/%d/%d %d/%d/%d %d", name, &ys, &ms, &ds, &yb, &mb, &db, &course);
        printf("%s", name);
        if (ys >= 2010) {
            printf("eligible\n");
        }
        else if (yb >= 1991) {
            printf("eligible\n");
        } 
        else if (course >= 41) {
            printf("ineligible\n");
        }
        else {
            printf("coach petitions\n");
        }
    }
    return 0;
}