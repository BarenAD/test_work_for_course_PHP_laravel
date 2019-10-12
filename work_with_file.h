#ifndef __WORK_WITCH_FILE_H__
#define __WORK_WITCH_FILE_H__

#include <iostream>
#include <cstdio>
#include <string.h>
#include <cstdlib>
#include <stdlib.h>
#include <time.h>

using namespace std;

class Module_work_witch_file
{
private:
    int * array_numbers;
    char * name_file;
public:
    Module_work_witch_file(char *);
    int update_file();
    int print_file();
};

Module_work_witch_file::Module_work_witch_file(char * in_name_file)
{
    this->name_file = new char[strlen(in_name_file)];
    strcpy(this->name_file, in_name_file);
}

int Module_work_witch_file::update_file()
{
    FILE * file = fopen(this->name_file, "w");
    if (file != NULL)
    {
        int count_for = 100;
        srand(time(NULL));
        for (int i = 0; i < count_for; i++){
            int new_rand = 1 + rand()%100;
            char bbbb[4];
            itoa(new_rand, bbbb, 10);
            if (i == count_for-1){
                strcat(bbbb, ".");
            } else {
                strcat(bbbb, ",");
            }
            fputs(bbbb, file);
        }
        fclose (file);
        return 0;
    } else {
        return 403;
    }
}

int Module_work_witch_file::print_file()
{
    FILE * file = fopen(this->name_file, "r");
    if (file != NULL)
    {
        int less_50 = 0;
        int more_50 = 0;
        char temp_number[4];
        char temp_symbol;
        int index = 0;
        printf("NUMBER  ::   conditional_number\n");
        while (!feof(file))
        {
            temp_symbol = fgetc(file);
            switch (temp_symbol)
            {
                default:
                    temp_number[index] = temp_symbol;
                    temp_number[index+1] = '\0';
                    index++;
                break;

                case ',':
                case '.':
                    int integer_number = atoi(temp_number);
                    if (integer_number > 50) {
                        printf("%3.0i     ::   1\n", integer_number);
                        more_50++;
                    } else {
                        printf("%3.0i     ::   0\n", integer_number);
                        less_50++;
                    }
                    temp_number[0] = '\0';
                    index = 0;
                break;
            }
        }
        cout<<"====================="<<endl;
        cout<<"more 50 numbers: "<<more_50<<endl<<endl;
        fclose (file);
        return 0;
        //printf("less 50 (0) = %3.0i \nmore 50 (1) = %3.0i\n\n\n", less_50, more_50);
    } else {
        return 404;
    }
}

#endif
