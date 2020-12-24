#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

typedef struct
{
    int min_val;
    int min_depth;
} retvals;

struct tree
{
    int fatherVal; // для построения дерева по значению отца
    int val;
    struct tree *son;
    struct tree *brother;
};

bool clean_screen()
{
    return (printf("\033[2J") && printf("\033[0;0f"));
}

struct tree *root;
struct tree *mktree(struct tree *root1, struct tree *subTree, int val, int fatherVal);
void printTree(struct tree *root, int lvl);
bool isExists(const struct tree *root, int fatherVal);
void deleteTree(struct tree **root, int val, int id);
bool isEmpty(const struct tree *root);
retvals min_depth_val(const struct tree *root, int min_depth, int cur_depth, int min_val, int used_values[10]);

int main()
{

    root = NULL;

    int val, fatherVal, used_leaf_count = 0, min_depth = INT_MAX;
    int answer = 'y', answer1;
    int choice;
    int used_values[10];
    retvals values;

    clean_screen();

    while (clean_screen() && printf("\nMenu: \n\t1) Add root/leaf.\n\t2) Print tree.\n\t3) Remove tree node.\n\t4) The value of a leaf having a minimum depth.\n\t5) Exit.\n\nYour choice: ") && scanf("%d", &choice))
    {
        switch (choice)
        {
        case 1:
        {
            do
            {
                printf("Enter father and value of leaf: ");
                if (!root)
                {
                    scanf("%d", &val);
                    fatherVal = val;
                }
                else
                    scanf("%d %d", &fatherVal, &val);

                if (root && !isExists(root, fatherVal))
                {
                    printf("No such father.\n");
                }
                else
                {
                    if (!root || !isExists(root, val))
                    {
                        root = mktree(root, root, val, fatherVal);
                        printf("Item (%d) has been added.\n", val);
                    }
                    else
                    {
                        printf("Item with this value already exists.\n");
                    }
                }

                printf("Do you want to add another leaf? (y/n) : ");
                do
                {
                    answer = tolower(getchar());
                } while ((answer != 'y') && (answer != 'n'));
            } while (answer != 'n');
            break;
        }
        case 2:
        {
            if (isEmpty(root))
                printf("Tree is empty...\n");
            else
            {
                printf("\n__________TREE__________\n\n");
                printTree(root, 1);
                printf("\n__________TREE__________\n\n");
            }
            while (answer1 != 0)
            {
                printf("Press (0) to go back: ");
                scanf("%d", &answer1);
            }

            answer1 = 1;
            break;
        }
        case 3:
        {
            if (isEmpty(root))
                printf("Tree is empty...\n");
            else {
                do
                {
                    answer1 = 0;
                    printf("Enter value of element that you want to delete: ");
                    scanf("%d", &val);
                    if (isExists(root, val))
                        deleteTree(&root, val, 0);
                    else
                        printf("There is no this node.\n");
                    if (root)
                    {
                        printf("Do you want to remove another leaf? (y/n) : ");
                        do
                        {
                            answer = tolower(getchar());
                        } while ((answer != 'y') && (answer != 'n'));
                    }
                } while (answer != 'n');
            }
            while (answer1 != 0)
            {
                printf("Press (0) to go back: ");
                scanf("%d", &answer1);
            }

            answer1 = 1;
            break;
        }
        case 4:
        {

            if (!root)
                printf("Tree is empty... \n");
            else
            {
                printf("Value(s) with minimum depth: ");
                while (true)
                {
                    values = min_depth_val(root, INT_MAX, 0, INT_MAX, used_values);
                    if (values.min_val == INT_MAX || values.min_depth > min_depth)
                        break;
                    min_depth = values.min_depth;
                    printf("%d ", values.min_val);
                    ++used_leaf_count;
                    used_values[used_leaf_count - 1] = values.min_val;
                }
                used_leaf_count = 0;
                values.min_val = 0;
                values.min_depth = INT_MAX;
                min_depth = INT_MAX;
                for (int i = 0; i < 10; ++i)
                {
                    used_values[i] = 0;
                }
                printf("\n");
            }

            while (answer1 != 0)
            {
                printf("Press (0) to go back: ");
                scanf("%d", &answer1);
            }

            answer1 = 1;
            break;
        }
        case 5:
        {
            clean_screen();
            return 0;
        }
        default:
        {
            break;
        }

            clean_screen();
            return 0;
        }
    }
}

struct tree *mktree(struct tree *root, struct tree *subTree, int val, int fatherVal)
{

    if (!subTree)
    {
        subTree = (struct tree *)malloc(sizeof(struct tree));

        if (!subTree)
        {
            printf("No memory.");
            exit(1);
        }

        subTree->son = NULL;
        subTree->brother = NULL;
        subTree->val = val;
        subTree->fatherVal = fatherVal;

        if (!root)
            return subTree; // для первого вхождения
        if (root->val == fatherVal)
            root->son = subTree;
        else
            root->brother = subTree;

        subTree->val = val;
        subTree->fatherVal = fatherVal;

        return root;
    }

    if (subTree->val == fatherVal)
    {
        mktree(subTree, subTree->son, val, fatherVal);
        return root;
    }
    else
    {
        if (subTree->fatherVal == fatherVal)
        {
            mktree(subTree, subTree->brother, val, fatherVal);
            return root;
        }
        else
        {
            if (subTree->son)
                mktree(subTree, subTree->son, val, fatherVal);
            if (subTree->brother)
                mktree(subTree, subTree->brother, val, fatherVal);
            return root;
        }
    }

    return root;
}

void printTree(struct tree *root, int lvl)
{
    if (!root)
        return;
    printf("%*d\n", 2 * lvl, root->val);
    if (root->son)
        printTree(root->son, lvl + 1);
    if (root->brother)
    {
        root = root->brother;
        printTree(root, lvl);
    }
}

bool isEmpty(const struct tree *root)
{
    return root == NULL;
}

void deleteTree(struct tree **t, int val, int id)
{ // id: 1 - удалить, 0 - пропустить

    struct tree *tmp = *t;
    struct tree *tmp1;
    struct tree *tmp2;

    if (tmp->val == val)
        id = 1;
    if (tmp->son)
    {
        if (tmp->son->val == val && tmp->son->brother)
        { // swap указателей

            tmp1 = tmp->son->brother;
            tmp2 = tmp->son;
            tmp2->brother = NULL;
            tmp->son = tmp1;

            deleteTree(&tmp2, tmp2->val, 1);
        }
        else
            deleteTree(&tmp->son, val, id);
    }
    if (tmp->brother)
    {
        if (tmp->brother->val == val && tmp->brother->brother)
        { // swap указателей

            tmp1 = tmp->brother->brother;
            tmp2 = tmp->brother;
            tmp2->brother = NULL;
            tmp->brother = tmp1;

            deleteTree(&tmp2, tmp2->val, 1);
        }
        else
            deleteTree(&tmp->brother, val, id);
    }

    if (id == 1)
    {
        free(*t);
        *t = NULL;
    }

    return;
}

bool isExists(const struct tree *root, int val)
{
    if (!(root)) {
        return false;
    }

    bool tmp = false;

    if (root->val == val)
    {
        tmp = true;
    }
    if (!tmp && root->son)
    {
        tmp = isExists(root->son, val);
    }
    if (!tmp && root->brother)
    {
        tmp = isExists(root->brother, val);
    }

    return tmp;
}

retvals min_depth_val(const struct tree *root, int min_depth, int cur_depth, int min_val, int used_values[10])
{

    retvals rv;
    rv.min_val = min_val;
    rv.min_depth = min_depth;

    for (int i = 0; i < 10; ++i)
    {
        if (used_values[i] == root->val)
            return rv;
    }

    if (!root->son && min_depth >= cur_depth)
    {
        rv.min_val = root->val;
        rv.min_depth = cur_depth;
    }
    if (root->son)
    {
        rv = min_depth_val(root->son, rv.min_depth, cur_depth + 1, rv.min_val, used_values);
    }
    if (root->brother)
    {
        rv = min_depth_val(root->brother, rv.min_depth, cur_depth, rv.min_val, used_values);
    }
    return rv;
}