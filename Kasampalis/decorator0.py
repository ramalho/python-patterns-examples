"""
    >>> hello()
    'Hello, World!'
    >>> hello_bold = make_bold(hello)
    >>> hello_bold.__name__
    'wrapped'
    >>> hello_bold()
    '<b>Hello, World!</b>'
    >>> hello('Kitty')
    'Hello, Kitty'
    >>> hello_bold('Kitty')
    '<b>Hello, Kitty</b>'
    >>> hello2('Vai Corinthians!!!')
    '<b>HELLO! Vai Corinthians!!!!</b>'
    >>> hello2.__name__
    'wrapped'
    >>> hello2.__doc__ is None
    True

"""


def make_bold(fn):
    def wrapped(*args):
        return "<b>" + fn(*args) + "</b>"
    return wrapped

def hello(name='World!'):
    """a decorated hello world"""
    return "Hello, {}".format(name)

@make_bold
def hello2(name='World!'):
    """a decorated hello world, v2"""
    return "HELLO! {}!".format(name)

if __name__ == '__main__':
    import doctest
    doctest.testmod()


"""
https://docs.python.org/2/library/functools.html#functools.wraps
https://stackoverflow.com/questions/739654/how-can-i-make-a-chain-of-function-decorators-in-python/739665#739665
"""
