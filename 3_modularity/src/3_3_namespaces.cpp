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

#include "modularity.hpp"

using namespace std;

namespace ch3_namespaces_impl {
    class complex {
    public:
        complex(double r, double i) : re{ r }, im{ i } {}
        double
        real() const {
            return re;
        }
        double
        imag() const {
            return im;
        }

    private:
        double re, im;
    };

    complex
    operator+(complex a, complex b) {
        return { a.real() + b.real(), a.imag() + b.imag() };
    }

    int
    main();
}  // namespace ch3_namespaces_impl

int
ch3_namespaces_impl::main() {
    complex z{ 1, 2 };
    complex z2{ 3, 4 };
    complex z3 = z + z2;
    cout << "z3 = (" << z3.real() << ", " << z3.imag() << "i)" << endl;
    return 0;
}

/**
 * @ingroup modularity_group
 * @brief 3.3 命名空间：演示 namespace 的定义与使用
 *
 * 介绍如何使用命名空间来组织代码，避免命名冲突。
 *
 * 对应《C++ 之旅》3.4 节（C++20 后为 3.4，之前版本可能不同）。
 */
void
tutorial_namespaces() {
    cout << "--- 3.3 Namespaces ---" << endl;
    ch3_namespaces_impl::main();
}
