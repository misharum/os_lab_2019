#include <CUnit/Basic.h>
#include <stdio.h>
#include <string.h>

#include "find_min_max.h"
//struct MinMax GetMinMax(int *array, unsigned int begin, unsigned int end);

_Bool EqualMinMax (struct MinMax v1, struct MinMax v2)
    {
	if((v2.min == v1.min)&&(v2.max == v1.max))
	   return 1;
	else
	   return 0;
    }

void testGetMinMax(void) {
  int array1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
  int array2[] = {1, 2, 3, 4, 5, 6, 14, 8, 9, 10, 11};
  int array3[] = {1, 2, 0, 4, 5, 6, 7, 8, 9, 10, 11};
  int array4[] = {1, 2, 3, 4, 5, 6, 7, -4, 9, -10, 11};
  int array5[] = {1933, 2, 38, 499, 5, 6, 7, 8, 9, -10000, -11000};

  struct MinMax test1 = GetMinMax(array1, 0, 11);
  struct MinMax res1;
  res1.min = 1;
  res1.max = 11;
  CU_ASSERT_TRUE_FATAL(EqualMinMax(test1, res1));
  
  struct MinMax test2 = GetMinMax(array2, 0, 11);
  struct MinMax res2;
  res2.min = 1;
  res2.max = 14;
  CU_ASSERT_TRUE_FATAL(EqualMinMax(test2, res2));
  
  struct MinMax test3 = GetMinMax(array3, 0, 11);
  struct MinMax res3;
  res3.min = 0;
  res3.max = 11;
  CU_ASSERT_TRUE_FATAL(EqualMinMax(test3, res3));
  
  struct MinMax test4 = GetMinMax(array4, 0, 11);
  struct MinMax res4;
  res4.min = -10;
  res4.max = 11;
  CU_ASSERT_TRUE_FATAL(EqualMinMax(test4, res4));
  
  struct MinMax test5 = GetMinMax(array5, 0, 11);
  struct MinMax res5;
  res5.min = -11000;
  res5.max = 1933;
  CU_ASSERT_TRUE_FATAL(EqualMinMax(test5, res5));
  
}

int main() {
  CU_pSuite pSuite1 = NULL;

  /* initialize the CUnit test registry */
  if (CUE_SUCCESS != CU_initialize_registry()) return CU_get_error();

  /* add a suite to the registry */
  pSuite1 = CU_add_suite("Suite", NULL, NULL);
  if (NULL == pSuite1) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  /* add the tests to the suite */
  /* NOTE - ORDER IS IMPORTANT - MUST TEST fread() AFTER fprintf() */
  if ((NULL == CU_add_test(pSuite1, "test of GetMinMax function",
                           testGetMinMax))) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  /* Run all tests using the CUnit Basic interface */
  CU_basic_set_mode(CU_BRM_VERBOSE);
  CU_basic_run_tests();
  CU_cleanup_registry();
  return CU_get_error();
}