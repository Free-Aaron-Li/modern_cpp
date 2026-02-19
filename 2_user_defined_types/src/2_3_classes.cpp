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

class Vector {
public:
    Vector(int s) : elem{new double[s]}, sz{s} {
    }

    double &operator[](int i) { return elem[i]; }
    int size() { return sz; }

private:
    double *elem;
    int sz;
};

void tutorial_classes() {
    std::cout << "\n2.3 类 (class)" << std::endl;
    Vector v(6);
    for (int i = 0; i < v.size(); ++i) {
        v[i] = i * 1.1;
    }

    double sum = 0;
    for (int i = 0; i < v.size(); ++i) {
        sum += v[i];
    }
    std::cout << "Vector sum: " << sum << std::endl;
}