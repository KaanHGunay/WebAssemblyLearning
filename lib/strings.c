#include <emscripten.h>
#include <stdio.h>

char* str = "My string";
char* getStr() {
    return str;
}
// in JS use
// Pointer_stringify(_getStr()) or
// UTF8ToString(_getStr())
// in JS to overrite the function use;
// stringToUTF8('An other string', _getStr(), 'An other string'.length + 1)

int getNumber() {
    int num = 16;
    // emscripten_debugger(); // creating breakpoint
    return num;
}

int main() {

    printf("WASM Ready!\n");

    return 1;
}
