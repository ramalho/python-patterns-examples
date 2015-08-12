# coding: utf-8

class Ordinaria(object):
    """Apenas ma classe ordinária."""

class Singleton(object):
    def __new__(cls, *a, **k):
        if not hasattr(cls, '_inst'):
            cls._inst = super(Singleton, cls).__new__(cls, *a, **k)
        return cls._inst

class Foo(Singleton): pass
class Bar(Foo): pass

def teste_ordinaria():
    a = Ordinaria()
    b = Ordinaria()
    assert a is not b

def teste_singleton():
    a = Singleton()
    b = Singleton()
    assert a is b

def teste_subclasses():
    a = Singleton()
    f = Foo()
    b = Bar()
    assert f is a
    assert b is a


