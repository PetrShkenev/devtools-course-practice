// Copyright 2018 Ioanu Daniel

#include <gtest/gtest.h>
#include <fstream>

#include "include/bisymmetric_matrix.h"

// Paths to the test files
#define MATRIX "../../../../../modules/bisymmetric-matrix/test/matrix1.txt"
#define MATRIX2 "../../../../../modules/bisymmetric-matrix/test/matrix2.txt"
#define ADD_RES "../../../../../modules/bisymmetric-matrix/test/add_matrix.txt"
#define SUB_RES "../../../../../modules/bisymmetric-matrix/test/sub_mat.txt"

TEST(Bisymmetric_Matrix, Can_Create) {
    // Arrange & Act
    Matrix m(1);
    std::ifstream is(MATRIX);
    is >> m;
    is.close();

    // Assert
    EXPECT_EQ(1, m.GetElem(1, 1));
}

TEST(Bisymmetric_Matrix, Can_Copy) {
    // Arrange
    Matrix a(5);
    Matrix b(5);

    std::ifstream is(MATRIX);
    is >> a;
    is.close();

    a.Output();

    a = b;

    // Act & Assert
    EXPECT_EQ(a, b);
}

TEST(Bisymmetric_Matrix, Can_Add) {
    // Arrange
    Matrix a(5);
    Matrix b(5);
    Matrix res(5);

    std::ifstream is(MATRIX);
    is >> a;
    is.close();

    a.Output();

    std::ifstream ist(MATRIX);
    ist >> b;
    ist.close();

    std::ifstream resIs(ADD_RES);
    resIs >> res;
    resIs.close();

    // Act & Assert
    EXPECT_EQ(a + b, res);
}

TEST(Bisymmetric_Matrix, Can_Subtract) {
    // Arrange
    Matrix a(5);
    Matrix b(5);
    Matrix res(5);

    std::ifstream is(MATRIX);
    is >> a;
    is.close();

    std::ifstream ist(MATRIX);
    ist >> b;
    ist.close();

    std::ifstream resIs(SUB_RES);
    resIs >> res;
    resIs.close();

    // Act & Assert
    EXPECT_EQ(a - b, res);
}

TEST(Bisymmetric_Matrix, Can_Multiply_With_Number) {
    // Arrange
    Matrix a(5);
    Matrix res(5);

    std::ifstream is(MATRIX);
    is >> a;
    is.close();

    std::ifstream resIs(ADD_RES);
    resIs >> res;
    resIs.close();

    // Act & Assert
    EXPECT_EQ(a * 2, res);
}

TEST(Bisymmetric_Matrix, Not_Equal_Matrix) {
    // Arrange
    Matrix a(5);
    Matrix b(5);
    bool equalMatrix = false;

    std::ifstream is(MATRIX);
    is >> a;
    is.close();

    std::ifstream ist(MATRIX2);
    ist >> b;
    ist.close();

    // Act
    if (a == b)
        equalMatrix = true;

    // Assert
    EXPECT_FALSE(equalMatrix);
}

TEST(Bisymmetric_Matrix, Subtract_Matrix_with_Different_Sizes) {
    // Arrange
    Matrix a(5);
    Matrix b(3);
    Matrix res(5);

    std::ifstream is(MATRIX);
    is >> a;
    is.close();

    std::ifstream ist(MATRIX);
    ist >> b;
    ist.close();

    // Act & Assert
    EXPECT_ANY_THROW(a - b);
}
