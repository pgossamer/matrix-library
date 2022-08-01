#include <gtest/gtest.h>

#include "_matrix_oop.h"

TEST(operation, eq_test) {
  MyMatrix f_matrix(2, 2);
  f_matrix(0, 0) = 1;
  f_matrix(0, 1) = 1;
  f_matrix(1, 0) = 1;
  f_matrix(1, 1) = 1;
  MyMatrix s_matrix(2, 2);
  s_matrix(0, 0) = 1;
  s_matrix(0, 1) = 1;
  s_matrix(1, 0) = 1;
  s_matrix(1, 1) = 1;

  EXPECT_EQ(1, f_matrix.eq_matrix(s_matrix));
}

TEST(operation, eq_test_2) {
  MyMatrix f_matrix(2, 2);
  f_matrix(0, 0) = 1;
  f_matrix(0, 1) = 1;
  f_matrix(1, 0) = 1;
  f_matrix(1, 1) = 1;
  MyMatrix s_matrix(2, 2);
  s_matrix(0, 0) = 1;
  s_matrix(0, 1) = 1;
  s_matrix(1, 0) = 1;
  s_matrix(1, 1) = 1;

  int a = 0;
  if (f_matrix == s_matrix) {
    a = 1;
  }
  EXPECT_EQ(1, a);
}

TEST(operation, eq_test_3) {
  MyMatrix f_matrix(2, 2);
  f_matrix(0, 0) = 1;
  f_matrix(0, 1) = 1;
  f_matrix(1, 0) = 0;
  f_matrix(1, 1) = 1;
  MyMatrix s_matrix(2, 2);
  s_matrix(0, 0) = 1;
  s_matrix(0, 1) = 1;
  s_matrix(1, 0) = 1;
  s_matrix(1, 1) = 1;

  EXPECT_EQ(0, f_matrix.eq_matrix(s_matrix));
}

TEST(operation, sum_test) {
  MyMatrix f_matrix(3, 3);
  f_matrix(0, 0) = 1;
  f_matrix(0, 1) = 1;
  f_matrix(0, 2) = 1;
  f_matrix(1, 0) = 0;
  f_matrix(1, 1) = 1;
  f_matrix(1, 2) = 1;
  f_matrix(2, 0) = 11;
  f_matrix(2, 1) = 1;
  f_matrix(2, 2) = 1;
  MyMatrix s_matrix(3, 3);
  s_matrix(0, 0) = 1;
  s_matrix(0, 1) = 13;
  s_matrix(0, 2) = 1;
  s_matrix(1, 0) = 1;
  s_matrix(1, 1) = 1;
  s_matrix(1, 2) = 1;
  s_matrix(2, 0) = 11;
  s_matrix(2, 1) = 1;
  s_matrix(2, 2) = 1;
  MyMatrix result_matrix(3, 3);
  result_matrix(0, 0) = 2;
  result_matrix(0, 1) = 14;
  result_matrix(0, 2) = 2;
  result_matrix(1, 0) = 1;
  result_matrix(1, 1) = 2;
  result_matrix(1, 2) = 2;
  result_matrix(2, 0) = 22;
  result_matrix(2, 1) = 2;
  result_matrix(2, 2) = 2;

  f_matrix.sum_matrix(s_matrix);

  EXPECT_EQ(0, f_matrix.eq_matrix(s_matrix));
  EXPECT_EQ(1, result_matrix.eq_matrix(f_matrix));
}

TEST(operation, sum_test_2) {
  MyMatrix f_matrix(3, 3);
  f_matrix(0, 0) = 1;
  f_matrix(0, 1) = 1;
  f_matrix(0, 2) = 1;
  f_matrix(1, 0) = 0;
  f_matrix(1, 1) = 1;
  f_matrix(1, 2) = 1;
  f_matrix(2, 0) = 11;
  f_matrix(2, 1) = 1;
  f_matrix(2, 2) = 1;
  MyMatrix s_matrix(3, 3);
  s_matrix(0, 0) = 1;
  s_matrix(0, 1) = 13;
  s_matrix(0, 2) = 1;
  s_matrix(1, 0) = 1;
  s_matrix(1, 1) = 1;
  s_matrix(1, 2) = 1;
  s_matrix(2, 0) = 11;
  s_matrix(2, 1) = 1;
  s_matrix(2, 2) = 1;
  MyMatrix result_matrix(3, 3);
  result_matrix(0, 0) = 2;
  result_matrix(0, 1) = 14;
  result_matrix(0, 2) = 2;
  result_matrix(1, 0) = 1;
  result_matrix(1, 1) = 2;
  result_matrix(1, 2) = 2;
  result_matrix(2, 0) = 22;
  result_matrix(2, 1) = 2;
  result_matrix(2, 2) = 2;

  MyMatrix my_result_matrix(3, 3);
  my_result_matrix = f_matrix + s_matrix;
  EXPECT_EQ(0, f_matrix.eq_matrix(s_matrix));
  EXPECT_EQ(1, result_matrix.eq_matrix(my_result_matrix));
}

TEST(operation, sum_test_3) {
  MyMatrix f_matrix(3, 3);
  f_matrix(0, 0) = 1;
  f_matrix(0, 1) = 1;
  f_matrix(0, 2) = 1;
  f_matrix(1, 0) = 0;
  f_matrix(1, 1) = 1;
  f_matrix(1, 2) = 1;
  f_matrix(2, 0) = 11;
  f_matrix(2, 1) = 1;
  f_matrix(2, 2) = 1;
  MyMatrix s_matrix(3, 3);
  s_matrix(0, 0) = 1;
  s_matrix(0, 1) = 13;
  s_matrix(0, 2) = 1;
  s_matrix(1, 0) = 1;
  s_matrix(1, 1) = 1;
  s_matrix(1, 2) = 1;
  s_matrix(2, 0) = 11;
  s_matrix(2, 1) = 1;
  s_matrix(2, 2) = 1;
  MyMatrix result_matrix(3, 3);
  result_matrix(0, 0) = 2;
  result_matrix(0, 1) = 14;
  result_matrix(0, 2) = 2;
  result_matrix(1, 0) = 1;
  result_matrix(1, 1) = 2;
  result_matrix(1, 2) = 2;
  result_matrix(2, 0) = 22;
  result_matrix(2, 1) = 2;
  result_matrix(2, 2) = 2;

  f_matrix += s_matrix;

  EXPECT_EQ(0, f_matrix.eq_matrix(s_matrix));
  EXPECT_EQ(1, result_matrix.eq_matrix(f_matrix));
}

TEST(operation, sub_test) {
  MyMatrix f_matrix(3, 3);
  f_matrix(0, 0) = 1;
  f_matrix(0, 1) = 1;
  f_matrix(0, 2) = 1;
  f_matrix(1, 0) = 0;
  f_matrix(1, 1) = 1;
  f_matrix(1, 2) = 1;
  f_matrix(2, 0) = 11;
  f_matrix(2, 1) = 1;
  f_matrix(2, 2) = 1;
  MyMatrix s_matrix(3, 3);
  s_matrix(0, 0) = 1;
  s_matrix(0, 1) = 13;
  s_matrix(0, 2) = 1;
  s_matrix(1, 0) = 1;
  s_matrix(1, 1) = 1;
  s_matrix(1, 2) = 1;
  s_matrix(2, 0) = 11;
  s_matrix(2, 1) = 1;
  s_matrix(2, 2) = 1;
  MyMatrix result_matrix(3, 3);
  result_matrix(0, 0) = 0;
  result_matrix(0, 1) = -12;
  result_matrix(0, 2) = 0;
  result_matrix(1, 0) = -1;
  result_matrix(1, 1) = 0;
  result_matrix(1, 2) = 0;
  result_matrix(2, 0) = 0;
  result_matrix(2, 1) = 0;
  result_matrix(2, 2) = 0;

  f_matrix.sub_matrix(s_matrix);

  EXPECT_EQ(1, result_matrix.eq_matrix(f_matrix));
}

TEST(operation, sub_test_2) {
  MyMatrix f_matrix(3, 3);
  f_matrix(0, 0) = 1;
  f_matrix(0, 1) = 1;
  f_matrix(0, 2) = 1;
  f_matrix(1, 0) = 0;
  f_matrix(1, 1) = 1;
  f_matrix(1, 2) = 1;
  f_matrix(2, 0) = 11;
  f_matrix(2, 1) = 1;
  f_matrix(2, 2) = 1;
  MyMatrix s_matrix(3, 3);
  s_matrix(0, 0) = 1;
  s_matrix(0, 1) = 13;
  s_matrix(0, 2) = 1;
  s_matrix(1, 0) = 1;
  s_matrix(1, 1) = 1;
  s_matrix(1, 2) = 1;
  s_matrix(2, 0) = 11;
  s_matrix(2, 1) = 1;
  s_matrix(2, 2) = 1;
  MyMatrix result_matrix(3, 3);
  result_matrix(0, 0) = 0;
  result_matrix(0, 1) = -12;
  result_matrix(0, 2) = 0;
  result_matrix(1, 0) = -1;
  result_matrix(1, 1) = 0;
  result_matrix(1, 2) = 0;
  result_matrix(2, 0) = 0;
  result_matrix(2, 1) = 0;
  result_matrix(2, 2) = 0;

  MyMatrix my_result_matrix(3, 3);
  my_result_matrix = f_matrix - s_matrix;

  EXPECT_EQ(1, result_matrix.eq_matrix(my_result_matrix));
}

TEST(operation, sub_test_3) {
  MyMatrix f_matrix(3, 3);
  f_matrix(0, 0) = 1;
  f_matrix(0, 1) = 1;
  f_matrix(0, 2) = 1;
  f_matrix(1, 0) = 0;
  f_matrix(1, 1) = 1;
  f_matrix(1, 2) = 1;
  f_matrix(2, 0) = 11;
  f_matrix(2, 1) = 1;
  f_matrix(2, 2) = 1;
  MyMatrix s_matrix(3, 3);
  s_matrix(0, 0) = 1;
  s_matrix(0, 1) = 13;
  s_matrix(0, 2) = 1;
  s_matrix(1, 0) = 1;
  s_matrix(1, 1) = 1;
  s_matrix(1, 2) = 1;
  s_matrix(2, 0) = 11;
  s_matrix(2, 1) = 1;
  s_matrix(2, 2) = 1;
  MyMatrix result_matrix(3, 3);
  result_matrix(0, 0) = 0;
  result_matrix(0, 1) = -12;
  result_matrix(0, 2) = 0;
  result_matrix(1, 0) = -1;
  result_matrix(1, 1) = 0;
  result_matrix(1, 2) = 0;
  result_matrix(2, 0) = 0;
  result_matrix(2, 1) = 0;
  result_matrix(2, 2) = 0;

  f_matrix -= s_matrix;

  EXPECT_EQ(1, result_matrix.eq_matrix(f_matrix));
}

TEST(operation, mul_m_test) {
  MyMatrix f_matrix(3, 3);
  f_matrix(0, 0) = 1;
  f_matrix(0, 1) = 1;
  f_matrix(0, 2) = 1;
  f_matrix(1, 0) = 0;
  f_matrix(1, 1) = 1;
  f_matrix(1, 2) = 1;
  f_matrix(2, 0) = 11;
  f_matrix(2, 1) = 1;
  f_matrix(2, 2) = 1;
  MyMatrix s_matrix(3, 3);
  s_matrix(0, 0) = 1;
  s_matrix(0, 1) = 13;
  s_matrix(0, 2) = 1;
  s_matrix(1, 0) = 1;
  s_matrix(1, 1) = 1;
  s_matrix(1, 2) = 1;
  s_matrix(2, 0) = 11;
  s_matrix(2, 1) = 1;
  s_matrix(2, 2) = 1;
  MyMatrix result_matrix(3, 3);
  result_matrix(0, 0) = 13;
  result_matrix(0, 1) = 15;
  result_matrix(0, 2) = 3;
  result_matrix(1, 0) = 12;
  result_matrix(1, 1) = 2;
  result_matrix(1, 2) = 2;
  result_matrix(2, 0) = 23;
  result_matrix(2, 1) = 145;
  result_matrix(2, 2) = 13;

  f_matrix.mul_matrix(s_matrix);

  EXPECT_EQ(1, result_matrix.eq_matrix(f_matrix));
}

TEST(operation, mul_m_test_2) {
  MyMatrix f_matrix(3, 3);
  f_matrix(0, 0) = 1;
  f_matrix(0, 1) = 1;
  f_matrix(0, 2) = 1;
  f_matrix(1, 0) = 0;
  f_matrix(1, 1) = 1;
  f_matrix(1, 2) = 1;
  f_matrix(2, 0) = 11;
  f_matrix(2, 1) = 1;
  f_matrix(2, 2) = 1;
  MyMatrix s_matrix(3, 3);
  s_matrix(0, 0) = 1;
  s_matrix(0, 1) = 13;
  s_matrix(0, 2) = 1;
  s_matrix(1, 0) = 1;
  s_matrix(1, 1) = 1;
  s_matrix(1, 2) = 1;
  s_matrix(2, 0) = 11;
  s_matrix(2, 1) = 1;
  s_matrix(2, 2) = 1;
  MyMatrix result_matrix(3, 3);
  result_matrix(0, 0) = 13;
  result_matrix(0, 1) = 15;
  result_matrix(0, 2) = 3;
  result_matrix(1, 0) = 12;
  result_matrix(1, 1) = 2;
  result_matrix(1, 2) = 2;
  result_matrix(2, 0) = 23;
  result_matrix(2, 1) = 145;
  result_matrix(2, 2) = 13;

  MyMatrix my_result_matrix(3, 3);
  my_result_matrix = f_matrix * s_matrix;

  EXPECT_EQ(1, result_matrix.eq_matrix(my_result_matrix));
}

TEST(operation, mul_m_test_3) {
  MyMatrix f_matrix(3, 3);
  f_matrix(0, 0) = 1;
  f_matrix(0, 1) = 1;
  f_matrix(0, 2) = 1;
  f_matrix(1, 0) = 0;
  f_matrix(1, 1) = 1;
  f_matrix(1, 2) = 1;
  f_matrix(2, 0) = 11;
  f_matrix(2, 1) = 1;
  f_matrix(2, 2) = 1;
  MyMatrix s_matrix(3, 3);
  s_matrix(0, 0) = 1;
  s_matrix(0, 1) = 13;
  s_matrix(0, 2) = 1;
  s_matrix(1, 0) = 1;
  s_matrix(1, 1) = 1;
  s_matrix(1, 2) = 1;
  s_matrix(2, 0) = 11;
  s_matrix(2, 1) = 1;
  s_matrix(2, 2) = 1;
  MyMatrix result_matrix(3, 3);
  result_matrix(0, 0) = 13;
  result_matrix(0, 1) = 15;
  result_matrix(0, 2) = 3;
  result_matrix(1, 0) = 12;
  result_matrix(1, 1) = 2;
  result_matrix(1, 2) = 2;
  result_matrix(2, 0) = 23;
  result_matrix(2, 1) = 145;
  result_matrix(2, 2) = 13;

  f_matrix *= s_matrix;

  EXPECT_EQ(1, result_matrix.eq_matrix(f_matrix));
}

TEST(operation, mul_n_test) {
  MyMatrix f_matrix(3, 3);
  f_matrix(0, 0) = 1;
  f_matrix(0, 1) = 1;
  f_matrix(0, 2) = 1;
  f_matrix(1, 0) = 0;
  f_matrix(1, 1) = 1;
  f_matrix(1, 2) = 1;
  f_matrix(2, 0) = 11;
  f_matrix(2, 1) = 1;
  f_matrix(2, 2) = 1;
  MyMatrix result_matrix(3, 3);
  result_matrix(0, 0) = 3.763;
  result_matrix(0, 1) = 3.763;
  result_matrix(0, 2) = 3.763;
  result_matrix(1, 0) = 0;
  result_matrix(1, 1) = 3.763;
  result_matrix(1, 2) = 3.763;
  result_matrix(2, 0) = 41.393;
  result_matrix(2, 1) = 3.763;
  result_matrix(2, 2) = 3.763;
  f_matrix.mul_number(3.763);
  EXPECT_EQ(1, result_matrix.eq_matrix(f_matrix));
}

TEST(operation, mul_n_test_2) {
  MyMatrix f_matrix(3, 3);
  f_matrix(0, 0) = 1;
  f_matrix(0, 1) = 1;
  f_matrix(0, 2) = 1;
  f_matrix(1, 0) = 0;
  f_matrix(1, 1) = 1;
  f_matrix(1, 2) = 1;
  f_matrix(2, 0) = 11;
  f_matrix(2, 1) = 1;
  f_matrix(2, 2) = 1;
  MyMatrix result_matrix(3, 3);
  result_matrix(0, 0) = 3.763;
  result_matrix(0, 1) = 3.763;
  result_matrix(0, 2) = 3.763;
  result_matrix(1, 0) = 0;
  result_matrix(1, 1) = 3.763;
  result_matrix(1, 2) = 3.763;
  result_matrix(2, 0) = 41.393;
  result_matrix(2, 1) = 3.763;
  result_matrix(2, 2) = 3.763;

  MyMatrix my_result_matrix(3, 3);
  my_result_matrix = 3.763 * f_matrix;

  EXPECT_EQ(1, result_matrix.eq_matrix(my_result_matrix));
}

TEST(operation, mul_n_test_3) {
  MyMatrix f_matrix(3, 3);
  f_matrix(0, 0) = 1;
  f_matrix(0, 1) = 1;
  f_matrix(0, 2) = 1;
  f_matrix(1, 0) = 0;
  f_matrix(1, 1) = 1;
  f_matrix(1, 2) = 1;
  f_matrix(2, 0) = 11;
  f_matrix(2, 1) = 1;
  f_matrix(2, 2) = 1;
  MyMatrix result_matrix(3, 3);
  result_matrix(0, 0) = 3.763;
  result_matrix(0, 1) = 3.763;
  result_matrix(0, 2) = 3.763;
  result_matrix(1, 0) = 0;
  result_matrix(1, 1) = 3.763;
  result_matrix(1, 2) = 3.763;
  result_matrix(2, 0) = 41.393;
  result_matrix(2, 1) = 3.763;
  result_matrix(2, 2) = 3.763;
  f_matrix *= 3.763;
  EXPECT_EQ(1, result_matrix.eq_matrix(f_matrix));
}

TEST(operation, mul_n_test_4) {
  MyMatrix f_matrix(3, 3);
  f_matrix(0, 0) = 1;
  f_matrix(0, 1) = 1;
  f_matrix(0, 2) = 1;
  f_matrix(1, 0) = 0;
  f_matrix(1, 1) = 1;
  f_matrix(1, 2) = 1;
  f_matrix(2, 0) = 11;
  f_matrix(2, 1) = 1;
  f_matrix(2, 2) = 1;
  MyMatrix result_matrix(3, 3);
  result_matrix(0, 0) = 3.763;
  result_matrix(0, 1) = 3.763;
  result_matrix(0, 2) = 3.763;
  result_matrix(1, 0) = 0;
  result_matrix(1, 1) = 3.763;
  result_matrix(1, 2) = 3.763;
  result_matrix(2, 0) = 41.393;
  result_matrix(2, 1) = 3.763;
  result_matrix(2, 2) = 3.763;

  MyMatrix my_result_matrix(3, 3);
  my_result_matrix = f_matrix * 3.763;

  EXPECT_EQ(1, result_matrix.eq_matrix(my_result_matrix));
}

TEST(operation, transpose_test) {
  MyMatrix test_matrix(4, 2);
  int n = 1;
  double rows = test_matrix.get_rows_value();
  double cols = test_matrix.get_cols_value();
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      test_matrix(i, j) = n;
    }
    n++;
  }

  test_matrix = test_matrix.transpose();

  MyMatrix result_matrix(2, 4);
  result_matrix(0, 0) = 1;
  result_matrix(0, 1) = 2;
  result_matrix(0, 2) = 3;
  result_matrix(0, 3) = 4;
  result_matrix(1, 0) = 1;
  result_matrix(1, 1) = 2;
  result_matrix(1, 2) = 3;
  result_matrix(1, 3) = 4;

  EXPECT_EQ(1, result_matrix.eq_matrix(test_matrix));
}

TEST(operation, determinant_test) {
  MyMatrix result_matrix(4, 4);
  result_matrix(0, 0) = 1.2;
  result_matrix(0, 1) = 2.13;
  result_matrix(0, 2) = -33;
  result_matrix(0, 3) = 1;
  result_matrix(1, 0) = -1;
  result_matrix(1, 1) = 1;
  result_matrix(1, 2) = 3;
  result_matrix(1, 3) = 4;
  result_matrix(2, 0) = 14;
  result_matrix(2, 1) = 4;
  result_matrix(2, 2) = 0.12;
  result_matrix(2, 3) = 1.4;
  result_matrix(3, 0) = 1.4;
  result_matrix(3, 1) = 2;
  result_matrix(3, 2) = 9;
  result_matrix(3, 3) = 9.2;

  double res = result_matrix.determinant();
  EXPECT_DOUBLE_EQ(2194.69728, res);
}

TEST(operation, calc_complements_test) {
  MyMatrix A(3, 3);
  A(0, 0) = 1.0;
  A(0, 1) = 1.0;
  A(0, 2) = 1.0;
  A(1, 0) = 1.0;
  A(1, 1) = 1.0;
  A(1, 2) = 1.0;
  A(2, 0) = 1.0;
  A(2, 1) = 1.0;
  A(2, 2) = 1.0;
  MyMatrix res(3, 3);
  res(0, 0) = 0.0;
  res(0, 1) = 0.0;
  res(0, 2) = 0.0;
  res(1, 0) = 0.0;
  res(1, 1) = 0.0;
  res(1, 2) = 0.0;
  res(2, 0) = 0.0;
  res(2, 1) = 0.0;
  res(2, 2) = 0.0;

  MyMatrix B = A.calc_complements();
  EXPECT_EQ(B.eq_matrix(res), 1);
}

TEST(operation, inverse_test) {
  MyMatrix test_matrix(3, 3);
  test_matrix(0, 0) = 1;
  test_matrix(0, 1) = 13;
  test_matrix(0, 2) = 1;
  test_matrix(1, 0) = 1;
  test_matrix(1, 1) = 1;
  test_matrix(1, 2) = 1;
  test_matrix(2, 0) = 11;
  test_matrix(2, 1) = 1;
  test_matrix(2, 2) = 1;

  MyMatrix result_matrix(3, 3);
  result_matrix(0, 0) = 0;
  result_matrix(0, 1) = -0.1;
  result_matrix(0, 2) = 0.1;
  result_matrix(1, 0) = 1.0 / 12.0;
  result_matrix(1, 1) = -1.0 / 12.0;
  result_matrix(1, 2) = 0;
  result_matrix(2, 0) = -1.0 / 12.0;
  result_matrix(2, 1) = 71.0 / 60.0;
  result_matrix(2, 2) = -0.1;

  test_matrix = test_matrix.inverse_matrix();
  EXPECT_EQ(1, result_matrix.eq_matrix(test_matrix));
}

TEST(construction, transfer) {
  MyMatrix B(1, 1);
  MyMatrix C = std::move(B);
  MyMatrix result_matrix(1, 1);

  EXPECT_EQ(1, result_matrix.eq_matrix(C));

  C.set_rows_value(2);
  C.set_cols_value(2);

  MyMatrix result_matrix_2(1, 2);

  EXPECT_EQ(0, result_matrix_2.eq_matrix(C));
}

int main(int argc, char *argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
