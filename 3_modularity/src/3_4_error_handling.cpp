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

#include <stdexcept>

#include "modularity.hpp"

using namespace std;

namespace ch3_error_handling_impl {
    class Vector {
    public:
        Vector(int s) {
            if (s < 0)
                throw length_error{ "Vector constructor: negative size" };
            elem = new double[s];
            sz   = s;
        }

        double&
        operator[](int i) {
            if (i < 0 || size() <= i)
                throw out_of_range{ "Vector::operator[]" };
            return elem[i];
        }

        int
        size() const {
            return sz;
        }

    private:
        double* elem;
        int     sz;
    };

    void
    test_exceptions() {
        try {
            Vector v(-1);
        } catch (const length_error& e) {
            cerr << "Caught expected error: " << e.what() << endl;
        }

        try {
            Vector v(5);
            v[10] = 7;
        } catch (const out_of_range& e) {
            cerr << "Caught expected error: " << e.what() << endl;
        }
    }

    void
    test_static_assert() {
        constexpr double speed_of_light = 299792458;
        static_assert(speed_of_light > 0, "Light must move!");

        // static_assert(sizeof(int) >= 64, "Integers are too small"); // Would
        // fail at compile time
    }
}  // namespace ch3_error_handling_impl

/**
 * @ingroup modularity_group
 * @brief 3.4 错误处理：演示异常与断言
 *
 * 展示如何使用异常处理运行时错误，以及使用 static_assert 进行编译时检查。
 *
 * 对应《C++ 之旅》3.5 节（旧版）或 3.6 节（C++20 版）。
 */
void
tutorial_error_handling() {
    cout << "--- 3.4 Error Handling ---" << endl;
    ch3_error_handling_impl::test_exceptions();
    ch3_error_handling_impl::test_static_assert();
}
