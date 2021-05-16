TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += append_line.cpp \
create_text.cpp \
editor.cpp \
m.cpp \
mlb.cpp \
p1.cpp \
process_backward.cpp \
process_forward.cpp \
remove_all.cpp \
save.cpp \
load.cpp \
set_cursor.cpp \
show.cpp \
showreveven.cpp


HEADERS += \
        text.h \
        _text.h \
        common.h

QMAKE_CFLAGS += -Werror

# gcov
QMAKE_CFLAGS += -fprofile-arcs -ftest-coverage
LIBS += -lgcov 
