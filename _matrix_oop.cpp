
#include "_matrix_oop.h"

MyMatrix::MyMatrix() {
  rows_ = 0;
  cols_ = 0;
  matrix_ = nullptr;
}

MyMatrix::MyMatrix(int rows, int cols) {
  rows_ = rows;
  cols_ = cols;
  create_matrix();
}

MyMatrix &MyMatrix::operator=(const MyMatrix &other) {
  delite_matrix();
  rows_ = other.rows_;
  cols_ = other.cols_;
  create_matrix();
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] = other.matrix_[i][j];
    }
  }
  return *this;
}

void MyMatrix::set_cols_value(int cols) {
  int rows = rows_;
  if (cols != cols_) {
    delite_matrix();
    cols_ = cols;
    rows_ = rows;
    create_matrix();
  }
}

void MyMatrix::set_rows_value(int rows) {
  int cols = cols_;
  if (rows != rows_) {
    delite_matrix();
    rows_ = rows;
    cols_ = cols;
    create_matrix();
  }
}

MyMatrix::MyMatrix(const MyMatrix &other)
    : rows_(other.rows_), cols_(other.cols_) {
  create_matrix();
  *this = other;
}

MyMatrix::MyMatrix(MyMatrix &&other)
    : rows_(other.rows_), cols_(other.cols_), matrix_(other.matrix_) {
  *this = other;
  other.rows_ = 0;
  other.cols_ = 0;
  other.matrix_ = nullptr;
}

MyMatrix::~MyMatrix() { delite_matrix(); }

void MyMatrix::create_matrix() {
  if (rows_ < 1 || cols_ < 1) {
    throw std::out_of_range(
        "Incorrect input, the number of columns and rows should be > 0");
  }
  matrix_ = new double *[rows_];
  for (int i = 0; i < rows_; i++) {
    matrix_[i] = new double[cols_]();
  }
}

void MyMatrix::delite_matrix() {
  for (int i = 0; i < rows_; i++) {
    delete[] matrix_[i];
  }
  if (rows_ > 0) {
    delete[] matrix_;
  }
  rows_ = 0;
  cols_ = 0;
}

void MyMatrix::sum_matrix(const MyMatrix &other) {
  if (other.rows_ != rows_ || other.cols_ != cols_) {
    throw std::invalid_argument(
        "Incorrect input, matrices should have the same size");
  }
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] = matrix_[i][j] + other.matrix_[i][j];
    }
  }
}

void MyMatrix::sub_matrix(const MyMatrix &other) {
  if (other.rows_ != rows_ || other.cols_ != cols_) {
    throw std::invalid_argument(
        "Incorrect input, matrices should have the same size");
  }
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] = matrix_[i][j] - other.matrix_[i][j];
    }
  }
}

void MyMatrix::mul_matrix(const MyMatrix &other) {
  MyMatrix buf_matrix(rows_, other.cols_);
  if (cols_ != other.rows_) {
    throw std::invalid_argument(
        "The columns of one matrix != the rows of the second matrix");
  }
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < other.cols_; j++) {
      for (int n = 0; n < cols_; n++) {
        buf_matrix.matrix_[i][j] += matrix_[i][n] * other.matrix_[n][j];
      }
    }
  }
  *this = buf_matrix;
}

void MyMatrix::mul_number(const double num) {
  MyMatrix buf_matrix(rows_, cols_);
  for (int i = 0; i < rows_; i++) {
    for (int n = 0; n < cols_; n++) {
      buf_matrix.matrix_[i][n] += matrix_[i][n] * num;
    }
  }
  *this = buf_matrix;
}

MyMatrix MyMatrix::transpose() {
  MyMatrix buf_matrix(cols_, rows_);
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      buf_matrix.matrix_[j][i] = matrix_[i][j];
    }
  }
  return buf_matrix;
}

MyMatrix MyMatrix::minor_for_other_function(int rows, int cols) {
  MyMatrix buf_matrix(rows_ - 1, cols_ - 1);
  int ii = 0;
  for (int i = 0; i < rows_; i++) {
    if (i == rows) continue;
    int jj = 0;
    for (int j = 0; j < cols_; j++) {
      if (j == cols) continue;
      buf_matrix.matrix_[ii][jj] = matrix_[i][j];
      jj++;
    }
    ii++;
  }
  return buf_matrix;
}

double MyMatrix::determinant() {
  double result = 0.0;
  if (cols_ != rows_ || rows_ < 1) {
    throw std::invalid_argument("Incorrect input, the matrix is not square");
  }
  if (rows_ == 2) {
    result = matrix_[0][0] * matrix_[1][1] - matrix_[0][1] * matrix_[1][0];
  } else {
    for (int i = 0; i < rows_; i++) {
      double m_num = matrix_[0][i];
      MyMatrix minor = minor_for_other_function(0, i);
      result += m_num * minor.determinant() * pow(-1, i);
    }
  }
  return result;
}

MyMatrix MyMatrix::calc_complements() {
  MyMatrix buf_matrix(rows_, cols_);
  if (cols_ != rows_ || rows_ == 1) {
    throw std::invalid_argument("Incorrect input, the matrix is not square");
  }
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      MyMatrix minor = minor_for_other_function(i, j);
      buf_matrix.matrix_[i][j] = minor.determinant() * pow(-1, i + j);
    }
  }
  return buf_matrix;
}

MyMatrix MyMatrix::inverse_matrix() {
  MyMatrix buf_matrix, clon_res_1;
  if (cols_ != rows_ && determinant() == 0) {
    throw std::invalid_argument(
        "Incorrect input, the matrix is not square or matrix determinant is 0");
  }
  clon_res_1 = calc_complements();
  buf_matrix = clon_res_1.transpose();
  buf_matrix.mul_number(1 / determinant());
  return buf_matrix;
}

bool MyMatrix::eq_matrix(const MyMatrix &other) {
  int res = 1;
  if (rows_ == other.rows_ && cols_ == other.cols_) {
    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < cols_; j++) {
        if (fabs(matrix_[i][j] - other.matrix_[i][j]) > 0.0000001) res = 0;
      }
    }
  } else {
    res = 0;
  }
  return res;
}

MyMatrix MyMatrix::operator+(const MyMatrix &other) {
  MyMatrix result_matrix = *this;
  result_matrix.sum_matrix(other);
  return result_matrix;
}

MyMatrix MyMatrix::operator-(const MyMatrix &other) {
  MyMatrix result_matrix = *this;
  result_matrix.sub_matrix(other);
  return result_matrix;
}

MyMatrix MyMatrix::operator*(const MyMatrix &other) {
  MyMatrix result_matrix = *this;
  result_matrix.mul_matrix(other);
  return result_matrix;
}

MyMatrix operator*(const MyMatrix &other, double num) {
  MyMatrix result_matrix = other;
  result_matrix.mul_number(num);
  return result_matrix;
}

MyMatrix operator*(double num, const MyMatrix &other) {
  MyMatrix result_matrix = other;
  result_matrix.mul_number(num);
  return result_matrix;
}

int MyMatrix::operator==(const MyMatrix &other) {
  int eq = eq_matrix(other);
  return eq;
}

MyMatrix &MyMatrix::operator+=(const MyMatrix &other) {
  MyMatrix buf_matrix = *this;
  buf_matrix.sum_matrix(other);
  *this = buf_matrix;
  return *this;
}

MyMatrix &MyMatrix::operator-=(const MyMatrix &other) {
  MyMatrix buf_matrix = *this;
  buf_matrix.sub_matrix(other);
  *this = buf_matrix;
  return *this;
}

MyMatrix &MyMatrix::operator*=(const MyMatrix &other) {
  MyMatrix buf_matrix = *this;
  buf_matrix.mul_matrix(other);
  *this = buf_matrix;
  return *this;
}

MyMatrix &MyMatrix::operator*=(const double num) {
  MyMatrix buf_matrix = *this;
  buf_matrix.mul_number(num);
  *this = buf_matrix;
  return *this;
}

double &MyMatrix::operator()(int rows, int cols) {
  if (rows > rows_ || cols > cols_) {
    throw std::out_of_range("Incorrect input, index is outside the matrix");
  }
  return matrix_[rows][cols];
}
