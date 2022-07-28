#ifndef SRC__MATRIX_OOP_H_
#define SRC__MATRIX_OOP_H_

#include <cmath>
#include <iostream>
#include <string>

class MyMatrix {
 private:
  int rows_, cols_;
  double **matrix_;

  void create_matrix();
  void delite_matrix();
  MyMatrix minor_for_other_function(int rows, int cols);

 public:
  MyMatrix();
  MyMatrix(int rows, int cols);
  MyMatrix(const MyMatrix &other);
  MyMatrix(MyMatrix &&other);
  ~MyMatrix();

  void sum_matrix(const MyMatrix &other);
  void sub_matrix(const MyMatrix &other);
  void mul_number(const double num);
  void mul_matrix(const MyMatrix &other);
  MyMatrix transpose();
  MyMatrix calc_complements();
  double determinant();
  MyMatrix inverse_matrix();
  bool eq_matrix(const MyMatrix &other);

  int get_rows_value() const { return rows_; }
  int get_cols_value() const { return cols_; }

  void set_rows_value(int rows);
  void set_cols_value(int cols);

  MyMatrix &operator=(const MyMatrix &other);
  MyMatrix operator+(const MyMatrix &other);
  MyMatrix operator-(const MyMatrix &other);
  MyMatrix operator*(const MyMatrix &other);
  friend MyMatrix operator*(const MyMatrix &other, double num);
  friend MyMatrix operator*(double num, const MyMatrix &other);
  int operator==(const MyMatrix &other);
  MyMatrix &operator+=(const MyMatrix &other);
  MyMatrix &operator-=(const MyMatrix &other);
  MyMatrix &operator*=(const MyMatrix &other);
  MyMatrix &operator*=(const double num);
  double &operator()(int rows, int cols);
};

MyMatrix operator*(double num, const MyMatrix &other);
MyMatrix operator*(const MyMatrix &other, double num);

#endif  // SRC__MATRIX_OOP_H_
