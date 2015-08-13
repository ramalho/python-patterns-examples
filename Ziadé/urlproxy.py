"""
>>> python_org = Url('http://python.org')
>>> h = python_org.headers()
>>> len(h)
16
>>> sorted(h.keys())  # doctest: +ELLIPSIS
['Accept-Ranges', 'Age', 'Connection', 'Content-Length', 'Content-Type', ...]
>>> h['Content-Type']
'text/html; charset=utf-8'
>>> ubuntu_iso = Url('http://archive.ubuntu.com/ubuntu/dists/trusty-updates/main/installer-amd64/current/images/netboot/mini.iso')
>>> ubuntu_iso.headers()['Last-Modified']
'Wed, 29 Jul 2015 23:34:27 GMT'
>>> len(ubuntu_iso.get())  # doctest: +SKIP
40894464
"""

from urllib.request import urlopen


class Url(object):

    def __init__(self, location):
        self._url = urlopen(location)

    def headers(self):
        return dict(self._url.headers.items())

    def get(self):
        return self._url.read()
