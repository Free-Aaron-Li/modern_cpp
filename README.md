# Modern CPP 学习项目

本项目致力于通过实际代码示例来学习和掌握现代 C++（C++11 及更高版本）的核心特性和最佳实践。

## 项目愿景

现代 C++ 引入了许多强大的特性，如自动内存管理、右值引用、Lambda 表达式、模板增强等。本项目通过模块化的方式，逐一探讨这些特性的实现原理与应用场景。

## 当前模块

### 1. 智能指针与 RAII (Smart Pointers & RAII)

- **RAII 手法**：展示如何通过对象的生命周期自动管理资源。
- **内存管理**：涵盖了 `std::shared_ptr` 的基本用法，后续将深入探讨 `std::unique_ptr` 和 `std::weak_ptr`。

### 学习笔记系列

- **[智能指针概说](docs/1_智能指针概说.md)**: 深入探讨 C++ 内存管理、RAII 原理及智能指针细节。
	- 内存管理基础：堆与栈的区别。
	- RAII 原理：如何利用对象生命周期管理资源。
	- 智能指针深挖：`shared_ptr` 的实现细节、原子计数与性能考量。

## 目录结构

- `docs/`: 包含详细的学习笔记。
	- `1_智能指针概说.md`: 智能指针与 RAII 的详细解析。
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