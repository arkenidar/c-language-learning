// gcc arg-calc.c -o arg-calc

#include "numbers_utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h> // use -lm : gcc -Wall -o "%e" "%f" -lm

void print_usage()
{
    char *usage = "use with: arg-calc {number} {+|-|*|/|//|%|^} {number}";
    puts(usage);
    /// exit(1);
}

char *skip_spaces(char *cursor)
{
    while (1)
    {
        if (cursor[0] == '\0')
            break;
        if (cursor[0] != ' ')
            break;
        cursor++;
    }
    return cursor;
}

int line_main(int argc, char **argv);

int main(int argc, char **argv)
{

    /// debug tool
    /// for(int i=0; i<argc; i++) printf(" i:{%d} arg:{%s} \n", i, argv[i]);

    // skip first argument:
    argc--;
    argv++; // fix

    if (argc <= 0)
    {
        while (1)
        {
            int return_code = line_main(argc, argv);
            if (return_code == EXIT_FAILURE)
                return return_code;
        }
    }
    else
    {
        return line_main(argc, argv);
    }
    return 0;
}

int line_main(int argc, char **argv)
{
    if (argc <= 0)
    {
        char line[101];
        int count = 1;
        char *vector[100] = {0};

        puts("insert a line to calculate");
        int successfully = scanf("%100[^\n]", line);
        // flushes the standard input
        // (clears the input buffer)
        while ((getchar()) != '\n')
            ;
        /// if(successfully != 1) print_usage();
        if (successfully != 1)
            strcpy(line, "");

        /// puts(line); // DEBUG tool
        char *cursor = line;
        cursor = skip_spaces(cursor);
        char *previous = cursor;
        while (1)
        {
            if (cursor[0] == ' ' || cursor[0] == '\0')
            {
                vector[count] = previous;
                count++;
                char *end = cursor;
                cursor = skip_spaces(cursor);
                previous = cursor;
                int is_terminated = end[0] == '\0' ? 1 : 0;
                end[0] = '\0';
                if (is_terminated || count >= (sizeof(vector) / sizeof(char *)))
                    break;
            }
            cursor++;
        }
        argc = count;
        argv = vector;

        argc--;
        argv++; // fix
    }

    /// DEBUG tool
    // printf("argc: %d\n", argc);
    // for(int i=0; i<argc; i++) printf(" i:{%d} arg:{%s} \n", i, argv[i]);

    if (argc % 2 == 0)
    {
        print_usage();
        return EXIT_FAILURE;
    }

    /// double x=atof(argv[0]);
    double x = 0;
    int return_code = parse_number(&x, argv[0]);
    if (return_code != PARSE_NUMBER_SUCCESS)
    {
        puts("parse number error: not a valid number format!");
        return EXIT_FAILURE;
    }
    for (int i = 1; i < argc; i += 2)
    {

        char *operator= argv[i];
        /// double y=atof(argv[i+1]);
        double y = 0;
        int return_code = parse_number(&y, argv[i + 1]);
        if (return_code != PARSE_NUMBER_SUCCESS)
        {
            puts("parse number error: not a valid number format!");
            return EXIT_FAILURE;
        }

        /// DEBUG tool
        /// print_double(x); printf(" %s ",operator); print_double(y); puts("");

        if (0 == strcmp(operator, "+"))
            x = x + y;
        else if (0 == strcmp(operator, "-"))
            x = x - y;
        else if (0 == strcmp(operator, "*"))
            x = x * y;
        else if (0 == strcmp(operator, "/"))
            x = x / y;
        else if (0 == strcmp(operator, "//"))
            x = trunc(x / y);
        else if (0 == strcmp(operator, "%"))
            x = (long)trunc(x) % (long)trunc(y);
        else if (0 == strcmp(operator, "^"))
            x = pow(x, y);
        else
        {
            printf("unrecognized operator: {%s}\n", operator);
            print_usage();
            return EXIT_FAILURE;
        }
    }

    printf("result: ");
    print_double(x);
    puts("");

    return 0;
}
