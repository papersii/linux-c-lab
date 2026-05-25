/*
 * pointer_string.c  —  B4 起手模板 (starter template)
 * 目标：用【纯指针】实现 strlen / strcpy / reverse，禁止使用 [] 下标。
 *
 * 规则：
 *   - 只用 *p、p++、p-- 这类指针操作，不准写 str[i]
 *   - 每个 TODO 自己填，填完用 make 编译，再 ./pointer_string 运行
 *   - 运行前先去 exercises.md 写下你的预测输出
 *
 * 编译: make   |   运行: ./pointer_string   |   调试: make gdb
 */

#include <stdio.h>
#include <stddef.h>  /* size_t */

/* ---------------------------------------------------------------------------
 * 1) my_strlen —— 返回字符串长度（不含结尾 '\0'）
 *
 *    思路：让一个指针从头走到 '\0'，走了几步就是长度。
 *    内存图（"hi"）:
 *      地址      内容
 *      s+0      'h'
 *      s+1      'i'
 *      s+2      '\0'   ← 停在这，走了 2 步
 * ------------------------------------------------------------------------- */
size_t my_strlen(const char *s)
{
    const char *p = s;
    /* TODO: 让 p 一直前进直到 *p == '\0' */

    /* TODO: 返回 p 和 s 的差值（指针相减得到元素个数） */
    return 0; /* <- 改掉这一行 */
}

/* ---------------------------------------------------------------------------
 * 2) my_strcpy —— 把 src 拷到 dst（含结尾 '\0'），返回 dst
 *
 *    思路：一边解引用读 src，一边写进 dst，两个指针同步前进，
 *          直到把 '\0' 也拷过去为止。
 *    陷阱：'\0' 也要拷！经典的 `while (*dst++ = *src++);` 就是干这个的，
 *          但今天请你写展开版，先别用那个炫技写法，把每一步看清楚。
 * ------------------------------------------------------------------------- */
char *my_strcpy(char *dst, const char *src)
{
    char *ret = dst;
    /* TODO: 当 *src 不是 '\0' 时，*dst = *src，然后两个指针都 ++ */

    /* TODO: 循环结束后，别忘了把结尾 '\0' 也写进 *dst */

    return ret;
}

/* ---------------------------------------------------------------------------
 * 3) my_reverse —— 原地反转字符串（in-place），返回 s
 *
 *    思路：左指针指头，右指针指尾（'\0' 前一个），向中间靠拢交换。
 *    内存图（"abc"）:
 *      左→ a  b  c ←右      交换 a,c
 *         c  b  a            左右相遇/交错 → 停
 *    提示：先用 my_strlen 找到长度，定位右指针。
 * ------------------------------------------------------------------------- */
char *my_reverse(char *s)
{
    char *left = s;
    char *right = s + my_strlen(s) - 1; /* 指向最后一个真实字符 */
    /* TODO: 当 left < right 时，交换 *left 和 *right，然后 left++、right-- */

    return s;
}

/* --------------------------------------------------------------------------- */
int main(void)
{
    char buf[64];

    printf("my_strlen(\"hello\")      = %zu  (期望 5)\n", my_strlen("hello"));
    printf("my_strlen(\"\")           = %zu  (期望 0)\n", my_strlen(""));

    my_strcpy(buf, "GPU kernel");
    printf("my_strcpy -> buf         = \"%s\"  (期望 \"GPU kernel\")\n", buf);

    my_strcpy(buf, "abcde");
    printf("my_reverse(\"abcde\")     = \"%s\"  (期望 \"edcba\")\n", my_reverse(buf));

    my_strcpy(buf, "x");
    printf("my_reverse(\"x\")         = \"%s\"  (期望 \"x\")\n", my_reverse(buf));

    return 0;
}
