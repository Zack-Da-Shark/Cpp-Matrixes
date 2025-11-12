#include <iostream>
#include "Matrix.h"
#include <string>
using namespace Numbers;

//Testing the To String method
static void TestCase1()
{
    Matrix test(3, 3);
    cout << test.toString();
}

//Testing the get columns and rows
static void TestCase2()
{
    Matrix test(4, 6);
    cout << "Rows: " << test.getRows() << "\n";
    cout << "Columns: " << test.getColumns() << "\n";
}

//Testing the get and set methods
static void TestCase3()
{
    Matrix test(3, 3);
    cout << "Changing the middle most position, awaiting user input\n";
    cout << test.toString();

    int input;
    cin >> input;
    test.setElement(1, 1, input);

    cout << "Number changed to:" << test.getElement(1,1) <<"\n";
    cout << test.toString();

}

//Testing the + operator and - and * and == operators
static void TestCase4()
{
    Matrix donuts(3, 3);
    Matrix waffle(3, 3);
    //Above two will never change
    
    //Bottom 3 will contain results
    Matrix pancakes(3, 3);
    Matrix cupcakes(3, 3);
    Matrix croissant(3, 3);

    //This matrix will check the == operator
    Matrix cinnamonBun(3, 3);

    //I got hungry, don't judge me ;w;

    //Creating the 2 matrices
    int count = 1;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            donuts.setElement(i, j, count * 3);
            count++;
        }
    }
    cout << "First Matrix:\n" << donuts.toString();

    count = 1;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            waffle.setElement(i, j, count * 2);
            count++;
        }
    }
    cout << "Second Matrix:\n" << waffle.toString();

    //Creating the cinnamon matrix to compare (*5)

    count = 1;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cinnamonBun.setElement(i, j, count * 5);
            count++;
        }
    }
    cout << "Third Matrix:\n" << cinnamonBun.toString();

    //Additionsing (+)
    cout << "Adding Matrices...\n";
    pancakes = waffle + donuts;
    cout << pancakes.toString();

    //Subatrsactoins (-)
    cout << "Subtracting Matrices, smaller from bigger...\n";
    cupcakes = donuts - waffle;
    cout << cupcakes.toString();

    //Muatiplications (*)
    cout << "Multiplying Matrices...\n";
    croissant = donuts * waffle;
    cout << croissant.toString();

    //is equal to (==)
    cout << "comparing cinnamon buns to donuts first then to pancakes\n";
    if (cinnamonBun == donuts)
        cout << "Cinnamon buns are like donuts\n";
    else if (cinnamonBun == pancakes)
        cout << "Cinnamon buns are like panckes\n";
    else
        cout << "Someone tell the coder that something went wrong :/";
}

//Testing the transpose method
static void TestCase5()
{
    //2 matixes, 1 to tranpose to
    Matrix fish(2, 3);
    Matrix chip(3, 2);

    //Popuate fish with numbers from 1 - 6
    int count = 1;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            fish.setElement(i, j, count);
            count++;
        }
    }
    cout << "Fish matrix created!\n" << fish.toString();
    cout << "Transpose attempt\n";

    chip = ~fish;
    cout << "Chip transpose:\n" << chip.toString();
}

//Testing the copying
static void TestCase6()
{
    Matrix loaf(3, 3);
    //Populate it
    int count = 1;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            loaf.setElement(i, j, count);
            count++;
        }
    }
    cout << "Got matrix:\n" << loaf.toString();
    cout << "Copying to matrix baguette\n";

    Matrix baguette = loaf;
    cout << "Baguette:\n" << baguette.toString();

}

int main()
{
    cout << "Trying to create Matrix of size 3, 3\n";
    Matrix test(3,3);
    cout << "Matrix created!\n";
    test.destroyMatrix();

    cout << "Trying the To String method\n";
    TestCase1();

    cout << "Trying the get Rows and Columns methods\n";
    cout << "It will have 4 rows and 6 columns\n";
    TestCase2();

    cout << "Trying the get element and set element methods in a matrix(3, 3)\n";
    TestCase3();

    cout << "Trying the +, -, *, == operator\n";
    TestCase4();

    cout << "Trying to transpose a matrix\n";
    TestCase5();

    cout << "Trying to copy a matrix\n";
    TestCase6();
    return 0;
}