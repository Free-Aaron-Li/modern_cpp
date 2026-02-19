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

using namespace std;

/**
 * @brief 简单的向量结构体
 */
struct Vector {
    double* elem; /**< 指向元素的指针 */
    int sz_;      /**< 元素的数量 */
};

/**
 * @brief 初始化 Vector
 * @param v 待初始化的 Vector 引用
 * @param s 元素数量
 *
 * 使用 new 从自由存储（堆）中分配内存。
 */
void
vector_init(Vector& v, int s) { /* 非 const 引用参数，允许修改 v */
    v.elem = new double[s];     /* 分配数组空间，包含 s 个 double 类型的值 */
    /* new
     * 从自由存储（即动态内存或堆）中分配内存，与对象创建时所在的作用域无关，
     * 会持续存在，直至被
     * `delete` 释放 */
    v.sz_ = s;
}

/**
 * @brief 从标准输入读取元素并计算总和
 * @param s 元素数量
 * @return 元素的总和
 */
double
read_and_sum(int s) {
    Vector v;
    vector_init(v, s); /* 为 v 分配 s 个元素 */

    for (int i = 0; i != s; ++i) cin >> v.elem[i]; /* 读入元素 */

    double sum = 0;
    for (int i = 0; i != s; ++i) sum += v.elem[i]; /* 计算元素的和 */
    return sum;
}

/**
 * @brief 演示不同方式访问结构体成员
 * @param v 按值传递
 * @param rv 按引用传递
 * @param pv 按指针传递
 */
void
f(Vector v, Vector& rv, Vector* pv) {
    /* [[maybe_unused]] C++17
     * 属性，告诉编译器即使这个变量/参数/函数/返回值未被使用，
     * 也不要报“unused...”之类警告
     */
    [[maybe_unused]] int i1{ v.sz_ };   /* 通过名字访问 */
    [[maybe_unused]] int i2{ rv.sz_ };  /* 通过引用访问 */
    [[maybe_unused]] int i3{ pv->sz_ }; /* 通过指针访问 */
}

/**
 * @ingroup user_defined_types_group
 * @brief 2.2 结构体：演示 struct 的定义与初始化
 *
 * 展示如何定义结构体、在堆上分配内存以及通过不同方式访问成员。
 *
 * 对应《C++ 之旅》2.2 节。
 */
void
tutorial_structs() {
    cout << "--- 2.2 Structs ---" << endl;
    // read_and_sum(10);
    Vector v;
    f(v, v, &v);
}
