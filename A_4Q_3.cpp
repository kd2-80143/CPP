/*
Q3. Write a Matrix class. Allocate memory dynamically in parameterized constructor. 
Also write parameter-less constructor. Write accept() and print() functions.
Also provide add(), subtract(), multiply() and transpose() function.
*/
#include<iostream>
using namespace std;

class Matrix
{
private:
    int row;
    int col;
    int **arr;
public:
    Matrix()
    {
        this->row=2;
        this->col=3;
    }
    Matrix(int row, int col) : row(row),col(col)
    {
        arr = new int*[row];
        for(int i = 0 ; i < row ; i++)
        {
            arr[i] = new int[col];
        }
    }

    void acceptMatrix()
    {
        
        cout << "Enter the elements " << endl;
        for(int i=0; i <row; i++)
        {   
            for(int j=0; j<col ; j++)
            {
                cin >> arr[i][j];
            }
            cout << endl;
        }
    }

    void printMatrix()
    {
        for(int i=0; i < this->row ; i++ )
        {
            for(int j=0; j< this->col; j++)
            {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    }

    void add(Matrix m1, Matrix m2)
    {
        for(int i=0; i< row; i++)
        {
            for(int j=0; j<col; j++)
            {
                arr[i][j] = m1.arr[i][j] + m2.arr[i][j];
            }
        }
    }

    void subtract(Matrix m1, Matrix m2)
    {
        for(int i=0;i<row;i++)
        {
            for(int j=0; j<col; j++)
            {
                arr[i][j] = m1.arr[i][j] - m2.arr[i][j];
            }
        }
    }

    void multiply(Matrix m1, Matrix m2)
    {
            for(int i=0;i<row;i++)
            {
                for(int j=0; j<col; j++)
                {
                    arr[i][j] = m1.arr[i][j]*m2.arr[i][j];
                }
            }
    }
    Matrix transpose()
    {

        Matrix result(row,col);
        for(int i=0;i<row;i++)
        {
            for(int j=0; j<col; j++)
            {
                result.arr[j][i] = arr[i][j];
            }
           
        }
        return result;
    }
};

int main()
{   
    int i,j,row,col;
    cout << "Enter the number of rows " << endl;
    cin >> row;
    cout << "Enter the number of columns " << endl;
    cin >> col;

    Matrix m1(row,col);
    m1.acceptMatrix();
    m1.printMatrix();

    Matrix m2(row,col);
    m2.acceptMatrix();
    m2.printMatrix();

    Matrix res(row,col);
    //Addition
    res.add(m1,m2);
    cout << "Addition of 2 matrix :" << endl;
    res.printMatrix();
    //Subtraction
    res.subtract(m1,m2);
    cout << "Subtraction of 2 matrix :" << endl;
    res.printMatrix();
    //Multiplication
    res.multiply(m1,m2);
    cout << "Multiplication of 2 matrix :" << endl;
    res.printMatrix();
    //Transpose
    Matrix transpose = m1.transpose();
    cout << "Transpose of 1st Matrix :" << endl;
    transpose.printMatrix();
    Matrix transpose1 = m2.transpose();
    cout << "Transpose of 2nd Matrix :" << endl;
    transpose1.printMatrix();


    
    return 0;
}
