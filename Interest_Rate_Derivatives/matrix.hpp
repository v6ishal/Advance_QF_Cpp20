#ifndef MATRIX_H
#define MATRIX_H

#include <bits/stdc++.h>

// A template class to represent a 2D matrix
template <typename T>
class matrix {
private:
    std::vector<std::vector<T> > mat;
    int rows;
    int cols;

public:
    // Default constructor
    matrix() : rows(0), cols(0) {}

    // Constructor with size initialization
    matrix(int rows_, int cols_, const T& initial = T()) {
        resize(rows_, cols_, initial);
    }

    // Resize the matrix to new dimensions
    void resize(int rows_, int cols_, const T& initial = T()) {
        rows = rows_;
        cols = cols_;
        mat.resize(rows);
        for (int i = 0; i < rows; ++i) {
            mat[i].resize(cols, initial);
        }
    }

    // Access element (const version)
    const std::vector<T>& operator[](int i) const {
        if (i >= rows || i < 0)
            throw std::out_of_range("Index out of range");
        return mat[i];
    }

    // Access element (non-const version)
    std::vector<T>& operator[](int i) {
        if (i >= rows || i < 0)
            throw std::out_of_range("Index out of range");
        return mat[i];
    }

    // Get number of rows
    int num_rows() const {
        return rows;
    }

    // Get number of columns
    int num_cols() const {
        return cols;
    }

};

// Utility function to resize a matrix
template <typename T>
void matrix_resize(matrix<T>& mat, int new_rows, int new_cols, const T& initial = T()) {
    mat.resize(new_rows, new_cols, initial);
}

#endif