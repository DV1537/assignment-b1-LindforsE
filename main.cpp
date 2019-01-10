#include "Shape.h"
#include "Point.h"
#include "Line.h"
#include "Triangle.h"
#include "Polygon.h"
#include <sstream>

void expand(double *&arr, int &size);

int main(int argc, const char * argv[])
{
    int size = 2, size2 = 2;
    double a = 0;
    int n = 0, count = 0;
    std::string line, tmpNr;
    bool line2 = false, shape2 = false;

    //std::cout.setprecision() only available with iomanip
    //std::cout.precision() doesn't work for decimals

    //(new, mem-leak)
    double * numbers = new double[size];
    double * numbers2 = new double[size2];
   
    //Read numbers from file. filename through argv[]
    std::ifstream myReadFile;
    myReadFile.open(argv[1]);

    //If file can't be opened, throw
    if (!(myReadFile.is_open()))
    {
        throw ("error opening file");
    }
    else
    {
        //Read loop
        while (!(myReadFile.eof()))
        {
            
            std::getline(myReadFile, line);
            std::stringstream linestream(line);
            while(!line2 && std::getline(linestream, tmpNr, ' '))
            {
                numbers[n] = std::stod(tmpNr);
                n++;
                if(n >= size)
                    expand(numbers, size);
            }
            

            while(line2 && std::getline(linestream, tmpNr, ' '))
            {
                numbers2[count] = std::stod(tmpNr);
                count++;
                if(count >= size2)
                    expand(numbers2, size2);
                shape2 = true;
            }

            /*
            //if a number
            if (myReadFile >> a)
            {   
                numbers[n] = a;
                n++;
                //if no space in array, expand
                if (n >= size)
                {
                    expand(numbers, size);
                }
            }   
            //if not a number
            else
            {
                myReadFile.clear();
                myReadFile.ignore(1, ' ');
            }
            */
            line2 = true;
        }
    }
    myReadFile.close();
    
    double arr[n];

    for(int i = 0; i <n; i++)
        arr[i] = numbers[i];

    double arr2[count];

    for(int i = 0; i < count; i++)
        arr2[i] = numbers2[i];
    
    //Run everything through Shape ???
    //Set Shape as below ??? (getType / setType ?)
    //Typecast, C-style

    //Staticly allocated Shape will always be a Shape
    //can't become Point/Line/Triangle/Polygon??

    //Constructor for v these v take vertices coordinates as input
    //1 point(s) = Point
    //2 point(s) = Line
    //3 point(s) = Triangle
    //4 or more point(s) = Polygon

    //Run only if n is even VVVVVVVV
    if( (n %2) == 0 && (count%2) == 0 )
    {
        Polygon s1(arr, n);
        Polygon s2(arr2, count);

        //s1 = new Polygon(arr, n);
        //std::cout << s1.area() << '\n';

        //s2 = new Polygon(arr2, count);
        //std::cout << '\n' << s2.area();

        s1 + s2;
        //std::cout << s1;
        std::cout << '\n' << s1.area();
    }

    //Delete dynamic array (del, mem leak)
    delete [] numbers;
    delete [] numbers2;

    return 0;
}

void expand(double *&arr, int &size)
{
    int n = size;
    size = size * 2;
    //1. New bigger array (new, mem-leak)
    double * tmp = new double[size];
    //2. Copy elements to new array
    for (int i = 0; i < n; i++)
        tmp[i] = arr[i];

    //3. Delete pointer (del, mem-leak)
    delete [] arr;
    //4. Redirect pointer
    arr = tmp;
}