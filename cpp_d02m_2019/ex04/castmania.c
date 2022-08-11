/*
** EPITECH PROJECT, 2018
** my_getnbr.c
** File description:
** return_intvalue_of_str_argument
*/

#include "castmania.h"

void exec_operation(instruction_type_t instruction_type, void *data)
{
    instruction_t *ptr = (instruction_t *) data;

    if (instruction_type == ADD_OPERATION) {
        addition_t *ptr2 = (addition_t *) ptr->operation;
        exec_add(ptr2);
        if (ptr->output_type == VERBOSE) {
            printf("%d\n", ptr2->add_op.res);
        }
    } else if (instruction_type == DIV_OPERATION) {
        division_t *ptr2 = (division_t *) ptr->operation;
        exec_div(ptr2);
        if (ptr2->div_type == INTEGER && ptr->output_type == VERBOSE) {
            integer_op_t *ptr3 = (integer_op_t *) ptr2->div_op;
            printf("%d\n", ptr3->res);
        } else if (ptr2->div_type == DECIMALE && ptr->output_type == VERBOSE) {
            decimale_op_t *ptr3 = (integer_op_t *) ptr2->div_op;
            printf("%f\n", ptr3->res);
        }
    }
}

void  exec_instruction(instruction_type_t  instruction_type , void *data)
{
    if (instruction_type == PRINT_INT) {
        int *i = (int *) data;
        printf("%i\n", *i);
    } else if (instruction_type == PRINT_FLOAT) {
        float *f = (float *) data;
        printf("%f\n", *f);
    } else {
        exec_operation(instruction_type, data);
    }
}