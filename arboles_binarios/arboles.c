#include <stdio.h>
#include <stdlib.h>

//Estructura de nodo
typedef struct node
{
    struct node *left;  
    struct node *right; 
    int data;           
} node;

//Prototipos
node *newNode(int data);
node *insert(node *root, int data);
node *getMax(node *root);
node *delete (node *root, int data);
int find(node *root, int data);
int height(node *root);
void purge(node *root);
void inOrder(node *root);

//Main
int main()
{
    node *root = NULL;
    int opt = -1;
    int data = 0;

    while (opt != 0)
    {
        printf(
            "\n\n[1] Insertar Nodo\n[2] Borrar Nodo\n[3] Encontrar Nodo\n[4] Obtener "
            "altura actual\n[5] Imprimir arbol en orden creciente\n[0] Salir\n");
        scanf("%d", &opt); 

        switch (opt)
        {
        case 1:
            printf("Ingrese el valor del nuevo nodo:\n");
            scanf("%d", &data);
            root = insert(root, data);
            break;

        case 2:
            printf("Ingrese el valor del nodo a ser borrado:\n");
            if (root != NULL)
            {
                scanf("%d", &data);
                root = delete (root, data);
            }
            else
            {
                printf("Error: El arbol ya esta vacio.\n");
            }
            break;

        case 3:
            printf("Ingrese el valor que desea buscar:\n");
            scanf("%d", &data);
            find(root, data) ? printf("El valor esta en el arbol.\n")
                             : printf("El valor no esta en el arbol.\n");
            break;

        case 4:
            printf("La altura actual del arbol es: %d\n", height(root));
            break;

        case 5:
            inOrder(root);
            break;
        }
    }

    purge(root);

    return 0;
}

node *newNode(int data)
{
    node *tmp = (node *)malloc(sizeof(node));

    tmp->data = data;
    tmp->left = NULL;
    tmp->right = NULL;

    return tmp;
}

node *insert(node *root, int data)
{
    if (root == NULL)
    {
        root = newNode(data);
    }
    else if (data > root->data)
    {
        root->right = insert(root->right, data);
    }
    else if (data < root->data)
    {  
        root->left = insert(root->left, data);
    }

    return root;
}

node *getMax(node *root)
{
    if (root->right != NULL)
    {
        return getMax(root->right);
    }
    return root;
}

node *delete (node *root, int data)
{
    if (root == NULL)
    {
        return root;
    }
    else if (data > root->data)
    {  
        root->right = delete (root->right, data);
    }
    else if (data < root->data)
    {  
        root->left = delete (root->left, data);
    }
    else if (data == root->data)
    {
        if ((root->left == NULL) && (root->right == NULL))
        {  
            free(root);
            return NULL;
        }
        else if (root->left == NULL)
        {  
            node *tmp = root;
            root = root->right;
            free(tmp);
            return root;
        }
        else if (root->right == NULL)
        {
            node *tmp = root;
            root = root->left;
            free(tmp);
            return root;
        }
        else
        {  
            node *tmp = getMax(root->left);

            root->data = tmp->data;
            root->left = delete (root->left, tmp->data);
        }
    }
    return root;
}

int find(node *root, int data)
{
    if (root == NULL)
    {
        return 0;
    }
    else if (data > root->data)
    {
        return find(root->right, data);
    }
    else if (data < root->data)
    {
        return find(root->left, data);
    }
    else if (data == root->data)
    {
        return 1;
    }
    else
    {  
        return 0;
    }
}


int height(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        int right_h = height(root->right);
        int left_h = height(root->left);

        if (right_h > left_h)
        {
            return (right_h + 1);
        }
        else
        {
            return (left_h + 1);
        }
    }
}

void purge(node *root)
{
    if (root != NULL)
    {
        if (root->left != NULL)
        {
            purge(root->left);
        }
        if (root->right != NULL)
        {
            purge(root->right);
        }
        free(root);
        root = NULL; 
    }
}

void inOrder(node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("\t[ %d ]\t", root->data);
        inOrder(root->right);
    }
}