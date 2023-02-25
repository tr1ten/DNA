# Functions can specify keyword-only arguments.This is indicated by defining extra
# parameters after the first starred parameter. For example:
def foo(x, *args, strict=False):
    pass
def foo(x, *, strict=False):
    pass
# Here is an example of usage:
foo(1,True)
foo(1,strict=True)
# Fails. TypeError: foo() takes 1 positional argument
# Ok.

def foo(a,b):
    print(b)