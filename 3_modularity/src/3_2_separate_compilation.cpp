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

#include "Vector.hpp"
#include "modularity.hpp"

using namespace std;

/**
 * @ingroup modularity_group
 * @brief 3.2 分离编译：演示头文件与源文件的分离
 *
 * 介绍 C++ 如何通过头文件 (.hpp/.h) 包含接口声明，
 * 以及源文件 (.cpp) 包含具体实现，从而支持分离编译。
 * 涵盖：`ch3_sep_comp_impl::Vector`
 *
 * 对应《C++ 之旅》3.2 节。
 */
void
tutorial_separate_compilation() {
    using namespace ch3_separate_compilation_impl;
    cout << "--- 3.2 Separate Compilation ---" << endl;

    Vector v(6);
    for (int i = 0; i < v.size(); ++i) { v[i] = i * i; }

    double sum = 0;
    for (int i = 0; i < v.size(); ++i) { sum += v[i]; }

    cout << "Sum of square of [0, 6) is: " << sum << endl;
}
