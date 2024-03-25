#include <stdio.h>

typedef struct Point
{
    double x;
    double y;
} Point;

Point getMiddlePoint(Point *a, Point *b)
{
    Point m;
    m.x = (a->x + b->x) / 2;
    m.y = (a->y + b->y) / 2;

    return m;
}

int main()
{
    Point p1;
    p1.x = 1;
    p1.y = 1;

    Point p2 = {
        .x = 3,
        .y = 2};

    printf("middle x is %lf, middle y is %lf\n", p1.x, p1.y);

    Point middle;
    middle = getMiddlePoint(&p1, &p2);
    printf("middle x is %lf, middle y is %lf\n", middle.x, middle.y);

    return 0;
}