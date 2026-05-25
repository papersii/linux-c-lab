# B4 练习题 — 数组与指针 (2026-05-26)

> **铁律：先预测，再运行。** 每题运行前先在「我的预测」栏写下答案，运行后填「实际输出」，不一致的就用 gdb / 内存图找原因。

---

## Part A — 填空实现 (在 pointer_string.c 中完成)

完成三个纯指针函数，然后 `make && ./pointer_string`。

- [ ] `my_strlen` — 指针走到 `'\0'`，返回 `p - s`
- [ ] `my_strcpy` — 同步拷贝，记得拷 `'\0'`
- [ ] `my_reverse` — 左右指针向中间交换

| 测试 | 我的预测 | 实际输出 | ✅/❌ |
|------|---------|---------|------|
| `my_strlen("hello")` | ___ | | |
| `my_strlen("")` | ___ | | |
| `my_strcpy(buf,"GPU kernel")` | ___ | | |
| `my_reverse("abcde")` | ___ | | |
| `my_reverse("x")` | ___ | | |

---

## Part B — 指针的指针 (在 ptr_to_ptr.c 中完成)

完成 `set_via_pp`，然后 `make && ./ptr_to_ptr`。

| 表达式 | 我的预测 | 实际输出 | ✅/❌ |
|--------|---------|---------|------|
| `**pp`（初始） | ___ | | |
| `p == &x` ? | ___ | | |
| `*pp == p` ? | ___ | | |
| `pp == &p` ? | ___ | | |
| 调用 `set_via_pp(pp,99)` 后 `x` | ___ | | |
| `*q` | ___ | | |
| `*(q+1)` | ___ | | |
| `**(q+2)` | ___ | | |

**思考题（写下你的答案）：**
1. 想让 `p` 改指向另一个变量 `y`，在 `set_via_pp` 里应该写 `___ = &y;`（解引用几层？）
2. 为什么 `q + 1` 跳过的字节数是 `sizeof(char*)` 而不是 1？

---

## Part C — gdb 强制单步 (今日必做)

用 `ptr_to_ptr.c` 跑一遍：

```bash
make gdb
# 在 gdb 里：
(gdb) break main
(gdb) run
(gdb) next            # 走过 x/p/pp 的赋值
(gdb) print &x        # 记下地址
(gdb) print p         # 应等于 &x
(gdb) print *pp       # 应等于 p
(gdb) print **pp      # 应等于 42
(gdb) x/3xw &x        # 以 16 进制看 x 附近 3 个 word 的内存
```

把你看到的三个地址抄下来，画成 README 里那样的内存图：

```
地址            变量    说明
__________     x       42
__________     p       = &x
__________     pp      = &p
```

---

## Part D — 进阶 / 追加任务 (有余力再做)

1. **边界处理**：给 `my_strcpy` 加 `NULL` 检查（src 或 dst 为 NULL 时怎么办？）。
2. **`watch` 命令**：在 gdb 里对 `my_reverse` 用 `watch *left`，观察交换时内存变化。
3. **整合小工具**：把今天三个函数收进 `my_string.h`，做你自己的 `string.h` 子集的第一步（B5 会继续扩）。
4. **AI Sys 连接**：写两句话——CUDA kernel 里 `A[row*N+col]` 这种扁平索引，和今天的指针算术是同一回事吗？为什么 GPU 上更爱用一维扁平数组而不是 `float**`？

---

## 今日自评 / Self-check

- [ ] 三个函数都用纯指针实现，没用 `[]`
- [ ] 至少一题用 gdb 单步，画出了内存图
- [ ] 所有预测都先写后运行
- [ ] commit 到 `linux-c-lab`

**进阶判断**：能默写 strlen/strcpy/reverse + 解释 `int**` 内存图 → 明天进 [B5]。
