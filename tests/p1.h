#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include "common.h"
#include "text.h"
#include "_text.h"

TEST(p1, normal)
{
    text txt = create_text();
    txt->lines->push_back("zero\n");
    txt->lines->push_back("first\n");
    txt->lines->push_back("second\n");
    txt->cursor->line_num = 0;
    txt->cursor->position = 0;

    p1(txt, 1, "new line\n");

    string* txt_arr = new string[txt->lines->size()];
    copy(txt->lines->begin(), txt->lines->end(), txt_arr);

    EXPECT_EQ(txt->lines->size(), 4);
    EXPECT_STREQ(txt_arr[0].c_str(), "zero\n");
    EXPECT_STREQ(txt_arr[1].c_str(), "new line\n");
    EXPECT_STREQ(txt_arr[2].c_str(), "first\n");
    EXPECT_STREQ(txt_arr[3].c_str(), "second\n");

    free(txt);
}

TEST(p1, without_text)
{
    text txt = create_text();
    txt->cursor->line_num = 0;
    txt->cursor->position = 0;

    p1(txt, 0, "new line\n");

    string* txt_arr = new string[txt->lines->size()];
    copy(txt->lines->begin(), txt->lines->end(), txt_arr);

    EXPECT_EQ(txt->lines->size(), 1);
    EXPECT_STREQ(txt_arr[0].c_str(), "new line\n");

    free(txt);
}

