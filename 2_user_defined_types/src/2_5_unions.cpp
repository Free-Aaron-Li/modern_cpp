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
#include <variant>

enum Type { str, num };

struct Entry {
    std::string name;
    Type t;

    union {
        const char* s;
        int i;
    } v;
};

void
print_entry(const Entry& e) {
    if (e.t == str) std::cout << e.name << ": " << e.v.s << std::endl;
    else std::cout << e.name << ": " << e.v.i << std::endl;
}

/**
 * @ingroup user_defined_types_group
 * @brief 2.5 联合：演示 union 的内存布局与应用
 * 
 * 展示如何在同一块内存区域存储不同类型的变量，以及它的风险与现代替代方案。
 * 
 * 对应《C++ 之旅》2.5 节。
 */
void
tutorial_unions() {
    std::cout << "--- 2.5 Unions ---" << std::endl;
    Entry e1;
    e1.name = "Age";
    e1.t = num;
    e1.v.i = 25;
    print_entry(e1);

    Entry e2;
    e2.name = "Name";
    e2.t = str;
    e2.v.s = "Aaron";
    print_entry(e2);

    std::cout << "Modern C++ alternative: std::variant" << std::endl;
    std::variant<int, std::string> v;
    v = 12;
    std::cout << "std::variant (int): " << std::get<int>(v) << std::endl;
    v = "Hello";
    std::cout << "std::variant (string): " << std::get<std::string>(v) <<
            std::endl;
}
