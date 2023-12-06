#include <Python.h>

void print_python_list(PyObject *p) {
    PyListObject *list = (PyListObject *)p;
    PyVarObject *var_obj = (PyVarObject *)p;

    printf("[*] Python list info\n");
    printf("[*] Size of the Python List = %zd\n", var_obj->ob_size);
    printf("[*] Allocated = %zd\n", list->allocated);

    for (Py_ssize_t i = 0; i < var_obj->ob_size; ++i) {
        PyObject *element = PyList_GET_ITEM(p, i);
        printf("Element %zd: %s\n", i, Py_TYPE(element)->tp_name);

        if (PyBytes_Check(element)) {
            printf("[.] bytes object info\n");
            printf("  size: %zd\n", PyBytes_GET_SIZE(element));
            printf("  trying string: %s\n", PyBytes_AS_STRING(element));

            printf("  first 10 bytes: ");
            for (int j = 0; j < 10 && j < PyBytes_GET_SIZE(element); ++j) {
                printf("%02x ", (unsigned char)PyBytes_AS_STRING(element)[j]);
            }
            printf("\n");
        }
    }
}

void print_python_bytes(PyObject *p) {
    if (!PyBytes_Check(p)) {
        printf("[.] bytes object info\n");
        printf("  [ERROR] Invalid Bytes Object\n");
        return;
    }

    printf("[.] bytes object info\n");
    printf("  size: %zd\n", PyBytes_GET_SIZE(p));
    printf("  trying string: %s\n", PyBytes_AS_STRING(p));

    printf("  first 10 bytes: ");
    for (int i = 0; i < 10 && i < PyBytes_GET_SIZE(p); ++i) {
        printf("%02x ", (unsigned char)PyBytes_AS_STRING(p)[i]);
    }
    printf("\n");
}

