#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "testman_types.h"

static testman_context *ctx;

void testman_init()
{
    ctx = malloc(sizeof(testman_context));
    ctx->nb_tests_total = 0;
    ctx->nb_tests_total_succeeded = 0;
    ctx->nb_tests_currently = 0;
    ctx->nb_tests_currently_succeeded = 0;
    ctx->function_list = NULL;
}

void testman_int_assert(char* file, int line, char* func, int result, int expected)
{
    ctx->nb_tests_total++;
    ctx->nb_tests_currently++;
    printf("[%s:%d][%s] Testing equality of %d and %d",file, line, func, result, expected);
    if (result == expected)
    {
        printf("   Ok..\n");
        ctx->nb_tests_total_succeeded++;
        ctx->nb_tests_currently_succeeded++;
    }
    else 
    {
        printf("Failed..\n");
    }
}


void testman_float_assert(char* file, int line, char* func, float result, float expected)
{
    ctx->nb_tests_total++;
    ctx->nb_tests_currently++;
    printf("[%s:%d][%s] Testing equality of %f and %f",file, line, func, result, expected);
    if (result == expected)
    {
        printf("   Ok..\n");
        ctx->nb_tests_total_succeeded++;
        ctx->nb_tests_currently_succeeded++;
    }
    else 
    {
        printf("Failed..\n");
    }
}


void testman_long_assert(char* file, int line, char* func, long result, long expected)
{
    ctx->nb_tests_total++;
    ctx->nb_tests_currently++;
    printf("[%s:%d][%s] Testing equality of %ld and %ld",file, line, func, result, expected);
    if (result == expected)
    {
        printf("   Ok..\n");
        ctx->nb_tests_total_succeeded++;
        ctx->nb_tests_currently_succeeded++;
    }
    else 
    {
        printf("Failed..\n");
    }
}

void testman_string_assert(char* file, int line, char* func, char* result, char* expected)
{
    ctx->nb_tests_total++;
    ctx->nb_tests_currently++;
    printf("[%s:%d][%s] Testing equality of %s and %s",file, line, func, result, expected);
    if (!strcmp(result, expected))
    {
        printf("   Ok..\n");
        ctx->nb_tests_total_succeeded++;
        ctx->nb_tests_currently_succeeded++;
    }
    else 
    {
        printf("Failed..\n");
    }
}

void testman_void_assert(char* file, int line, char* func, void* result, void* expected)
{
    ctx->nb_tests_total++;
    ctx->nb_tests_currently++;
    printf("[%s:%d][%s] Testing equality of %p and %p",file, line, func, result, expected);
    if (result == expected)
    {
        printf("   Ok..\n");
        ctx->nb_tests_total_succeeded++;
        ctx->nb_tests_currently_succeeded++;
    }
    else 
    {
        printf("Failed..\n");
    }
}

void testman_register(void* test)
{
    if (ctx->function_list == NULL)
    {
        ctx->function_list = malloc(sizeof(testman_functions_to_test));
        memset(ctx->function_list, '\0', sizeof(testman_functions_to_test));
        ctx->function_list->function = test;
    }
    else
    {
        testman_functions_to_test *test_func = ctx->function_list;
        while (test_func->next != NULL)
            test_func = test_func->next;
        test_func->next = malloc(sizeof(testman_functions_to_test));
        memset(test_func->next, '\0', sizeof(testman_functions_to_test));
        test_func->next->function = test;
    }
}

int testman_launch()
{
    printf("\nLaunching test suite\n");
    testman_functions_to_test *test_func = ctx->function_list;
    while (test_func != NULL)
    {
        printf("\nLaunching test function\n");
        (test_func->function)();
        printf("%d / %d tests\n", ctx->nb_tests_currently_succeeded, ctx->nb_tests_currently);
        printf("TOTAL = %d / %d tests\n", ctx->nb_tests_total_succeeded, ctx->nb_tests_total);
        ctx->nb_tests_currently = 0;
        ctx->nb_tests_currently_succeeded = 0;
        test_func = test_func->next;
    }
    printf("\n Test suite ended: \n results \n\n ");
    printf("TOTAL = %d / %d tests\n", ctx->nb_tests_total_succeeded, ctx->nb_tests_total);
}
