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
#include <initializer_list>
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
        explicit
        Vector(const int s) :
            elems_{ new double[s] }, sz_{ s } {
            if (s < 0) {
                throw std::out_of_range("Vector index out of range.");
            }
            for (int i = 0; i < s; ++i) elems_[i] = 0;
        }

        /**
         * @brief 使用初始化列表构造 Vector
         *
         * 允许使用 {1.0, 2.0, 3.0} 这样的语法初始化 Vector。
         *
         * @param init 初始化列表，包含要存储的双精度浮点数值。
         */
        Vector(const std::initializer_list<double> init) :
            elems_{ new double[init.size()] },
            sz_{ static_cast<int>(init.size()) } {
            /** static_cast 并不负责检查要转换的值 */
            int i = 0;
            for (const auto& val: init) { elems_[i++] = val; }
        }

        /**
         * @brief 移动构造函数
         *
         * 从另一个 Vector 对象移动资源，避免不必要的内存分配和复制。
         * 源对象的指针被置为 nullptr，大小被置为 0。
         *
         * @param other 被移动的 Vector 对象（右值引用）。
         */
        Vector(Vector&& other) noexcept :
            elems_{ other.elems_ }, sz_{ other.sz_ } {
            other.elems_ = nullptr;
            other.sz_    = 0;
        }

        ~Vector() {
            /** 释放数组 */
            std::cout << "delete elements.\n";
            delete[] elems_;
        }

        /**
         * @brief 移动赋值运算符
         *
         * 释放当前对象的资源，然后从另一个 Vector 对象移动资源。
         * 源对象的指针被置为 nullptr，大小被置为 0。
         *
         * @param other 被移动的 Vector 对象（右值引用）。
         * @return Vector& 返回当前对象的引用。
         */
        auto
        operator=(Vector&& other) noexcept -> Vector& {
            if (this != &other) {
                delete[] elems_;
                elems_       = other.elems_;
                sz_          = other.sz_;
                other.elems_ = nullptr;
                other.sz_    = 0;
            }
            return *this;
        }

        auto
        operator[](const int i) -> double& {
            if (i < 0 || i >= sz_) {
                throw std::out_of_range("Vector index out of range.");
            }
            return elems_[i];
        }

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
        operator[](const int i) const -> const double& {
            if (i < 0 || i >= sz_) {
                throw std::out_of_range("Vector index out of range.");
            }
            return elems_[i];
        }

        /**
         * @brief 向 Vector 末尾添加一个元素
         *
         * 该方法使用移动语义重新分配内存以容纳新元素，将现有元素复制到新数组中，
         * 然后添加新元素。通过移动语义转移资源所有权，避免显式的手动释放。
         *
         * @param value 要添加的双精度浮点数值。
         */
        auto
        push_back(const double value) -> void {
            auto* new_elems = new double[sz_ + 1];
            for (int i = 0; i < sz_; ++i) { new_elems[i] = elems_[i]; }
            new_elems[sz_] = value;

            // 创建临时 Vector 并使用移动赋值转移资源
            Vector temp(0);
            temp.elems_ = new_elems;
            temp.sz_    = sz_ + 1;
            *this       = std::move(temp);
        }

        auto
        push_back1(const double value) -> void {
            auto* new_elems = new double[sz_ + 1];
            for (int i = 0; i < sz_; ++i) { new_elems[i] = elems_[i]; }
            new_elems[sz_] = value;

            delete[] elems_;
            elems_ = new_elems;
            ++sz_;
        }

        [[nodiscard]] auto
        size() const -> int { return sz_; }

    private:
        double* elems_{ nullptr };
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

    auto
    test_vector() {
        using namespace ch5_concrete_types_impl;
        Vector v1 = { 1, 2, 3, 4 };
        Vector v2{ 1.2, 1.4, 1.5, 1.6 };
        Vector v3(4);

        v3.push_back(14);
        v3.push_back1(10);

        std::cout << "Vector v1 (size=" << v1.size() << "): ";
        for (int i = 0; i < v1.size(); ++i) { std::cout << v1[i] << " "; }
        std::cout << "\n";

        std::cout << "Vector v2 (size=" << v2.size() << "): ";
        for (int i = 0; i < v2.size(); ++i) { std::cout << v2[i] << " "; }
        std::cout << "\n";

        std::cout << "Vector v3 (size=" << v3.size() << "): ";
        for (int i = 0; i < v3.size(); ++i) { std::cout << v3[i] << " "; }
        std::cout << "\n";
    }
}


/**
 * @ingroup classes_module_group
 * @brief 5.2 具体类型入口
 */
auto
tutorial_concrete_types() -> void {
    using namespace ch5_concrete_types_impl;
    std::cout << "--- 5.2 Concrete Types ---" << std::endl;
    test_complex();
    test_vector();
}
