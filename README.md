# Modern CPP 学习项目

本项目致力于通过实际代码示例来学习和掌握现代 C++（C++11 及更高版本）的核心特性和最佳实践。

## 项目愿景

现代 C++ 引入了许多强大的特性，如自动内存管理、右值引用、Lambda 表达式、模板增强等。本项目通过模块化的方式，逐一探讨这些特性的实现原理与应用场景。

## 当前模块

### 1. 基础 (Basics)

- **语言实体**：C++ 核心语言特性与标准库组件。
- **程序结构**：ISO C++ 定义的基本实体与程序构成。

### 2. 智能指针与 RAII (Smart Pointers & RAII)

- **RAII 手法**：展示如何通过对象的生命周期自动管理资源。
- **内存管理**：涵盖了 `std::shared_ptr` 的基本用法，后续将深入探讨 `std::unique_ptr` 和 `std::weak_ptr`。

### 学习笔记系列

- **[第1章 基础](docs/1_基础.md)**: C++ 基础概念、核心语言特性与标准库。
- **[智能指针概说](docs/1_智能指针概说.md)**: 深入探讨 C++ 内存管理、RAII 原理及智能指针细节。
	- 内存管理基础：堆与栈的区别。
	- RAII 原理：如何利用对象生命周期管理资源。
	- 智能指针深挖：`shared_ptr` 的实现细节、原子计数与性能考量。

> **提示**：本项目仍处于开发阶段，后续还会添加许多其他章节（如模板元编程、并发编程、STL 深入解析等）。

## 目录结构

- `docs/`: 包含详细的学习笔记。
	- `1_基础.md`: C++ 基础概念解析。
	- `1_智能指针概说.md`: 智能指针与 RAII 的详细解析。
- `1_basics/`: 包含 C++ 基础相关的示例。
	- `include/`: 头文件目录。
		- `1_basics.hpp`: 基础章节主头文件。
	- `src/`: 源代码目录。
		- `main.cpp`: 演示程序入口。
- `smart_pointer/`: 包含智能指针与 RAII 相关的实现。
	- `include/`: 头文件目录。
		- `raii.hpp`: RAII 核心原理解析与测试类。
		- `shared_ptr.hpp`: std::shared_ptr 示例。
		- `sp.hpp`: 智能指针模块主头文件。
	- `src/`: 源代码目录。
		- `main.cpp`: 演示程序入口。
		- `raii.cpp`: RAII 相关实现代码。
- `doxygen/`: 生成的 Doxygen 文档。
- `Doxyfile`: Doxygen 配置文件。

## 如何开始

### 环境要求

- 支持 C++11 或更高版本的编译器 (如 GCC 11+, Clang, MSVC)。
- CMake 3.10+。
- Doxygen (可选，用于生成文档)。

### 构建与运行

1. 创建构建目录：
   ```bash
   mkdir build && cd build
   ```
2. 配置项目：
   ```bash
   cmake ..
   ```
3. 编译并运行：
   ```bash
   make && ./bin/smart_pointer
   ```

### 生成文档

在项目根目录下运行：

```bash
doxygen Doxyfile
```

然后打开 `doxygen/html/index.html` 查看。

## 参考

### 视频参考

[C++_The Cherno](https://www.youtube.com/watch?v=18c3MTX0PK0&list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb)

### 书籍参考

[C++之旅（第3版）—— Bjarne Stroustrup](https://book.douban.com/subject/36596125/)