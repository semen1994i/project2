#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <string>
#include <iostream>
#include <sstream>

#include "common.h"
#include "text.h"
#include "_text.h"


TEST(showreveven, without_line)
{
    text txt = create_text();
    txt->cursor->line_num = 0;
    txt->cursor->position = 0;

    testing::internal::CaptureStdout();

    showreveven(txt);
    std::string text = testing::internal::GetCapturedStdout();

    EXPECT_EQ(text.length(), 0);

    free(txt);
}

TEST(showreveven, one_line)
{
    text txt = create_text();
    txt->lines->push_back("PRIVET\n");
    txt->cursor->line_num = 0;
    txt->cursor->position = 0;

    testing::internal::CaptureStdout();

    showreveven(txt);
    std::string text = testing::internal::GetCapturedStdout();

    EXPECT_STREQ(text.c_str(), "PRIVET\n");

    free(txt);
}

TEST(showreveven, three_lines)
{
    text txt = create_text();
    txt->lines->push_back("full\n");
    txt->lines->push_back("out\n");
    txt->lines->push_back("full 2\n");
    txt->cursor->line_num = 0;
    txt->cursor->position = 0;

    testing::internal::CaptureStdout();

    showreveven(txt);
    std::string text = testing::internal::GetCapturedStdout();

    EXPECT_STREQ(text.c_str(), "full 2\nfull\n");

    free(txt);
}
