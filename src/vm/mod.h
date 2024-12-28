#pragma once

// A mod is a compilation unit,
// like the dictionary of forth.

struct mod_t {
    const char *src;
    const char *code;
    hash_t *def_hash;
};

mod_t *mod_new(const char *src, const char *string);
void mod_destroy(mod_t **self_pointer);

void mod_define(mod_t *self, def_t *def);
const def_t *mod_find_def(const mod_t *self, const char *name);
