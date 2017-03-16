#include "gtest/gtest.h"
#include "Integer.h"
#include "Complex.h"

TEST(Integer, add_integer_and_complex) {
	shaka::Integer i(5);
	shaka::Complex c(10, -7);

	shaka::Complex c2(i + c);

	ASSERT_EQ(c2.get_real(), static_cast<double>(15));
	ASSERT_EQ(c2.get_imag(), static_cast<double>(-7));
}

TEST(Integer, sub_integer_and_complex) {
	shaka::Integer i(22);
	shaka::Complex c(5, 10);

	shaka::Complex c2(c - i);

	ASSERT_EQ(c2.get_real(), static_cast<double>(-17));
	ASSERT_EQ(c2.get_imag(), static_cast<double>(10));


}

TEST(Integer, mul_integer_and_complex) {
	shaka::Integer i(30);
	shaka::Complex c(7, -15);

	shaka::Complex c2(i * c);

	ASSERT_EQ(c2.get_real(), static_cast<double>(210));
	ASSERT_EQ(c2.get_imag(), static_cast<double>(-450));
}

TEST(Integer, div_integer_and_complex) {
	shaka::Integer i(10);
	shaka::Complex c(5, 10);

	shaka::Complex c2(i / c);

	ASSERT_EQ(c2.get_real(), static_cast<double>(0.4));
	ASSERT_EQ(c2.get_imag(), static_cast<double>(-0.8));

}

int main(int argc, char* argv[]) {
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}
