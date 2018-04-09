//
// Created by pawel on 29.03.18.
//

#include <iostream>
#include <iomanip>
#include <cstring>
#include "Matrix.h"

namespace algebra{
    Matrix::Matrix() {
        array_= nullptr;
        rows_=0;
        columns_=0;
    }

    Matrix::Matrix(std::initializer_list<std::vector<std::complex<double>>> arg) {
        int elements=0;
        rows_=0;
        std::vector<std::complex<double>> arguments;
        for (auto const& value_y : arg){
            rows_++;
            for (auto const& value_x : value_y){
                elements++;
                arguments.emplace_back(value_x);
            }
        }
        columns_=elements/rows_;
        array_ = new std::complex<double>*[rows_];
        for (int i=0; i<rows_; ++i){
            array_[i] = new std::complex<double>[columns_];
        }
        for (int i=0; i<rows_; ++i){
            for (int j=0; j<columns_; ++j){
                array_[i][j] = arguments[0];
                arguments.erase(arguments.begin());
            }
        }
    }

    Matrix::Matrix(int rows, int columns) {
        rows_=rows;
        columns_=columns;
        array_ = new std::complex<double>*[rows_];
        for (int i=0; i<rows_; ++i){
            array_[i] = new std::complex<double>[columns_];
        }
        for (int i=0; i<rows_; ++i){
            for (int j=0; j<columns_; ++j){
                array_[i][j]=0;
            }
        }
    }

    Matrix::Matrix(const char *string_arg) {
        std::string matlab = string_arg;
        rows_=1;
        columns_=1;
        for (int i=0; i<matlab.length(); ++i){
            if (matlab[i]==' ' && rows_==1) columns_++;
            if (matlab[i]==';') rows_++;
        }
        array_ = new std::complex<double>*[rows_];
        for (int i=0; i<rows_; ++i){
            array_[i] = new std::complex<double>[columns_];
        }
        int i=0,j=0;
        std::stringstream current;
        std::complex<double> value =(0.0);
        current << "(";
        for (int it=1; it<matlab.length(); ++it){
            if (matlab[it]==',' || matlab[it]==';' || matlab[it]==']'){
                current << ")";
                current >> value;
                array_[i][j] = value;
                current.str("");
                current << "(";
                ++j;
                if (matlab[it]==';') {++i; j=0;}
            }
            else if (matlab[it]=='i'){
                current <<",";
            }
            else if (matlab[it]!=' ')
                current << matlab[it];
        }
    }

    Matrix::~Matrix() {
        for(int i=0; i<rows_; ++i){
            delete[] array_[i];
        }
        delete[] array_;
    }

    Matrix::Matrix(const Matrix &other) {
        rows_=other.rows_;
        columns_=other.columns_;
        array_ = new std::complex<double>*[rows_];
        for (int i=0; i<rows_; ++i){
            array_[i] = new std::complex<double>[columns_];
        }
        for (int i=0; i<rows_; ++i){
            for (int j=0; j<columns_; ++j){
                array_[i][j]=other.array_[i][j];
            }
        }
    }

    Matrix &Matrix::operator=(const Matrix &other) {
        if (this==&other){
            return *this;
        }
        for(int i=0; i<rows_; ++i){
            delete[] array_[i];
        }
        delete[] array_;
        rows_=other.rows_;
        columns_=other.columns_;
        array_ = new std::complex<double>*[rows_];
        for (int i=0; i<rows_; ++i){
            array_[i] = new std::complex<double>[columns_];
        }
        for (int i=0; i<rows_; ++i){
            for (int j=0; j<columns_; ++j){
                array_[i][j]=other.array_[i][j];
            }
        }
        return *this;
    }

    std::string Matrix::Print() const {
        std::string output="",current="",re="",im="";
        output+="[";
        for (int i=0; i<rows_; ++i){
            for (int j=0; j<columns_; ++j){
                current = CurrentComplex(current, re, im, i, j);
                output += current+", ";
            }
            output.erase(output.length()-2,2);
            output += "; ";
        }
        output = output.substr(0,output.length()-2);
        output += "]";
        return output;
    }

    std::string &Matrix::CurrentComplex(std::string &current, std::string &re, std::string &im, int i, int j) const {
        std::ostringstream stringstreamre,stringstreamim;
        stringstreamre << std::fixed << std::setprecision(2) << array_[i][j].real();
        re = stringstreamre.str();
        if (re[re.length()-1]=='0'&&re[re.length()-2]=='0') {
            re.erase(re.length() - 3,3);
        }
        else if (re[re.length()-1]=='0'){
            re.erase(re.length()-1,1);
        }
        stringstreamim << std::fixed << std::setprecision(2) << array_[i][j].imag();
        im = stringstreamim.str();
        if (im[im.length()-1]=='0'&&im[im.length()-2]=='0') {
            im.erase(im.length() - 3,3);
        }
        else if (im[im.length()-1]=='0'){
            im.erase(im.length()-1,1);
        }
        current = re+"i"+im;
        return current;
    }

    Matrix Matrix::Add(const Matrix &other) const {
        if (rows_!=other.rows_ || columns_!=other.columns_){
            return Matrix(0,0);
        }
        Matrix add_matrix(rows_,columns_);
        for (int i=0; i<rows_; i++){
            for (int j=0; j<columns_; j++){
                add_matrix.array_[i][j] = array_[i][j] + other.array_[i][j];
            }
        }
        return add_matrix;

    }

    Matrix Matrix::Sub(const Matrix &other) const {
        if (rows_!=other.rows_ || columns_!=other.columns_){
            return Matrix(0,0);
        }
        Matrix sub_matrix(rows_,columns_);
        for (int i=0; i<rows_; i++){
            for (int j=0; j<columns_; j++){
                sub_matrix.array_[i][j] = array_[i][j] - other.array_[i][j];
            }
        }
        return sub_matrix;
    }


    Matrix Matrix::Mul(const Matrix &other) const {
        if (columns_!=other.rows_) {
            return Matrix(0,0);
        }
        Matrix mul_matrix(rows_, other.columns_);
        for (int i = 0; i < rows_; ++i) {
            for (int j = 0; j < other.columns_; ++j) {
                for (int k=0; k < columns_; ++k) {
                    mul_matrix.array_[i][j] += array_[i][k] * other.array_[k][j];
                }
            }
        }
        return mul_matrix;
    }

    Matrix Matrix::Div(const Matrix &other) const {
        return Matrix();
    }

    Matrix Matrix::Mul(std::complex<double> &multiplier) const {
        Matrix mul_matrix(rows_,columns_);
        for (int i=0; i<rows_; i++){
            for (int j=0; j<columns_; j++){
                mul_matrix.array_[i][j] = array_[i][j]*multiplier;
            }
        }
        return mul_matrix;
    }

    Matrix Matrix::Div(std::complex<double> &divider) const {
        if(divider.imag()==0 || divider.real()==0){
            return Matrix(0,0);
        }
        Matrix div_matrix(rows_,columns_);
        for (int i=0; i<rows_; i++){
            for (int j=0; j<columns_; j++){
                div_matrix.array_[i][j] = array_[i][j]/divider;
            }
        }
        return div_matrix;
    }

    Matrix Matrix::Pow(int pow) const {
       if (pow<0 || rows_!=columns_){
            return Matrix(0,0);
        }
        else if (pow==0){
            Matrix pow_matrix(rows_,columns_);
            for (int i=0; i<rows_; ++i){
                pow_matrix.array_[i][i]=1;
            }
            return pow_matrix;
        }
        else if (pow==1){
            return *this;
        }
        Matrix pow_matrix(*this);
        for (int i=1; i<pow; ++i){
            pow_matrix = pow_matrix.Mul(*this);
        }
        return pow_matrix;
    }

    std::pair<long unsigned int, long unsigned int> Matrix::Size() const {
        return std::make_pair(rows_, columns_);
    }
}