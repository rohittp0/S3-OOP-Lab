## Question 10
❔ 

### Program

```cpp
#include <iostream>

class Complex{
private:
    float a, b;

public:
    Complex() = default;

    friend std::ostream &operator<<(std::ostream &out, Complex &p) {
        return out << p.a << "i + " << p.b;
    }

    friend std::istream &operator>>(std::istream &is, Complex &p) {
        return is >> p.a >> p.b;
    }
};

int main()
{
    Complex c{};

    std::cout << "Enter the complex coefficients : ";
    std::cin >> c;

    std::cout << "The complex number is "<< c;

    return 0;
}
```

### Algorithm

```markdown

```

### Output

```text
Enter the complex coefficients : 3
6
The complex number is 3i + 6
```

![complex](outputs/complex.png)

## Question 11
❔ 

### Program

```cpp
#include <cmath>
#include <iostream>

class PolarCoordinates {
private:
    double theta, r;

public:

    PolarCoordinates(double r, double theta) {
        this->theta = theta;
        this->r = r;
    }

    PolarCoordinates() = default;

    double getX() const {
        return r * cos(theta);
    }

    double getY() const{
        return  r * sin(theta);
    }

    friend std::ostream &operator<<(std::ostream &out, PolarCoordinates &p) {
        return out << "r = " << p.r << " theta = " << p.theta;
    }

    friend std::istream &operator>>(std::istream &is, PolarCoordinates &p) {
        return is >> p.r >> p.theta;
    }

};

class RectangularCoordinates {
private:
    double x, y;

public:

    RectangularCoordinates(double x, double y) {
        this->x = x;
        this->y = y;
    }

    RectangularCoordinates() = default;

    double getR() const
    {
        return sqrt(x*x + y*y);
    }

    double getTheta() const
    {
        return atan(y/x);
    }

    explicit operator PolarCoordinates() const {
        return {getR(), getTheta()};
    }

    RectangularCoordinates &operator=(PolarCoordinates &p) {
        this->x = p.getX();
        this->y = p.getY();

        return *this;
    }

    friend std::ostream &operator<<(std::ostream &out, RectangularCoordinates &p) {
        return out << "( " << p.x << " , " << p.y << " )";
    }

    friend std::istream &operator>>(std::istream &is, RectangularCoordinates &p) {
        return is >> p.x >> p.y;
    }
};


int main()
{
    PolarCoordinates p{};
    RectangularCoordinates r{};

    std::cout << "Enter radius and angle : ";
    std::cin >> p;

    std::cout << "Enter x and y coordinates : ";
    std::cin >> r;

    PolarCoordinates pFromR = (PolarCoordinates) r;
    RectangularCoordinates rFromP{};
    rFromP = p;

    std::cout << p << " in rectangular coordinates = " << rFromP << std::endl;
    std::cout << r << " in polar coordinates = " << pFromR << std::endl;

    return 0;
}
```

### Algorithm

```markdown
```

### Output

```text
Enter radius and angle : 2
30
Enter x and y coordinates : 2
4
r = 2 theta = 30 in rectangular coordinates = ( 0.308503 , -1.97606 )
( 2 , 4 ) in polar coordinates = r = 4.47214 theta = 1.10715
```

![distance](outputs/distance.png)

## Question 12
❔ 

### Program

```cpp
#include <iostream>

using namespace std;

class Distance {
    int feet, inch;

public:
    Distance() {
        feet = 0;
        inch = 0;
    }

    void get_value() {
        cout << "Enter a distance in feet \n";
        cin >> feet;
        cout << "Enter a distance in inch \n";
        cin >> inch;
    }

    void display_data() const {
        cout << endl << "Feet value = " << feet << endl;
        cout << "Inch value = " << inch << endl;
    }

    Distance operator+(Distance &obj) const {
        Distance demo;

        demo.feet = feet + obj.feet;
        demo.inch = inch + obj.inch;

        if (demo.inch >= 12) {
            demo.feet += (demo.inch / 12);
            demo.inch = demo.inch % 12;
        }

        return demo;
    }

    friend string operator<(Distance &, Distance &);
};

string operator<(Distance &obj1, Distance &obj2) {
    if (obj1.feet < obj2.feet) {
        return "distance 1 less than distance 2\n";
    } else if (obj1.feet == obj2.feet && obj1.inch < obj2.inch) {
        return "distance 1 less than distance 2\n";
    } else if (obj1.feet > obj2.feet) {
        return "distance 1 greater than distance 2\n";
    } else if (obj1.feet == obj2.feet && obj1.inch > obj2.inch) {
        return "distance 1 great than distance 2\n";
    } else {
        return "distance 1 equal to distance 2\n";
    }
}

int main() {
    Distance obj1, obj2;

    obj1.get_value();
    obj1.display_data();

    obj2.get_value();
    obj2.display_data();

    Distance obj3 = obj1 + obj2;
    cout << "sum of distance\n";
    obj3.display_data();

    string out = obj1 < obj2;
    cout << out;
    return 0;
}
```

### Algorithm

```markdown
```

### Output

```text
Enter a distance in feet 
2
Enter a distance in inch 
4
Feet value = 2
Inch value = 4
Enter a distance in feet 
1
Enter a distance in inch 
3
Feet value = 1
Inch value = 3
sum of distance

Feet value = 3
Inch value = 7
distance 1 greater than distance 2
```

![distance](outputs/distance.png)

## Question 13
❔ 

### Program

```cpp
#include <cmath>
#include <iostream>

class FeetInch {
private:
    double inch;
    int feet;

    void validate()
    {
        int extra = (int) (this->inch / 12);
        this->feet += extra;
        this->inch -= extra * 12;
    }

public:

    FeetInch(int r, double theta) {
        this->inch = theta;
        this->feet = r;

        validate();
    }

    FeetInch() = default;

    double getMeters() const {
        return (feet + inch/12) / 3.28;
    }

    friend std::ostream &operator<<(std::ostream &out, FeetInch &p) {
        return out << p.feet << " Foot " << p.inch << " inches";
    }

    friend std::istream &operator>>(std::istream &is, FeetInch &p) {
        is >> p.feet >> p.inch;
        p.validate();

        return is;
    }

};

class Meter {
private:
    double length;

public:

    explicit Meter(double x) {
        this->length = x;
    }

    Meter() = default;

    int getFeet() const
    {
        return (int) (this->length * 3.28);
    }

    double getInch() const
    {
        return (this->length * 39.37) - (getFeet() * 12);
    }

    explicit operator FeetInch() const {
        return {getFeet(), getInch()};
    }

    Meter &operator=(FeetInch &p) {
        this->length = p.getMeters();
        return *this;
    }

    friend std::ostream &operator<<(std::ostream &out, Meter &p) {
        return out <<  p.length << " Meters";
    }

    friend std::istream &operator>>(std::istream &is, Meter &p) {
        return is >> p.length;
    }
};


int main()
{
    FeetInch p{};
    Meter r{};

    std::cout << "Enter feet and inches : ";
    std::cin >> p;

    std::cout << "Enter meters : ";
    std::cin >> r;

    FeetInch pFromR = (FeetInch) r;
    Meter rFromP{};
    rFromP = p;

    std::cout << p << " = " << rFromP << std::endl;
    std::cout << r << " = " << pFromR << std::endl;

    return 0;
}
```

### Algorithm

```markdown
```

### Output

```text
Enter feet and inches : 2
4
Enter meters : 3
2 Foot 4 inches = 0.711382 Meters
3 Meters = 9 Foot 10.11 inches
```

![feet2meter](outputs/feet2meter.png)

## Question 14
❔ 

### Program

```cpp

```

### Algorithm

```markdown
```

### Output

```text


```

![ss](outputs/ss.png)

## Question 15
❔ 

### Program

```cpp

```

### Algorithm

```markdown

```

### Output

```text

```

![ss](outputs/ss.png)
