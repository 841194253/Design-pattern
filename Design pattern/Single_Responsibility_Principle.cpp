//
// Created by apple on 8/11/21.
//

#include <iostream>

using namespace std;

class FDYWork;
class Leader;

class FDYWork
{
public:
    void classbuild()
    {
        cout << "classbuild" << endl;
    }
};

class Leader
{
public:
    void study()
    {
        cout << "study" << endl;
    }
};

class StudentWork
{
public:
    void Life(FDYWork* teacher)
    {
        teacher->classbuild();
    }
    void Study(Leader* teacher)
    {
        teacher->study();
    }
};


int main()
{
    StudentWork* studentWork = new StudentWork();
    studentWork->Life(new FDYWork());
    studentWork->Study(new Leader());
}