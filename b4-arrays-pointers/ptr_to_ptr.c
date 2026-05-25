/*
 * ptr_to_ptr.c  —  B4 起手模板：指针的指针 (int**)
 *
 * 这个文件主要用来配合 gdb 单步，把 x / p / pp 三层关系看清楚。
 * 今日强制：用 gdb 在 main 里单步，依次 print &x, p, *p, pp, *pp, **pp，
 *           对照 README 里的内存图，确认地址链对得上。
 *
 * 编译: make   |   gdb: make gdb
 */

#include <stdio.h>

/* ---------------------------------------------------------------------------
 * set_via_pp —— 通过二级指针修改最底层的值
 *   传入 int**，把它指向的 int 改成 newval。
 *   这是 "传址调用再加一层" 的典型：要改 p 指向的 x，需要 *pp 拿到 x。
 *
 *   提问：如果想修改的不是 x 的值，而是让 p 改指向另一个变量，
 *         该解引用几层？(答案写进 exercises.md)
 * ------------------------------------------------------------------------- */
void set_via_pp(int **pp, int newval)
{
    /* TODO: 用 **pp = newval; 修改最底层的 int */
}

int main(void)
{
    int   x  = 42;
    int  *p  = &x;
    int **pp = &p;

    /* 先预测：下面每一行打印什么？写进 exercises.md 再运行对答案 */
    printf("x      = %d\n", x);
    printf("*p     = %d\n", *p);
    printf("**pp   = %d\n", **pp);

    printf("&x     = %p\n", (void *)&x);
    printf("p      = %p   (应等于 &x)\n", (void *)p);
    printf("*pp    = %p   (应等于 p，也就是 &x)\n", (void *)*pp);
    printf("&p     = %p\n", (void *)&p);
    printf("pp     = %p   (应等于 &p)\n", (void *)pp);

    set_via_pp(pp, 99);
    printf("调用 set_via_pp(pp, 99) 后  x = %d   (期望 99)\n", x);

    /* 进阶探索：char** 字符串数组（和 main 的 argv 一个结构） */
    const char *names[] = { "vLLM", "Triton", "Megatron" };
    const char **q = names;        /* q 指向第一个 char* */
    printf("\nchar** 探索:\n");
    printf("*q       = %s   (期望 vLLM)\n", *q);
    printf("*(q+1)   = %s   (期望 Triton)\n", *(q + 1));
    printf("**(q+2)  = %c   (期望 M, 即 Megatron 的首字符)\n", **(q + 2));

    return 0;
}
