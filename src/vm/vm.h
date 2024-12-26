#pragma once

struct vm_t {
    ram_t *ram;
    stack_t *value_stack;
    stack_t *return_stack;
};

vm_t *vm_new(size_t ram_size);
void vm_destroy(vm_t **self_pointer);

void vm_step(vm_t *self);
void vm_run_until(vm_t *self, size_t base_length);
void vm_run(vm_t *self);

void vm_emu(const blob_t *blob);
