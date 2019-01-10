#ifndef FIGURE_H
#define FIGURE_H
#include "Shape.h"

class Figure
{

private:

public:
    Figure();
    ~Figure();
    
    bool addShape(Shape s);
    double* getBoundingBox();

};


#endif //FIGURE_H