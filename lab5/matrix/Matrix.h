//
// Created by pawel on 29.03.18.
//

#ifndef JIMP_EXERCISES_MATRIX_H
#define JIMP_EXERCISES_MATRIX_H
#include <array>
#include <complex.h>
#include <vector>

namespace algebra{
    class Matrix {
    public:
        Matrix(); // konstruktor domyślny
        Matrix(std::initializer_list<std::vector<std::complex<double>>> arg); // konstruktor z listą inicjalizacyjną
        Matrix(int rows, int columns); // konstuktor parametrowy wymiarów
        Matrix(const char* string_arg); // konstruktor string
        ~Matrix(); // destruktor
        Matrix(const Matrix &other); // konstruktor kopiujacy
        Matrix &operator=(const Matrix &other); // operator kopiujący



        std::string Print() const;
        Matrix Add(const Matrix &other) const;
        Matrix Sub(const Matrix &other) const;
        Matrix Mul(const Matrix &other) const;
        Matrix Mul(std::complex<double> &multiplier) const;
        Matrix Div(const Matrix &other) const;
        Matrix Div(std::complex<double> &divider) const;
        Matrix Pow(int pow) const;
        std::pair<long unsigned int, long unsigned int> Size() const;



    private:
        std::complex<double> **array_;
        int rows_,columns_;

        std::string &CurrentComplex(std::string &current, std::string &re, std::string &im, int i, int j) const;
    };
}




#endif //JIMP_EXERCISES_MATRIX_H
