

// Write a C++ program as a python module with python API, so that these C++ functions can be called from a python program.
//  this C++ program contains following functions: [1] a function that returns the current system time as a string or char* whichever
//  works better for you, [2] Calculate and return the sum of two numbers received from parameters, [3] Calculate and return the
//  differences of two numbers received from parameters. set "Utils" as the name of the module. once these are done, using "distutils
//  " Python package to write a python program called "setup.py" which can compile your C++ program into a python module. name your extension as "Utils".
//   then run python3 setup.py install or python2 setup.py install depends on python API functions you used (some functions does only support Python3+ ).
//    running this command will then generate the module. (.so on Linux and .dll on Windows )




#include <Python.h>
#include <iostream>
#include<time.h>

char* getTime();

using namespace std;


/*
 * get the system time
 */
static PyObject* getSystemTime(PyObject* self) {

   return Py_BuildValue("s", getTime());
}


/*
 * return the sum of two number
 */
static PyObject* add(PyObject* self, PyObject* args){

    int i,j;

    if(!PyArg_ParseTuple(args,"ii", &i,&j)){

        return NULL;
    }


    return Py_BuildValue("i", i+j);
}




/*
 * return the differences of two number
 */
static PyObject* getDifferences(PyObject* self, PyObject* args){

    int i,j;

    if(!PyArg_ParseTuple(args,"ii", &i,&j)){

        return NULL;
    }


    return Py_BuildValue("i", i-j);
}


/*
 * function to get current time
 */
char* getTime(){

    time_t rawtime;
    struct tm * timeinfo;

     time ( &rawtime );
     timeinfo = localtime ( &rawtime );
     //printf ( " %s", asctime (timeinfo) );

     return asctime(timeinfo);

}




static PyMethodDef System_funcs[] = {
   {"getSystemTime", (PyCFunction)getSystemTime,
      METH_NOARGS, NULL},
      {"add",(PyCFunction)add,
              METH_VARARGS, NULL},
      {"minus",(PyCFunction)getDifferences,
              METH_VARARGS, NULL},
      {NULL}
};

static struct PyModuleDef Utils=
{
    PyModuleDef_HEAD_INIT,
    "Utils", /* name of module */
    "hello\n", /* module documentation, may be NULL */
    -1,   /* size of per-interpreter state of the module, or -1 if the module keeps state in global variables. */
    System_funcs
};


PyMODINIT_FUNC PyInit_Utils(void) {

    cout<<"C++ Module Loaded"<<endl;
    return PyModule_Create(&Utils);

}
