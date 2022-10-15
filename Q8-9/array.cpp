//
// Created by Rohit on 23-11-2021.
//

#include <iostream>

class Array {
public:
    static int *data;
    static int length;

    static float getAverage() {
        int sum = 0;
        for (int i = 0; i < length; sum += data[i++]);

        return (float) sum / (float) length;
    }

    static void readData() {
        std::cout << "Enter how many numbers you want to enter : ";
        int a;
        std::cin >> a;

        length = a;
        data = new int[length];
        for (int i = 0; i < length; std::cin >> data[i++]);
    }

    static void scale(int factor) {
        for (int i = 0; i < length; data[i++] *= factor);
    }

    static void sort() {
        for (int i = 0; i < length - 1; i++)
            for (int j = 0; j < length - i - 1; j++)
                if (data[j] > data[j + 1]) {
                    int temp = data[j];
                    data[j] = data[j + 1];
                    data[j + 1] = temp;
                }
    }

    static void print() {
        for (int i = 0; i < length; std::cout << data[i++] << '\t');
    }
};

int* Array :: data = new int[1];
int Array :: length = 0;

int main() {
    Array array1, array2, array3;
    int m;

    array1.readData();
    std::cout << "Average = " << array1.getAverage() << std::endl;
    std::cout << "By what number do you want to multiply : ";
    std::cin >> m;
    array2.scale(m);
    std::cout << "Average = " << array1.getAverage() << std::endl;
    array3.sort();
    array3.print();
}
