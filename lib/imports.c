#include <emscripten.h>
#include <stdio.h>

EM_JS( void, jsFunction, (int x), {
    console.log( 'Call JS function in C: ' + x );
})

int main() {
    printf("WASM Ready!\n");

    // Call JS Function (eval)
    emscripten_run_script("console.log('Hello from C')");

    // Call JS Function Async (eval)
    emscripten_async_run_script("console.log('Hello from C')", 2000);

    // Get return val from JS - INT
    int jsVal = emscripten_run_script_int("getNum()");
    printf("jsVal => %d\n", jsVal);

    // Get return val from JS - STRING
    char* jsValStr = emscripten_run_script_string("getStr()");
    printf("jsValStr => %s\n", jsValStr);

    jsFunction(55);

    return 1;
}
