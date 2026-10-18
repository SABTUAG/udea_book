#ifndef PARSER_H
#define PARSER_H

#include "str.h"

inline str extractParens(const str& text, const str& key) {
    int pos = text.find(key);
    if (pos == str::NPOS) return "";
    str subText = text.substr(pos, text.len() - pos);
    int start = subText.find('(');
    int end = subText.find(')');
    if (start == str::NPOS || end == str::NPOS) return "";
    return subText.substr(start + 1, end - start - 1);
}
#endif