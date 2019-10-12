#include <iostream>
//#include <locale.h>
#include "./work_with_file.h"

using namespace std;

void check_code(int);
double calc_factorial(int);

int main()
{
    //setlocale(LC_ALL,"russian");
    //Task 1-2
    char NameFile[] = "numbers.csv";
    Module_work_witch_file Module_WorkFile(NameFile);
    int code;
    check_code(Module_WorkFile.update_file());
    check_code(Module_WorkFile.print_file());

    //Task 3
    int input = 0;
    while (input < 1 || input > 10){
        cout<<"Enter a number 1 >= X <= 10: ";
        cin>>input;
    }
    //cout<<"Факториал числа "<<input<<" равен "<<calc_factorial(input);
    printf("The factorial of a number %i === %8.0lf\n\n\n",input,calc_factorial(input));
    system("pause");
    return 0;
};

void check_code(int in_code)
{
    if (in_code != 0){
        switch (in_code)
        {
            case 403: cout<<endl<<"Programm do not may open is file. Check permissions."<<endl; break;
            case 404: cout<<endl<<"Programm do not may open is file. File not found or check permissions."<<endl; break;
        };
    }
}

double calc_factorial(int in_number)
{
    if (in_number <= 2){
        return 2;
    } else {
        return in_number * calc_factorial(in_number-1);
    }
}
