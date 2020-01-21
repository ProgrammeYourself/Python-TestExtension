#!/usr/bin/python3
from distutils.core import setup, Extension

def main():
	setup(name="pyext",
	version="0.0.3",
	description="Testing module",
	author="Riedler",
	author_email="coding@riedler.wien",
	ext_modules=[Extension("pyext", ["pyext.cpp"])])
if __name__ == "__main__":
	main()
