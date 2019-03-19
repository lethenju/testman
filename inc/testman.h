#ifndef TESTMAN_H
#define TESTMAN_H

void testman_init();

#define TESTMAN_INT_ASSERT(...)                      \
    do                                               \
    {                                                \
        testman_int_assert(__FILE__, __LINE__, __func__, ##__VA_ARGS__); \
    } while (0)


#define TESTMAN_FLOAT_ASSERT(...)                      \
    do                                               \
    {                                                \
        testman_float_assert(__FILE__, __LINE__, __func__, ##__VA_ARGS__); \
    } while (0)


#define TESTMAN_LONG_ASSERT(...)                      \
    do                                               \
    {                                                \
        testman_long_assert(__FILE__, __LINE__, __func__, ##__VA_ARGS__); \
    } while (0)


#define TESTMAN_STRING_ASSERT(...)                      \
    do                                               \
    {                                                \
        testman_string_assert(__FILE__, __LINE__, __func__, ##__VA_ARGS__); \
    } while (0)


#define TESTMAN_VOID_ASSERT(...)                      \
    do                                               \
    {                                                \
        testman_void_assert(__FILE__, __LINE__, __func__, ##__VA_ARGS__); \
    } while (0)


void testman_register(void* test);

int testman_launch();

#endif