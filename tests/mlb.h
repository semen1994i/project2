#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include "common.h"
#include "text.h"
#include "_text.h"

TEST(mlb, easy)
{
    text txt = create_text();
    txt->lines->push_back("qwerty\n");
    txt->lines->push_back("summa\n");
    txt->lines->push_back("pogoda\n");
    txt->cursor->line_num = 0;
    txt->cursor->position = -1;

    mlb(txt);

    EXPECT_EQ(txt->cursor->line_num, 0);
    EXPECT_EQ(txt->cursor->position, 0);

    free(txt);
}

TEST(mlb, negative)
{
    text txt = create_text();
    txt->lines->push_back("qwerty\n");
    txt->lines->push_back("summa\n");
    txt->lines->push_back("pogoda\n");
    txt->cursor->line_num = 3;
    txt->cursor->position = -1;

    mlb(txt);

    EXPECT_EQ(txt->cursor->line_num, 3);
    EXPECT_EQ(txt->cursor->position, 0);

    free(txt);
}

TEST(mlb, without_text)
{
    text txt = create_text();
    txt->cursor->line_num = -1;
    txt->cursor->position = -1;

    mlb(txt);

    EXPECT_EQ(txt->cursor->line_num, 0);
    EXPECT_EQ(txt->cursor->position, 0);

    free(txt);
}
