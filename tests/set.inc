struct _SetNode {
    void *data;
    struct _SetNode *next;
};

struct _Set {
    struct _SetNode *head;
};
