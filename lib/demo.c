#include <stdio.h>
#include <string.h>

int main() {
    printf("WASM Ready!\n");
    return 1;
}

int getNum() {
    return 22;
}

int getDoubleNum( int x ) {
    return x * 2;
}

char* greet( char* name ) {
    char* greeting = "Hello ";
    strcat(greeting, name);
    return greeting;
}

// Emscripten Compile Command
// basic => emcc lib\demo.c -s WASM=1 -o public\demo.js 
// for only create wasm file => emcc lib\demo.c -s WASM=1 -s SIDE_MODULE=1 -o public\demo.wasm 
// compile with optimisation => emcc lib\demo.c -s WASM=1 -O3 -o public\demo.js
// run pos js file => emcc lib\demo.c -s WASM=1 --post-js public\ready.js -o public\demo.js
// export c functions => emcc lib\demo.c -s WASM=1 -s EXPORTED_FUNCTIONS="['_getNum', '_main', '_getDoubleNum', '_greet']" -o public\demo.js