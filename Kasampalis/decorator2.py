"""
    >>> hello()
    'Hello, World!'
    >>> hello_bold = make_bold(hello)
    >>> hello_bold.__name__
    'hello'
    >>> hello_bold()
    '<b>Hello, World!</b>'
    >>> hello('Kitty')
    'Hello, Kitty'
    >>> hello_bold('Kitty')
    '<b>Hello, Kitty</b>'
    >>> hello3('Vai Corinthians!!!')
    '<b><i>HELLO! Vai Corinthians!!!!</i></b>'
    >>> hello3.__name__
    'hello3'
    >>> hello3.__doc__
    'a decorated hello world, v2'

"""

from functools import wraps

def make_bold(fn):
    @wraps(fn)
    def wrapped(*args):
        return "<b>" + fn(*args) + "</b>"
    return wrapped

def make_italic(fn):
    @wraps(fn)
    def wrapped(*args):
        return "<i>" + fn(*args) + "</i>"
    return wrapped


def hello(name='World!'):
    """a decorated hello world"""
    return "Hello, {}".format(name)


@make_bold
@make_italic
def hello3(name='World!'):
    """a decorated hello world, v2"""
    return "HELLO! {}!".format(name)

if __name__ == '__main__':
    import doctest
    doctest.testmod()


"""
https://docs.python.org/2/library/functools.html#functools.wraps
https://stackoverflow.com/questions/739654/how-can-i-make-a-chain-of-function-decorators-in-python/739665#739665
"""
