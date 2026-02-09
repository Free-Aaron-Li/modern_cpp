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
 * @file main.cpp
 * @brief 程序入口点
 * @details
 * 本程序演示了现代 C++ 中两种重要的内存管理方式：
 * 1. **RAII (Resource Acquisition Is Initialization)**: 通过手动编写的管理类来接管资源。
 * 2. **std::shared_ptr**: 使用标准库提供的引用计数智能指针来自动管理共享资源。
 */

#include "sp.hpp"
#include "raii.hpp"
#include "shared_ptr.hpp"

/**
 * @brief 主函数
 * @return 程序退出码
 */
int
main() {
    /* 1. 开始演示 RAII 手法 */
    {

        /**
         * @brief 演示步骤：
         * 1. 显式创建一个 `RAII_TEST` 对象的裸指针。
         * 2. 创建 `CRAII` 对象 `c`，并将裸指针传递给它，由其接管生命周期。
         * 3. 当花括号结束，`c` 离开作用域被销毁，其析构函数负责 `delete` 裸指针。
         */
        RAII_TEST* p = new RAII_TEST(); /* 创建裸指针 */
        CRAII c(p); /* 使用CRAII管理p */

        /* 
         * 预期输出：
         * raii_test()
         * ~CRAII()
         * ~raii_test()
         */

    }

    /* 2. 开始演示 shared_ptr 手法 */
    {
        /**
         * @brief 演示步骤：
         * 1. 使用裸指针构造第一个 `std::shared_ptr` 对象 `sp`。
         * 2. 使用 `new` 直接构造第二个 `std::shared_ptr` 对象 `sp1`。
         * 3. 通过拷贝构造创建 `sp2`，此时 `sp` 和 `sp2` 共享同一个资源。
         * 4. 在局部作用域内创建 `sp3`，观察引用计数增加。
         * 5. 局部作用域结束，`sp3` 销毁，引用计数减少。
         * 6. `main` 函数结束前，所有 `shared_ptr` 离开作用域，资源被最终释放。
         */
        SHARED_PTR_TEST* p = new SHARED_PTR_TEST(); /* 成为悬空指针 */
        std::shared_ptr<SHARED_PTR_TEST> sp(p);
        std::shared_ptr<SHARED_PTR_TEST> sp1(new SHARED_PTR_TEST());

        /* 通过一个shared_ptr对象构造 */
        std::shared_ptr<SHARED_PTR_TEST> sp2(sp);

        /* use count 变化 */
        {
            std::shared_ptr<SHARED_PTR_TEST> sp3(sp);
            std::cout << "use count: sp:" << sp.use_count() << " sp1:" << sp1.
                    use_count() << " sp2:" << sp2.use_count() << " sp3:" << sp3.
                    use_count() << std::endl;
        }

        std::cout << "use count: sp:" << sp.use_count() << " sp1:" <<
                sp1.use_count() << " sp2:" << sp2.use_count()
                << std::endl;
    }

    /* 3. shared_ptr 使用注意事项 */
    {
        /* 3.1 避免使用同一个裸指针初始化多个独立的 shared_ptr 对象 */
        int* p = new int(10);
        std::shared_ptr<int> sp1(p); /* use_count 为 1 */
        std::cout << "sp1 use_count: " << sp1.use_count() << std::endl;
        // std::shared_ptr<int> sp2(p); /* 错误：sp2 也会认为自己独占 p */
        // std::cout << "sp2 use_count: " << sp2.use_count() << std::endl;
        /* 导致 double free：sp1 和 sp2 销毁时都会尝试 delete p */

        /* 3.2 避免在类成员函数中通过 `this` 直接创建 shared_ptr 对象 */
        /* 正确做法是继承 std::enable_shared_from_this 并使用 shared_from_this() */
        auto sp3 = std::make_shared<CSPTEST>();
        sp3->process();
        std::cout << "CSPTEST processed." << std::endl;
    }

    /* 4. shared_ptr的细节 */
    {
        /* 4.1 shared_ptr一般大小是裸指针的两倍 */
        int* p = new int(10);
        std::shared_ptr<int> sp(p);
        std::cout << "p size: " << sizeof(p) << ", sp size: " << sizeof(sp) <<
                "." << std::endl;
    }

    return 0;

}
