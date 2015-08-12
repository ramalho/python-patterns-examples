from abc import ABCMeta, abstractmethod
import random

class AbstractSubject(object):
    """A common interface for the real and proxy objects."""

    __metaclass__ = ABCMeta

    @abstractmethod
    def sort(self, reverse=False):
        pass

class RealSubject(AbstractSubject):
    """A class for a heavy object which takes a lot of memory space
    and takes some time to instantiate."""

    def __init__(self):
        self.digits = []

        for i in xrange(10000000):
            self.digits.append(random.random())

    def sort(self, reverse=False):
        self.digits.sort()

        if reverse:
            self.digits.reverse()

class Proxy(AbstractSubject):
    """A proxy which has the same interface as RealSubject."""

    reference_count = 0

    def __init__(self):
        """A constructor which creates an object if it is not exist and caches it otherwise."""

        if not getattr(self.__class__, 'cached_object', None):
            self.__class__.cached_object = RealSubject()
            print 'Created new object'
        else:
            print 'Using cached object'

        self.__class__.reference_count += 1

        print 'Count of references = ', self.__class__.reference_count

    def sort(self, reverse=False):
        """The args are logged by the Proxy."""

        print 'Called sort method with args:'
        print locals().items()

        self.__class__.cached_object.sort(reverse=reverse)

    def __del__(self):
        """Decreases a reference to an object, if the number of references is 0, delete the object."""
        self.__class__.reference_count -= 1

        if self.__class__.reference_count == 0:
            print 'Number of reference_count is 0. Deleting cached object...'
            del self.__class__.cached_object

        print 'Deleted object. Count of objects = ', self.__class__.reference_count

if __name__ == '__main__':
    proxy1 = Proxy()
    print

    proxy2 = Proxy()
    print

    proxy3 = Proxy()
    print

    proxy1.sort(reverse=True)
    print

    print 'Deleting proxy2...'
    del proxy2
    print

    print 'The other objects are deleted upon program termination...'
