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

#include "user_defined_types.hpp"

struct Vector {
    double sz;
    double *elem;
};

void vector_init(Vector &v, int s) {
    v.elem = new double[s];
    v.sz = s;
}

double read_and_sum(int s) {
    Vector v;
    vector_init(v, s);
    for (int i = 0; i != s; ++i)
        v.elem[i] = i; // 仅作为示例

    double sum = 0;
    for (int i = 0; i != s; ++i)
        sum += v.elem[i];
    return sum;
}

void tutorial_structs() {
    std::cout << "2.2 结构体 (struct)" << std::endl;
    double s = read_and_sum(10);
    std::cout << "Sum of 10 elements: " << s << std::endl;
}