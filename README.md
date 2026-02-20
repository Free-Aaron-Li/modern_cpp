# Modern CPP 学习项目

本项目致力于通过实际代码示例来学习和掌握现代 C++ （C++ 11 及更高版本） 的核心特性和最佳实践。

## 项目愿景

现代 C++ 引入了许多强大的特性，如自动内存管理、右值引用、Lambda 表达式、模板增强等。本项目通过模块化的方式，逐一探讨这些特性的实现原理与应用场景。

## 当前模块

### 1. 基础 （Basics）

- **语言实体**：C++ 核心语言特性与标准库组件。
- **程序结构**：ISO C++ 定义的基本实体与程序构成。

### 2. 用户自定义类型 （User-Defined Types）

- **结构体与类**：展示如何通过 `struct` 和 `class` 构建自定义类型。
- **枚举与联合**：探讨强类型枚举和联合体及其现代替代方案。

### 3. 智能指针与 RAII （Smart Pointers & RAII）

- **RAII 手法**：展示如何通过对象的生命周期自动管理资源。
- **内存管理**：涵盖了 `std::shared_ptr` 的基本用法，后续将深入探讨 `std::unique_ptr` 和 `std::weak_ptr`。

### 学习笔记序列

本页面汇集了项目开发过程中的核心知识点记录，按模块序列进行排列，便于后续查阅和系统性学习。

同时在 Doxygen 生成的 `专题` 中包含对应章节的具体实现示例，可结合 `深入阅读` 一同学习。

- **[第 1 章 基础](docs/1_基础.md)**: C++ 基础概念、核心语言特性与标准库。
- **[第 2 章 用户自定义类型](docs/2_用户自定义类型.md)**: 结构体、类、枚举与联合。

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
- `2_user_defined_types/`: 包含用户自定义类型相关的示例。
	- `include/`: 头文件目录。
		- `user_defined_types.hpp`: 用户自定义类型主头文件。
	- `src/`: 源代码目录。
		- `main.cpp`: 演示程序入口。
- `.clang-format`: C++ 代码格式化配置文件。
- `.gitignore`: Git 忽略文件。
- `CMakeLists.txt`: 整体项目 `CMake` 配置文件。
- `Doxyfile`: Doxygen 配置文件。

## 如何开始

### 环境要求

- 支持 C++ 23 或更高版本的编译器 （如 GCC 13+, Clang 16+, MSVC 17.4+）
  ，具体请参考 [C++ 标准](https://en.cppreference.com/w/cpp/compiler_support)。
- CMake 3.10+。
- Doxygen 1.6.0+ （可选，用于生成文档）。

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

[C++ 之旅 （第 3 版） —— Bjarne Stroustrup](https://book.douban.com/subject/36596125/)