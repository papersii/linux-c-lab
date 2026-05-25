# B4 数组与指针 — Makefile
# 用法: make | make run | make gdb | make memcheck | make clean

CC      := gcc
CFLAGS  := -g -Wall -Wextra -std=c11
BINS    := pointer_string ptr_to_ptr

.PHONY: all run gdb memcheck clean

all: $(BINS)

pointer_string: pointer_string.c
	$(CC) $(CFLAGS) $< -o $@

ptr_to_ptr: ptr_to_ptr.c
	$(CC) $(CFLAGS) $< -o $@

run: all
	@echo "===== pointer_string ====="; ./pointer_string
	@echo "===== ptr_to_ptr ====="; ./ptr_to_ptr

# 进 gdb 调试 ptr_to_ptr（今日强制单步任务）
gdb: ptr_to_ptr
	gdb ./ptr_to_ptr

# 检查内存问题（本节点暂无 malloc，养成习惯）
memcheck: all
	valgrind --leak-check=full ./pointer_string
	valgrind --leak-check=full ./ptr_to_ptr

clean:
	rm -f $(BINS)
