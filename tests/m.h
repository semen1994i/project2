#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include "common.h"
#include "text.h"
#include "_text.h"

TEST(move, normal)
{
    text txt = create_text();
    txt->lines->push_back("qwerty\n");
    txt->lines->push_back("summa\n");
    txt->lines->push_back("pogoda\n");
    txt->cursor->line_num = 0;
    txt->cursor->position = 0;

    m(txt, 0, 0);
    EXPECT_EQ(txt->cursor->line_num, 0);
    EXPECT_EQ(txt->cursor->position, 0);

    m(txt, 2, 2);
    EXPECT_EQ(txt->cursor->line_num, 2);
    EXPECT_EQ(txt->cursor->position, 2);

    free(txt);
}

TEST(move, more)
{
    text txt = create_text();
    txt->lines->push_back("qwerty\n");
    txt->lines->push_back("summa\n");
    txt->lines->push_back("pogoda\n");
    txt->cursor->line_num = 0;
    txt->cursor->position = 0;

    m(txt, 0, 50);
    EXPECT_EQ(txt->cursor->line_num, 0);
    EXPECT_EQ(txt->cursor->position, 0);
    m(txt, 100, 0);
    EXPECT_EQ(txt->cursor->line_num, 0);
    EXPECT_EQ(txt->cursor->position, 0);
    m(txt, 100, 100);
    EXPECT_EQ(txt->cursor->line_num, 0);
    EXPECT_EQ(txt->cursor->position, 0);

    free(txt);
}
