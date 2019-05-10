#ifndef SUM_FUNC_H
#define SUM_FUNC_H

struct SumArgs {
  int *array;
  int begin;
  int end;
};
int Sum(const struct SumArgs *args);

#endif