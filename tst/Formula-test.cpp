#include "gtest/gtest.h"
#include "ComplexNumber.h"
#include <iostream>

TEST(testSubtract, test1)
{
    ComplexNumber c1(1,1);
    ComplexNumber c2(2,3);
    EXPECT_EQ (c1 - c2, ComplexNumber(-1,-2));

}

TEST(testAdd, test2)
{
    ComplexNumber c1(1,1);
    ComplexNumber c2(2,3);
    EXPECT_EQ (c1 + c2, ComplexNumber(3,4));
}

TEST(testCon, test3)
{
    ComplexNumber c1(1,1);
    EXPECT_EQ (c1, ComplexNumber(1,1));
}

TEST(testEmptyCon, test4)
{
    ComplexNumber c1;
    EXPECT_EQ (c1, ComplexNumber(0,0));
}

TEST(testMultiplicationByConstans, test5)
{
    ComplexNumber c1(10,10);
    ComplexNumber result;
    result = (ComplexNumber)10 * c1;
    EXPECT_EQ (result, ComplexNumber(100,100));
}

TEST(testMultiplicationByComplexNumber, test6)
{
    ComplexNumber c1(10,10);
    ComplexNumber c2(2,1);
    EXPECT_EQ (c1 * c2, ComplexNumber(10,30));
}

TEST(testDivisionByConstans, test7)
{
    ComplexNumber c1(10,10);
    ComplexNumber result;
    result = c1 / (ComplexNumber)10;
    EXPECT_EQ (result, ComplexNumber(1,1));
}

TEST(testDivisionByComplexNumber, test8)
{
    ComplexNumber c1(4,6);
    ComplexNumber c2(1,-5);
    EXPECT_EQ (c1 / c2, ComplexNumber(-1,1));
}

TEST(testDivisionByZero, test9)
{
    ComplexNumber c1(4,4);
    ComplexNumber c2(0,0);
    EXPECT_THROW(c1/c2, std::exception);
}

TEST(testPrintingComplexNum, test10)
{
    ComplexNumber c1(4,4);
    ComplexNumber c2(0,-4);
    ComplexNumber c3(4,0);
    std::stringstream sts;
    sts << c1;
    EXPECT_EQ ("(4+4i)", sts.str());

    sts = std::stringstream();
    sts << c2;
    EXPECT_EQ ("(-4i)", sts.str());

    sts = std::stringstream();
    sts << c3;
    EXPECT_EQ ("(4)", sts.str());
}

TEST(testGetingComplexNum, test11)
{
    ComplexNumber c1;
    std::stringstream ist;

    ist << "(4+4.67i)";
    ist >> c1;
    EXPECT_EQ (c1, ComplexNumber(4,4.67));

    ist << "(0-4i)";
    ist >> c1;
    EXPECT_EQ (c1, ComplexNumber(0,-4));

    ist << "(420.12345+0i)";
    ist >> c1;
    EXPECT_EQ (c1, ComplexNumber(420.12345,0));

//    ist << "(42 + 4i)";
//    ist >> c1;
//    EXPECT_EQ(c1, ComplexNumber(42,4));

    ist = std::stringstream();
    ist << "(420+0.i)";
    ist >> c1;
    EXPECT_EQ(c1, ComplexNumber(420,0));
}

TEST(testErrorThrows, test12)
{
    ComplexNumber c1;
    std::stringstream ist;

    ist = std::stringstream();
    ist << "420.12345+0i";
    EXPECT_THROW(ist >> c1, std::exception);

    ist = std::stringstream();
    ist << "(42+0i";
    EXPECT_THROW(ist >> c1, std::exception);

    ist = std::stringstream();
    ist << "42+0i)";
    EXPECT_THROW(ist >> c1, std::exception);

    ist = std::stringstream();
    ist << "(42g0i)";
    EXPECT_THROW(ist >> c1, std::exception);

    ist = std::stringstream();
    ist << "(t + 4i)";
    EXPECT_THROW(ist >> c1, std::exception);

    ist = std::stringstream();
    ist << "(420+0.0)";
    EXPECT_THROW(ist >> c1, std::exception);

}

TEST (Test, showInformationAboutComplexNumber) {
    ComplexNumber z1(2, 5);
    ComplexNumber z2(0, -3);
    ComplexNumber z3(-5, 0);
    ComplexNumber z4(0, -1);
    ComplexNumber z5(3, 1);
    ComplexNumber z6(0, 1);
    ComplexNumber z7(10, -7);
    std::stringstream os;

    os << z1;
    ASSERT_EQ("(2+5i)", os.str());

    os = std::stringstream();
    os << z2;
    ASSERT_EQ("(-3i)", os.str());

    os = std::stringstream();
    os << z3;
    ASSERT_EQ("(-5)", os.str());

    os = std::stringstream();
    os << z4;
    ASSERT_EQ("(-i)", os.str());

    os = std::stringstream();
    os << z5;
    ASSERT_EQ("(3+i)", os.str());

    os = std::stringstream();
    os << z6;
    ASSERT_EQ("(i)", os.str());

    os = std::stringstream();
    os << z7;
    ASSERT_EQ("(10-7i)", os.str());
}

TEST (Test, getComplexFromCin) {
    ComplexNumber z1;
    std::stringstream is;

    is << "(51+55.2i)";
    is >> z1;

    ASSERT_EQ(z1, ComplexNumber(51, 55.2));

    is << "(10-5i)";
    is >> z1;

    ASSERT_EQ(z1, ComplexNumber(10, -5));

    is << "(-3-1i)";
    is >> z1;

    ASSERT_EQ(z1, ComplexNumber(-3, -1));

    is << "(0-1i)";
    is >> z1;

    ASSERT_EQ(z1, ComplexNumber(0, -1));

    is << "(1.5+0i)";
    is >> z1;

    ASSERT_EQ(z1, ComplexNumber(1.5, 0));
}

TEST (Test, shorterVersionComplex) {
    ComplexNumber z1;
    std::stringstream is;

    is << "(i)";
    is >> z1;
    ASSERT_EQ(z1, ComplexNumber(0, 1));
    z1 = ComplexNumber();

    is << "(-i)";
    is >> z1;
    ASSERT_EQ(z1, ComplexNumber(0, -1));
    is = std::stringstream();
    z1 = ComplexNumber();

    is << "(2i)";
    is >> z1;
    ASSERT_EQ(z1, ComplexNumber(0, 2));
    is = std::stringstream();
    z1 = ComplexNumber();

    is << "(2)";
    is >> z1;
    ASSERT_EQ(z1, ComplexNumber(2, 0));
    is = std::stringstream();
    z1 = ComplexNumber();

    is << "(-4i)";
    is >> z1;
    EXPECT_EQ(z1, ComplexNumber(0, -4));
    is = std::stringstream();
    z1 = ComplexNumber();

    is << "(3-i)";
    is >> z1;
    EXPECT_EQ(z1, ComplexNumber(3, -1));
    is = std::stringstream();
    z1 = ComplexNumber();
}

TEST (Test, unfamiliarSyntaxErrorComplex) {
    ComplexNumber z1;
    std::stringstream is;

    is << "5+6i)";
    EXPECT_THROW(is >> z1, std::exception);
    is = std::stringstream();

    is << "(5+6i";
    EXPECT_THROW(is >> z1, std::exception);
    is = std::stringstream();

    is << "(5+6";
    EXPECT_THROW(is >> z1, std::exception);
    is = std::stringstream();

    is << "(5+6)";
    EXPECT_THROW(is >> z1, std::exception);
    is = std::stringstream();

    is << "(5%6i";
    EXPECT_THROW(is >> z1, std::exception);
    is = std::stringstream();

    is << "(a+6i)";
    EXPECT_THROW(is >> z1, std::exception);
    is = std::stringstream();

}