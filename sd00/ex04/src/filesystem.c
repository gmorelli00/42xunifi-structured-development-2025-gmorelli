#include "../includes/filesystem.h"

FSNode *create_file(const char *name, int size)
{
    if (!name || size <= 0)
        return NULL;

    FSNode *file = (FSNode *)malloc(sizeof(FSNode));
    if (!file)
        return NULL;
    file->name = strdup(name);
    file->size = size;
    file->child = NULL;
    file->sibling = NULL;
    return file;
}

FSNode *create_folder(const char *name)
{
    if (!name)
        return NULL;

    FSNode *folder = (FSNode *)malloc(sizeof(FSNode));
    if (!folder)
        return NULL;
    folder->name = strdup(name);
    folder->size = 0;
    folder->child = NULL;
    folder->sibling = NULL;
    return folder;
}

void add_child(FSNode *parent, FSNode *child)
{
    if (!parent || !child || parent->size != 0)
        return;

    if (!parent->child)
        parent->child = child;
    else
    {
        FSNode *current = parent->child;
        while (current->sibling)
            current = current->sibling;
        current->sibling = child;
    }
}

FSNode *get_children(const FSNode *parent)
{
    if (!parent)
        return NULL;

    return parent->child;
}

FSNode *get_sibling(const FSNode *node)
{
    if (!node)
        return NULL;

    return node->sibling;
}

// int main(void)
// {
//     FSNode *root = create_folder("root");
//     FSNode *file1 = create_file("file1.txt", 100);
//     FSNode *file2 = create_file("file2.txt", 200);
//     FSNode *subfolder = create_folder("docs");

//     add_child(root, file1);
//     add_child(root, file2);
//     add_child(root, subfolder);

//     FSNode *child = get_children(root);
//     while (child)
//     {
//         printf("Nome: %s, Size: %d\n", child->name, child->size);
//         child = get_sibling(child);
//     }

//     return 0;
// }
