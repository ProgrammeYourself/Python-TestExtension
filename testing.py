#!/usr/bin/python3
import pyext

def testMerge():
	l1=list(range(0,12,3))
	l2=list(range(0,24,5))
	print("Merging two lists:",l1,l2,sep="\n")
	l3=pyext.merge(l1,l2)
	print("Lists got merged into:",l3,sep="\n")

if __name__=="__main__":
	testMerge()
