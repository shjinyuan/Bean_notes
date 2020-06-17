/*
 * Filename: strcut_constructor_self.cpp
 *
 * Copyright (C) 2018-2023 yuan  <yuan@company.com>. All Rights Reserved.
 *
 * History:
 *    2020/06/16 - [yuan] Created file
 *
 * Maintainer: yuan <yuan@email.com>
 *    Created: 2020-06-16
 * LastChange: 2020-06-16
 *    Version: v0.0.01
 *
 */
#include <iostream>
struct box  {
    int width;
    int height;

    // 括号内是参数，外是需要赋值的成员
    box () :width(10), height(10) {
        printf("box inner constructor with no arg\n");
    }

    box (int width) : width(width), height(10) {
        printf("box inner constructor with one arg\n");
    }

    box (int width, int height) : width(width), height(height) {
        printf("box inner constructor with full arg\n");
    }

};


int main() {
    struct box a{};
    printf("struct box a{};: %d %d\n\n", a.width, a.height);

    struct box b{10};
    printf("struct box b{10}: %d %d\n\n", b.width, b.height);

    struct box c{10, 20};
    printf("struct box c{10, 20};: %d %d\n\n", c.width, c.height);

    return 0;
}
