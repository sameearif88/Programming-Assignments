#include <iostream>

struct Order
{
    int M; //Rows
    int N; //Columns
};

void inputOrder(Order &order);
int findMaxSize(Order order1, Order order2);
void inputMatrix(double matrix[], int size, Order order);
bool validateMatrixInput(double number);
Order MatrixMultiply(double matrix1[], Order order1, double matrix2[], Order order2, double result_matrix[]);
Order MatrixTranspose(double matrix[], Order order, double result_matrix[]);
void outputMatrix(double matrix[], Order order);

int main()
{
    Order order1, order2, order_result;
    //Input the size of the two matrix;
    system("cls");
    std::cout << "Enter order for matrix one:" << std::endl;
    inputOrder(order1);
    std::cout << "Enter order for matrix two:" << std::endl;
    inputOrder(order2);

    //Declare the matrix array by calculation the size
    int size1 = order1.M * order1.N;
    int size2 = order2.M * order2.N;
    double matrix1[size1], matrix2[size2];

    //Declare the result array by finding the largest order possible from the two arrays and initialize
    int size_result = findMaxSize(order1, order2);
    double result_matrix[size_result];
    for(int i = 0; i < size_result; ++i)
    {
        result_matrix[i] = 0;
    }

    //Input the values in both matrix
    std::cout << "ENTER VALUES IN 1st MATRIX:" << std::endl;
    inputMatrix(matrix1, size1, order1);
    std::cout << "ENTER VALUES IN 2nd MATRIX:" << std::endl;
    inputMatrix(matrix2, size2, order2);
    system("cls");

    //Output both matrices
    std::cout << "MATRIX 1:" << std::endl;
    outputMatrix(matrix1, order1);
    std::cout << std::endl << "MATRIX 2:" << std::endl;
    outputMatrix(matrix2, order2);
    std::cout << "-----------------------------" << std::endl;
    

    //Multiply
    std::cout << "MATRIX 1 * MATRIX 2:" << std::endl;
    if(order1.N == order2.M)
    {
        order_result = MatrixMultiply(matrix1, order1, matrix2, order2, result_matrix);
        //Output
        std::cout << std::endl << "MULTIPLY:" << std::endl;
        outputMatrix(result_matrix, order_result);
    }
    else
    {
        std::cout << std::endl << "MULTIPLY: MATH ERROR!" << std::endl;
    }
    std::cout << "-----------------------------" << std::endl;
    
    //Transpose of matrix 1
    order_result = MatrixTranspose(matrix1, order1, result_matrix);
    //Output
    std::cout << std::endl << "TRANSPOSE OF MATRIX 1:" << std::endl;
    outputMatrix(result_matrix, order_result);
    std::cout << "-----------------------------" << std::endl;

    //Transpose of matrix 2
    order_result = MatrixTranspose(matrix2, order2, result_matrix);
    //Output
    std::cout << std::endl << "TRANSPOSE OF MATRIX 2:" << std::endl;
    outputMatrix(result_matrix, order_result);
    std::cout << "-----------------------------" << std::endl;
    return 0;
}

void inputOrder(Order &order)
{
    //Enter and validate Rows
    std::cout << "Enter Row (M): ";
    std::cin >> order.M;
    while(std::cin.fail() || order.M < 1)
    {
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cout << "Wrong entry! Enter Row (M) again:" << std::endl;
        std::cin >> order.M;
    }

    //Enter and validate Columns
    std::cout << "Enter Column (N): ";
    std::cin >> order.N;
    while(std::cin.fail() || order.N < 1)
    {
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cout << "Wrong entry! Enter Column (N):" << std::endl;
        std::cin >> order.N;
    }
    system("cls");
}

int findMaxSize(Order order1, Order order2)
{
    int temp;
    if(order1.M > order2.M)
    {
        if(order1.N > order2.N)
        {
            temp = order1.M * order1.N;
        }
        else
        {
            temp = order1.M * order2.N;
        }
    }
    else
    {
        if(order1.N > order2.N)
        {
            temp = order2.M * order1.N;
        }
        else
        {
            temp = order2.M * order2.N;
        }
    }
    return temp;
}

void inputMatrix(double matrix[], int size, Order order)
{
    double temp;
    bool invalidInput = true;
    int count = 0;
    for(int c = 0; c < order.M; ++c)
    {
        std::cout << "Enter row " << c + 1 << ":" << std::endl;
        for(int r = 0; r < order.N; ++r)
        {
            std::cout << "Enter value " << r + 1 << ":" << std::endl;
            std::cin >> temp;
            invalidInput = validateMatrixInput(temp);
            while(invalidInput == true)
            {
                std::cout << "Wrong Entry! Enter again value " << r + 1 << " again:" << std::endl;
                std::cin >> temp;
                invalidInput = validateMatrixInput(temp);
            }
            matrix[count] = temp;
            count++;
        }
        std::cout << "-----------------------------" << std::endl;
    }
    system("cls");
}

bool validateMatrixInput(double number)
{
    if(std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        return true;
    }
    return false;
}

Order MatrixMultiply(double matrix1[], Order order1, double matrix2[], Order order2, double result_matrix[])
{
    //Find the order of the resultant matrix
    Order temp_order;
    temp_order.M = order1.M;
    temp_order.N = order2.N;

    //Multiply the matrices and store the result
    int count_result = 0, temp_column = 0, temp_row = 0, temp_result = 0;
    for(int i = 0; i < temp_order.M; ++i)
    {
        for(int r = temp_row; r < temp_row + order1.N; ++r)
        {
            for(int c = temp_column; c < temp_column + order2.N; ++c)
            {
                result_matrix[count_result] += matrix1[r] * matrix2[c];
                count_result++;
            }
            temp_column += order2.N;
            count_result = temp_result;
        }
        count_result += temp_order.N;
        temp_result = count_result;
        temp_column = 0;
        temp_row += order1.N;
    }

    //Return order
    return temp_order;
}

void outputMatrix(double matrix[], Order order)
{
    int count = 0;
    for(int c = 0; c < order.M; ++c)
    {
        for(int r = 0; r < order.N; ++r)
        {
            std::cout << matrix[count] << " ";
            count++;
        }
        std::cout << std::endl;
    }
}

Order MatrixTranspose(double matrix[], Order order, double result_matrix[])
{
//Find the order of the resultant matrix
    Order temp_order;
    temp_order.M = order.N;
    temp_order.N = order.M;

    //Multiply the matrices and store the result
    int temp_row = 0, result_count = 0, temp_result = 0;
    for(int i = 0; i < order.M; ++i)
    {
        for(int r = temp_row; r < temp_row + order.N; ++r)
        {
            result_matrix[result_count] = matrix[r];
            result_count += temp_order.N;
        }
        temp_result++;
        result_count = temp_result;
        temp_row += order.N;
    }

    //Return the order
    return temp_order;
}

