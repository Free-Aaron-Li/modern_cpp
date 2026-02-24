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

#ifndef MODERN_CPP_VECTOR_HPP
#define MODERN_CPP_VECTOR_HPP

/**
 * @file Vector.hpp
 * @brief 演示分离编译的 Vector 类声明
 */

namespace ch3_separate_compilation_impl {
    class Vector {
    public:
        Vector(int s);
        double&
        operator[](int i);
        int
        size();

    private:
        double* elem;
        int     sz;
    };
}  // namespace ch3_separate_compilation_impl

#endif  // MODERN_CPP_VECTOR_HPP
