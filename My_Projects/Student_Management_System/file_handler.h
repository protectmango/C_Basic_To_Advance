/*
 * file_handler.h
 */
#include "linked_list.h"
#include "student.h"

int save_students_to_csv(const char *filename ,const struct Node *head);

int load_students_from_csv(const char *filename , struct Node **head);

