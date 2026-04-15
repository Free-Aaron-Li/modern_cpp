/*
 * Copyright (C) 2026 Aaron <communicate_aaron@outlook.com>
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

/**
 * @file 5_2_concrete_types.cpp
 * @brief 第 5 章 类：5.2 具体类型示例实现
 */

module;
#include <iostream>
#include <vector>
module classes;

/**
 * @brief 5.2 具体类型相关的命名空间实现
 */
namespace ch5_concrete_types_impl {
    /**
     * @brief 复数类，演示不带指针成员的具体类
     */
    class Complex {
    public:
        Complex(const double r, const double i) :
            re_{ r }, im_{ i } {}

        explicit
        Complex(const double r) :
            re_{ r }, im_{ 0 } {}

        Complex() = default;

        /**
         * 一些简单的操作（如构造函数、+=、imag() 等）不应该以函数调用方式实现。
         * 定义在类内部的函数默认是内联的，也可以在函数声明前加上关键字 inline。
         */

        [[nodiscard]] inline auto
        real() const -> double;

        [[nodiscard]] inline auto
        imag() const -> double;

        auto
        operator+=(const Complex& other) -> Complex& {
            re_ += other.re_, im_ += other.im_;
            return *this;
        }

        auto
        operator-=(const Complex& other) -> Complex& {
            re_ -= other.re_, im_ -= other.im_;
            return *this;
        }

        /**
         * @brief 复数乘法复合赋值
         *
         * @details 按多项式乘法展开，并替换 \f$ i^2 = -1 \f$
         *
         * \f[
         * z_1*z_2=(a + bi)(c + di) = (ac - bd) + (ad + bc)i
         * \f]
         */
        auto
        operator*=(const Complex& other) -> Complex& {
            const double new_re = re_ * other.re_ - im_ * other.im_;
            const double new_im = re_ * other.im_ + im_ * other.re_;
            re_                 = new_re;
            im_                 = new_im;
            return *this;
        }

        /**
         * @brief 复数除法复合赋值
         *
         * @details 利用共轭复数将分母实数化。\f$ z_2 \f$ 的共轭 \f$ \overline{z_2} = c-di \f$
         * \f[
         * \frac{z_1}{z_2}=
         * \frac{a + bi}{c + di}
         * = \frac{(a + bi)(c - di)}{c^2 + d^2}
         * \f]
         *
         * 分母为零复数时不能进行除法。
         */
        auto
        operator/=(const Complex& other) -> Complex& {
            const double denom = other.re_ * other.re_ + other.im_ * other.im_;
            if (denom == 0.0) { throw std::domain_error("division by zero"); }

            const double new_re = (re_ * other.re_ + im_ * other.im_) / denom;
            const double new_im = (im_ * other.re_ - re_ * other.im_) / denom;

            re_ = new_re;
            im_ = new_im;
            return *this;
        }

        auto
        operator-() const -> Complex { return { -re_, -im_ }; }

        auto
        operator==(const Complex& other) const -> bool {
            return re_ == other.re_ && im_ == other.im_;
        }

    private:
        double re_{ 0.0 }; /**< real 实部 */
        double im_{ 0.0 }; /**< imaginary 虚部 */
    };

    inline auto
    operator+(Complex lhs, const Complex& rhs) -> Complex { return lhs += rhs; }

    inline auto
    operator-(Complex lhs, const Complex& rhs) -> Complex { return lhs -= rhs; }

    inline auto
    operator*(Complex lhs, const Complex& rhs) -> Complex { return lhs *= rhs; }

    inline auto
    operator/(Complex lhs, const Complex& rhs) -> Complex { return lhs /= rhs; }

    inline auto
    operator/(double lhs, const Complex& rhs) -> Complex {
        const double denom =
                rhs.real() * rhs.real() + rhs.imag() * rhs.imag();
        if (denom == 0.0) { throw std::domain_error("division by zero"); }
        return {
            (lhs * rhs.real()) / denom,
            (-lhs * rhs.imag()) / denom
        };
    }

    inline auto
    operator!=(const Complex& lhs, const Complex& rhs) -> bool {
        return !(lhs == rhs);
    }

    auto
    Complex::real() const -> double { return re_; }

    auto
    Complex::imag() const -> double { return im_; }

    /**
     * @brief 表示双精度浮点数动态数组的类。
     *
     * 提供动态分配和管理指定大小的浮点数数组，并提供访问和修改数组元素的接口。
     * 支持通过下标操作符的非 const 和 const 版本访问元素。
     * 该类负责内存的动态分配和释放，确保资源的释放以防止内存泄漏。
     */
    class Vector {

    public:
        Vector(int s) :
            elem_{ new double[s] }, sz_{ s } {
            for (int i = 0; i != s; ++i) elem_[i] = 0;
        }

        ~Vector() { delete[] elem_; }

        auto
        operator[](const int i) -> double& { return elem_[i]; }

        /**
         * @brief 通过下标访问指定索引的元素（只读）。
         *
         * 提供只读访问动态数组中指定索引的元素。用于确保调用方无法更改元素的值。
         *
         * @param i 要访问的元素的索引。
         * @return const double& 返回索引对应的元素的常量引用。
         * @throw 如果索引超出数组范围，可能会导致未定义行为。
         * @details const 成员函数重载。
         */
        auto
        operator[](const int i) const -> const double& { return elem_[i]; }

        [[nodiscard]] auto
        size() const -> int { return sz_; }

    private:
        double* elem_{ nullptr };
        int     sz_{ 0 };

    };

    auto
    test_complex() {
        using namespace ch5_concrete_types_impl;
        Complex z{ 1, 2 };
        Complex a{ 3, 4 };
        Complex b{ 1 / a };
        Complex c{ a + z * Complex{ 1, 2.3 } };
        if (c != b) { c = -(b / a) + a * b; }

        std::cout << "Complex a: " << "{" << a.real() << ", " << a.imag() <<
                "};\n"
                << "Complex b:" << "{" << b.real() << ", " << b.imag() << "};\n"
                << "Complex c:" << "{" << c.real() << ", " << c.imag() <<
                "}.\n";
    };
}


/**
 * @ingroup classes_module_group
 * @brief 5.2 具体类型入口
 */
auto
tutorial_concrete_types() -> void {
    std::cout << "--- 5.2 Concrete Types ---" << std::endl;

    ch5_concrete_types_impl::Complex       z{ 1, 2 };
    const ch5_concrete_types_impl::Complex cz{ 2, 3 };

    z = cz; /** 可行：赋值给非 const 变量 */
    // 变cz = z;  /**< 不可行：赋值给 const*/
    double x = z.real(); /** 可行：complex::real() 是 const */
    ch5_concrete_types_impl::test_complex();

    std::cout << "Complex: " << z.real() << " + " << z.imag() << "i" <<
            std::endl;

    ch5_concrete_types_impl::Vector v(5);
    std::cout << "Vector size: " << v.size() << std::endl;
}
