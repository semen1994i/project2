#include <string.h>
#include <string.h>
#include <sstream>
#include <stdlib.h>
#include "common.h"
#include "text.h"
#include <stdio.h>

string set_cursor(string contents, int cursor) {
    std::stringstream res;
    res << contents.substr(0, cursor) << '|' << contents.substr(0) << '\n';

    return res.str().c_str();
}
