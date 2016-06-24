/*
 *  Vector.h
 */


// the definition of the queue class.
class Vector {
  public:
    // init the queue (constructor).
    Vector ();
    Vector (int, int, int);
    int x, y, z;
};

Vector::Vector()
{
    x = 0;
    y = 0;
    z = 0;
}

Vector::Vector(int _x, int _y, int _z)
{
    x = _x;
    y = _y;
    z = _z;
}
