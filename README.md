# CPP_05

This academic exercise teach about Exceptions

I successfully completed CPP04 nine months ago; thus, I daresay this exercise marks a near renewal of my journey in learning C++.

##“Key Concepts Revisited”

+ A class constructor must initialize member attributes in the same order in which they are declared.
+ Exceptions thrown by a class should not be declared as private; otherwise, they cannot be caught outside the class.
+ Default and copy constructors do not have return types.
+ An initialization list must initialize all member attributes.
+ When a negative integer is passed to a function expecting a size_t parameter, it is implicitly converted to a large positive integer due to unsigned integer wrapping (e.g., -5 becomes 18446744073709551611).
+ If a class contains virtual functions, the compiler generates a virtual table (vtable) to support dynamic dispatch.
+ Failing to declare a virtual destructor in a base class can lead to memory leaks when deleting derived class objects through base class pointers.
+ If a class has virtual functions, it must declare a virtual destructor — especially if it is intended to be inherited from.
