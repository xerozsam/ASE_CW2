#define BOOST_TEST_MODULE BoostUnitTest

#include <iostream>
#include <string>
#include <boost/test/included/unit_test.hpp>

#include "rational.h"
#include "dividebyzeroerror.h"

using namespace ExactArithmetic;

using std::cout;
using std::cin;
using std::endl;

Rational expected_value;

Rational addition()
{
	cout << "Addition Testing (Test Case 1)\n";
	//cout << "Enter the left operand (e.g. 1/3): ";
	//Rational x;
	//cin >> x;

	//cout << "Enter the right operand (e.g. 4/9): ";
	//Rational y;
	//cin >> y;

	Rational x = Rational::Rational(1, 3);
	Rational y = Rational::Rational(2, 3);

	Rational result = x + y;
	cout << x << "+" << y << "=" << result;
	return result;
}

Rational subtraction()
{
	cout << "Subtraction Testing (Test Case 2)\n";
	//cout << "Enter the left operand (e.g. 1/3): ";
	//Rational x;
	//cin >> x;

	//cout << "Enter the right operand (e.g. 4/9): ";
	//Rational y;
	//cin >> y;

	Rational x = Rational::Rational(4, 5);
	Rational y = Rational::Rational(2, 5);

	Rational result = x - y;
	cout << x << "-" << y << "=" << result;
	return result;
}

Rational multiplication()
{
	cout << "Multiplication Testing (Test Case 3)\n";
	//cout << "Enter the left operand (e.g. 1/3): ";
	//Rational x;
	//cin >> x;

	//cout << "Enter the right operand (e.g. 4/9): ";
	//Rational y;
	//cin >> y;

	Rational x = Rational::Rational(5, 10);
	Rational y = Rational::Rational(5, 3);

	Rational result = x * y;
	cout << x << "*" << y << "=" << result;
	return result;
}

Rational division()
{
	cout << "Division Testing (Test Case 4)\n";
	//cout << "Enter the left operand (e.g. 1/3): ";
	//Rational x;
	//cin >> x;

	//cout << "Enter the right operand (e.g. 4/9): ";
	//Rational y;
	//cin >> y;

	Rational x = Rational::Rational(1, 7);
	Rational y = Rational::Rational(1, 2);

	Rational result = x / y;
	cout << x << "/" << y << "=" << result;
	return result;
}

BOOST_AUTO_TEST_SUITE(maths_function)
BOOST_AUTO_TEST_CASE(addition_test)
{
	cout << endl;
	std::cout << "------START OF ARITHMETIC CALCULATION TEST------" << std::endl;
	cout << endl;
	expected_value = Rational::Rational(1, 1);
	BOOST_CHECK_EQUAL(addition() == expected_value, true);
	cout << endl;
	cout << "The expected answer: " << expected_value << endl;
	cout << endl;
}
BOOST_AUTO_TEST_CASE(subtration_test)
{
	expected_value = Rational::Rational(2, 5);
	BOOST_CHECK_EQUAL(subtraction() == expected_value, true);
	cout << endl;
	cout << "The expected answer: " << expected_value << endl;
	cout << endl;
}

BOOST_AUTO_TEST_CASE(multiplication_test)
{
	expected_value = Rational::Rational(5, 6);
	BOOST_CHECK_EQUAL(multiplication() == expected_value, true);
	cout << endl;
	cout << "The expected answer: " << expected_value << endl;
	cout << endl;
}
BOOST_AUTO_TEST_CASE(division_test)
{
	expected_value = Rational::Rational(2, 7);
	BOOST_CHECK_EQUAL(division() == expected_value, true);
	cout << endl;
	cout << "The expected answer: " << expected_value << endl;
	cout << endl;
	cout << "------END OF ARITHMETIC CALCULATION TEST------" << endl;
	cout << endl;
}

//this test section wrote by Lucas Song Wei Shen
BOOST_AUTO_TEST_CASE(default_constructor)
{
	BOOST_CHECK_EQUAL(Rational(), Rational(0, 1));
}

BOOST_AUTO_TEST_CASE(normalise)
{
	BOOST_CHECK_EQUAL(Rational(2, 4), Rational(1, 2));
}

BOOST_AUTO_TEST_CASE(zero_denom_error)
{
	BOOST_CHECK_THROW(Rational(1, 0), DivideByZeroError);
}

BOOST_AUTO_TEST_CASE(single_int_input_constructor)
{
	BOOST_CHECK_EQUAL(Rational(3), Rational(3, 1));
}

BOOST_AUTO_TEST_CASE(single_double_input_constructor)
{
	BOOST_CHECK_EQUAL(Rational(3.2), Rational(3, 1));
}

BOOST_AUTO_TEST_CASE(string_constructor)
{
	BOOST_CHECK_EQUAL(Rational("1/2"), Rational(1, 2));
}

BOOST_AUTO_TEST_CASE(string_constructor_error)
{
	BOOST_CHECK_THROW(Rational("adgsajzryk"), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(equals_success)
{
	BOOST_CHECK_EQUAL(Rational(1, 3) == Rational(1, 3), true);
}

BOOST_AUTO_TEST_CASE(equals_fail)
{
	BOOST_CHECK_EQUAL(Rational(1, 3) == Rational(5, 7), false);
}

BOOST_AUTO_TEST_CASE(not_equals_success)
{
	BOOST_CHECK_EQUAL(Rational(1, 3) != Rational(4, 9), true);
}

BOOST_AUTO_TEST_CASE(not_equals_fail)
{
	BOOST_CHECK_EQUAL(Rational(1, 3) != Rational(1, 3), false);
}

BOOST_AUTO_TEST_CASE(less_than_success)
{
	Rational x = Rational(1, 3);
	Rational y = Rational(1, 2);
	BOOST_CHECK_EQUAL(x < y, true);
}

BOOST_AUTO_TEST_CASE(less_than_fail)
{
	Rational x = Rational(2, 3);
	Rational y = Rational(1, 3);
	BOOST_CHECK_EQUAL(x < y, false);
}

BOOST_AUTO_TEST_CASE(more_than_success)
{
	Rational x = Rational(2, 3);
	Rational y = Rational(1, 3);
	BOOST_CHECK_EQUAL(x > y, true);
}

BOOST_AUTO_TEST_CASE(more_than_fail)
{
	Rational x = Rational(1, 3);
	Rational y = Rational(1, 2);
	BOOST_CHECK_EQUAL(x > y, false);
}

BOOST_AUTO_TEST_CASE(less_than_or_equal_to_success_different_input)
{
	Rational x = Rational(1, 4);
	Rational y = Rational(1, 2);
	BOOST_CHECK_EQUAL(x <= y, true);
}

BOOST_AUTO_TEST_CASE(less_than_or_equal_to_success_equal_input)
{
	Rational x = Rational(2, 3);
	Rational y = Rational(2, 3);
	BOOST_CHECK_EQUAL(x <= y, true);
}

BOOST_AUTO_TEST_CASE(less_than_or_equal_to_fail)
{
	Rational x = Rational(5, 6);
	Rational y = Rational(3, 6);
	BOOST_CHECK_EQUAL(x <= y, false);
}

BOOST_AUTO_TEST_CASE(more_than_or_equal_to_success_different_input)
{
	Rational x = Rational(5, 6);
	Rational y = Rational(3, 6);
	BOOST_CHECK_EQUAL(x >= y, true);
}

BOOST_AUTO_TEST_CASE(more_than_or_equal_to_success_equal_input)
{
	Rational x = Rational(1, 2);
	Rational y = Rational(1, 2);
	BOOST_CHECK_EQUAL(x >= y, true);
}

BOOST_AUTO_TEST_CASE(more_than_or_equal_to_fail)
{
	Rational x = Rational(1, 4);
	Rational y = Rational(1, 2);
	BOOST_CHECK_EQUAL(x >= y, false);
}

BOOST_AUTO_TEST_CASE(add_assign)
{
	Rational x = Rational(3, 4);
	Rational y = Rational(1, 2);
	x += y;
	BOOST_CHECK_EQUAL(x, Rational(5, 4));
}

BOOST_AUTO_TEST_CASE(minus_assign)
{
	Rational x = Rational(1, 4);
	Rational y = Rational(2, 3);
	x -= y;
	BOOST_CHECK_EQUAL(x, Rational(-5, 12));
}

BOOST_AUTO_TEST_CASE(multiply_assign)
{
	Rational x = Rational(2, 3);
	Rational y = Rational(3, 5);
	x *= y;
	BOOST_CHECK_EQUAL(x, Rational(2, 5));
}

BOOST_AUTO_TEST_CASE(divide_assign)
{
	Rational x = Rational(4, 7);
	Rational y = Rational(5, 2);
	x /= y;
	BOOST_CHECK_EQUAL(x, Rational(8, 35));
}

BOOST_AUTO_TEST_CASE(abs_negative)
{
	BOOST_CHECK_EQUAL(Rational::abs(Rational(-1, 2)), Rational(1, 2));
}

BOOST_AUTO_TEST_CASE(abs_positive)
{
	BOOST_CHECK_EQUAL(Rational::abs(Rational(1, 2)), Rational(1, 2));
}

BOOST_AUTO_TEST_CASE(negate_positive)
{
	BOOST_CHECK_EQUAL(Rational::negate(Rational(1, 2)), Rational(-1, 2));
}

BOOST_AUTO_TEST_CASE(negate_negative)
{
	BOOST_CHECK_EQUAL(Rational::negate(Rational(-1, 2)), Rational(1, 2));
}

BOOST_AUTO_TEST_CASE(output)
{
	Rational x = Rational(1, 2);
	std::ostringstream testOutputStream;
	testOutputStream << x;
	BOOST_CHECK_EQUAL(testOutputStream.str(), "1/2");
}

BOOST_AUTO_TEST_CASE(input)
{
	Rational x;
	std::istringstream testInputStream("1/2");
	testInputStream >> x;
	BOOST_CHECK_EQUAL(x, Rational(1, 2));
}
BOOST_AUTO_TEST_SUITE_END()
//this test section wrote by Lucas Song Wei Shen