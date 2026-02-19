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

enum class Color { red, blue, green };

enum class Traffic_light { green, yellow, red };

Traffic_light &operator++(Traffic_light &t) {
    switch (t) {
        case Traffic_light::green: return t = Traffic_light::yellow;
        case Traffic_light::yellow: return t = Traffic_light::red;
        case Traffic_light::red: return t = Traffic_light::green;
    }
    return t;
}

void tutorial_enums() {
    std::cout << "\n2.4 枚举 (enum)" << std::endl;
    Color col = Color::red;
    Traffic_light light = Traffic_light::red;
    if (col == Color::red) {
        // use col to avoid warning
    }

    if (light == Traffic_light::red) {
        ++light;
    }

    if (light == Traffic_light::green) {
        std::cout << "Light is now green" << std::endl;
    }
}