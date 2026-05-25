# Day B4 — 数组与指针、指针的指针 (Arrays & Pointers, Pointer-to-Pointer)

> **日期 / Date:** 2026-05-26 (周二 / Tue) · Phase 1 技术除锈 · 节点 [B4]
> **拉日 (Pull day)** — 认知状态中等，正常推进新内容。

---

## 今日目标 / Today's Goal

**进阶条件 (Advancement criteria):**
- 能用**纯指针**（不用数组下标 `[]`）实现 `strlen` / `strcpy` / `reverse`
- 能用内存图解释 `int**`（指针的指针）的物理布局

做到这两点 → 推进 [B5] struct 与内存对齐。
卡住 → 换角度继续 B4，不重复同一题。

---

## 核心概念回顾 / Core Concepts

### 1. 数组名 ≈ 首元素地址 (Array name decays to pointer)

```c
int a[5] = {10, 20, 30, 40, 50};
//   a      == &a[0]      (数组名退化为首元素指针)
//  *a      == a[0]       == 10
//  *(a+1)  == a[1]       == 20
//   a[i]   == *(a + i)   ← 编译器就是这么翻译下标的
```

`a[i]` 只是 `*(a + i)` 的语法糖。这就是为什么 `2[a] == a[2]`（合法但别这么写）。

### 2. 指针算术按类型步长走 (Pointer arithmetic scales by type size)

```
int a[3]    地址(hex)        内容
            0x7ffc1000   [0a 00 00 00]  ← a[0] = 10
            0x7ffc1004   [14 00 00 00]  ← a[1] = 20   (a+1 跳了 4 字节 = sizeof(int))
            0x7ffc1008   [1e 00 00 00]  ← a[2] = 30
```

`p + 1` 不是地址 +1，而是 +`sizeof(*p)` 字节。`char*` 走 1 字节，`int*` 走 4 字节。

### 3. 指针的指针 `int**` 内存图 (Pointer-to-pointer)

```c
int    x   = 42;
int*   p   = &x;     // p 存 x 的地址
int**  pp  = &p;     // pp 存 p 的地址
```

```
地址(hex)      变量    内容              说明
0x7ffc2000    x      [2a 00 00 00]     ← int x = 42
0x7ffc2008    p      [00 20 fc 7f]     ← p = &x，存的是 x 的地址 0x7ffc2000
0x7ffc2010    pp     [08 20 fc 7f]     ← pp = &p，存的是 p 的地址 0x7ffc2008

解引用链:
  pp   → 0x7ffc2008  (p 的地址)
 *pp   → 0x7ffc2000  (p 的值 = x 的地址)
**pp   → 42          (x 的值)
```

**口诀：** 每多一个 `*`，就顺着地址再"跳"一层。`int**` 在 AI Sys 里随处可见——比如二维矩阵 `float**`、`argv` 字符串数组 `char**`。

---

## 文件结构 / Files

```
b4-arrays-pointers/
├── README.md          ← 本文件：概念笔记 + 内存图
├── exercises.md       ← 练习题 + 预测输出栏（先预测再运行！）
├── pointer_string.c   ← 起手模板：strlen/strcpy/reverse 骨架待你填
├── ptr_to_ptr.c       ← int** 探索模板（配合 gdb 单步）
└── Makefile           ← gcc -g -Wall 编译，含 valgrind / gdb 目标
```

## 怎么用 / How to use

```bash
# 1. 编译（带调试符号 + 全部警告）
make

# 2. 运行
./pointer_string
./ptr_to_ptr

# 3. 用 gdb 单步观察内存（今日强制至少一题用 gdb）
make gdb            # 进 gdb，试 break main / run / next / print / x

# 4. 检查内存泄漏（本节点暂无 malloc，但养成习惯）
make memcheck
```

---

## 今日纪律 / Discipline

- **先预测再运行**：每道练习题运行前，先在 `exercises.md` 写下预测输出。
- **至少一题用 gdb 单步**：建议用 `ptr_to_ptr.c`，`print pp`、`print *pp`、`print **pp` 看清三层。
- **不用 `[]`**：strlen/strcpy/reverse 强制用纯指针写，逼自己理解指针算术。
- **GitHub commit**：哪怕只填了一个函数，也 commit 一次。

---

## 与 AI Sys 的连接 / Why this matters

| 今日概念 | AI Infra 实际场景 |
|---------|------------------|
| `int**` / `float**` 二级指针 | 矩阵存储、CUDA 中 host 端的二维数组指针传递 |
| 指针算术步长 | CUDA kernel 里 `A[row * N + col]` 的扁平化索引就是手动指针算术 |
| 数组名退化 | 把数组传进函数时丢失长度信息 → 为什么 CUDA kernel 必须显式传 N |
```
