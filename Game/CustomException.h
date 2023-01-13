#pragma once
#include<exception>
#include<string>
using namespace std;
class CustomException:virtual public exception
{
public:
    CustomException(string msg);
};

