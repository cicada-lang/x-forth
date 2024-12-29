#include "index.h"

static bool
compile_int_token(vm_t *vm, const token_t *token, function_t *function) {
    (void) vm;

    if (token->kind != INT_TOKEN) return false;
    if (!string_is_xint(token->string)) return false;

    value_t value = xint(string_parse_xint(token->string));
    function_emit_literal(function, value);
    return true;
}

static bool
compile_float_token(vm_t *vm, const token_t *token, function_t *function) {
    (void) vm;

    if (token->kind != FLOAT_TOKEN) return false;
    if (!string_is_double(token->string)) return false;

    value_t value = xfloat(string_parse_double(token->string));
    function_emit_literal(function, value);
    return true;
}

static bool
compile_generic_token(vm_t *vm, const token_t *token, function_t *function) {
    function_emit_call(function, vm->mod, token->string);
    return true;
}

void
compile_token(vm_t *vm, const token_t *token, function_t *function) {
    if (compile_int_token(vm, token, function)) return;
    if (compile_float_token(vm, token, function)) return;
    if (compile_generic_token(vm, token, function)) return;

    fprintf(stderr, "[compile_token] unknown token: %s\n", token->string);
}