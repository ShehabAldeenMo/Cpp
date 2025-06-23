#include <stdio.h>
#include <iostream>
#include <string>
#include <graphics.h>

class point
{
    int x, y;

public:
    point()
    {
        x = y = 0;
    }
    point(int x = 0, int y = 0)
    {
        this->x = x;
        this->y = y;
    }
    void setX(int x = 0)
    {
        this->x = x;
    }
    void setY(int y = 0)
    {
        this->y = y;
    }

    int getX()
    {
        return this->x;
    }
    int getY()
    {
        return this->y;
    }
};

// compostion relation with point
class Line
{
    point start;
    point end;

public:
    Line(int x1, int y1, int x2, int y2) : start(x1, y1), end(x2, y2)
    {
        std::cout << "At line constant\n";
    }
    void Draw()
    {
        line(start.getX(), start.getY(), end.getX(), end.getY());
    }
};

// compostion relation with point
class rect
{
    point ul;
    point lr;

public:
    rect(int x1, int y1, int x2, int y2) : ul(x1, y1), lr(x2, y2)
    {
        std::cout << "At rect const.";
    }

    draw()
    {
        rectangle(ul.getX(), lr.getY(), ul.getX(), lr.getY());
    }
};

// compostion relation with point
class circle
{
    point center;
    int radius;

public:
    circle(int m, int n, int r) : center(m, n)
    {
        radius = r;
    }

    draw()
    {
        circle(center.getX, center.getY, radius);
    }
};

// aggregation relation with line
// aggregation relation with circle
// aggregation relation with rect
class picture
{
    circle *ptrCr;
    line *ptrL;
    rect *ptrRe;
    int num_L;
    int num_C;
    int num_R;

public:
    picture()
    {
        num_L = num_C = num_R = 0;
        ptrCr = ptrL = ptrRe = NULL;
    }

    picture(int num_L, int num_C, int num_R, Line *ptrL, rect *ptrRe, circle *ptrCr)
    {
        this->num_C = num_C;
        this->num_R = num_R;
        this->num_L = num_L;
        this->ptrCr = ptrCr;
        this->ptrRe = ptrRe;
        this->ptrL = ptrL;
    }

    setCircles(int n, circle *cr)
    {
        num_C = n;
        ptrCr = cr;
    }

    setLines(int n, circle *l)
    {
        num_L = n;
        ptrL = l;
    }
    setRect(int n, circle *R)
    {
        num_R = n;
        ptrRe = R;
    }

    paint()
    {
        for (int i = 0; i < num_C; i++)
        {
            ptr[i].draw();
        }
        for (int i = 0; i < num_L; i++)
        {
            ptr[i].draw();
        }
        for (int i = 0; i < num_R; i++)
        {
            ptr[i].draw();
        }
    }
};

int main()
{
    picture pic;
    Circle cArr[3] = {circle(50, 50, 50), circle(100, 200, 14), circle(420, 50, 30)};
    Line lArr[3] = {Line(50, 50, 50), Line(100, 200, 14), Line(420, 50, 30)};
    rect rArr[3] = {rect(50, 50, 50), rect(100, 200, 14), rect(420, 50, 30)};

    pic.setCircles(3, cArr);
    pic.setLines(3.lArr);
    pic.setRect(3, rArr);

    pic.paint();

    return 0;
}