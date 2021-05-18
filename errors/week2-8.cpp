// C++ for C Programmers, Part A
// Week 2.8
// Author: Alec Landow
//
// The week 2.8 video presents what appears to be a correction at time 7:00 of the video.
// It appears that the correction was meant to update the code to meet community standards,
//  but it looks like the code does not generate the expected output.

#include <iostream>

using namespace std;

typedef enum days{
    SUN,
    MON,
    TUE,
    WED,
    THU,
    FRI,
    SAT
} days;

// Does not compile
days operator++(days &d)
    { return d  = static_cast<int>d + 1 % 7; }

// What I believe works as expected
days operator++(days &d)
    { return d = static_cast<days>( (static_cast<int>(d) + 1) % 7 ); }

int main() {
    days test_day = SAT;
    cout << "The test day is " << test_day << endl;
    cout << "The next day is " << ++test_day << endl;

    return 0;
}
