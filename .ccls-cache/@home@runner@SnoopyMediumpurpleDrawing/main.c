#include <stdio.h>
#include <string.h>

#define MAX_PRODUCTOS 100
#define MAX_NOMBRE 50

char nombres[MAX_PRODUCTOS][MAX_NOMBRE];
int cantidades[MAX_PRODUCTOS];
float precios[MAX_PRODUCTOS];

void guardarEnArchivo(int numProductos);
void cargarDesdeArchivo(int *numProductos);
void ingresarProducto(int *numProductos);
void editarProducto(int numProductos);
void eliminarProducto(int *numProductos);
void listarProductos(int numProductos);

int main() {
    int numProductos = 0;
    int opcion;

    cargarDesdeArchivo(&numProductos);

    do {
        printf("\nSistema de Inventario\n");
        printf("1. Ingresar Producto\n");
        printf("2. Editar Producto\n");
        printf("3. Eliminar Producto\n");
        printf("4. Listar Productos\n");
        printf("0. Salir\n");
        printf("Ingrese su opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                ingresarProducto(&numProductos);
                break;
            case 2:
                editarProducto(numProductos);
                break;
            case 3:
                eliminarProducto(&numProductos);
                break;
            case 4:
                listarProductos(numProductos);
                break;
            case 0:
                guardarEnArchivo(numProductos);
                printf("Saliendo del programa.\n");
                break;
            default:
                printf("Opción no válida. Intente de nuevo.\n");
        }
    } while (opcion != 0);

    return 0;
}

void guardarEnArchivo(int numProductos) {
    FILE *archivo;
    archivo = fopen("inventario.txt", "w");

    if (archivo != NULL) {
        for (int i = 0; i < numProductos; i++) {
            fprintf(archivo, "%s %d %.2f\n", nombres[i], cantidades[i], precios[i]);
        }
        fclose(archivo);
    } else {
        printf("Error al abrir el archivo para escritura.\n");
    }
}

void cargarDesdeArchivo(int *numProductos) {
    FILE *archivo;
    archivo = fopen("inventario.txt", "r");

    if (archivo != NULL) {
        while (fscanf(archivo, "%s %d %f", nombres[*numProductos], &cantidades[*numProductos], &precios[*numProductos]) != EOF) {
            (*numProductos)++;
            if (*numProductos >= MAX_PRODUCTOS) {
                break;
            }
        }
        fclose(archivo);
    } else {
        printf("No se encontró el archivo. Se creará uno nuevo al salir del programa.\n");
    }
}

void ingresarProducto(int *numProductos) {
    if (*numProductos < MAX_PRODUCTOS) {
        printf("Ingrese el nombre del producto: ");
        scanf("%s", nombres[*numProductos]);
        printf("Ingrese la cantidad del producto: ");
        scanf("%d", &cantidades[*numProductos]);
        printf("Ingrese el precio del producto: ");
        scanf("%f", &precios[*numProductos]);

        (*numProductos)++;

        printf("Producto ingresado exitosamente.\n");

        guardarEnArchivo(*numProductos);
    } else {
        printf("Error: Se alcanzó el límite máximo de productos.\n");
    }
}

void editarProducto(int numProductos) {
    int indice;

    if (numProductos > 0) {
        printf("Ingrese el índice del producto que desea editar (0-%d): ", numProductos - 1);
        scanf("%d", &indice);

        if (indice >= 0 && indice < numProductos) {
            printf("Ingrese el nuevo nombre del producto: ");
            scanf("%s", nombres[indice]);
            printf("Ingrese la nueva cantidad del producto: ");
            scanf("%d", &cantidades[indice]);
            printf("Ingrese el nuevo precio del producto: ");
            scanf("%f", &precios[indice]);

            printf("Producto editado exitosamente.\n");

            guardarEnArchivo(numProductos);
        } else {
            printf("Error: Índice no válido.\n");
        }
    } else {
        printf("Error: No hay productos para editar.\n");
    }
}

void eliminarProducto(int *numProductos) {
    int indice;

    if (*numProductos > 0) {
        printf("Ingrese el índice del producto que desea eliminar (0-%d): ", *numProductos - 1);
        scanf("%d", &indice);

        if (indice >= 0 && indice < *numProductos) {
            for (int i = indice; i < *numProductos - 1; i++) {
                strcpy(nombres[i], nombres[i + 1]);
                cantidades[i] = cantidades[i + 1];
                precios[i] = precios[i + 1];
            }

            (*numProductos)--;

            printf("Producto eliminado exitosamente.\n");

            guardarEnArchivo(*numProductos);
        } else {
            printf("Error: Índice no válido.\n");
        }
    } else {
        printf("Error: No hay productos para eliminar.\n");
    }
}

void listarProductos(int numProductos) {
    if (numProductos > 0) {
        printf("Inventario de Productos:\n");
        printf("%-20s %-10s %-10s\n", "Nombre", "Cantidad", "Precio");
        for (int i = 0; i < numProductos; i++) {
            printf("%-20s %-10d %-10.2f\n", nombres[i], cantidades[i], precios[i]);
        }
    } else {
        printf("El inventario está vacío.\n");
    }
}
