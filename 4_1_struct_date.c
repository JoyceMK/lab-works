#include<stdio.h>

struct Date
{
    int day, month, year;
};

void readDate(struct Date *date) {

    printf("Enter date (DD/MM/YYYY) : ");
    scanf("%d/%d/%d", &(*date).day, &(*date).month, &(*date).year);
}

void printDate(struct Date date) {

    printf("%2d/%2d/%2d\n", date.day, date.month, date.year);
}
int dateEqual(struct Date d1, struct Date d2 )
{
    return (d1.day == d2.day && d1.month == d2.month && d1.year == d2.year);
}
int main() {

    struct Date d1,d2;

    readDate(&d1);
    readDate(&d2);

    printDate(d1);
    printDate(d2);

    if(dateEqual(d1,d2))
        printf("\nDates are same");
    else
        printf("\nDates are not same");

}
