#ifndef TESTMAN_TYPES_H
#define TESTMAN_TYPES_H

typedef struct testman_functions_to_test_t testman_functions_to_test;

typedef struct testman_functions_to_test_t
{
    void (*function)();                     // the function to test
    testman_functions_to_test *next;    // the next function to test
} testman_functions_to_test;

typedef struct testman_context_t
{
    int nb_tests_total;                       // total number of asserts tested for this test suite 
    int nb_tests_total_succeeded;             // total number of asserts succeeded for this test suite
    int nb_tests_currently;                   // number of asserts tested for this function
    int nb_tests_currently_succeeded;         // number of asserts succeeded for this function
    testman_functions_to_test *function_list; // pointer to the functions to test
} testman_context;
#endif