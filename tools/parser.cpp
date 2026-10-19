#include "parser.h"

str extractValue(const str& block, const str& key) {
    int pos = block.find(key);
    if (pos == str::NPOS) return "";
    int start = pos + key.len();
    int end = start;
    while (
        (end < block.len()) && 
        (block[end] != ';') && 
        (block[end] != '\n') && 
        (block[end] != '[')
    ) {
        end++;
    }
    str rawValue = block.substr(start, end-start);
    return rawValue.strip();
}


str extractBlock(const str& block, const str& key) {
    int pos = block.find(key);
    if (pos == str::NPOS) return "";
    str subBlock = block.substr(pos, block.len() - pos);
    int start = subBlock.find('[');
    int end = subBlock.find(']');
    if (start == str::NPOS || end == str::NPOS) return "";
    return subBlock.substr(start + 1, end - start - 1);
}


str extractParens(const str& text, const str& key){
    int pos = text.find(key);
    if (pos == str::NPOS) return "";
    str subText = text.substr(pos, text.len() - pos);
    int start = subText.find('(');
    int end = subText.find(')');
    if (start == str::NPOS || end == str::NPOS) return "";
    return subText.substr(start + 1, end - start - 1);
}