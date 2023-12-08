#include <iostream>
#include <cmath>
#define PI 2*asin(1) //I find it silly that PI isn't a pre-defined const
#define RAD2DEG (180/(2*asin(1))) //the program hates dividing by PI for the conversion back to degrees, but when the conversion value is defined there's no problem
using std::cout;
using std::cin;
//angle calculators
double internalAngles(double A, double B) {
    return (PI - A - B);
}
double lawOfSinsAngle(double sideC, double sideB, double angleC) {
    return asin(sideB * sin(angleC) / sideC);
}
//side calculators
double pythagC(double A, double B) {
    return sqrt(pow(A, 2) + pow(B, 2));
}
double pythagAB(double AB, double C) {
    return sqrt(pow(C, 2) - pow(AB, 2));
}
double lawOfSinsSide(double sideA, double angleA, double angleB) {
    return ((sideA * sin(angleB)) / sin(angleA));
}
//now time for main
int main() {
    double ent1, ent2, ent3, ent4, ent5;
    double ent6 = (90);
    cout << "    /I\n   /bI\n C/  IA\n /   I\n/a  cI\n______\n   B  \nLowercase letters are angles in degrees and the Capital letters are their related sides\n\n";
    cout << "Please enter positive values for Sides A, B, and C, and Angles a and b or enter 0 if you want said value calculated. Angle c is set to 90 degrees for simplicity\n Enter the Values with spaces inbetween each entry\n";
    cin >> ent1 >> ent2 >> ent3 >> ent4 >> ent5;
    //checks the entered values to ensure that the data entered is correct on the user's side
    if (ent1 < 0 or ent2 < 0 or ent3 < 0 or ent4 < 0 or ent5 < 0) {
        cout << "Please do not enter negative values. Please try again\n";
            return 0;
    }
    if (ent4 != 0 and ent5 != 0 and ent4 + ent5 != 90) {
        cout << "Your angles didn't add up to 90. Please try again\n";
        return 0;
    }
    if (ent1 != 0 and ent2 != 0 and ent3 != 0 and ent3 != sqrt(pow(ent1, 2) + pow(ent2, 2))) {
        cout << "Your sides did not follow the Pythagorean Theorem. Please only enter as many values as you have full confidence in and let the other values get calculated\n";
        return 0;
    }
    //convert to radians. I did it like this because cmath uses radians and because degrees are much more intuitive to read and input.
    ent4 = (ent4 * PI / 180);
    ent5 = (ent5 * PI / 180);
    ent6 = (ent6 * PI / 180);
    for (int i = 0; i < 2; i++) { // do the loop twice in case an early calculation can be done only after a later calculation is done
        //angle calculations
        if (ent4 == 0 and ent5 != 0) {
            ent4 = (internalAngles(ent5, ent6));
        }
        if (ent5 == 0 and ent4 != 0) {
            ent5 = (internalAngles(ent4, ent6));
        }
        //side calculations
        if (ent3 == 0 and ent1 != 0 and ent2 != 0) {
            ent3 = (pythagC(ent1, ent2));
        }
        if (ent2 == 0 and ent1 != 0 and ent3 != 0) {
            ent2 = (pythagAB(ent1, ent3));
        }
        if (ent1 == 0 and ent2 != 0 and ent3 != 0) {
            ent1 = (pythagAB(ent2, ent3));
        }
        //complicated calculations
        if (ent5 == 0 and ent2 != 0 and ent3 != 0) {
            ent5 = (lawOfSinsAngle(ent3, ent2, ent6));
        }
        if (ent4 == 0 and ent1 != 0 and ent3 != 0) {
            ent4 = (lawOfSinsAngle(ent3, ent1, ent6));
        }
        if (ent1 == 0 and ent4 != 0 and ent3 != 0) {
            ent1 = (lawOfSinsSide(ent3, ent6, ent4));
        }
        if (ent2 == 0 and ent5 != 0 and ent3 != 0) {
            ent2 = (lawOfSinsSide(ent3, ent6, ent5));
        }
        if (ent3 == 0 and ent5 != 0 and ent2 != 0) {
            ent3 = (lawOfSinsSide(ent2, ent5, ent6));
        }
        if (ent3 == 0 and ent4 != 0 and ent1 != 0) {
            ent3 = (lawOfSinsSide(ent1, ent4, ent6));
        }
    }
    //convert back to degrees
    ent4 = (ent4 * RAD2DEG);
    ent5 = (ent5 * RAD2DEG);
    ent6 = (ent6 * RAD2DEG);
    //check if everything has a value
    if (ent1 == 0 or ent2 == 0 or ent3 == 0 or ent4 == 0 or ent5 == 0) {
        cout << "Some data could not be calculated\nEverthing that could be calculated will now be printed out\n";
    }
    //print out the values
    cout << "Now printing values\n";
    cout << "A = " << ent1 << ", B = " << ent2 << ", C = " << ent3 << ", a = " << ent4 << ", b = " << ent5 << ", c = " << ent6 << "\n";
    system("pause");
    return 0;
}