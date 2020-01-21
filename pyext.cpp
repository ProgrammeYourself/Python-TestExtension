#include <iostream>
#include <python3.7/Python.h>
#include <vector>
#include <algorithm>

std::vector<long long> list2vec(PyObject* incoming) {
	std::vector<long long> data;
	if (PyTuple_Check(incoming)) {
		for(Py_ssize_t i = 0; i < PyTuple_Size(incoming); i++) {
			PyObject* value = PyTuple_GetItem(incoming, i);
			data.push_back( PyLong_AsLongLong(value) );
		}
	} else {
		if (PyList_Check(incoming)) {
			for(Py_ssize_t i = 0; i < PyList_Size(incoming); i++) {
				PyObject* value = PyList_GetItem(incoming, i);
				data.push_back( PyLong_AsLongLong(value) );
			}
		} else {
			throw std::logic_error("Passed PyObject pointer was not a list or tuple!");
		}
	}
	return data;
}

PyObject* vec2list(std::vector<long long> data) {
	PyObject* listObj = PyList_New(data.size());
	if (!listObj) throw std::logic_error("Unable to allocate memory for Python list");
	for (unsigned int i = 0; i < data.size(); i++) {
		PyObject *num = PyLong_FromLongLong(data[i]);
		if (!num) {
			Py_DECREF(listObj);
			throw std::logic_error("Unable to allocate memory for Python list");
		}
		PyList_SET_ITEM(listObj, i, num);
	}
	return listObj;
}

static PyObject* method_merge(PyObject* self, PyObject* args){
	PyObject *l1,*l2=NULL;
	if(!PyArg_ParseTuple(args,"ss",&l1,&l2)){
		return NULL;
	}
	std::vector<long long> v1=list2vec(l1);
	std::vector<long long> v2=list2vec(l2);
	std::vector<long long> result={};
	std::merge(v1.begin(),v1.end(),v2.begin(),v2.end(),result.begin());
	return vec2list(result);
}

static PyMethodDef PyExtMethods[] = {
	{"merge", method_merge, METH_VARARGS, "Python interface for merge C++ library function"},	//defines a function for python
	{NULL, NULL, 0, NULL}
};
static struct PyModuleDef pyextmodule = {
	PyModuleDef_HEAD_INIT,
	"pyext",
	"Just some module to test C++ modules for python",
	-1,
	PyExtMethods
};

PyMODINIT_FUNC PyInit_pyext(void){
	return PyModuleCreate(&pyextmodule)
}