# coding: utf-8

class Borg(object):
    _shared_state = {}
    def __new__(cls, *a, **k):
        obj = super(Borg, cls).__new__(cls, *a, **k)
        obj.__dict__ = cls._shared_state
        return obj

class Foo(Borg): pass
class Bar(Foo): pass
class Baz(Foo): _shared_state = {}

def teste_borg():
    a = Borg()
    b = Borg()
    assert a is not b
    a.x = 123
    assert b.x == 123

def teste_subclasses():
    a = Borg()
    b = Foo()
    a.x = 234
    assert b.x == 234

def teste_sobrescrever_dados():
    a = Foo()
    b = Baz()
    a.x = 345
    try:
        b.x
    except AttributeError, e:
        assert e.args[0] == "'Baz' object has no attribute 'x'"
