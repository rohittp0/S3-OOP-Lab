## Question 16

❔ Problem to be solved/Question.

### Program

```cpp

```

### Algorithm

```markdown

```

### Output

```Text

```

![screenShot of the output](outputs/prime_check.png)

## Question 17

❔ 

### Program

```cpp
#include <iostream>

#define TOTAL_WORKING_HOURS 160

class Employee {
protected:
    char name[10]{};
    int empNo{};
    float payRate{};
public:
    Employee() = default;

    void getEmployeeData() {
        std::cout << "Enter the employee details below" << '\n';
        std::cout << "--------------------------------" << '\n';
        std::cout << "Enter the name:" << '\n';
        std::cin >> name;
        std::cout << "Enter employment no." << '\n';
        std::cin >> empNo;
        std::cout << "Enter pay rate:" << '\n';
        std::cin >> payRate;
    }

    virtual float pay() = 0;

    void displayEmployeeData() {
        std::cout << "********" << '\n';
        std::cout << "Name of employee: " << name << '\n';
        std::cout << "Employment No. " << empNo << '\n';
        std::cout << "Pay rate " << payRate << '\n';
        std::cout << "Salary: " << pay() << '\n';
        std::cout << "********" << '\n';
    }
};

class Manager : public Employee {
private:
    bool isSalaried{};
    int workingHours{};
public:
    void getManagerData() {
        std::cout << "If salaried hourly enter 0 else 1:" << '\n';
        std::cin >> isSalaried;
        if (!isSalaried) {
            std::cout << "Enter the total working hours:" << '\n';
            std::cin >> workingHours;
        }
    }

    float pay() override {
        if (isSalaried)
            return payRate * TOTAL_WORKING_HOURS;
        else
            return payRate * (float) workingHours;
    }
};

class Supervisor : public Employee {
private:
    std::string department;
public:
    void getSupervisorData() {
        std::cout << "\n Department: ";
        std::cin >> department;
    }

    float pay() override {
        return payRate * TOTAL_WORKING_HOURS;
    }
};

int main() {
    Manager M1;
    Supervisor S;
    int choice;
    std::cout << "\n **enter details** ";
    std::cout << "\n 1. Manager";
    std::cout << "\n 2. Supervisor";
    std::cout << "\n Enter your choice(1 or 2): ";
    std::cin >> choice;
    switch (choice) {
        case 1:
            M1.getEmployeeData();
            M1.getManagerData();
            M1.displayEmployeeData();
            break;
        case 2:
            S.getEmployeeData();
            S.getSupervisorData();
            S.displayEmployeeData();
            break;
        default:
            std::cout << "\n Oops.....Incorrect Choice!";
    }
    return 0;
}
```

### Algorithm

```markdown

```

### Output

```Text
**enter details** 
 1. Manager
 2. Supervisor
 Enter your choice(1 or 2): 2
 Enter the employee details below
--------------------------------
Enter the name:
Rohit
Enter employment no.
1
Enter pay rate:
1000
Department: CS
********
Name of employee: Rohit
Employment No. 1
Pay rate 1000
Salary: 160000
********

```

![employee](outputs/employee.png)

## Question 18

❔ Problem to be solved/Question.

### Program

```cpp
#include<iostream>
#include<cmath>

class shape {
protected:
    float a, b, c, s{}, l{}, b1{}, x{};
    float r{};
public:
    shape() {
        a = 0;
        b = 0;
        c = 0;
    }

    virtual void input() {}

    virtual void validity() {}

    virtual void area() {}

    virtual void perimeter() {}
};

class triangle : public shape {
protected:
    float a1{}, p1{};
public:
    void input() override {
        std::cout << "Enter the dimensions of triangle" << '\n';
        std::cin >> a;
        std::cin >> b;
        std::cin >> c;
    }

    void validity() override {
        {
            if (((a + b) > c) && ((b + c) > a) && ((c + a) > b))
                std::cout << "triangle is valid" << '\n';
            else
                std::cout << "invalid" << '\n';
        }
    }

    void area() override {
        s = (a + b + c) / 2;
        a1 = (float) sqrt(s * (s - a)*(s - b)*(s - c));
        std::cout << "Area of triangle =" << a1 << '\n';
    }

    void perimeter() override {
        p1 = a + b + c;
        std::cout << "Perimeter of triangle =" << p1 << '\n';
    }
};

class rectangle : public shape {
protected:
    float a2{}, p2{};
public:
    void area() override {
        std::cout << "Enter the dimensions of rectangle" << '\n';
        std::cin >> l;
        std::cin >> b1;
        a2 = l * b1;
        std::cout << "Area of rectangle =" << a2 << '\n';
    }

    void perimeter() override {
        p2 = 2 * (l + b1);
        std::cout << "Perimeter of rectangle =" << p2 << '\n';
    }
};

class circle : public shape {
protected:
    float a3{}, p3{};
public:
    void area() override {
        std::cout << "Enter the dimensions of circle" << '\n';
        std::cin >> r;
        a3 = (float) 3.14 * r * r;
        std::cout << "Area of circle =" << a3 << '\n';
    }

    void perimeter() override {
        p3 = (float) (2 * 3.14 * r);
        std::cout << "Perimeter of circle =" << p3 << '\n';
    }
};

class square : public shape {
protected:
    float a4{}, p4{};
public:
    void area() override {
        std::cout << "Enter the dimensions of square" << '\n';
        std::cin >> x;
        a4 = x * x;
        std::cout << "Area of square =" << a4 << '\n';
    }

    void perimeter() override {
        p4 = 4 * x;
        std::cout << "Perimeter of square =" << p4 << '\n';
    }
};

int main() {
    shape s1;
    triangle t;
    rectangle r1;
    circle c1;
    square s2;
    shape *ptr;

    ptr = &s1;
    ptr->input();
    ptr->area();
    ptr->perimeter();
    std::cout << "TRIANGLE" << '\n';

    ptr = &t;
    ptr->input();
    ptr->validity();
    ptr->area();
    ptr->perimeter();
    std::cout << "RECTANGLE" << '\n';

    ptr = &r1;
    ptr->area();
    ptr->perimeter();
    std::cout << "CIRCLE" << '\n';

    ptr = &c1;
    ptr->area();
    ptr->perimeter();
    std::cout << "SQUARE" << '\n';

    ptr = &s2;
    ptr->area();
    ptr->perimeter();

    return 0;
}
```

### Algorithm

```markdown

```

### Output

```Text
TRIANGLE
Enter the dimensions of triangle
10
12
13
triangle is valid
Area of triangle =56.9951
Perimeter of triangle =35
RECTANGLE
Enter the dimensions of rectangle
10
12
Area of rectangle =120
Perimeter of rectangle =44
CIRCLE
Enter the dimensions of circle
4
Area of circle =50.24
Perimeter of circle =25.12
SQUARE
Enter the dimensions of square
5
Area of square =25
Perimeter of square =20

```

![shape](outputs/shape.png)

## Question 19

❔ Problem to be solved/Question.

### Program

```cpp

```

### Algorithm

```markdown

```

### Output

```Text

```

![screenShot of the output](outputs/prime_check.png)

## Question 20

❔ Problem to be solved/Question.

### Program

```cpp
#include<iostream>

#define MAXSIZE 10

class student {
protected:
    int age{};
    long reg_no{};
    std::string name;
public:
    virtual void sort(int n) = 0;
};

class MTech_stud : public student {
protected:
    float gpa;
public:
    MTech_stud() : student() {
        gpa = 0.0;
    }

    void getval() {
        std::cout << "Name :: ";
        std::cin >> name;
        std::cout << "Age :: ";
        std::cin >> age;
        std::cout << "Registration Number :: ";
        std::cin >> reg_no;
        std::cout << "GPA :: ";
        std::cin >> gpa;
    }

    void sort(int n) override {
        for (int i = 0; i < n - 1; ++i) {
            for (int j = 0; j < n - i - 1; ++j) {
                if (this[i].gpa > this[i + 1].gpa) {
                    MTech_stud temp = this[i];
                    this[i] = this[i + 1];
                    this[i + 1] = temp;
                }
                if (this[i].gpa == this[i + 1].gpa) {
                    if ((this[i].name.compare(this[i + 1].name)) < 0) {
                        MTech_stud temp = this[i];
                        this[i] = this[i + 1];
                        this[i + 1] = temp;
                    }
                }
            }
        }
    }

    void display() {
        std::cout << "Name :: " << name << '\n';
        std::cout << "Age :: " << age << '\n';
        std::cout << "Reg No. :: " << reg_no << '\n';
        std::cout << "GPA :: " << gpa << '\n' << '\n';
    }
};

class BTech_stud : public student {
protected:
    float mks;
public:
    BTech_stud() : student() {
        mks = 0.0;
    }

    void getval() {
        std::cout << "Name :: ";
        std::cin >> name;
        std::cout << "Age :: ";
        std::cin >> age;
        std::cout << "Registration Number :: ";
        std::cin >> reg_no;
        std::cout << "Marks :: ";
        std::cin >> mks;
    }

    void sort(int n) override {
        for (int i = 0; i < n - 1; ++i) {
            for (int j = 0; j < n - i - 1; ++j) {
                if (this[i].mks > this[i + 1].mks) {
                    BTech_stud temp = this[i];
                    this[i] = this[i + 1];
                    this[i + 1] = temp;
                }
                if (this[i].mks == this[i + 1].mks) {
                    if ((this[i].name.compare(this[i + 1].name)) < 0) {
                        BTech_stud temp = this[i];
                        this[i] = this[i + 1];
                        this[i + 1] = temp;
                    }
                }
            }
        }
    }

    void display() {
        std::cout << "Name :: " << name << '\n';
        std::cout << "Age :: " << age << '\n';
        std::cout << "Reg No. :: " << reg_no << '\n';
        std::cout << "Marks :: " << mks << '\n' << '\n';
    }
};

int main() {
    student *S;
    BTech_stud B[MAXSIZE];
    MTech_stud M[MAXSIZE];
    int n, x = -1;
    while (x) {
        std::cout << "Choose Programme :: \n";
        std::cout << "1. B.Tech \n";
        std::cout << "2. M.Tech \n";
        std::cout << "Enter 0 to EXIT \n";
        std::cout << "Your Choice :: ";
        std::cin >> x;
        switch (x) {
            case 0:
                std::cout << "Exiting";
                break;

            case 1:
                std::cout << "Enter number of Students enrolled in the B.Tech programme ( <10 ):: ";
                std::cin >> n;
                std::cout << "Enter data of " << n << " student(s)";
                S = B;
                for (int i = 0; i < n; ++i) {
                    std::cout << "Student #" << i + 1 << '\n';
                    B[i].getval();
                }
                S->sort(n);
                std::cout << "The details of students sorted according to Marks :: \n";
                for (int i = n - 1; i >= 0; --i) {
                    B[i].display();
                }
                break;
            case 2:
                std::cout << "Enter number of Students enrolled in the M.Tech programme ( <10 ):: ";
                std::cin >> n;
                std::cout << "Enter data of " << n << " student(s)\n";
                S = M;
                for (int i = 0; i < n; ++i) {
                    std::cout << "Student #" << i + 1 << '\n';
                    M[i].getval();
                }
                S->sort(n);
                std::cout << "The details of students sorted according to Marks :: \n";
                for (int i = n - 1; i >= 0; --i) {
                    M[i].display();
                }
                break;
            default:
                std::cout << "Invalid entry!";
        }
    }
    return 0;
}

```

### Algorithm

```markdown

```

### Output

```Text
/tmp/1gl4CLoYEb.o
Choose Programme :: 
1. B.Tech 
2. M.Tech 
Enter 0 to EXIT 
Your Choice :: 2
Enter number of Students enrolled in the M.Tech programme ( <10 ):: 2
Enter data of 2 student(s)
Student #1
Name :: A
Age :: 23
Registration Number :: 1234
GPA :: 5
Student #2
Name :: B
Age :: 30
Registration Number :: 122
GPA :: 4
The details of students sorted according to Marks :: 
Name :: A
Age :: 23
Reg No. :: 1234
GPA :: 5

Name :: B
Age :: 30
Reg No. :: 122
GPA :: 4

Choose Programme :: 
1. B.Tech 
2. M.Tech 
Enter 0 to EXIT 
Your Choice :: 
```

![student](outputs/student.png)

