/**
 * @file       set.inc
 *
 * @author     Maxime Chasles
 * @date       2024-2025
 * @copyright  BSD 3-Clause License
 */

struct _SetNode
{
    void *data;
    struct _SetNode *next;
};

struct _Set
{
    struct _SetNode *head;
};

struct _SetIterator
{
    struct _Set *set;
    struct _SetNode *current;
    unsigned int index;
};
