/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2022-10-30     lhylh       the first version
 */

#include <rtthread.h>
#include "utest.h"
#include "string.h"

static void test_memcpy_uint8(void)
{
    rt_uint8_t a=0,b=0;
    rt_uint8_t *p=RT_NULL;
    a = 211 ;
    p = rt_memcpy(&b, &a, 1);

    uassert_not_null(p);
    uassert_int_equal(p,&b);
    uassert_int_equal(a,b);
}

static void test_memcpy_int8(void)
{
    rt_int8_t a=0,b=0;
    rt_int8_t *p=RT_NULL;
    a = -123 ;
    p = rt_memcpy(&b, &a, 1);

    uassert_not_null(p);
    uassert_int_equal(p,&b);
    uassert_int_equal(a,b);
}

static void test_memcpy_uint16(void)
{
    rt_uint16_t a=0,b=0;
    rt_uint16_t *p=RT_NULL;
    a = 65534 ;
    p = rt_memcpy(&b, &a, sizeof(rt_uint16_t));

    uassert_not_null(p);
    uassert_int_equal(p,&b);
    uassert_int_equal(a,b);
}

static void test_memcpy_int16(void)
{
    rt_int16_t a=0,b=0;
    rt_int16_t *p=RT_NULL;
    a = -12345 ;
    p = rt_memcpy(&b, &a, sizeof(rt_int16_t));

    uassert_not_null(p);
    uassert_int_equal(p,&b);
    uassert_int_equal(a,b);
}

static void test_memcpy_uint32(void)
{
    rt_uint32_t a=0,b=0;
    rt_uint32_t *p=RT_NULL;
    a = 346673456 ;
    p = rt_memcpy(&b, &a, sizeof(rt_uint32_t));

    uassert_not_null(p);
    uassert_int_equal(p,&b);
    uassert_int_equal(a,b);
}

static void test_memcpy_int32(void)
{
    rt_int32_t a=0,b=0;
    rt_int32_t *p=RT_NULL;
    a = -235645636 ;
    p = rt_memcpy(&b, &a, sizeof(rt_int32_t));

    uassert_not_null(p);
    uassert_int_equal(p,&b);
    uassert_int_equal(a,b);
}

static void test_memcpy_float(void)
{
    float a=0,b=0;
    float *p=RT_NULL;
    a = -3.14151 ;
    p = rt_memcpy(&b, &a, sizeof(float));

    uassert_not_null(p);
    uassert_int_equal(p,&b);
    uassert_int_equal(a,b);
}
static void test_memcpy_double(void)
{
    double a=0,b=0;
    double *p=RT_NULL;
    a = -3.141593 ;
    p = rt_memcpy(&b, &a, sizeof(double));

    uassert_not_null(p);
    uassert_int_equal(p,&b);
    uassert_int_equal(a,b);
}

static void test_memcpy_string(void)
{
    char *s1="hello RT-thread!=-[];'./";
    char *s2,*s3;
    int n= strlen(s1);
    s2 = (char *)rt_malloc(sizeof(char)*(n+1));
    s3 = rt_memcpy(s2,s1,(n+1)*sizeof(char));

    uassert_not_null(s3);
    uassert_int_equal(s3, s2);
    uassert_str_equal(s1, s2);
}

static void test_memcpy_struct(void)
{
    struct ss
    {
        int val;
        char* names;
        float val_val;
        struct ss * pa;
    };
    struct ss ss0,ss1,ss2;
    struct ss *ss3;

    ss1.names="hello";
    ss1.pa = &ss0;
    ss1.val=999;
    ss1.val_val = 3.1415926;

    ss3 = rt_memcpy(&ss2, &ss1, sizeof(struct ss));

    uassert_not_null(ss3);
    uassert_int_equal(ss3,&ss2);
    uassert_str_equal(ss1.names,ss2.names);
    uassert_true(ss1.pa == ss2.pa);
    uassert_true(ss1.val == ss2.val);
    uassert_true(ss1.val_val == ss2.val_val);
}

static rt_err_t utest_tc_init(void)
{
    return RT_EOK;
}

static rt_err_t utest_tc_cleanup(void)
{
    return RT_EOK;
}

static void testcase(void)
{
    UTEST_UNIT_RUN(test_memcpy_uint8);
    UTEST_UNIT_RUN(test_memcpy_int8);
    UTEST_UNIT_RUN(test_memcpy_uint16);
    UTEST_UNIT_RUN(test_memcpy_int16);
    UTEST_UNIT_RUN(test_memcpy_uint32);
    UTEST_UNIT_RUN(test_memcpy_int32);
    UTEST_UNIT_RUN(test_memcpy_float);
    UTEST_UNIT_RUN(test_memcpy_double);
    UTEST_UNIT_RUN(test_memcpy_string);
    UTEST_UNIT_RUN(test_memcpy_struct);
}
UTEST_TC_EXPORT(testcase, "applications.utest_memcpy.c", utest_tc_init, utest_tc_cleanup, 10);
