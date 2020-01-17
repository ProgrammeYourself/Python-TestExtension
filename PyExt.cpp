#include <iostream>
#include <python3.7/Python.h>
#include <vector>

static PyObject *method_merge(PyObject *self, PyObject *args){
	PyObject *l1,*l2=NULL;
	if(!PyArg_ParseTuple(args,"ss",&l1,&l2)){
		return NULL;
	}
	vector<PyObject> data;
	if (PyTuple_Check(incoming)) {
		for(Py_ssize_t i = 0; i < PyTuple_Size(incoming); i++) {
			PyObject *value = PyTuple_GetItem(incoming, i);
			data.push_back( PyFloat_AsDouble(value) );
		}
	} else {
		if (PyList_Check(incoming)) {
			for(Py_ssize_t i = 0; i < PyList_Size(incoming); i++) {
				PyObject *value = PyList_GetItem(incoming, i);
				data.push_back( PyFloat_AsDouble(value) );
			}
		} else {
			throw logic_error("Passed PyObject pointer was not a list or tuple!");
		}
	}
}

int main(){
	std::cout << "This is a module, you fucking donkey!\n";
}
